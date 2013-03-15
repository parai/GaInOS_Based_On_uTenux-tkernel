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
 *	 File Name      : td_lst_oid.S
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
	.global Csym(td_lst_alm)
	.type	Csym(td_lst_alm), %function
Csym(td_lst_alm):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_LST_ALM
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
	.global Csym(td_lst_cyc)
	.type	Csym(td_lst_cyc), %function
Csym(td_lst_cyc):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_LST_CYC
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
	.global 	Csym(td_lst_flg)
	.type	Csym(td_lst_flg), %function
Csym(td_lst_flg):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_LST_FLG
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
	.global Csym(td_lst_mbf)
	.type	Csym(td_lst_mbf), %function
Csym(td_lst_mbf):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_LST_MBF
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
	.global Csym(td_lst_mbx)
	.type	Csym(td_lst_mbx), %function
Csym(td_lst_mbx):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_LST_MBX
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
	.global Csym(td_lst_mpf)
	.type	Csym(td_lst_mpf), %function
Csym(td_lst_mpf):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_LST_MPF
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
	.global Csym(td_lst_mpl)
	.type	Csym(td_lst_mpl), %function
Csym(td_lst_mpl):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_LST_MPL
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
	.global Csym(td_lst_mtx)
	.type	Csym(td_lst_mtx), %function
Csym(td_lst_mtx):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_LST_MTX
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
	.global Csym(td_lst_por)
	.type	Csym(td_lst_por), %function
Csym(td_lst_por):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_LST_POR
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
	.global Csym(td_lst_sem)
	.type	Csym(td_lst_sem), %function
Csym(td_lst_sem):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_LST_SEM
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
	.global Csym(td_lst_tsk)
	.type	Csym(td_lst_tsk), %function
Csym(td_lst_tsk):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_LST_TSK
#if USE_TRAP
	swi	    SWI_DEBUG
#else
	bl	    Csym(knl_call_dbgspt)
#endif
	ldmfd	sp!, {lr}
	bx	    lr
#endif

	.end
