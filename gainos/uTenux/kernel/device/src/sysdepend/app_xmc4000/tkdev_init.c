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
 *    CPU:        CORTEX M4
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : tkdev_init.c
 *	 Create Date    : 2012/9/6-2012/9/6
 *	 Author	        : Zhangzl-Zhangzl
 *	 Description    : micro T-Kernel Device-Dependent Initialization/Finalization(XMC4000).
 *-------------------------------------------------------------------------------
 */

#include "kernel.h"
#include <tk/sysdef.h>
#include <tk/syslib.h>
#include <tm/tmonitor.h>

EXPORT	UW	knl_TimerClkDiv;	/* Dividing rate of timer clock */

/*
 * Target system-dependent initialization
 */
EXPORT ER knl_tkdev_initialize( void )
{
	out_w(NVIC_BASE | NVIC_ICER, 0xffffffff); /* clear enable */
	out_w(NVIC_BASE | NVIC_ICPR, 0xffffffff); /* clear pending*/

	return E_OK;
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
