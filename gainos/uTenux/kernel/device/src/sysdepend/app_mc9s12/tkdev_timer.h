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
 *    CPU:        MC9S12
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : tkdev_timer.h
 *	 Create Date    : 2013/3/15-2013/3/17
 *	 Author	        : Fan Wang(parai)
 *	 Description    : Hardware-Dependent Timer Processing(MC9S12).
 *-------------------------------------------------------------------------------
 */

#ifndef _TKDEV_TIMER_
#define _TKDEV_TIMER_

#include <tk/syslib.h>
#include <sys/sysinfo.h>
#include "tkdev_conf.h"
#include "mc9s12dp512.h"
/*
 * Settable interval range (millisecond)
 */
#define MIN_TIMER_PERIOD	1
#define MAX_TIMER_PERIOD	50

IMPORT UW	knl_TimerClkDiv;	/* Dividing rate of timer clock */

/*
 *    Function Name : knl_start_hw_timer
 *    Create Date   : 2009/12/27-2012/10/04
 *    Author        : wangshb
 *    Description   : Init and Startup hardware timer and enable periodical interrupt.
 *                    for Cortex M,timer is systick.
 *    Param	        : none
 *    Return Code   : none
 */
Inline void knl_start_hw_timer( void )
{
    UB imask;
	DI(imask);

    CRGINT_RTIE=1;       //使能实时中断
    RTICTL = 0x70;       //设置实时中断的时间间隔为4.096ms
    /*????*/
    //中断周期=1/16 x 10E-6 x （0+1）x 2E（7+9）=0.004096s=4.096ms 
	EI(imask);
}

/*
 *    Function Name : knl_clear_hw_timer_interrupt
 *    Create Date   : 2009/12/27-2012/10/04
 *    Author        : wangshb
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
 *    Create Date   : 2009/12/27-2012/10/04
 *    Author        : wangshb
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
 *    Create Date   : 2009/12/27-2012/10/04
 *    Author        : wangshb
 *    Description   : Stop hardware timer.Called when system stops.
 *                    for Cortex M,timer is systick.
 *    Param	        : none
 *    Return Code   : none
 */
Inline void knl_terminate_hw_timer( void )
{
}

/*
 *    Function Name : knl_get_hw_timer_nsec
 *    Create Date   : 2009/12/27-2012/10/04
 *    Author        : wangshb
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
}

#endif /* _TKDEV_TIMER_ */
