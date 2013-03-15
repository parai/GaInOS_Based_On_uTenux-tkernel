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
 *    CPU:        CORTEX M4
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : icrt0.S
 *	 Create Date    : 2012/9/6-2013/1/15
 *	 Author	        : Zhangzl-Zhangzl
 *	 Description    : Start up module(XMC4500F144K1024).
 *-------------------------------------------------------------------------------
 */


#include "hwconfig.h"
#include "utk_config.h"

#include <machine.h>
#include <tk/asm.h>

#include "tkdev_conf.h"

     .syntax unified

/*
 * Imports external symbols
 */
     .extern main, __data_org, __data_start, __data_end, __bss_start, __bss_end, knl_systick_handler

#if USE_IMALLOC
	/* Low level memory manager information */
    .comm	Csym(knl_lowmem_top),   4  	/* Head of area (Low address) */
	.comm	Csym(knl_lowmem_limit), 4	/* End of area (High address) */
#endif

/*
 * Vector Table
 */
    .section .vector,"ax"
    .align 0
    .global __Vectors,__Vectors_End
__Vectors:
    /*    Internal Exceptions Vector Define                                 */
    .word   STACK_TOP                    /* 00: Top of Main Stack           */
    .word   reset_handler                /* 01: Reset Handler               */
    .word   default_handler              /* 02: NMI Handler                 */
    .word   default_handler              /* 03: Hard Fault Handler          */
    .word   default_handler              /* 04: MPU Fault Handler           */
    .word   default_handler              /* 05: Bus Fault Handler           */
    .word   default_handler              /* 06: Usage Fault Handler         */
    .word   0                            /* 07: Reserved                    */
    .word   0                            /* 08: Reserved                    */
    .word   0                            /* 09: Reserved                    */
    .word   0                            /* 10: Reserved                    */
    .word   svc_handler                  /* 11: SVCall Handler              */
    .word   default_handler              /* 12: Debug Monitor Handler       */
    .word   0                            /* 13: Reserved                    */
    .word   knl_dispatch_entry           /* 14: PendSV Handler              */
    .word   knl_systick_handler          /* 15: Systick Handler             */

    /*    External Interrupts Vector Define                                 */
    .word   default_handler              /* 16: */
    .word   default_handler              /* 17: */
    .word   default_handler              /* 18: */
    .word   default_handler              /* 19: */
    .word   default_handler              /* 20: */
    .word   default_handler              /* 21: */
    .word   default_handler              /* 22: */
    .word   default_handler              /* 23: */
    .word   default_handler              /* 24: */
    .word   default_handler              /* 25: */
    .word   default_handler              /* 26: */
    .word   default_handler              /* 27: */
    .word   default_handler              /* 28: */
    .word   default_handler              /* 29: */
    .word   default_handler              /* 30: */
    .word   default_handler              /* 31: */
    .word   default_handler              /* 32: */
    .word   default_handler              /* 33: */
    .word   default_handler              /* 34: */
    .word   default_handler              /* 35: */
    .word   default_handler              /* 36: */
    .word   default_handler              /* 37: */
    .word   default_handler              /* 38: */
    .word   default_handler              /* 39: */
    .word   default_handler              /* 40: */
    .word   default_handler              /* 41: */
    .word   default_handler              /* 42: */
    .word   default_handler              /* 43: */
    .word   default_handler              /* 44: */
    .word   default_handler              /* 45: */
    .word   default_handler              /* 46: */
    .word   default_handler              /* 47: */
    .word   default_handler              /* 48: */
    .word   default_handler              /* 49: */
    .word   default_handler              /* 50: */
    .word   default_handler              /* 51: */
    .word   default_handler              /* 52: */
    .word   default_handler              /* 53: */
    .word   default_handler              /* 54: */
    .word   default_handler              /* 55: */
    .word   default_handler              /* 56: */
    .word   default_handler              /* 57: */
    .word   default_handler              /* 58: */
    .word   default_handler              /* 59: */
    .word   default_handler              /* 60: */
    .word   default_handler              /* 61: */
    .word   default_handler              /* 62: */
    .word   default_handler              /* 63: */
    .word   default_handler              /* 64: */
    .word   default_handler              /* 65: */
    .word   default_handler              /* 66: */
    .word   default_handler              /* 67: */
    .word   default_handler              /* 68: */
    .word   default_handler              /* 69: */
    .word   default_handler              /* 70: */
    .word   default_handler              /* 71: */
    .word   default_handler              /* 72: */
    .word   default_handler              /* 73: */
    .word   default_handler              /* 74: */
    .word   default_handler              /* 75: */
    .word   default_handler              /* 76: */
    .word   default_handler              /* 77: */
    .word   default_handler              /* 78: */
    .word   default_handler              /* 79: */
    .word   default_handler              /* 80: */
    .word   default_handler              /* 81: */
    .word   default_handler              /* 82: */
    .word   default_handler              /* 83: */
    .word   default_handler              /* 84: */
    .word   default_handler              /* 85: */
    .word   default_handler              /* 86: */
    .word   default_handler              /* 87: */
    .word   default_handler              /* 88: */
    .word   default_handler              /* 89: */
    .word   default_handler              /* 90: */
    .word   default_handler              /* 91: */
    .word   default_handler              /* 92: */
    .word   default_handler              /* 93: */
    .word   default_handler              /* 94: */
    .word   default_handler              /* 95: */
    .word   default_handler              /* 96: */
    .word   default_handler              /* 97: */
    .word   default_handler              /* 98: */
    .word   default_handler              /* 99: */
    .word   default_handler              /* 100: */
    .word   default_handler              /* 101: */
    .word   default_handler              /* 102: */
    .word   default_handler              /* 103: */
    .word   default_handler              /* 104: */
    .word   default_handler              /* 105: */
    .word   default_handler              /* 106: */
    .word   default_handler              /* 107: */
    .word   default_handler              /* 108: */
    .word   default_handler              /* 109: */
    .word   default_handler              /* 110: */
    .word   default_handler              /* 111: */
    .word   default_handler              /* 112: */
    .word   default_handler              /* 113: */
    .word   default_handler              /* 114: */
    .word   default_handler              /* 115: */
    .word   default_handler              /* 116: */
    .word   default_handler              /* 117: */
    .word   default_handler              /* 118: */
    .word   default_handler              /* 119: */
    .word   default_handler              /* 120: */
    .word   default_handler              /* 121: */
    .word   default_handler              /* 122: */
    .word   default_handler              /* 123: */
    .word   default_handler              /* 124: */
    .word   default_handler              /* 125: */
    .word   default_handler              /* 126: */
    .word   default_handler              /* 127: */
    .word   default_handler              /* 128: */
    .word   default_handler              /* 129: */
    .word   default_handler              /* 130: */
    .word   default_handler              /* 131: */
    .word   default_handler              /* 132: */
    .word   default_handler              /* 133: */
    .word   default_handler              /* 134: */
    .word   default_handler              /* 135: */
    .word   default_handler              /* 136: */
    .word   default_handler              /* 137: */
    .word   default_handler              /* 138: */
    .word   default_handler              /* 139: */
    .word   default_handler              /* 140: */
    .word   default_handler              /* 141: */
    .word   default_handler              /* 142: */
    .word   default_handler              /* 143: */
    .word   default_handler              /* 144: */
    .word   default_handler              /* 145: */
    .word   default_handler              /* 146: */
    .word   default_handler              /* 147: */
    .word   default_handler              /* 148: */
    .word   default_handler              /* 149: */
    .word   default_handler              /* 150: */
    .word   default_handler              /* 151: */
    .word   default_handler              /* 152: */
    .word   default_handler              /* 153: */
    .word   default_handler              /* 154: */
    .word   default_handler              /* 155: */
    .word   default_handler              /* 156: */
    .word   default_handler              /* 157: */
    .word   default_handler              /* 158: */
    .word   default_handler              /* 159: */
    .word   default_handler              /* 160: */
    .word   default_handler              /* 161: */
    .word   default_handler              /* 162: */
    .word   default_handler              /* 163: */
    .word   default_handler              /* 164: */
    .word   default_handler              /* 165: */
    .word   default_handler              /* 166: */
    .word   default_handler              /* 167: */
    .word   default_handler              /* 168: */
    .word   default_handler              /* 169: */
    .word   default_handler              /* 170: */
    .word   default_handler              /* 171: */
    .word   default_handler              /* 172: */
    .word   default_handler              /* 173: */
    .word   default_handler              /* 174: */
    .word   default_handler              /* 175: */
    .word   default_handler              /* 176: */
    .word   default_handler              /* 177: */
    .word   default_handler              /* 178: */
    .word   default_handler              /* 179: */
    .word   default_handler              /* 180: */
    .word   default_handler              /* 181: */
    .word   default_handler              /* 182: */
    .word   default_handler              /* 183: */
    .word   default_handler              /* 184: */
    .word   default_handler              /* 185: */
    .word   default_handler              /* 186: */
    .word   default_handler              /* 187: */
    .word   default_handler              /* 188: */
    .word   default_handler              /* 189: */
    .word   default_handler              /* 190: */
    .word   default_handler              /* 191: */
    .word   default_handler              /* 192: */
    .word   default_handler              /* 193: */
    .word   default_handler              /* 194: */
    .word   default_handler              /* 195: */
    .word   default_handler              /* 196: */
    .word   default_handler              /* 197: */
    .word   default_handler              /* 198: */
    .word   default_handler              /* 199: */
    .word   default_handler              /* 200: */
    .word   default_handler              /* 201: */
    .word   default_handler              /* 202: */
    .word   default_handler              /* 203: */
    .word   default_handler              /* 204: */
    .word   default_handler              /* 205: */
    .word   default_handler              /* 206: */
    .word   default_handler              /* 207: */
    .word   default_handler              /* 208: */
    .word   default_handler              /* 209: */
    .word   default_handler              /* 210: */
    .word   default_handler              /* 211: */
    .word   default_handler              /* 212: */
    .word   default_handler              /* 213: */
    .word   default_handler              /* 214: */
    .word   default_handler              /* 215: */
    .word   default_handler              /* 216: */
    .word   default_handler              /* 217: */
    .word   default_handler              /* 218: */
    .word   default_handler              /* 219: */
    .word   default_handler              /* 220: */
    .word   default_handler              /* 221: */
    .word   default_handler              /* 222: */
    .word   default_handler              /* 223: */
    .word   default_handler              /* 224: */
    .word   default_handler              /* 225: */
    .word   default_handler              /* 226: */
    .word   default_handler              /* 227: */
    .word   default_handler              /* 228: */
    .word   default_handler              /* 229: */
    .word   default_handler              /* 230: */
    .word   default_handler              /* 231: */
    .word   default_handler              /* 232: */
    .word   default_handler              /* 233: */
    .word   default_handler              /* 234: */
    .word   default_handler              /* 235: */
    .word   default_handler              /* 236: */
    .word   default_handler              /* 237: */
    .word   default_handler              /* 238: */
    .word   default_handler              /* 239: */
    .word   default_handler              /* 240: */
    .word   default_handler              /* 241: */
    .word   default_handler              /* 242: */
    .word   default_handler              /* 243: */
    .word   default_handler              /* 244: */
    .word   default_handler              /* 245: */
    .word   default_handler              /* 246: */
    .word   default_handler              /* 247: */
    .word   default_handler              /* 248: */
    .word   default_handler              /* 249: */
    .word   default_handler              /* 250: */
    .word   default_handler              /* 251: */
    .word   default_handler              /* 252: */
    .word   default_handler              /* 253: */
    .word   default_handler              /* 254: */
    .word   default_handler              /* 255: */
