/*
 *------------------------------------------------------------------------------
 *    Libtk
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
 *	 File Name      : disint.S
 *	 Create Date    : 2009/12/27-2012/9/24
 *	 Author	        : WangShb
 *	 Description    : Enable/disable external interrupt.
 *-------------------------------------------------------------------------------
 */

#include <machine.h>
#include <tk/sysdef.h>

    .syntax unified

/*
 *    Function Name : disint
 *    Create Date   : 2009/12/27-2012/9/24
 *    Author        : wangshb
 *    Description   : Disable external interrupt,CPSR interrupt flag is in  disabled status.
 *    Param	        : none
 *    Return Code   : UINT: CPSR prior to change.
 */
	.text
	.balign	4
	.global	Csym(disint)
	.type	Csym(disint), %function
Csym(disint):
	mrs	    r0, cpsr
	orr	    ip, r0, #PSR_DI
	msr	    cpsr_c, ip
	bx	    lr


/*
 *    Function Name : enaint
 *    Create Date   : 2009/12/27
 *    Author        : wangshb
 *    Description   : Enable external interrupt (restore to original state),
 *                    Updates CPSR interrupt disabled flag with the intsts interrupt flag.
 *    Param	        : UINT intsts: CPSR remains unchanged apart from the interrupt disabled flag.
 *    Return Code   : UINT: CPSR prior to change.
 */
	.text
	.balign	4
	.global	Csym(enaint)
	.type	Csym(enaint), %function
Csym(enaint):
	and	    r3, r0, #PSR_DI
	mrs	    r0, cpsr
	bic	    r2, r0, #PSR_DI
	orr	    r2, r2, r3
	msr	    cpsr_c, r2
	bx	    lr

	.end
