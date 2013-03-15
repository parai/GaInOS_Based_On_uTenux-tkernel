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
 *	 File Name      : cpu_task.h
 *	 Create Date    : 2009/7/27-2012/11/19
 *	 Author	        : WangShb
 *	 Description    : CPU-Dependent Task Start Processing.
 *-------------------------------------------------------------------------------
 */

#ifndef _CPU_TASK_
#define _CPU_TASK_

#include "cpu_insn.h"

/*
 * System stack configuration at task startup
 */
typedef struct {
        VW      r4;           /* R4        */
        VW      r5;           /* R5        */
        VW      r6;           /* R6        */
        VW      r7;           /* R7        */
        VW      r8;           /* R8        */
        VW      r9;           /* R9        */
        VW      r10;          /* R10       */
        VW      r11;          /* R11       */
        UW      taskmode;     /* used for saving knl_taskmode */
        VW      r0;           /* R0        */
        VW      r1;           /* R1        */
        VW      r2;           /* R2        */
        VW      r3;           /* R3        */
        UW      r12;          /* R12       */
        VP      lr;           /* LR        */
        VP      pc;           /* PC        */
        VW      xpsr;         /* PSR       */
} SStackFrame;

/*
 * Size of system stack area destroyed by 'make_dormant()'
 * In other words, the size of area required to write by 'setup_context().'
 */
#define DORMANT_STACK_SIZE	( sizeof(VW) * 9 )	/* To 'taskmode' position */


/*
 * Create stack frame for task startup
 *	Call from 'make_dormant()'
 */
Inline void knl_setup_context( TCB *tcb )
{
    SStackFrame     *ssp;
    UW              pc, xpsr;

    ssp = tcb->isstack;
    ssp--;

	pc = (UW)tcb->task;
	xpsr = PSR_T;                   /* Thumb mode */

    /* CPU context initialization */
    ssp->taskmode  = 0;             /* Initial taskmode */
    ssp->xpsr = xpsr;               /* Initial SR */
    ssp->pc = (VP)pc;               /* Task startup address */
    tcb->tskctxb.ssp = ssp;         /* System stack */
}

/*
 * Set task startup code
 *	Called by 'tk_sta_tsk()' processing.
 */
Inline void knl_setup_stacd( TCB *tcb, INT stacd )
{
	SStackFrame	*ssp = tcb->tskctxb.ssp;

	ssp->r0 = stacd;
	ssp->r1 = (VW)tcb->exinf;
}

/*
 * Delete task contexts
 */
Inline void knl_cleanup_context( TCB *tcb )
{
}

#endif /* _CPU_TASK_ */
