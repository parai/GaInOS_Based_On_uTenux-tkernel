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
 *	 File Name      : tkdev_conf.h
 *	 Create Date    : 2011/02/11-2012/10/11
 *	 Author	        : wangxd-wangxd
 *	 Description    : Target System Configuration(LPC1788).
 *-------------------------------------------------------------------------------
 */

#ifndef _TKDEV_CONF_
#define _TKDEV_CONF_
/* Also included from assembler source */

/*
 * memories
 */
#define RAM_VECTOR_TABLE_START  SYSTEMAREA_END
#define EXCEPTION_STACK_TOP     INTERNAL_RAM_END
#define APPLICATION_STACK_TOP   INTERNAL_RAM_END

#define	TMP_STACK_SZ	        (128)

/* Timer clock input (MHz)£¬usualy select MCK */
#define TMCLK		            120

/*
 * Timer interrupt level
 */
#define TIMER_INTLEVEL		    0

#endif /* _TKDEV_CONF_ */