__Vectors_End:
/*
 * Start up routine
 */
    .section .ftext.1,"ax"
    .align  0
    .global reset_handler
    .type	reset_handler,function
reset_handler:
    cpsid   i                       /*Disable interrupt   */
    mov.w   r0, #CTL_SVC
    msr.w   control, r0             /*Select MSP+SVC mode */

    .section .romtext.1,"ax"
    .align  0
flashrom_init:

enable_pll:
	/* Enable PLL.*/
	ldr.w   r0, =SCU_BASE
	ldr.w   r1, =SCU_PLLCON0
	ldr.w   r2, [r0, r1]
	ldr.w   r3, =(~(SCU_PLLCON0_VCOPWD | SCU_PLLCON0_PLLPWD))
	and.w   r2, r3
	str.w   r2, [r0, r1]

enable_osc_hp:
    /* External crystal mode and external input clock mode. */
    ldr.w   r0, =SCU_BASE
    ldr.w   r1, =SCU_OSCHPCTRL
    ldr.w   r2, =SCU_OSCHPCTRL_MODE
    str.w   r2, [r0, r1]

setup_osc_wdg:
	/* Setup osc wdg divider. */
	ldr.w   r0, =SCU_BASE
    ldr.w   r1, =SCU_OSCHPCTRL
    ldr.w   r2, [r0, r1]
    ldr.w   r3, =SCU_OSCHPCTRL_OSCVAL
    orr.w   r2, r3
    str.w   r2, [r0, r1]

