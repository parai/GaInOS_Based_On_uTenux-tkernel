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
 *    CPU:        MC9S12
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *
 *	 File Name      : cpu_task.h
 *	 Create Date    : 2013/3/15-2013/3/17
 *	 Author	        : Fan Wang(parai)
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
	VW r1;      /* sp */
    VW blk;
    /*untouch R2 and R13 because of _SDA_BASE_ _SDA2_BASE_*/
    VW rl[10];  /* R3 ~ R12 */
    VW rh[17];  /* R14 ~ R31 */
    VW r0;
    VW taskmode;
    VW srr0;
    VW srr1;
    VW usprg;
    VW ctr;
    VW xer;
    VW cr;
    VW lr;
    VW spefscr;
    VW pad2;
    VW pad3;
    VW msr;
} SStackFrame;

/*
 * Size of system stack area destroyed by 'make_dormant()'
 * In other words, the size of area required to write by 'setup_context().'
 */
#define DORMANT_STACK_SIZE	( sizeof(VW) * 12 )	/* To 'taskmode' position */


/*
 * Create stack frame for task startup
 *	Call from 'make_dormant()'
 */
#define  configUSE_FPU	0
/* Definitions to set the initial MSR of each task. */
#define portCRITICAL_INTERRUPT_ENABLE	( 1UL << 17UL )
#define portEXTERNAL_INTERRUPT_ENABLE	( 1UL << 15UL )
#define portMACHINE_CHECK_ENABLE		( 1UL << 12UL )

#if configUSE_FPU == 1
	#define portAPU_PRESENT				( 1UL << 25UL )
	#define portFCM_FPU_PRESENT			( 1UL << 13UL )
#else
	#define portAPU_PRESENT				( 0UL )
	#define portFCM_FPU_PRESENT			( 0UL )
#endif

#define portINITIAL_MSR		( portCRITICAL_INTERRUPT_ENABLE | portEXTERNAL_INTERRUPT_ENABLE | \
			portMACHINE_CHECK_ENABLE | portAPU_PRESENT | portFCM_FPU_PRESENT )
extern const unsigned _SDA_BASE_;
extern const unsigned _SDA2_BASE_;	
Inline void knl_setup_context( TCB *tcb )
{
    SStackFrame     *ssp;
    UW pc;

    ssp = tcb->isstack;
    ssp--;
    pc = (UW)tcb->task;

    /* CPU context initialization */
    ssp->taskmode  = 0;             /* Initial taskmode */
    ssp->srr1 = portINITIAL_MSR;
    ssp->srr0 = pc;             /* Task startup address */
   /* 
   	 ssp->r[13-2]=(UW)&_SDA_BASE_;
   	 ssp->r[12-2]=(UW)&_SDA2_BASE_; 
   	 */
    tcb->tskctxb.ssp = ssp;         /* System stack */
}

/*
 * Set task startup code
 *	Called by 'tk_sta_tsk()' processing.
 */
Inline void knl_setup_stacd( TCB *tcb, INT stacd )
{
	SStackFrame	*ssp = tcb->tskctxb.ssp;

	ssp->rl[3-3] = stacd;
	ssp->rl[4-3] = (UW)tcb->exinf;
}

/*
 * Delete task contexts
 */
Inline void knl_cleanup_context( TCB *tcb )
{
	(void)tcb;
}

#endif /* _CPU_TASK_ */
