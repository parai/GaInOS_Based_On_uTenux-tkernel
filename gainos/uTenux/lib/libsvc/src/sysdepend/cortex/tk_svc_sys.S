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
 *	 File Name      : tk_svc_sys.S
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
	.global	Csym(tk_dis_dsp)
	.type	Csym(tk_dis_dsp),function
Csym(tk_dis_dsp):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TFN_DIS_DSP
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
	.global	Csym(tk_ena_dsp)
	.type	Csym(tk_ena_dsp),function
Csym(tk_ena_dsp):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TFN_ENA_DSP
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
	.global	Csym(tk_get_tid)
	.type	Csym(tk_get_tid),function
Csym(tk_get_tid):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TFN_GET_TID
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
	.global	Csym(tk_ref_sys)
	.type	Csym(tk_ref_sys),function
Csym(tk_ref_sys):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TFN_REF_SYS
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
	.global	Csym(tk_ref_ver)
	.type	Csym(tk_ref_ver),function
Csym(tk_ref_ver):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TFN_REF_VER
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
	.global	Csym(tk_rot_rdq)
	.type	Csym(tk_rot_rdq),function
Csym(tk_rot_rdq):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TFN_ROT_RDQ
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