pll_ext_osc_select:
    /* Select external OSC as PLL input. */
    ldr.w   r0, =SCU_BASE
    ldr.w   r1, =SCU_PLLCON2
    ldr.w   r2, [r0, r1]
    ldr.w   r3, =CRYSTAL_ENABLE_MOSC
    and.w   r2, r3
    str.w   r2, [r0, r1]

restart_osc_wdg:
    /* Restart osc watchdog. */
    ldr.w   r0, =SCU_BASE
	ldr.w   r1, =SCU_PLLCON0
	ldr.w   r2, [r0, r1]
	and.w   r2, #(~SCU_PLLCON0_OSCRES)
	str.w   r2, [r0, r1]

wait_select_osc:
    /* Wait select external OSC as PLL input.*/
    ldr.w   r0, =SCU_BASE
    ldr.w   r1, =SCU_PLLSTAT
    ldr.w   r2, [r0, r1]
    tst.w   r2, #(SCU_PLLSTAT_PLLSP | SCU_PLLSTAT_PLLHV | SCU_PLLSTAT_PLLLV)
    beq.w   wait_select_osc

select_ofi_clk:
	/* Select OFI as system cloak.*/
	ldr.w   r0, =SCU_BASE
    ldr.w   r1, =SCU_SYSCLKCR
    ldr.w   r2, =0x0
    str.w   r2, [r0, r1]

