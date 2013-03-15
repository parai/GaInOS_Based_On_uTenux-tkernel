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
 *	 File Name      : cpu_status.h
 *	 Create Date    : 2009/12/27-2012/11/25
 *	 Author	        : WangShb
 *	 Description    : CPU-Dependent Definition.
 *-------------------------------------------------------------------------------
 */

#ifndef _CPU_STATUS_
#define _CPU_STATUS_

#include <tk/syslib.h>
#include <tk/sysdef.h>
#include "cpu_insn.h"

/*
 * Start/End critical section
 */
#define BEGIN_CRITICAL_SECTION	{ UINT _primask_ = disint();
#define END_CRITICAL_SECTION	if ( !isDI(_primask_)			\
				  && knl_ctxtsk != knl_schedtsk		        	\
				  && !knl_isTaskIndependent()	            	\
				  && !knl_dispatch_disabled ) {		            \
					knl_dispatch();		                    	\
				}				                            	\
				enaint(_primask_); }

/*
 * Start/End interrupt disable section
 */
#define BEGIN_DISABLE_INTERRUPT	{ UINT _primask_ = disint();
#define END_DISABLE_INTERRUPT	enaint(_primask_); }


/*
 * Interrupt enable/disable
 */
#define ENABLE_INTERRUPT	{ enaint(0); }
#define DISABLE_INTERRUPT	{ disint(); }

/*
 * Enable interrupt nesting
 *	Enable the interrupt that has a higher priority than 'level.'
 */
#define ENABLE_INTERRUPT_UPTO(level)	{ enaint(0); }

/*
 * Move to/Restore task independent part
 */
#define ENTER_TASK_INDEPENDENT	{ knl_EnterTaskIndependent(); }
#define LEAVE_TASK_INDEPENDENT	{ knl_LeaveTaskIndependent(); }

/* ----------------------------------------------------------------------- */
/*
 *	Check system state
 */

/*
 * When a system call is called from the task independent part, TRUE
 */
#define in_indp()	( knl_isTaskIndependent() || knl_ctxtsk == NULL )

/*
 * When a system call is called during dispatch disable, TRUE
 * Also include the task independent part as during dispatch disable.
 */
#define in_ddsp()	( knl_dispatch_disabled	\
			|| in_indp()		\
			|| isDI(knl_getPRIMASK()) )

/*
 * When a system call is called during CPU lock (interrupt disable), TRUE
 * Also include the task independent part as during CPU lock.
 */
#define in_loc()	( isDI(knl_getPRIMASK())		\
			|| in_indp() )

/*
 * When a system call is called during executing the quasi task part, TRUE
 * Valid only when in_indp() == FALSE because it is not discriminated from
 * the task independent part.
 */
#define in_qtsk()	( knl_ctxtsk->sysmode > knl_ctxtsk->isysmode )

/* ----------------------------------------------------------------------- */
/*
 *	Task dispatcher startup routine
 */

/*
 * Request for task dispatcher startup
 *	Do nothing at this point because there is no delayed
 *	interrupt function in ARM.
 *	Perform dispatcher startup with END_CRITICAL_SECTION.
 */
#define knl_dispatch_request()	/* */

/*
 * Throw away the current task context.
 * and forcibly dispatch to the task that should be performed next.
 *	Use at system startup and 'tk_ext_tsk, tk_exd_tsk.'
 */
Inline void knl_force_dispatch( void )
{
IMPORT	void	knl_dispatch_to_schedtsk();

	Asm("bx %0":: "r"(&knl_dispatch_to_schedtsk));
}

/*
 * Start task dispatcher
 */
Inline void knl_dispatch( void )
{
    UW pendsvset;

    pendsvset=in_w(NVIC_BASE | NVIC_ICSR) | NVIC_ICSR_PENDSVSET;
	out_w(NVIC_BASE | NVIC_ICSR, pendsvset);
}

/* ----------------------------------------------------------------------- */

/*
 * Task context block
 */
typedef struct {
	VP	ssp;		/* System stack pointer */
} CTXB;



#endif /* _CPU_STATUS_ */
