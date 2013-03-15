/*
 *------------------------------------------------------------------------------
 *    Libsvc
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
 *    CPU:        ARM7&9
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : td_svc_mis.S
 *	 Create Date    : 2009/7/27-2012/9/24
 *	 Author	        : WangShb
 *	 Description    : micro T-Kernel SVC interface library.
 *                    created from /usr/local/te/include/tk/dbgspt.h
 *-------------------------------------------------------------------------------
 */

#include <machine.h>
#include <tk/sysdef.h>
#include <sys/svc/tdfncd.h>
#include "utk_config.h"

    .syntax unified

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(td_get_otm)
	.type	Csym(td_get_otm), %function
Csym(td_get_otm):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_GET_OTM
#if USE_TRAP
	swi	    SWI_DEBUG
#else
	bl	    Csym(knl_call_dbgspt)
#endif
	ldmfd	sp!, {lr}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(td_get_reg)
	.type	Csym(td_get_reg), %function
Csym(td_get_reg):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_GET_REG
#if USE_TRAP
	swi	    SWI_DEBUG
#else
	bl	Csym(knl_call_dbgspt)
#endif
	ldmfd	sp!, {lr}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(td_get_tim)
	.type	Csym(td_get_tim), %function
Csym(td_get_tim):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_GET_TIM
#if USE_TRAP
	swi	    SWI_DEBUG
#else
	bl	    Csym(knl_call_dbgspt)
#endif
	ldmfd	sp!, {lr}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(td_hok_dsp)
	.type	Csym(td_hok_dsp), %function
Csym(td_hok_dsp):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_HOK_DSP
#if USE_TRAP
	swi	    SWI_DEBUG
#else
	bl	    Csym(knl_call_dbgspt)
#endif
	ldmfd	sp!, {lr}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(td_hok_int)
	.type	Csym(td_hok_int), %function
Csym(td_hok_int):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_HOK_INT
#if USE_TRAP
	swi	    SWI_DEBUG
#else
	bl	    Csym(knl_call_dbgspt)
#endif
	ldmfd	sp!, {lr}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(td_hok_svc)
	.type	Csym(td_hok_svc), %function
Csym(td_hok_svc):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_HOK_SVC
#if USE_TRAP
	swi	    SWI_DEBUG
#else
	bl	    Csym(knl_call_dbgspt)
#endif
	ldmfd	sp!, {lr}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(td_inf_tsk)
	.type	Csym(td_inf_tsk), %function
Csym(td_inf_tsk):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_INF_TSK
#if USE_TRAP
	swi	    SWI_DEBUG
#else
	bl	    Csym(knl_call_dbgspt)
#endif
	ldmfd	sp!, {lr}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(td_set_dsname)
	.type	Csym(td_set_dsname), %function
Csym(td_set_dsname):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_SET_DSNAME
#if USE_TRAP
	swi	    SWI_DEBUG
#else
	bl	    Csym(knl_call_dbgspt)
#endif
	ldmfd	sp!, {lr}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(td_set_reg)
	.type	Csym(td_set_reg), %function
Csym(td_set_reg):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_SET_REG
#if USE_TRAP
	swi	    SWI_DEBUG
#else
	bl	    Csym(knl_call_dbgspt)
#endif
	ldmfd	sp!, {lr}
	bx	    lr
#endif

	.end
