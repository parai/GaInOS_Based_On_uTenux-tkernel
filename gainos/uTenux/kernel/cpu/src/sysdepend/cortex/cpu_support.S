/*
 *------------------------------------------------------------------------------
 *    Cpu
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
 *    CPU:        CORTEX M3
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : cpu_support.S
 *	 Create Date    : 2009/12/27-2013/1/10
 *	 Author	        : WangShb-wangshb
 *	 Description    : CPU-Dependent dispatcher Operation.
 *-------------------------------------------------------------------------------
 */

#include <machine.h>
#include <tk/errno.h>
#include <tk/sysdef.h>
#include <tk/asm.h>
#include <sys/sysinfo.h>

#include "config.h"
#include "utk_config.h"
#if USE_TRAP | (USE_DBGSPT & USE_HOOK_TRACE)
#include "isysconf.h"
#endif
#include "tkdev_conf.h"
#include "offset.h"

/*
 *    Function Name : knl_dispatch_to_schedtsk,knl_dispatch_entry,_ret_int_dispatch
 *    Create Date   : 2009/12/27-2012/11/22
 *    Author        : wangshb
 *    Description   : Dispatcher,save contexts 'ssp' to TCB.include three parts.
 *                    1.dispatch_to_schedtsk:
 *                         Throw away the current contexts and forcibly dispatch to
 *                         'schedtsk.'
 *                         Called directly by jump (bx) but do not return.
 *                         Called on the undefined stack state (undefined 'ssp').
 *                         Called on the interrupt disable state.
 *                    2.dispatch_entry:
 *                         Normal dispatch processing.
 *                         Called by PendSV exception.
 *                    3._ret_int_dispatch:
 *                         Called when dispatch is required by 'tk_ret_int().'
 *    Param	        : none
 *    Return Code   : none
 */
    .text
    .syntax unified
	.balign	4
	.global	Csym(knl_dispatch_to_schedtsk)
	.type	Csym(knl_dispatch_to_schedtsk), function
Csym(knl_dispatch_to_schedtsk):
	/* Interrupt is disabled,during SVC mode */
	ldr.w	sp, =(Csym(knl_tmp_stack) + TMP_STACK_SZ)	/* Set temporal stack */

	ldr.w	r12, =Csym(knl_dispatch_disabled)
	ldr.w	r0, =1
	str.w	r0, [r12]			        /* Dispatch disable */

	ldr.w	r4, =Csym(knl_ctxtsk)		/* R4 = &ctxtsk */
	ldr.w	r0, =0
#if USE_DBGSPT
	ldr.w	r8, [r4]
#endif
	str.w	r0, [r4]			        /* ctxtsk = NULL */
    cpsie   i                           /* Interrupt enable */
	b.w	l_dispatch0

	.global	Csym(knl_dispatch_entry)
	.type	Csym(knl_dispatch_entry), function
