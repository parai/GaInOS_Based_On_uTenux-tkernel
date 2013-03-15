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
 *	 File Name      : tk_svc_alm.S
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
	.global	Csym(tk_cre_alm)
	.type	Csym(tk_cre_alm),function
Csym(tk_cre_alm):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TFN_CRE_ALM
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
	.global	Csym(tk_del_alm)
	.type	Csym(tk_del_alm),function
Csym(tk_del_alm):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TFN_DEL_ALM
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
	.global	Csym(tk_ref_alm)
	.type	Csym(tk_ref_alm),function
Csym(tk_ref_alm):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TFN_REF_ALM
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
	.global	Csym(tk_sta_alm)
	.type	Csym(tk_sta_alm),function
Csym(tk_sta_alm):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TFN_STA_ALM
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
	.global	Csym(tk_stp_alm)
	.type	Csym(tk_stp_alm),function
Csym(tk_stp_alm):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TFN_STP_ALM
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
