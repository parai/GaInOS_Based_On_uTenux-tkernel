/*
 *------------------------------------------------------------------------------
 *    Include/sys
 *
 *    Copyright (C) 2008-2013 by Wang Fan(parai). All rights reserved.
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
 *-------------------------------------------------------------------------------
 */

#ifndef __SYS_SYSINFO_DEPEND_H__
#define __SYS_SYSINFO_DEPEND_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __ASSEMBLER__

#define N_INTVEC	(1)        /* Exception and Exteranl and SVC interrupt number */

/* IMPORT 	W*/extern signed long	knl_taskindp;
/* IMPORT 	W*/extern unsigned long	knl_taskmode;

#endif /* __ASSEMBLER__ */

#ifdef __cplusplus
}
#endif
#endif /* __SYS_SYSINFO_DEPEND_H__ */
