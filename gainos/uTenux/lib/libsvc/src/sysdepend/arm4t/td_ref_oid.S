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
 *	 File Name      : td_ref_oid.S
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
	.global Csym(td_ref_alm)
	.type	Csym(td_ref_alm), %function
Csym(td_ref_alm):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_REF_ALM
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
	.global Csym(td_ref_cyc)
	.type	Csym(td_ref_cyc), %function
Csym(td_ref_cyc):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_REF_CYC
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
	.global Csym(td_ref_dsname)
	.type	Csym(td_ref_dsname), %function
Csym(td_ref_dsname):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_REF_DSNAME
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
	.global Csym(td_ref_flg)
	.type	Csym(td_ref_flg), %function
Csym(td_ref_flg):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_REF_FLG
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
	.global Csym(td_ref_mbf)
	.type	Csym(td_ref_mbf), %function
Csym(td_ref_mbf):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_REF_MBF
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
	.global Csym(td_ref_mbx)
	.type	Csym(td_ref_mbx), %function
Csym(td_ref_mbx):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_REF_MBX
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
	.global Csym(td_ref_mpf)
	.type	Csym(td_ref_mpf), %function
Csym(td_ref_mpf):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_REF_MPF
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
	.global Csym(td_ref_mpl)
	.type	Csym(td_ref_mpl), %function
Csym(td_ref_mpl):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_REF_MPL
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
	.global Csym(td_ref_mtx)
	.type	Csym(td_ref_mtx), %function
Csym(td_ref_mtx):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_REF_MTX
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
	.global Csym(td_ref_por)
	.type	Csym(td_ref_por), %function
Csym(td_ref_por):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_REF_POR
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
	.global Csym(td_ref_sem)
	.type	Csym(td_ref_sem), %function
Csym(td_ref_sem):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_REF_SEM
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
	.global Csym(td_ref_sys)
	.type	Csym(td_ref_sys), %function
Csym(td_ref_sys):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_REF_SYS
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
	.global Csym(td_ref_tsk)
	.type	Csym(td_ref_tsk), %function
Csym(td_ref_tsk):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_REF_TSK
#if USE_TRAP
	swi	    SWI_DEBUG
#else
	bl	    Csym(knl_call_dbgspt)
#endif
	ldmfd	sp!, {lr}
	bx	    lr
#endif

	.end
