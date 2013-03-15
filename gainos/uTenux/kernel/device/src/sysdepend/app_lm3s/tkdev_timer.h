/*
 *------------------------------------------------------------------------------
 *    Device
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
 *	 File Name      : tkdev_timer.h
 *	 Create Date    : 2009/12/27-2012/10/11
 *	 Author	        : WangShb-dengjk
 *	 Description    : Hardware-Dependent Timer Processing(LM3S).
 *-------------------------------------------------------------------------------
 */

#ifndef _TKDEV_TIMER_
#define _TKDEV_TIMER_

#include <tk/syslib.h>
#include <sys/sysinfo.h>
#include "tkdev_conf.h"

/*
 * Settable interval range (millisecond)
 */
#define MIN_TIMER_PERIOD	1
#define MAX_TIMER_PERIOD	50

IMPORT UW	knl_TimerClkDiv;	/* Dividing rate of timer clock */

/*
 *    Function Name : knl_start_hw_timer
 *    Create Date   : 2009/12/27-2012/10/11
 *    Author        : wangshb-Dngjk
 *    Description   : Init and Startup hardware timer and enable periodical interrupt.
 *                    for Cortex M,timer is systick.
 *    Param	        : none
 *    Return Code   : none
 */
Inline void knl_start_hw_timer( void )
{
	UW	   n;
	UINT   imask;
	UW     channel =SYSTICK_BASE;

	/* Set dividing rate to 1,because systick is 24bit*/
	knl_TimerClkDiv =  1;

	DI(imask);

	/* Stop systick/Set systick source*/
	out_w(channel | SYSTICK_CTRL, SYSTICK_CLKSOURCE);

	/* Set systick counter */
	n = (UW)(CFN_TIMER_PERIOD * (TMCLK * 1000) / knl_TimerClkDiv - 1);
	out_w(channel | SYSTICK_LOAD, n);

	/* Set systick interrupt/Start systick count */
	out_w(channel | SYSTICK_CTRL, SYSTICK_CLKSOURCE | SYSTICK_TICKINT | SYSTICK_ENABLE);

	EI(imask);
}

/*
 *    Function Name : knl_clear_hw_timer_interrupt
 *    Create Date   : 2009/12/27-2012/10/11
 *    Author        : wangshb-dengjk
 *    Description   : Clear timer interrupt.
 *                    Depending on the type of hardware, there are two timings for clearing:
 *                    at the beginning and the end of the interrupt handler.
 *                    'clear_hw_timer_interrupt()' is called at the beginning of the timer interrupt handler.
 *                    'end_of_hw_timer_interrupt()' is called at the end of the timer interrupt handler.
 *                    Use either or both according to hardware.
 *                    for Cortex M,timer is systick.
 *    Param	        : none
 *    Return Code   : none
 */
Inline void knl_clear_hw_timer_interrupt( void )
{
}

/*
 *    Function Name : knl_end_of_hw_timer_interrupt
 *    Create Date   : 2009/12/27-2012/10/11
 *    Author        : wangshb-dengjk
 *    Description   : Clear timer interrupt.
 *                    Depending on the type of hardware, there are two timings for clearing:
 *                    at the beginning and the end of the interrupt handler.
 *                    'clear_hw_timer_interrupt()' is called at the beginning of the timer interrupt handler.
 *                    'end_of_hw_timer_interrupt()' is called at the end of the timer interrupt handler.
 *                    Use either or both according to hardware.
 *                    for Cortex M,timer is systick.
 *    Param	        : none
 *    Return Code   : none
 */
Inline void knl_end_of_hw_timer_interrupt( void )
{
}

/*
 *    Function Name : knl_terminate_hw_timer
 *    Create Date   : 2009/12/27-2012/10/11
 *    Author        : wangshb-dengjk
 *    Description   : Stop hardware timer.Called when system stops.
 *                    for Cortex M,timer is systick.
 *    Param	        : none
 *    Return Code   : none
 */
Inline void knl_terminate_hw_timer( void )
{
	UW     channel =SYSTICK_BASE;

	/* Systick disable */
    out_w(channel | SYSTICK_CTRL, SYSTICK_CLKSOURCE);
}

/*
 *    Function Name : knl_get_hw_timer_nsec
 *    Create Date   : 2009/12/27-2012/10/11
 *    Author        : wangshb-dengjk
 *    Description   : Get processing time from the previous timer interrupt to the current (nanosecond)
 *                    Consider the possibility that the timer interrupt occurred
 *                    during the interrupt disable and calculate the processing time within the following
 *                    range: 0 <= Processing time < CFN_TIMER_PERIOD * 2
 *                    for Cortex M,timer is systick.
 *    Param	        : none
 *    Return Code   : UW: processing time(nanosecond)
 */
Inline UW knl_get_hw_timer_nsec( void )
{
	UW	ofs, max, unf;
	UINT	imask;

	DI(imask);

    max = (in_w(SYSTICK_BASE | SYSTICK_LOAD) & 0xffffff) + 1;
	do {
		/* get COUNTFLAG bit */
		unf = in_w(SYSTICK_BASE | SYSTICK_CTRL) & SYSTICK_COUNTFLAG;
		ofs = in_w(SYSTICK_BASE | SYSTICK_VAL) & 0xffffff;
    } while ( unf != (in_w(SYSTICK_BASE | SYSTICK_CTRL) & SYSTICK_COUNTFLAG) );
	if ( unf != 0 ) {
		ofs += max;
	}

	EI(imask);

    return ofs * (1000 * knl_TimerClkDiv) / TMCLK;
}

#endif /* _TKDEV_TIMER_ */
