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
 *	 File Name      : sysinfo_depend.h
 *	 Create Date    : 2009/12/27-2013/1/5
 *	 Author	        : WangShb
 *	 Description    : System common information(sys/AT91SAM3).
 *-------------------------------------------------------------------------------
 */

#ifndef __SYS_SYSINFO_DEPEND_H__
#define __SYS_SYSINFO_DEPEND_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __ASSEMBLER__

#define N_INTVEC	(256)        /* Exception and Exteranl and SVC interrupt number */

IMPORT	W	knl_taskindp;
IMPORT	UW	knl_taskmode;

#endif /* __ASSEMBLER__ */

#ifdef __cplusplus
}
#endif
#endif /* __SYS_SYSINFO_DEPEND_H__ */
