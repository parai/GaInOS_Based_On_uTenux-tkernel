/*
 *------------------------------------------------------------------------------
 *    Include/sys
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
 *	 File Name      : machine_depend.h
 *	 Create Date    : 2012/7/9-2012/7/9
 *	 Author	        : WangShb
 *	 Description    : Machine type definition(sys/STM32F1).
 *-------------------------------------------------------------------------------
 */

#ifndef __SYS_MACHINE_DEPEND_H__
#define __SYS_MACHINE_DEPEND_H__

/*
 * CPU_xxxx		    CPU type
 * ALLOW_MISALIGN	1 if access to misalignment data is allowed
 * BIGENDIAN		1 if big endian
 * VIRTUAL_ADDRESS	1 if virtual memory
 * ALLOCA_NOSPT		1 if alloca() is not supported
 */

/* ----- uTenux Appliance STM32F1(ARM CORTEX M3) definition ----- */

#undef _APP_STM32F1_

#define _APP_STM32F1_	            	1
#define CPU_ARM7M		                1
#define CPU_STM32F1   		        	1
#define APP_STM32F1   		        	1


#define ALLOW_MISALIGN		        0
#define BIGENDIAN		            0
#define VIRTUAL_ADDRESS		        0
#define ALLOCA_NOSPT		        0
#define INT_BITWIDTH		        32

#ifndef _Csym
#define _Csym			            0
#endif

#endif /* __SYS_MACHINE_DEPEND_H__ */