pll_enter_bypass:
	/* Go to bypass PLL.*/
	ldr.w   r0, =SCU_BASE
	ldr.w   r1, =SCU_PLLCON0
	ldr.w   r2, [r0, r1]
	ldr.w   r3, =SCU_PLLCON0_VCOBYP
	orr.w   r2, r3
	str.w   r2, [r0, r1]

dis_osc_hp:
	/* Disconnect osc_hp to the PLL.*/
	ldr.w   r0, =SCU_BASE
	ldr.w   r1, =SCU_PLLCON0
	ldr.w   r2, [r0, r1]
	ldr.w   r3, =SCU_PLLCON0_FINDIS
	orr.w   r2, r3
	str.w   r2, [r0, r1]

set_pll_divider:
	/* P=1, N=79, K2=3, fpll = N/(P*K2).PLL output is 120MHz.*/
	ldr.w   r0, =SCU_BASE
	ldr.w   r1, =SCU_PLLCON1
	ldr.w   r2, =(SCU_PLLCON1_K1DIV | SCU_PLLCON1_NDIV | SCU_PLLCON1_K2DIV | SCU_PLLCON1_PDIV)
	str.w   r2, [r0, r1]

set_oscdiscdis:
	/* This bit is used to disable the control FINDIS in a
     * PLL loss-of-lock case.
     */
    ldr.w   r0, =SCU_BASE
	ldr.w   r1, =SCU_PLLCON0
	ldr.w   r2, [r0, r1]
	ldr.w   r3, =SCU_PLLCON0_OSCDISCDIS
	orr.w   r2, r3
	str.w   r2, [r0, r1]

connect_osc_hp:
	/* Connect osc_hp to PLL.*/
	ldr.w   r0, =SCU_BASE
	ldr.w   r1, =SCU_PLLCON0
	ldr.w   r2, [r0, r1]
	ldr.w   r3, =(~SCU_PLLCON0_FINDIS)
	and.w   r2, r3
	str.w   r2, [r0, r1]

