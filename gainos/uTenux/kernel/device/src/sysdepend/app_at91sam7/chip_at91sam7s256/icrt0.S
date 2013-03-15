/*
 *------------------------------------------------------------------------------
 *    Device
 *
 *    Copyright (C) 2008-2013 by Dalian uLoong Co.,Ltd. All rights reserved.
 *
 *    This program is open source software; developer can redistribute it and/or
 *    modify it under the terms of the U-License as published by the T-Engine China
 *    Open Source Society; either version 1 of the License, or (at developer option)
 *    any later Version.
 *
 *    This program is distributed in the hope that it will be useful,but WITHOUT ANY
 *    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 *    A PARTICULAR PURPOSE.  See the U-License for more details.
 *
 *    Developer should have received a copy of the U-License along with this program;
 *    if not, download from www.tecoss.org(the web page of the T-Engine China Open
 *    Source Society).
 *
 *    CPU:        ARM7
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : icrt0.S
 *	 Create Date    : 2009/7/27-2012/9/30
 *	 Author	        : WangShb
 *	 Description    : Start up module(AT91SAM7).
 *-------------------------------------------------------------------------------
 */

#include "hwconfig.h"
#include "utk_config.h"

#include <machine.h>
#include <tk/asm.h>

    .syntax unified

/*
 * Imports external symbols
 */
    .extern main, __data_org, __data_start, __data_end, __bss_start, __bss_end

#if USE_IMALLOC
	/* Low level memory manager information */
    .comm	Csym(knl_lowmem_top), 4	    /* Head of area (Low address) */
    .comm	Csym(knl_lowmem_limit), 4	/* End of area (High address) */
#endif

/*
 * Vector Table
 */
    .section .vector,"ax"
    .code 32
    .align 0
    .global __reset
__reset:
    b       start              /* reset */
    .global undef_vector
undef_vector:
    b       undef_vector       /* undefined operation */
    .global swi_vector
swi_vector:
    b       swi_handler        /* software interrupt */
    .global prefetch_vector
prefetch_vector:
    b       prefetch_vector    /* prefetch abort */
    .global data_abort_vector
data_abort_vector:
    b       data_abort_vector  /* data abort */
    .global reserved_vector
reserved_vector:
    b       reserved_vector    /* reserved */
    .global irq_vector
