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
 *	 File Name      : cpu_insn.h
 *	 Create Date    : 2009/12/27-2013/1/6
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
 * Get PRIMASK
 */
Inline UINT knl_getPRIMASK ( void )
{
	UINT	primask;
	Asm("mrs.w %0, primask ": "=r"( primask));
	return primask;
}


/* ------------------------------------------------------------------------ */
/*
 *	EIT-related
 */


/*
 *    Function Name : knl_define_inthdr
 *    Create Date   : 2009/12/27-2013/1/6
 *    Author        : wangshb
 *    Description   : Set interrupt handler
 *    Param	        : UINT dintno: from 0 to 255
 *                    FP inthdr: int handler pointer
 *    Return Code   : none
 */
Inline void knl_define_inthdr( UINT dintno, FP inthdr )
{
	FP * knl_intvec;

	knl_intvec = (FP*)SYSTEMAREA_END;    /* RAM_VECTOR_TABLE_START */
	if( (dintno != EI_STACK_TOP) && (dintno != EI_RESET) && (dintno != EI_SVC)
	    && (dintno != EI_PENDSV) && (dintno != EI_SYSTICK) && (dintno < N_INTVEC)){
		knl_intvec[dintno] = inthdr;
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
