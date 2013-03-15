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
 *    CPU:        CORTEX M3
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : tk_svc_mtx.S
 *	 Create Date    : 2009/12/27-2012/10/29
 *	 Author	        : WangShb
 *	 Description    : micro T-Kernel SVC interface library .
 *                    created from /usr/local/te/include/tk/syscall.h
 *-------------------------------------------------------------------------------
 */

#include <machine.h>
#include <tk/sysdef.h>
#include <sys/svc/tkfncd.h>
#include "utk_config.h"

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
    .syntax unified
	.global	Csym(tk_cre_mtx)
	.type	Csym(tk_cre_mtx),function
Csym(tk_cre_mtx):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TFN_CRE_MTX
	mov     ip,r3
	pop     {r3}
#if USE_TRAP
    svc		SWI_SVC
#else
	bl  	Csym(knl_call_entry)
#endif
	pop 	{r4}
	mov     lr,r4
	pop 	{r4}
	bx  	lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
    .syntax unified
	.global	Csym(tk_del_mtx)
	.type	Csym(tk_del_mtx),function
Csym(tk_del_mtx):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TFN_DEL_MTX
	mov     ip,r3
	pop     {r3}
#if USE_TRAP
    svc		SWI_SVC
#else
	bl  	Csym(knl_call_entry)
#endif
	pop 	{r4}
	mov     lr,r4
	pop 	{r4}
	bx  	lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
    .syntax unified
	.global	Csym(tk_loc_mtx)
	.type	Csym(tk_loc_mtx),function
Csym(tk_loc_mtx):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TFN_LOC_MTX
	mov     ip,r3
	pop     {r3}
#if USE_TRAP
    svc		SWI_SVC
#else
	bl  	Csym(knl_call_entry)
#endif
	pop 	{r4}
	mov     lr,r4
	pop 	{r4}
	bx  	lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
    .syntax unified
	.global	Csym(tk_ref_mtx)
	.type	Csym(tk_ref_mtx),function
Csym(tk_ref_mtx):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TFN_REF_MPL
	mov     ip,r3
	pop     {r3}
#if USE_TRAP
    svc		SWI_SVC
#else
	bl  	Csym(knl_call_entry)
#endif
	pop 	{r4}
	mov     lr,r4
	pop 	{r4}
	bx  	lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
    .syntax unified
	.global	Csym(tk_unl_mtx)
	.type	Csym(tk_unl_mtx),function
Csym(tk_unl_mtx):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TFN_UNL_MTX
	mov     ip,r3
	pop     {r3}
#if USE_TRAP
    svc		SWI_SVC
#else
	bl  	Csym(knl_call_entry)
#endif
	pop 	{r4}
	mov     lr,r4
	pop 	{r4}
	bx  	lr
#endif

	.end
