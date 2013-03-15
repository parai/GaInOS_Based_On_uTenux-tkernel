/*
 *------------------------------------------------------------------------------
 *    Cpu
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
 *	 File Name      : offset.h
 *	 Create Date    : 2009/7/27-2012/9/21
 *	 Author	        : WangShb
 *	 Description    : TCB Offset Definition.
 *-------------------------------------------------------------------------------
 */

#ifndef _OFFSET_
#define _OFFSET_

/* Adjust offset of TCB member variables in offset.h for cpu_support.S */
#include "config.h"

/*	TCB.wrdvno	*/
#if CFN_MAX_PORID > 0
#define TCBSZ_POR	(4)	/* = sizeof(RNO) */
#else
#define TCBSZ_POR	(0)
#endif

/*	TCB.mtxlist	*/
#if CFN_MAX_MTXID > 0
#define TCBSZ_MTX	(4)	/* = sizeof(MTXCB*) */
#else
#define TCBSZ_MTX	(0)
#endif

/*	TCB.winfo.xxx	*/
#if CFN_MAX_PORID > 0
#define TCBSZ_WINFO	(16)
#else
#if CFN_MAX_FLGID > 0
#define TCBSZ_WINFO	(12)
#else
#if CFN_MAX_MBFID > 0 || CFN_MAX_MPLID > 0
#define TCBSZ_WINFO	(8)
#else
#if CFN_MAX_SEMID > 0 || CFN_MAX_MBXID > 0 || CFN_MAX_MPFID > 0
#define TCBSZ_WINFO	(4)
#else
#define TCBSZ_WINFO	(0)
#endif
#endif
#endif
#endif

/*	TCB.stime, TCB.utime */
#if USE_DBGSPT && defined(USE_FUNC_TD_INF_TSK)
#define TCBSZ_EXECTIME	(8)
#else
#define TCBSZ_EXECTIME	(0)
#endif

#define _ALIGN_CPU(x)	(((x)+3)&0xFFFFFFFC)	/* ARM7TDMI : 32 bit CPU	*/


/*----------------------------------------------------------------------*/
/*	machine dependent data						*/
/*----------------------------------------------------------------------*/
#define	TCB_winfo	(60)		/* tskque - wercd		*/
#define	TCB_wtmeb	_ALIGN_CPU(TCB_winfo+TCBSZ_WINFO)
#define	TCBsz_wtmeb2isstack	(24+TCBSZ_MTX+TCBSZ_POR+TCBSZ_EXECTIME)
					/* wtmeb - istack		*/
#define TCBSZ_GP	(0)		/* No global pointer support	*/

/*----------------------------------------------------------------------*/
/*	offset data in TCB						*/
/*----------------------------------------------------------------------*/
#define TCB_isstack	(TCB_wtmeb+TCBsz_wtmeb2isstack)
#define TCB_tskctxb	_ALIGN_CPU(TCB_isstack+4+TCBSZ_GP)

#define TCB_tskid	8
#define TCB_tskatr	16
#define TCB_state	35
#define CTXB_ssp	0

#endif /* _OFFSET_ */
