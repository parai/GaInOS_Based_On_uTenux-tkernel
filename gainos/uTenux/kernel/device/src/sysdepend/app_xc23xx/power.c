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
 *    CPU:        XC2364
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : power.c
 *	 Create Date    : 2013/3/15-2013/3/17
 *	 Author	        : Fan Wang(parai)
 *	 Description    : Power-Saving Function(XC2364).
 *-------------------------------------------------------------------------------
 */

#include <basic.h>
#include <tk/tkernel.h>
#include <tk/sysdef.h>
#include <tm/tmonitor.h>
/*
 * Switch to power-saving mode
 */
EXPORT void knl_low_pow( void )
{
	static int flag = 0;
	if(flag == 0)
	{
		tm_putstring((UB*)"in knl_low_pow().So no tasks in ready state.\r\n");
		flag = 1;
	}
}

/*
 * Move to suspend mode
 */
EXPORT void knl_off_pow( void )
{
}
