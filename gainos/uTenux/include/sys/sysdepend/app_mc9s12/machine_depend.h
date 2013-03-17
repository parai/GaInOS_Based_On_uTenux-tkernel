/*
 *------------------------------------------------------------------------------
 *    Include/sys
 *
 *    Copyright (C) 2008-2013 by Fan Wang(parai). All rights reserved.
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
 *    CPU:        MC9S12DP512
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *
 *	 File Name      : machine_depend.h
 *	 Create Date    : 2013/3/15-2013/3/17
 *	 Author	        : Fan Wang(parai)
 *-------------------------------------------------------------------------------
 */

#ifndef __SYS_MACHINE_DEPEND_H__
#define __SYS_MACHINE_DEPEND_H__



#undef _APP_MC9S12_

#define _APP_MC9S12_		    1
#define CPU_SV12		            1
#define CPU_MC9S12	        	1
#define APP_MC9S12		        1


#define ALLOW_MISALIGN		        0
#define BIGENDIAN		            0
#define VIRTUAL_ADDRESS		        0
#define ALLOCA_NOSPT		        0
#define INT_BITWIDTH		        16

#ifndef _Csym
#define _Csym			            0
#endif

#endif /* __SYS_MACHINE_DEPEND_H__ */