irq_vector:
    ldr pc, [pc, #-0xf20]      /* IRQ: AIC_IVR */
    .global fiq_vector
fiq_vector:
    ldr pc, [pc, #-0xf20]      /* FIQ: AIC_FVR */

/*
 * Start up routine
 */
    .section .ftext.1,"ax"
    .code 32
    .align  0
    .global start
start:
	msr     cpsr, #(PSR_SVC|PSR_DI)

	.section .romtext.1,"ax"
    .code 32
    .align     0
watchdog_init:
	ldr     r1, =WDT_BASE
    ldr     r0, =WDT_WDDIS
	str     r0, [r1,# WDT_MR]
flashrom_init:
    ldr     r0, =MC_BASE
    ldr     r1, =0x280100
    str     r1,[r0,# MC_FMR]

crystal_init:
    ldr     r0, =PMC_BASE
    ldr     r1, =CRYSTAL_ENABLE_MOSC
    str     r1, [r0,#PMC_CKGR_MOR]

wait_stabilized:
    ldr     r1, [r0, #PMC_SR]
    tst     r1, #PMC_MOSCS
    beq     wait_stabilized

set_pllr:
    ldr     r1, =CRYSTAL_ENABLE_PLL
    str     r1, [r0,#PMC_CKGR_PLLR]
set_pllr_delay:
    ldr     r1, [r0, #PMC_SR]
    tst     r1, #PMC_PLL_LOCK
    beq     set_pllr_delay

set_mckr:
    ldr     r1, =CRYSTAL_ENABLE_MCK
    str     r1, [r0, #PMC_MCKR]
set_mckr_delay:
    ldr     r1, [r0, #PMC_SR]
    tst     r1, #PMC_MCKRDY
    beq     set_mckr_delay

enable_pll:
	ldr     r1, =CRYSTAL_ENABLE_PCK
	str     r1, [r0, #PMC_MCKR]
enable_pll_delay:
	ldr     r1, [r0, #PMC_SR]
	tst     r1, #PMC_MCKRDY
	beq     enable_pll_delay

tc_enable:
	/* TC0 clock enable */
	mov     r1, #(1 << TC0IRQ)
	str     r1, [r0, #PMC_PCER]

	b       setup_ram_vectors

ram_vector_table:
    ldr     pc, [pc, #0x18]        /* reset */
    ldr     pc, [pc, #0x18]        /* undefined operation */
    ldr     pc, [pc, #0x18]        /* software interrupt */
    ldr     pc, [pc, #0x18]        /* prefetch abort */
    ldr     pc, [pc, #0x18]        /* data abort */
    nop                            /* reserved */
    ldr     pc, [pc, #-0xf20]      /* IRQ: AIC_IVR */
    ldr     pc, [pc, #-0xf20]      /* FIQ: AIC_FVR */

ram_vector_address_table:
    .long   start
    .long   undef_vector
    .long   swi_vector
    .long   prefetch_vector
    .long   data_abort_vector

setup_ram_vectors:
	mov     r8, #INTERNAL_RAM_START_BEFORE_REMAP /* dst*/
	sub     r9, pc, #(8 + . - ram_vector_table)  /* src */
	ldmia   r9!, {r0-r7} /* read vector */
	stmia   r8!, {r0-r7} /* write vector */
	ldmia   r9!, {r0-r4} /* read jump table */
	stmia   r8!, {r0-r4} /* write jump table */

/*
 * chip select and remap
 */
	ldr     r12, =after_remap_start
    ldr     r1, =MC_BASE
	/* remap */
	mov     r2, #1
	str     r2, [r1, #MC_RCR]
	mov     pc, r12



/* -------- From here, address space after remap --------------------- */

after_remap_start:

    .section .ftext.2,"ax"
    .code   32
    .align  0

#if USE_PROTECT_MODE
	ldr     r1, =AIC_BASE
    ldr     r2,[r1,#AIC_DCR]
    orr     r2,r2,#1
    str     r2,[r1,#AIC_DCR]
#endif

init_stacks:
    ldr      r1, =EXCEPTION_STACK_TOP
#if ABT_STACK_SIZE != 0
	msr      cpsr, #(PSR_ABT|PSR_DI)
	mov      sp, r1
	sub      r1, r1, #ABT_STACK_SIZE
#endif
#if UND_STACK_SIZE != 0
	msr      cpsr, #(PSR_UND|PSR_DI)
	mov      sp, r1
	sub      r1, r1, #UND_STACK_SIZE
#endif
#if USR_STACK_SIZE != 0
	msr      cpsr, #(PSR_USR|PSR_DI)
	mov      sp, =APPLICATION_STACK_TOP
#endif
#if FIQ_STACK_SIZE != 0
	msr      cpsr, #(PSR_FIQ|PSR_DI)
	mov      sp, r1
	sub      r1, r1, #FIQ_STACK_SIZE
#endif
	msr      cpsr, #(PSR_IRQ|PSR_DI)
	mov      sp, r1
	sub      r1, r1, #IRQ_STACK_SIZE

	msr      cpsr, #(PSR_SVC|PSR_DI)
	mov      sp, r1

#if USE_TMONITOR
	ldr      r0, =tm_init
	mov      lr, pc
	bx       r0
#endif

	.section .romtext.2,"ax"
	.code    32
	.align   0

	/* .data */
	ldr     r8, =__data_org    /* src address */
	ldr     r9, =__data_start  /* dst address */
	ldr     r10, =__data_end
	subs    r10, r10, r9       /* r10 := data_size */
	beq     data_done          /* if __data_start == __data_end */

data_loop:
	ldmia   r8!, {r0}
	stmia   r9!, {r0}
	subs    r10, r10, #4
	bne     data_loop          /* if data_size != 0 */

data_done:

	.section .ftext.3,"ax"
	.code   32
	.align  0

#if USE_NOINIT
	ldr     r9, =__noinit_end   /* dst address */
#else
	/* .bss */
	ldr     r9, =__bss_start    /* dst address */
#endif
	ldr     r10, =__bss_end
	subs    r10, r10, r9        /* r10 := data_size */
	beq     bss_done            /* if __bss_start == __bss_end */
	mov     r0, #0

bss_loop:
	stmia   r9!, {r0}
	subs    r10, r10, #4
	bne     bss_loop            /* if data_size != 0 */

bss_done:

#if USE_IMALLOC
	ldr     r5, =SYSTEMAREA_TOP
	cmp	    r9, r5			    /* _end or RAM_TOP */
	movhi	r5, r9			    /* Either of High addresses */
	ldr	    ip, =knl_lowmem_top
	str	    r5, [ip]		    /* knl_lowmem_top = _end or RAM_TOP */
	ldr     r5, =SYSTEMAREA_END
	ldr	    ip, =knl_lowmem_limit
	str	    r5, [ip]		    /* knl_lowmem_limit = RAM_END */
#endif

kernel_start:
	ldr	    ip, =Csym(main)
	mov	    r0, #0
	mov	    r14, pc
	bx	    ip
l_end:
	b       l_end

#if USE_TMONITOR
tm_init:
	/* initialize serial I/O */
	ldr     r0, =sio_init
	bx      r0
	/* return directly to the place tm_init called from sio_init */
#endif

swi_handler:
	str     lr, [sp, #-4]!
	str     ip, [sp, #-4]!
	mrs     ip, spsr
	str     ip, [sp, #-4]!

	ldr     ip, [lr, #-4]   /* load SWI No. */
	bic     ip, ip, #(0xff << 24)

	ldr     lr, =Csym(knl_intvec) /* exception vector table */
	add     ip, lr, ip, LSL #2 /* lr := lr + ip*4 = vecaddr */
	ldr     lr, [ip]
	bx      lr

	.global knl_irq_handler
knl_irq_handler:
	sub     lr, lr, #4
	stmfd   sp!, {lr}  /* sp-> lr_xxx */

#if USE_PROTECT_MODE
    ldr     lr, =AIC_BASE
    str     lr, [lr, #AIC_IVR]
#else
    ldr     lr, =AIC_BASE
    ldr     lr, [lr, #AIC_IVR]
#endif

	stmfd   sp!, {ip} /* sp-> ip, lr_xxx */
	mrs     ip, spsr
	stmfd   sp!, {ip} /* sp-> spsr_xxx, ip, lr_xxx */
	stmfd   sp!, {r3} /* sp-> r3, spsr_xxx, ip, lr_xxx */

	ldr     lr, =(AIC_BASE | AIC_ISR)
	ldr     lr, [lr] /* lr := IRQ No. */
	ldr     ip, =Csym(knl_intvec) /* exception vector table */
	add     ip, ip, lr, LSL #2 /* ip := &vector[IRQ No.] */
	ldr     r3, [ip] /* r3 := vector[IRQ No.] */
	mov     lr, pc
	bx      r3

	.end
