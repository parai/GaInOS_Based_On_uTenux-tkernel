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
 *    CPU:        CORTEX M3
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : disint.S
 *	 Create Date    : 2009/12/27-2012/11/25
 *	 Author	        : WangShb
 *	 Description    : Enable/disable external interrupt.
 *-------------------------------------------------------------------------------
 */

#include <machine.h>
#include <tk/sysdef.h>

/*
 *    Function Name : disint
 *    Create Date   : 2009/12/27
 *    Author        : wangshb
 *    Description   : Disable external interrupt,PRIMASK interrupt flag is in  disabled status.
 *    Param	        : none
 *    Return Code   : UINT: PRIMASK prior to change.
 */
	.text
	.syntax unified
	.global	Csym(disint)
	.type	Csym(disint),function
Csym(disint):
	mrs  	r0, primask
	ldr     r1, =PMK_D
	msr  	primask, r1
	bx   	lr


/*
 *    Function Name : enaint
 *    Create Date   : 2009/12/27
 *    Author        : wangshb
 *    Description   : Enable external interrupt (restore to original state),
 *                    Updates PRIMASK interrupt disabled flag with the intsts interrupt flag.
 *    Param	        : UINT intsts: PRIMASK remains unchanged apart from the interrupt disabled flag.
 *    Return Code   : UINT: PRIMASK prior to change.
 */
	.text
	.syntax unified
	.global	Csym(enaint)
	.type	Csym(enaint), function
Csym(enaint):
    msr     primask, r0
    bx  	lr

    .end

