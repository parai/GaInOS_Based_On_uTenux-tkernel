/*
 *------------------------------------------------------------------------------
 *    Cpu
 *
 *    Copyright (C) 2008-2013 by Fan Wang(parai). All rights reserved.
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
 *    CPU:        MC9S12
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *
 *	 File Name      : cpu_init.c
 *	 Create Date    : 2013/3/15-2013/3/17
 *	 Author	        : Fan Wang(parai)
 *	 Description    : CPU-Dependent Initialization/Finalization.
 *-------------------------------------------------------------------------------
 */

#include "kernel.h"
#include "task.h"
#include "cpu_insn.h"
#include "tkdev_conf.h"
#include "cpu_task.h"


/* Temporal stack used when 'dispatch_to_schedtsk' is called */
Noinit(EXPORT	UB	knl_tmp_stack[TMP_STACK_SZ]);

/*
 * CPU-dependent initialization
 */
EXPORT ER knl_cpu_initialize( void )
{
	return E_OK;
}

#if USE_CLEANUP
/*
 * CPU-dependent finalization
 */
EXPORT void knl_cpu_shutdown( void )
{
}
#endif /* USE_CLEANUP */

EXPORT UB knl_getPRIMASK ( void )
{
    asm psha; /* sava A */
	asm tpa;
    asm tab;
    asm pula;
}

EXPORT BOOL knl_isTaskIndependent( void )
{
	return ( knl_taskindp > 0 )? TRUE: FALSE;
}

EXPORT void knl_EnterTaskIndependent( void )
{
	knl_taskindp++;
}
EXPORT void knl_LeaveTaskIndependent( void )
{
	knl_taskindp--;
}

EXPORT void knl_setup_context( TCB *tcb )
{
    SStackFrame     *ssp;
    UW pc;

    ssp = tcb->isstack;
    ssp--;
    pc = (UW)tcb->task;

    /* CPU context initialization */
    ssp->ppage =(VB)pc;
    ssp->taskmode  = 0;             /* Initial taskmode */
    ssp->ccr = (0xC0);              /* CCR Register (Disable STOP instruction and XIRQ)       */
    ssp->pc = (VH)(pc>>8);          /* Task startup address */
    tcb->tskctxb.ssp = ssp;         /* System stack */
}

EXPORT void knl_setup_stacd( TCB *tcb, INT stacd )
{
	SStackFrame	*ssp = tcb->tskctxb.ssp;

	ssp->stacd = stacd;
	ssp->b = (VB)(tcb->exinf);
	ssp->a = (VB)((VH)(tcb->exinf)>>8);
}

EXPORT void knl_cleanup_context( TCB *tcb )
{
}