Csym(knl_dispatch_entry):
_ret_int_dispatch:
	/* Interrupt is disabled,during SVC mode */
	ldr.w	r12, =Csym(knl_dispatch_disabled)
	ldr.w	r0, =1
	str.w	r0, [r12]	  		        /* Dispatch disable */
    cpsie   i                           /* Interrupt enable */
	ldr.w	r12, =Csym(knl_taskmode)
	ldr.w	r0, [r12]
    push    {r0}
    push    {r4-r11}
	ldr.w	r4, =Csym(knl_ctxtsk)       /* R4 = &ctxtsk */
	ldr.w	r0, =0
	ldr.w	r8, [r4]                    /* R8 = ctxtsk */
	str.w	sp, [r8, #TCB_tskctxb + CTXB_ssp] /* Save 'ssp' to TCB */
	str.w	r0, [r4]			        /* ctxtsk = NULL */

l_dispatch0:
	/* During interrupt enable */
#if USE_DBGSPT & USE_HOOK_TRACE
	ldr.w	r12, =knl_dsp_hook_stop_jmp	/* Hook processing */
	ldr.w	pc, [r12]
knl_dsp_hook_stop_ret:
#endif
	ldr.w	r5, =Csym(knl_schedtsk)		/* R5 = &schedtsk */
	ldr.w	r6, =Csym(knl_lowpow_discnt)/* R6 = &lowpow_discnt */

l_dispatch1:                            /* Judge if switch to 'schedtsk' or 'low_pow' */
    cpsid   i
	ldr.w	r8, [r5]			        /* R8 = schedtsk */
	cmp.w	r8, #0				        /* Is there 'schedtsk'? */
	bne.w	l_dispatch2

	/* Because there is no task that should be executed, move to the power-saving mode */
	ldr.w	r12, [r6]
	cmp.w	r12, #0                      /* Is 'low_pow' disabled? */
	it      eq
	bleq.w	Csym(knl_low_pow)		    /* call low_pow() */
    cpsie   i                           /* Interrupt enable */
	b.w	    l_dispatch1

l_dispatch2:					        /* Switch to 'schedtsk' */
	/* During interrupt disable */
	str.w	r8, [r4]			        /* ctxtsk = schedtsk */
	ldr.w	sp, [r8, #TCB_tskctxb + CTXB_ssp] /* Restore 'ssp' from TCB */

#if USE_DBGSPT & USE_HOOK_TRACE
	ldr.w	r12, =knl_dsp_hook_exec_jmp	/* Hook processing */
	ldr.w	pc, [r12]
knl_dsp_hook_exec_ret:
#endif

	ldr.w	r12, =Csym(knl_dispatch_disabled)
	ldr.w	r0, =0
	str.w	r0, [r12]			        /* Dispatch enable */
    mrs.w   r12,psr
    ldr.w   r0,=#0x1FF
    and.w   r12,r12,r0
    cmp.w   r12,#0
  	beq.w   knl_dsp_no_exception
  	bgt.w   knl_dsp_in_exception

knl_dsp_no_exception:
    pop     {r4-r11}
    ldr.w	r12, =Csym(knl_taskmode)
    pop     {r0}
	str.w	r0, [r12]
    ldr.w   r0, [sp, #24]               /* load stack's pc to r0 */
    orr.w   r0, r0, #1
    str.w   r0, [sp, #24]
	pop     {r0-r3}
	pop     {r12}
	pop     {lr}
	add.w   sp, sp, #8
    cpsie   i                           /* enbale interrupt just before schedule to next task */
	ldr.w   pc, [sp, #-8]

knl_dsp_in_exception:
    pop     {r4-r11}
    ldr.w	r12, =Csym(knl_taskmode)
    pop     {r0}
	str.w	r0, [r12]
    cpsie   i                           /* enbale interrupt just before schedule to next task */
	bx      lr                          /* lr is EXE_RETURN */

#if USE_DBGSPT & USE_HOOK_TRACE
/*
 *    Function Name : knl_dsp_hook_exec,knl_dsp_hook_stop
 *    Create Date   : 2009/12/27-2012/10/07
 *    Author        : wangshb
 *    Description   : Task dispatcher high language hook routine entry
 *	                     void stop( ID tskid, INT lsid, UINT tskstat )
 *	                     void exec( ID tskid, INT lsid )
 *    Param	        : none
 *    Return Code   : none
 */
	.text
    .syntax unified
	.balign	4
    .type	knl_dsp_hook_exec, function
    .type	knl_dsp_hook_stop, function
knl_dsp_hook_stop:
	cmp.w	r8, #0		                    /* r8 = ctxtsk */
	beq.w	l_notask

	ldrb.w	r2, [r8, #TCB_state]			/* tskstat */
	mov.w	r2, r2, lsl #1
	ldr.w	r0, [r8, #TCB_tskid]			/* tskid */

	ldr.w	ip, =Csym(knl_hook_stopfn)
	ldr.w	ip, [ip]
	mov 	lr, pc
	bx  	ip			    /* call stop(tskid, lsid, tskstat) */

l_notask:
	b.w	    knl_dsp_hook_stop_ret

knl_dsp_hook_exec:
					        /* r8 = ctxtsk */
	ldr.w	r0, [r8, #TCB_tskid]			/* tskid */

	ldr.w	ip, =Csym(knl_hook_execfn)
	ldr.w	ip, [ip]
	mov 	lr, pc
	bx  	ip			    /* call exec(tskid, lsid) */

	b.w	    knl_dsp_hook_exec_ret

/*
 *    Function Name : Csym(knl_hook_dsp),Csym(knl_unhook_dsp)
 *    Create Date   : 2009/12/27-2012/10/07
 *    Author        : wangshb
 *    Description   : Set/Free task dispatcher hook routine
 *                    called by td_hok_dsp_impl
 *    Param	        : none
 *    Return Code   : none
 */
	.text
    .syntax unified
	.balign	4
	.global	Csym(knl_hook_dsp)
	.type	Csym(knl_hook_dsp), function
Csym(knl_hook_dsp):
	ldr.w	r0, =knl_dsp_hook_exec_jmp
	ldr.w	r1, =knl_dsp_hook_stop_jmp
	ldr.w	r2, =knl_dsp_hook_exec
	ldr.w	r3, =knl_dsp_hook_stop
	str.w	r2, [r0]
	str.w	r3, [r1]
	bx  	lr

	.global	Csym(knl_unhook_dsp)
	.type	Csym(knl_unhook_dsp), function
Csym(knl_unhook_dsp):
	ldr.w	r0, =knl_dsp_hook_exec_jmp
	ldr.w	r1, =knl_dsp_hook_stop_jmp
	ldr.w	r2, =knl_dsp_hook_exec_ret
	ldr.w	r3, =knl_dsp_hook_stop_ret
	str.w	r2, [r0]
	str.w	r3, [r1]
	bx  	lr

	.data
	.balign	4
	.type	knl_dsp_hook_exec_ret, function
	.type	knl_dsp_hook_stop_ret, function
knl_dsp_hook_exec_jmp:
	.long	knl_dsp_hook_exec_ret
knl_dsp_hook_stop_jmp:
	.long	knl_dsp_hook_stop_ret

#endif /* USE_DBGSPT & USE_HOOK_TRACE */

/* ------------------------------------------------------------------------ */

#if USE_HLL_INTHDR
/*
 *    Function Name : Csym(knl_inthdr_startup),Csym(knl_exchdr_startup)
 *    Create Date   : 2009/12/27-2013/1/10
 *    Author        : wangshb
 *    Description   : High level programming language routine for interrupt handler
 *                    prepare to call high language interrupt handler,as below:
 *                      void intdhr( UINT dintno, VP ctxptr );
 *    Param	        : none
 *    Return Code   : none
 */
    .text
    .syntax unified
    .balign 4
    .global Csym(knl_inthdr_startup)
    .global Csym(knl_exchdr_startup)
    .type	Csym(knl_inthdr_startup), function
    .type	Csym(knl_exchdr_startup), function
Csym(knl_exchdr_startup):
Csym(knl_inthdr_startup):
    cpsid   i
    push    {lr}

    mrs     r0, ipsr            /* r0 = dintno */
    mov     r1, sp              /* r1 = sp */

    ldr.w   r12, =Csym(knl_taskindp)     /* Task independent part */
    ldr.w   lr, [r12]
    add.w   lr, lr, #1
    str.w   lr, [r12]

#if USE_DBGSPT & USE_HOOK_TRACE
	ldr.w   r12, =knl_int_hook_enter_jmp
	ldr.w   pc, [r12]
knl_int_hook_enter_ret:
#endif

    ldr.w   r12, =Csym(knl_hll_inthdr)
    lsl     r3, r0, #2                   /* r3 is offset */
    ldr.w   r12, [r12, r3]
    blx     r12                          /* call hll_inthdr[n](dintno) */

#if USE_DBGSPT & USE_HOOK_TRACE
	ldr.w   r12, =knl_int_hook_leave_jmp
	ldr.w   pc, [r12]
knl_int_hook_leave_ret:
#endif

    ldr.w   r12, =Csym(knl_taskindp)
    ldr.w   lr, [r12]
    sub.w   lr, lr, #1
    str.w   lr, [r12]

    cpsie   i
    pop    {lr}
    b      tk_ret_int_impl

#if USE_DBGSPT & USE_HOOK_TRACE
/*
 *    Function Name : knl_int_hook_enter,knl_int_hook_leave
 *    Create Date   : 2009/12/27-2012/10/11
 *    Author        : wangshb
 *    Description   : Interrupt handler hook routine call
 *    Param	        : none
 *    Return Code   : none
 */
	.text
	.balign	4
    .type	knl_int_hook_enter, function
    .type	knl_int_hook_leave, function
knl_int_hook_enter:
	push  	{r0, r1}			/* Register save */
	push  	{r3}

	ldr.w	ip, =Csym(knl_hook_ienterfn)
	ldr.w	ip, [ip]
	mov 	lr, pc
	bx  	ip					/* call enter(dintno, sp) */

	pop  	{r3}				/* Register restore */
	ldmfd.w	sp, {r0, r1}		/* Leave 'dintno,' 'sp' on stack */
	b.w 	knl_int_hook_enter_ret

knl_int_hook_leave:
	pop  	{r0, r1}			/* Restore 'dintno,' 'sp' */

	ldr.w	ip, =Csym(knl_hook_ileavefn)
	ldr.w	ip, [ip]
	mov 	lr, pc
	bx  	ip			        /* call leave(dintno, info) */

	b.w 	knl_int_hook_leave_ret

/*
 *    Function Name : Csym(knl_hook_int),Csym(knl_unhook_int)
 *    Create Date   : 2009/12/27-2012/10/11
 *    Author        : wangshb
 *    Description   : Set/Free interrupt handler hook routine
 *    Param	        : none
 *    Return Code   : none
 */
	.text
    .syntax unified
	.balign	4
	.global	Csym(knl_hook_int)
	.type	Csym(knl_hook_int), function
Csym(knl_hook_int):
	ldr.w	r0, =knl_int_hook_enter_jmp
	ldr.w	r1, =knl_int_hook_leave_jmp
	ldr.w	r2, =knl_int_hook_enter
	ldr.w	r3, =knl_int_hook_leave
	str.w	r2, [r0]
	str.w	r3, [r1]
	bx  	lr

	.global	Csym(knl_unhook_int)
	.type	Csym(knl_unhook_int), function
Csym(knl_unhook_int):
	ldr.w	r0, =knl_int_hook_enter_jmp
	ldr.w	r1, =knl_int_hook_leave_jmp
	ldr.w	r2, =knl_int_hook_enter_ret
	ldr.w	r3, =knl_int_hook_leave_ret
	str.w	r2, [r0]
	str.w	r3, [r1]
	bx  	lr

	.data
	.balign	4
	.type	knl_int_hook_enter_ret, function
	.type	knl_int_hook_leave_ret, function
knl_int_hook_enter_jmp:
	.long	knl_int_hook_enter_ret
knl_int_hook_leave_jmp:
	.long	knl_int_hook_leave_ret

#endif /* USE_DBGSPT & USE_HOOK_TRACE */
#endif /* USE_HLL_INTHDR */

/*
 *    Function Name : Csym(tk_ret_int_impl)
 *    Create Date   : 2009/12/27-2012/11/27
 *    Author        : wangshb
 *    Description   : System call entry
 *                    called by svc SWI_RET
 *    Param	        : none
 *    Return Code   : none
 */
    .text
    .syntax unified
	.balign	4
	.global	Csym(tk_ret_int_impl)
	.type	Csym(tk_ret_int_impl), function
Csym(tk_ret_int_impl):
    cpsid   i

	ldr.w	r0, =Csym(knl_taskindp)	/* Is it a nesting interrupt? */
	ldr.w	r0, [r0]
	cmp.w	r0, #0
	bne.w	l_nodispatch

	ldr.w	r0, =Csym(knl_dispatch_disabled)	/* Is it during dispatch disable? */
	ldr.w	r0, [r0]
	cmp.w	r0, #0
	bne.w	l_nodispatch

    ldr.w	r0, =Csym(knl_ctxtsk)	/* Is dispatch required? */
    ldr.w	r1, =Csym(knl_schedtsk)
	ldr.w	r0, [r0]
	ldr.w	r1, [r1]
	cmp.w	r0, r1
	bne.w	_ret_int_dispatch	    /* To dispatch processing */

l_nodispatch:
    cpsie   i
	bx      lr

/* ------------------------------------------------------------------------ */

#if USE_TRAP | USE_DBGSPT
/*
 *    Function Name : Csym(knl_no_support)
 *    Create Date   : 2009/12/27-2012/10/07
 *    Author        : wangshb
 *    Description   : Unsupported system call
 *    Param	        : none
 *    Return Code   : none
 */
	.text
    .syntax unified
	.balign	4
	.global	Csym(knl_no_support)
    .type	Csym(knl_no_support), function
Csym(knl_no_support):
	ldr.w	r0, =E_RSFN
	str.w   r0, [sp]
	bx  	lr
#endif /* USE_TRAP | USE_DBGSPT */

/*
 * System call entry table
 */
#if USE_TRAP | (USE_DBGSPT & USE_HOOK_TRACE)
	.text
    .syntax unified
	.balign	4
_svctbl:
	.int	Csym(knl_no_support)
#define	tk_ret_int_impl	knl_no_support
#include <sys/svc/tksvctbl.h>
#undef	tk_ret_int_impl
#endif /* USE_TRAP | (USE_DBGSPT & USE_HOOK_TRACE) */

/*
 *    Function Name : Csym(knl_call_entry)
 *    Create Date   : 2009/12/27-2012/10/07
 *    Author        : wangshb
 *    Description   : System call entry,Do not need to save the temporary register.
 *                    called by svc SWI_SVC
 *                    called by tk_*_* function entry
 *    Param	        : none
 *    Return Code   : none
 */
	.text
    .syntax unified
	.balign	4
	.global	Csym(knl_call_entry)
    .type	Csym(knl_call_entry), function
Csym(knl_call_entry):
#if USE_TRAP
	/* During interrupt,not need any process*/
#else
	cmp.w	ip, #0						/*	< 0: System call */
										/*	>= 0: Extended SVC */
	bge.w	l_no_more_stack				/* don't create stack */
	push    {ip}                        /* add stack like SVC entry */
	push    {ip}
	push    {ip}
	push    {ip}
    push    {r0,r1,r2,r3}
    push    {lr}
l_no_more_stack:
#endif
	push  	{r10, fp}					/* Save register for work */
	add.w	fp, sp, #2*4

	ldr.w	ip, =Csym(knl_taskmode)		/* Task mode flag update */
	ldr.w	r10, [ip]
	push  	{r10}						/* taskmode save */
	mov.w	lr, r10, lsl #16
	str.w	lr, [ip]

#if USE_DBGSPT & USE_HOOK_TRACE
	ldr.w	ip, =knl_svc_hook_enter_jmp /* Hook processing */
	ldr.w	pc, [ip]
knl_svc_hook_enter_ret:
#endif
    ldr.w	lr, [fp, #20]	            /* ip = Function code(in stack)   lr =Function code(now) */

	cmp.w	lr, #0			            /*	< 0: System call */
	bge.w	l_esvc_function		        /*	>= 0: Extended SVC */

#if USE_TRAP | (USE_DBGSPT & USE_HOOK_TRACE)
	/* micro T-Kernel System Call */
	mov.w	r10, lr, asr #16	        /* r10 = Function number */
	ldr.w	ip, =N_TFN + 0xffff8000
	cmp.w	r10, ip
	bgt.w	l_illegal_svc

	mov.w	lr, lr, lsr #8
	and.w	lr, lr, #0xff		        /* lr = Number of arguments */
	cmp.w	lr, #5
	bne.w	l_nocopy
	ldr.w	ip, [r4]		            /* Copy fifth argument */
	push  	{ip}
l_nocopy:

	ldr.w	ip, =_svctbl - (0xffff8000 << 2)
    add.w   lr, pc, #5
	ldr.w	pc, [ip, r10, lsl #2]	    /* micro T-Kernel system call */
#else
	b.w	    l_illegal_svc
#endif
	sub.w   fp, fp, #3*4
    mov.w	sp, fp
l_retsvc:
#if USE_DBGSPT & USE_HOOK_TRACE
	ldr.w	ip, =knl_svc_hook_leave_jmp /* Hook processing */
	ldr.w	pc, [ip]
knl_svc_hook_leave_ret:
#endif
	pop  	{r1, r10, fp}				/* Restore register for work */
	ldr.w	ip, =Csym(knl_taskmode)		/* Task mode restore */
	str.w	r1, [ip]
    mrs.w   ip, psr
    mov.w   lr, #0xFF
    orr.w   lr, lr, #0x100
    and.w   ip, ip, lr
    cmp.w   ip, #0
  	beq.w   knl_svc_no_exception
  	bgt.w   knl_svc_in_exception

knl_svc_no_exception:
    pop     {lr}
    pop     {r4}
    pop     {r1,r2,r3}
	pop     {ip}
	pop     {ip}
	pop     {ip}
	pop     {ip}
    bx      lr
knl_svc_in_exception:
    pop     {lr}
    str.w   r0, [sp]   /* return vale restore */
    bx      lr         /* lr is EXE_RETURN*/
l_illegal_svc:
	ldr.w	r0, =E_RSFN
	b.w	    l_retsvc

l_esvc_function:
	ldr.w	r0, =E_SYS
	b.w 	l_retsvc


#if USE_DBGSPT & USE_HOOK_TRACE
/*
 *    Function Name : knl_svc_hook_enter,knl_svc_hook_leave
 *    Create Date   : 2009/12/27-2012/10/07
 *    Author        : wangshb
 *    Description   : System call/Extended SVC hook routine call
 *	                     VP enter( FN fncd, TD_CALINF *calinf, ... )
 *	                     void leave( FN fncd, INT ret, VP exinf )
 *    Param	        : none
 *    Return Code   : none
 */
	.text
    .syntax unified
	.balign	4
    .type	knl_svc_hook_enter, function
    .type	knl_svc_hook_leave, function
knl_svc_hook_enter:
	push  	{r0-r3, r8-r9}		/* Save argument and register for work */
	mov.w	r8, sp				/* r8 = Keep stack position */

	ldr.w	ip, [fp, #-4]		/* Flame pointer when calling */
	push  	{fp, ip}			/* Create TD_CALINF */
	mov.w	r9, sp				/* r9 = &TD_CALINF */

	ldr.w	lr, [fp, #4]		/* lr = Function code */
	cmp.w	lr, #0				/*	< 0: System call */
	bge.w	l_hooksvc			/*	>= 0: Extended SVC */

	mov.w	lr, lr, lsr #8
	and.w	lr, lr, #0xff		/* Number of arguments */

	cmp.w	lr, #5
    itt     ge
	ldrge  	ip, [r4]
	stmgefd sp!, {ip}		    /* Fifth argument */
	cmp.w	lr, #4
	it      ge
	stmgefd	sp!, {r3}		    /* Fourth argument */
	cmp.w	lr, #3
	it      ge
	stmgefd	sp!, {r2}		    /* Third argument */
	mov.w	r3, r1				/* Second argument */
l_hooksvc:
	mov.w	r2, r0				/* First argument */
	mov.w	r1, r9				/* calinf */
	ldr.w	r0, [fp, #4]		/* fncd */
	ldr.w	ip, =Csym(knl_hook_enterfn)
	ldr.w	ip, [ip]
	mov 	lr, pc
	bx  	ip					/* exinf = enter(fncd, ...) */
	mov.w	r9, r0				/* Temporarily save 'exinf' */

	mov.w	sp, r8				/* Return stack position */
	pop  	{r0-r3, r8}			/* Restore argument and register for work */
    mov.w   ip, r9              /* ip as temp register */
	pop     {r9}                /* 'r9' restore */
	push    {ip}                /* 'exinf' save */
	b.w		knl_svc_hook_enter_ret

knl_svc_hook_leave:
	mov.w	r1, r0			    /* r1 = ret */

	mov.w	lr, #0
	ldr.w	r0, [fp, #4]		/* r0 = Function code */
	cmp.w	r0, #0			    /*	  < 0: System call */
	bge.w	l_hooksvc2		    /*    >= 0: Extended SVC */

	mov.w	lr, r0, lsr #8
	and.w	lr, lr, #0xff		/* Number of arguments */
	subs.w	lr, lr, #4
	it      lt
	movlt	lr, #0
l_hooksvc2:

	add.w	lr, lr, #3		    /* Whether 'hook_enter' is executed */
	sub.w	ip, sp, fp		    /* Check by stack usage */
	sub.w	r11, #4*4
    mov     sp, r11             /* Location in which 'sp = exinf' is saved */
	cmp.w	lr, ip, lsr #2		/* If 'hook_enter' is executed, */
	ite     ne
	ldrne	r2, [sp]		    /* Get 'exinf' from stack */
	ldreq	r2, =0			    /* If 'exinf' is not saved, 0 */

	str.w	r9, [sp]		    /* r9 save */
	mov.w	r9, r1			    /* Save 'ret' in 'r9' */

	ldr.w	ip, =Csym(knl_hook_leavefn)
	ldr.w	ip, [ip]
	mov 	lr, pc
	bx  	ip				    /* call leave(fncd, ret, exinf) */

	mov.w	r0, r9			    /* r0 = ret restore */
	pop  	{r9}			    /* r9 restore */
	b.w  	knl_svc_hook_leave_ret

/*
 *    Function Name : Csym(knl_hook_svc),Csym(knl_unhook_svc)
 *    Create Date   : 2009/12/27-2012/10/07
 *    Author        : wangshb
 *    Description   : Set/Free system call/extended SVC hook routine
 *                    called by td_hok_svc_impl
 *    Param	        : none
 *    Return Code   : none
 */
	.text
    .syntax unified
	.balign	4
	.global	Csym(knl_hook_svc)
    .type	Csym(knl_hook_svc), function
Csym(knl_hook_svc):
	ldr.w	r0, =knl_svc_hook_enter_jmp
	ldr.w	r1, =knl_svc_hook_leave_jmp
	ldr.w	r2, =knl_svc_hook_enter
	ldr.w	r3, =knl_svc_hook_leave
	str.w	r2, [r0]
	str.w	r3, [r1]
	bx  	lr

	.global	Csym(knl_unhook_svc)
    .type	Csym(knl_unhook_svc), function
Csym(knl_unhook_svc):
	ldr.w	r0, =knl_svc_hook_enter_jmp
	ldr.w	r1, =knl_svc_hook_leave_jmp
	ldr.w	r2, =knl_svc_hook_enter_ret
	ldr.w	r3, =knl_svc_hook_leave_ret
	str.w	r2, [r0]
	str.w	r3, [r1]
	bx  	lr

	.data
	.balign	4
	.type	knl_svc_hook_enter_ret, function
	.type	knl_svc_hook_leave_ret, function
knl_svc_hook_enter_jmp:
	.long	knl_svc_hook_enter_ret
knl_svc_hook_leave_jmp:
	.long	knl_svc_hook_leave_ret

#endif /* USE_DBGSPT & USE_HOOK_TRACE */


/* ------------------------------------------------------------------------ */

#if USE_DBGSPT & (USE_TRAP | USE_HOOK_TRACE)
/*
 * Debugger support function service call entry table
 */
	.text
	.balign	4
_tdsvctbl:
	.int	Csym(knl_no_support)
#include <sys/svc/tdsvctbl.h>

/*
 *    Function Name : Csym(knl_call_dbgspt)
 *    Create Date   : 2009/12/27-2012/10/07
 *    Author        : wangshb
 *    Description   : Debugger support function service call entry
 *                    called by svc SWI_DEBUG or
 *                    called by td_*_* function entry
 *    Param	        : none
 *    Return Code   : none
 */
	.text
    .syntax unified
	.balign	4
	.global	Csym(knl_call_dbgspt)
    .type	Csym(knl_call_dbgspt), function
Csym(knl_call_dbgspt):
#if USE_TRAP
	/* During interrupt,not need any process*/
#else
	/* push  	{psr,pc,lr,ip,r3,r2,r1,r0,lr } */
#endif
	push  	{r10, fp}		    	/* Save register for work */
	add.w	fp, sp, #2*4
	ldr.w	lr, [fp, #20]	    	/* lr = Function code */
	mov.w	r10, lr, asr #16
	ldr.w	ip, =N_TDFN + 0xffff8000
	cmp.w	r10, ip
	bgt.w	b_illegal_svc

	ldr.w	ip, =_tdsvctbl - (0xffff8000 << 2)
	add.w   lr, pc, #5
	ldr.w	pc, [ip, r10, lsl #2]	/* micro T-Kernel service call (DS) */

b_retsvc:
	pop  	{r10, fp}				/* Restore register for work */
    mrs.w   ip, psr
    mov.w   lr, #0xFF
    orr.w   lr, lr, #0x100
    and.w   ip, ip, lr
    cmp.w   ip, #0
  	beq.w   dbgspt_no_exception
  	bgt.w   dbgspt_in_exception

dbgspt_no_exception:
    pop     {lr}
    bx      lr
dbgspt_in_exception:
    pop     {lr}
    str.w   r0, [sp]               /* return vale restore */
    bx      lr                     /* lr is EXC_RETURN*/

b_illegal_svc:
	ldr.w	r0, =E_RSFN
	b.w 	b_retsvc

#endif /* USE_DBGSPT & (USE_TRAP | USE_HOOK_TRACE) */


/* ------------------------------------------------------------------------ */


/*
 *    Function Name : Csym(knl_systick_handler)
 *    Create Date   : 2009/12/27-2012/11/27
 *    Author        : wangshb
 *    Description   : Systick exception handler
 *    Param	        : none
 *    Return Code   : none
 */
	.text
    .syntax unified
	.balign	4
	.global	Csym(knl_systick_handler)
    .type	Csym(knl_systick_handler), function
Csym(knl_systick_handler):
    push    {lr}
	ldr.w	r1, =Csym(knl_taskindp)		/* Enter task independent part */
	ldr.w	r2, [r1]
	add.w	r3, r2, #1
	str.w	r3, [r1]
    push    {r1, r2}
	bl.w	Csym(knl_timer_handler)		/* call timer_handler() */

    pop     {r1,r2}
	str.w	r2, [r1]					/* Leave task independent part */
    pop     {lr}

	b	    tk_ret_int_impl

	.end
