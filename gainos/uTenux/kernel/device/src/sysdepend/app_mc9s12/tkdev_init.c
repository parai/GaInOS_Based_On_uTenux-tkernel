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
 *	 File Name      : tkdev_init.c
 *	 Create Date    : 2013/3/15-2013/3/17
 *	 Author	        : Fan Wang(parai)
 *	 Description    : micro T-Kernel Device-Dependent Initialization/Finalization(MC9S12).
 *-------------------------------------------------------------------------------
 */

#include "kernel.h"
#include <tk/sysdef.h>
#include <tk/syslib.h>
#include <tm/tmonitor.h>
#include "mc9s12dp512.h"
/*
 * Target system-dependent initialization
 */
EXPORT ER knl_tkdev_initialize( void )
{
	return E_OK;
}

EXPORT void knl_start_hw_timer( void )
{
    UB imask;
	DI(imask);

    CRGINT_RTIE=1;       //使能实时中断
    RTICTL = 0x70;       //设置实时中断的时间间隔为4.096ms
    /*????*/
    //中断周期=1/16 x 10E-6 x （0+1）x 2E（7+9）=0.004096s=4.096ms 
	EI(imask);
}

#if USE_CLEANUP
/*
 * Target system-dependent finalization
 *	No return from this function.
 */
EXPORT void knl_tkdev_exit( void )
{
	disint();
	tm_exit(0);	/* Turn off power and exit */

	/* Not suppose to return from 'tm_exit,' but just in case */
	for ( ;; ) {
		tm_monitor();  /* To T-Monitor equivalent function */
	}
}
#endif /* USE_CLEANUP */
