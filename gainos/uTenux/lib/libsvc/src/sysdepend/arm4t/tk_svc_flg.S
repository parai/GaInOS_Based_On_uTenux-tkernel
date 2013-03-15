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
 *	 File Name      : tk_svc_flg.S
 *	 Create Date    : 2009/7/27-2012/9/24
 *	 Author	        : WangShb
 *	 Description    : micro T-Kernel SVC interface library .
 *                    created from /usr/local/te/include/tk/syscall.h
 *-------------------------------------------------------------------------------
 */

#include <machine.h>
#include <tk/sysdef.h>
#include <sys/svc/tkfncd.h>
#include "utk_config.h"

    .syntax unified

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(tk_clr_flg)
	.type	Csym(tk_clr_flg), %function
Csym(tk_clr_flg):
	stmfd	sp!, {r4}
	add	    r4, sp, #4
	stmfd	sp!, {lr}
	ldr	    ip, =TFN_CLR_FLG
#if USE_TRAP
	swi	    SWI_SVC
#else
	bl	    Csym(knl_call_entry)
#endif
	ldmfd	sp!, {lr}
	ldmfd	sp!, {r4}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(tk_cre_flg)
	.type	Csym(tk_cre_flg), %function
Csym(tk_cre_flg):
	stmfd	sp!, {r4}
	add	    r4, sp, #4
	stmfd	sp!, {lr}
	ldr	    ip, =TFN_CRE_FLG
#if USE_TRAP
	swi	    SWI_SVC
#else
	bl	    Csym(knl_call_entry)
#endif
	ldmfd	sp!, {lr}
	ldmfd	sp!, {r4}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(tk_del_flg)
	.type	Csym(tk_del_flg), %function
Csym(tk_del_flg):
	stmfd	sp!, {r4}
	add	    r4, sp, #4
	stmfd	sp!, {lr}
	ldr	    ip, =TFN_DEL_FLG
#if USE_TRAP
	swi	    SWI_SVC
#else
	bl	    Csym(knl_call_entry)
#endif
	ldmfd	sp!, {lr}
	ldmfd	sp!, {r4}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(tk_ref_flg)
	.type	Csym(tk_ref_flg), %function
Csym(tk_ref_flg):
	stmfd	sp!, {r4}
	add	    r4, sp, #4
	stmfd	sp!, {lr}
	ldr	    ip, =TFN_REF_FLG
#if USE_TRAP
	swi	    SWI_SVC
#else
	bl	    Csym(knl_call_entry)
#endif
	ldmfd	sp!, {lr}
	ldmfd	sp!, {r4}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(tk_set_flg)
	.type	Csym(tk_set_flg), %function
Csym(tk_set_flg):
	stmfd	sp!, {r4}
	add	    r4, sp, #4
	stmfd	sp!, {lr}
	ldr	    ip, =TFN_SET_FLG
#if USE_TRAP
	swi	    SWI_SVC
#else
	bl	    Csym(knl_call_entry)
#endif
	ldmfd	sp!, {lr}
	ldmfd	sp!, {r4}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(tk_wai_flg)
	.type	Csym(tk_wai_flg), %function
Csym(tk_wai_flg):
	stmfd	sp!, {r4}
	add	    r4, sp, #4
	stmfd	sp!, {lr}
	ldr	    ip, =TFN_WAI_FLG
#if USE_TRAP
	swi	    SWI_SVC
#else
	bl    	Csym(knl_call_entry)
#endif
	ldmfd	sp!, {lr}
	ldmfd	sp!, {r4}
	bx	    lr
#endif

	.end