pll_lock_detection:
	/* Restart PLL lock detection.*/
	ldr.w   r0, =SCU_BASE
	ldr.w   r1, =SCU_PLLCON0
	ldr.w   r2, [r0, r1]
	ldr.w   r3, =SCU_PLLCON0_RESLD
	orr.w   r2, r3
	str.w   r2, [r0, r1]

wait_pll_lock:
	/* Wait pll lock.*/
    ldr.w   r0, =SCU_BASE
    ldr.w   r1, =SCU_PLLSTAT
    ldr.w   r2, [r0, r1]
    tst.w   r2, #SCU_PLLSTAT_VCOLOCK
    beq.w   wait_pll_lock

enter_pll_normal_mode:
    /* PLL normal mode, VCO is not bypassed.
     * Connect oscillator to the VCO part.
     */
    ldr.w   r0, =SCU_BASE
    ldr.w   r1, =SCU_PLLCON0
    ldr.w   r2, [r0, r1]
    ldr.w   r3, =(~SCU_PLLCON0_VCOBYP)
    and.w   r2, r3
    str.w   r2, [r0, r1]

wait_pll_normal_mode:
    /* Wait PLL normal mode. */
    ldr.w   r0, =SCU_BASE
    ldr.w   r1, =SCU_PLLSTAT
    ldr.w   r2, [r0, r1]
    tst.w   r2, #SCU_PLLSTAT_VCOBYST
    bne.w   wait_pll_normal_mode

cpu_clock_divider:
    /* Cpu clock = system clock. */
	ldr.w   r0, =SCU_BASE
	ldr.w   r1, =SCU_CPUCLKCR
	ldr.w   r2, =SCU_CPUCLKCR_CPUDIV
	str.w   r2, [r0, r1]

pb_clock_divider:
	/* Pb clock = cpu clock. */
	ldr.w   r0, =SCU_BASE
	ldr.w   r1, =SCU_PBCLKCR
	ldr.w   r2, =SCU_PBCLKCR_PBDIV
	str.w   r2, [r0, r1]

ccu_clock_divider:
    /* Ccu clock = system clock. */
	ldr.w   r0, =SCU_BASE
	ldr.w   r1, =SCU_CPUCLKCR
	ldr.w   r2, =SCU_CCUCLKCR_CCUDIV
	str.w   r2, [r0, r1]

sys_clk_pll:
	/* Enable PLL clcok,select PLL clock. */
	ldr.w   r0, =SCU_BASE
	ldr.w   r1, =SCU_SYSCLKCR
	ldr.w   r2, =(SCU_SYSCLKCR_SYSDIV | CRYSTAL_ENABLE_PLL)
	str.w   r2, [r0, r1]

wait_clkmxstat:
	/* Wait PLL clock active.*/
	ldr.w   r0, =SCU_BASE
	ldr.w   r1, =SCU_CLKMXSTAT
	ldr.w   r2, [r0, r1]
	lsr.w   r2, #0x1
	tst.w   r2, #0x1
	beq.w   wait_clkmxstat

clr_sys_tarp:
	/* Clear request for system OSC watchdog trap
	 * and system VCO lock trap.
	 */
	 ldr.w  r0, =SCU_BASE
	 ldr.w  r1, =SCU_TRAPCLR
	 ldr.w  r2, =(SCU_TRAPCLR_SOSCWDGT | SCU_TRAPCLR_SVCOLCKT)
	 str.w  r2, [r0, r1]

