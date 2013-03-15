/*
 *------------------------------------------------------------------------------
 *    Device
 *
 *    Copyright (C) 2008-2011 by Dalian uLoong Co.,Ltd. All rights reserved.
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
 *    CPU:        ARM7
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : tkdev_conf.h
 *	 Create Date    : 2009/7/27-2012/9/30
 *	 Author	        : WangShb
 *	 Description    : Target System Configuration(AT91SAM7).
 *-------------------------------------------------------------------------------
 */

#ifndef _TKDEV_CONF_
#define _TKDEV_CONF_
/* Also included from assembler source */

#define ARM_INT_MASK 0xC0
#define ARM_IRQ_BIT  0x80
#define ARM_FIQ_BIT  0x40
#define ARM_THM_BIT  0x20

#define ARM_MODE_MASK    0x1f
#define ARM_MODE_USER    0x10
#define ARM_MODE_FIQ     0x11
#define ARM_MODE_IRQ     0x12
#define ARM_MODE_SVC     0x13
#define ARM_MODE_ABORT   0x17
#define ARM_MODE_UNDEF   0x1F

/*
 * memories
 */
#define EXCEPTION_STACK_TOP     SYSTEMAREA_TOP
#define APPLICATION_STACK_TOP   INTERNAL_RAM_END


#define	TMP_STACK_SZ	(128)


#define TMCLK		48.054	    /* Timer clock input (MHz)£¬usually select MCK */


/*
 * Timer interrupt level
 */
#define TIMER_INTLEVEL		0

#endif /* _TKDEV_CONF_ */
