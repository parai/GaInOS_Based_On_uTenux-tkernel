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


#undef _APP_MPC56XX_

#define _APP_MPC56XX_		    1
#define CPU_E200Z		        1
#define CPU_MPC56XX	        	1
#define APP_MPC56XX		        1


#define ALLOW_MISALIGN		        0
#define BIGENDIAN		            0
#define VIRTUAL_ADDRESS		        0
#define ALLOCA_NOSPT		        0
#define INT_BITWIDTH		        32

#ifndef _Csym
#define _Csym			            0
#endif

#define configRTI  0
#define configDEC  1
#define configTickSrc configDEC

#define CPU_FREQUENCY  64   /* 64 MHZ */

#if(CPU_FREQUENCY==8)
#define SYNCR_V 0x36100000
#endif
#if(CPU_FREQUENCY==16)
#define SYNCR_V 0x16100000
#endif
#if(CPU_FREQUENCY==20)
#define SYNCR_V 0x18100000
#endif
#if(CPU_FREQUENCY==32)
#define SYNCR_V 0x16080000
#endif
#if(CPU_FREQUENCY==40)
#define SYNCR_V 0x18080000
#endif
#if(CPU_FREQUENCY==50)
#define SYNCR_V 0x1A880000
#endif
#if(CPU_FREQUENCY==60)
#define SYNCR_V 0x15800000
#endif
#if(CPU_FREQUENCY==64)
#define SYNCR_V 0x16000000	/**PREFDIV=1,MFD=12,RFD=0,->Fsys=64MHZ*/
#endif
#if(CPU_FREQUENCY==80) /**PREFDIV=1,MFD=16,RFD=0,->Fsys=80MHZ*/
#define SYNCR_V 0x18000000
#endif
#endif /* __SYS_MACHINE_DEPEND_H__ */
