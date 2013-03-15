/*
 *------------------------------------------------------------------------------
 *    Include/tk
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
 *	 File Name      : cpudef.h
 *	 Create Date    : 2012/7/9-2012/11/30
 *	 Author	        : WangShb
 *	 Description    : cpu dependent definition(tk/STM32F1).
 *-------------------------------------------------------------------------------
 */

#ifndef __TK_CPUDEF_H__
#define __TK_CPUDEF_H__

#ifdef __cplusplus
extern "C" {
#endif

/*
 * General purpose register			tk_get_reg tk_set_reg
 */
typedef struct t_regs {
	VW	r[13];		/* General purpose register R0-R12 */
	VP	lr;		    /* Link register R14 */
} T_REGS;

/*
 * Exception-related register		tk_get_reg tk_set_reg
 */
typedef struct t_eit {
    VP	pc;		    /* Program counter R15 */
    UW	psr;		/* Program status register */
    UW	taskmode;	/* Task mode flag */
} T_EIT;

/*
 * Control register			tk_get_reg tk_set_reg
 */
typedef struct t_cregs {
	VP	ssp;		/* System stack pointer usuealy MSP */
	VP	usp;		/* User stack pointer MSP or PSP */
} T_CREGS;

#ifdef __cplusplus
}
#endif
#endif /* __TK_CPUDEF_H__ */
