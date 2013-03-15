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
 *    CPU:        ARM7&9
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : cpu_insn.h
 *	 Create Date    : 2009/7/27-2012/921
 *	 Author	        : WangShb
 *	 Description    : Cpu Dependent Operation.
 *-------------------------------------------------------------------------------
 */

#ifndef _CPU_INSN_
#define _CPU_INSN_

#include <sys/sysinfo.h>

/* ------------------------------------------------------------------------ */
/*
 *	Control register operation
 */

/*
 * Get CPSR
 */
Inline UINT knl_getCPSR( void )
{
	UINT	cpsr;
	Asm("mrs %0, cpsr": "=r"(cpsr));
	return cpsr;
}

/* ------------------------------------------------------------------------ */
/*
 *	EIT-related
 */


/*
 * Set interrupt handler
 */
Inline void knl_define_inthdr( INT vecno, FP inthdr )
{
IMPORT FP knl_irq_handler;

	knl_intvec[vecno] = inthdr;
	if (vecno < 32) {
		out_w((AIC_BASE | AIC_SVR0) + vecno*4, (UW)&knl_irq_handler);
	}
}

/*
 * If it is the task-independent part, TRUE
 */
Inline BOOL knl_isTaskIndependent( void )
{
	return ( knl_taskindp > 0 )? TRUE: FALSE;
}

/*
 * Move to/Restore task independent part
 */
Inline void knl_EnterTaskIndependent( void )
{
	knl_taskindp++;
}
Inline void knl_LeaveTaskIndependent( void )
{
	knl_taskindp--;
}

/* ------------------------------------------------------------------------ */

#endif /* _CPU_INSN_ */
