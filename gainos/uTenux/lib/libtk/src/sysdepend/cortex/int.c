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
 *	 File Name      : int.c
 *	 Create Date    : 2009/12/27-2013/1/5
 *	 Author	        : WangShb
 *	 Description    : Nested Vectored Interrupt controller.
 *-------------------------------------------------------------------------------
 */

#include <basic.h>
#include <tk/syslib.h>
#include <tk/sysdef.h>

/*
 *    Function Name : EnableInt
 *    Create Date   : 2009/12/27-2013/1/5
 *    Author        : wangshb
 *    Description   : Enables the interrupt specified in intvec.
 *    Param	        : UINT dintno: from 0 to 255
 *    Return Code   : none
 */
EXPORT void EnableInt( UINT dintno )
{
	UINT	imask;

	DI(imask);

	*( (_UW*)(( NVIC_BASE | NVIC_ISER ) + (dintno >>0x05U) ) )= (0x01U << (dintno & 0x1F) );

	EI(imask);
}


/*
 *    Function Name : DisableInt
 *    Create Date   : 2009/12/27-2013/1/5
 *    Author        : wangshb
 *    Description   : Disables the interrupt specified in intvec.
 *    Param	        : UINT dintno: from 0 to 255
 *    Return Code   : none
 */
EXPORT void DisableInt( UINT dintno )
{
	UINT	imask;

	DI(imask);

	*( (_UW*)(( NVIC_BASE | NVIC_ICER) + (dintno >>0x05U ) ) )= (0x01U << (dintno & 0x1F) );

	EI(imask);
}


/*
 *    Function Name : ClearInt
 *    Create Date   : 2009/12/27-2013/1/5
 *    Author        : wangshb
 *    Description   : Clears the intvec interrupt request.
 *    Param	        : UINT dintno: from 0 to 255
 *    Return Code   : none
 */
EXPORT void ClearInt( UINT dintno )
{
	*( (_UW*)(( NVIC_BASE | NVIC_ICPR) + (dintno >>0x05U ) ) )= (0x01U << (dintno & 0x1F) );
}


/*
 *    Function Name : CheckInt
 *    Create Date   : 2009/12/27-2013/1/5
 *    Author        : wangshb
 *    Description   : Checks for intvec interrupt  requests.
 *                    If an interrupt request is found, returns TRUE (other than 0).
 *    Param	        : UINT dintno: from 0 to 255
 *    Return Code   : none
 */
EXPORT BOOL CheckInt( UINT dintno )
{
	return (BOOL)( ( *((_UW*)((NVIC_BASE | NVIC_ISPR) + (dintno >>0x05U ) ))
                    & (0x01U << (dintno & 0x1F)) ) != 0 );
}


/*
 *    Function Name : EndOfInt
 *    Create Date   : 2009/12/27-2013/1/5
 *    Author        : wangshb
 *    Description   : Notify end of interrupt
 *    Param	        : UINT dintno: from 0 to 255
 *    Return Code   : none
 */
EXPORT void EndOfInt( UINT dintno )
{
}