watchdog_init:
    ldr.w   r0, =WDT_BASE
    ldr.w   r1, [r0, #WDT_CTR]
    ldr.w   r2, =(~0x1)
    and.w   r1, r2
    str.w   r1, [r0, #WDT_CTR]

interrupt_priority:
    ldr.w   r0, =0xE000ED20
    ldr.w   r1, =0xFFFF0000     /* set PendSV and SysTick priority to be 0xFF  */
    str.w   r1, [r0]
    ldr.w   r0, =0xE000ED1C
    ldr.w   r1, =0xCC000000     /* set SVC priority to be 0xCC  */
    str.w   r1, [r0]

setup_ram_vectors:
    ldr.w   r8, =RAM_VECTOR_TABLE_START   /* dst */
    ldr.w   r9, =__Vectors                /* src */
    ldr.w   r7, =__Vectors_End
    sub.w   r7, r7, r9
    lsr.w   r7, r7, #2                    /* loop number */

setup_ram_loop:
    ldmia.w r9!, {r0}                 /* read vector */
    stmia.w r8!, {r0}                 /* write vector*/
    subs.w  r7, #1
    bne.w   setup_ram_loop
    ldr.w   r9, =( NVIC_BASE | NVIC_VTOR )
    ldr.w   r0, =RAM_VECTOR_TABLE_START
    str.w   r0, [r9]                   /* set VTOR register to new address*/

/*
 * chip select and remap
 */
	ldr.w   r12, =after_remap_start
	mov     pc, r12
	/* if remap need,fill code below*/

/* -------- From here, address space after remap --------------------- */

after_remap_start:

/* Because single stack,Here not init stacks   */
init_stacks:


#if USE_TMONITOR
	ldr.w   r0, =tm_init
/*  mov.w   lr, pc  */
/*	b       r0  */
    bl      tm_init   /* attention */

#endif
#if 0
	.section .romtext.2,"ax"
	.align  0
#endif
	/* .data */
	ldr.w   r8, =__data_org   /* src address */
	ldr.w   r9, =__data_start /* dst address */
	ldr.w   r10, =__data_end
	subs.w  r10, r10, r9       /* r10 := data_size */
	beq.w   data_done          /* if __data_start == __data_end */

data_loop:
	ldmia.w r8!, {r0}
	stmia.w r9!, {r0}
	subs.w  r10, r10, #4
	bne.w   data_loop          /* if data_size != 0 */
data_done:
    b       temp_bridge

	.section .ftext.3,"ax"
	.align  0
temp_bridge:
#if USE_NOINIT
	ldr.w   r9, =__noinit_end   /* dst address */
#else
	/* .bss */
	ldr.w   r9, =__bss_start   /* dst address */
#endif
	ldr.w   r10, =__bss_end
	subs.w  r10, r10, r9       /* r10 := data_size */
	beq.w   bss_done           /* if __bss_start == __bss_end */
	mov.w   r0, #0

bss_loop:
	stmia.w r9!, {r0}
	subs.w  r10, r10, #4
	bne.w   bss_loop           /* if data_size != 0 */

bss_done:
#if USE_IMALLOC
	ldr.w   r5, =SYSTEMAREA_TOP
	cmp.w	r9, r5			/* _end or RAM_TOP */
    it      hi
	movhi.w	r5, r9			/* Either of High addresses */
	ldr.w	ip, =knl_lowmem_top
	str.w	r5, [ip]		/* knl_lowmem_top = _end or RAM_TOP */
	ldr.w   r5, =SYSTEMAREA_END
	ldr.w	ip, =knl_lowmem_limit
	str.w	r5, [ip]		/* knl_lowmem_limit = RAM_END */
kernel_start:
	ldr.w	ip, =Csym(main)
	mov.w	r0, #0
	mov 	lr, pc
#endif
	bx  	ip
l_end:
	b.w     l_end

#if USE_TMONITOR
tm_init:

	/* initialize serial I/O */
	ldr.w   r0, =sio_init
    b       sio_init
	/* return directly to the place tm_init called from sio_init */
#endif

/*
 * Exeception and Interrupt process handler define
 */
	.global default_handler
  	.type	default_handler,function
default_handler:
    b.w     default_handler

	.global svc_handler
  	.type	svc_handler,function
svc_handler:
	mrs     ip, msp
    ldr.w   ip, [ip,#24]
    ldrb.w  ip, [ip,#-2]
    push    {lr}
	ldr.w   lr, = RAM_VECTOR_TABLE_START /* exception vector table */
	add.w   ip, lr, ip, LSL #2    /* lr := lr + ip*4 = vecaddr */
	ldr.w   lr, [ip]
	bx      lr

    .end

