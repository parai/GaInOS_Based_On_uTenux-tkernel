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
 *    CPU:        MC9S12
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : offset.h
 *	 Create Date    : 2009/12/27-2012/11/29
 *	 Author	        : Fan Wang(parai)
 *	 Description    : TCB Offset Definition.
 *-------------------------------------------------------------------------------
 */

#ifndef _OFFSET_
#define _OFFSET_

#include "config.h"

/***************************************************************************************************
		Regeister Map
***************************************************************************************************/
#define XR0     0
#define XR1     XR0+4
#define XR2     XR1+4  /* untouch it because of _SDA2_BASE_ */
#define XR3     XR2+4    
#define XR4     XR3+4
#define XR5     XR4+4
#define XR6     XR5+4
#define XR7     XR6+4
#define XR8     XR7+4
#define XR9     XR8+4
#define XR10    XR9+4
#define XR11    XR10+4
#define XR12    XR11+4
#define XR13    XR12+4	/* untouch it because of _SDA_BASE_ */
#define XR14    XR13+4
#define XR15    XR14+4
#define XR16    XR15+4
#define XR17    XR16+4
#define XR18    XR17+4
#define XR19    XR18+4
#define XR20    XR19+4
#define XR21    XR20+4
#define XR22    XR21+4
#define XR23    XR22+4
#define XR24    XR23+4
#define XR25    XR24+4
#define XR26    XR25+4
#define XR27    XR26+4
#define XR28    XR27+4
#define XR29    XR28+4
#define XR30    XR29+4
#define XR31    XR30+4 
#define XTMODE  XR31+4
#define XSRR0   XTMODE+4
#define XSRR1   XSRR0+4
#define XUSPRG  XSRR1+4 
#define XCTR    XUSPRG+4    
#define XXER    XCTR+4
#define XCR     XXER+4
#define XLR     XCR+4
#define XSPEFSCR XLR+4
#define XPAD2   XSPEFSCR+4
#define XPAD3   XPAD2+4
#define XMSR    XPAD3+4

#define STACK_FRAME_SIZE   XMSR+4
		
#define OS_SAVE_R2_TO_R31()  stmw  r2,XR2(r1)
#define OS_SAVE_R4_TO_R31()  stmw  r3,XR3(r1)	

#define OS_SAVE_SPFRS()                         \
	/*Store XMSR ang SPEFSCR  */                \
	mfmsr   r0;                                 \
	stw     r0,  XMSR(r1);                      \
	mfspr   r0,  SPEFSCR;                       \
	stw     r0,  XSPEFSCR(r1);                  \
	/*Store LR(SRR0)*/                          \
	mfspr   r0,  SRR0;                          \
	stw     r0,  XSRR0(r1);                     \
	/*Store MSR(SRR1)*/                         \
	mfspr   r0,  SRR1;                          \
	stw     r0,  XSRR1(r1);                     \
	/*Store USPRG0*/                            \
	mfspr   r0,  USPRG0;                        \
	stw     r0,  XUSPRG(r1);                    \
	/*Store LR*/                                \
	mflr    r0;                                 \
	stw     r0,  XLR(r1);                       \
	/*Store CTR*/                               \
	mfctr   r0;                                 \
	stw     r0,  XCTR(r1);                      \
	/*Store XER*/                               \
	mfxer   r0;                                 \
	stw     r0,  XXER(r1);                      \
	/*Store CR*/                                \
	mfcr    r0;                                 \
	stw     r0,  XCR(r1)
	
#define OS_RESTORE_R2_TO_R31()  lmw  r2,XR2(r1)

#define OS_RESTORE_R3_TO_R31()  lmw  r3,XR3(r1)

#define OS_RESTORE_SPFRS()                                              \
	/*restore CR*/                                                      \
    lwz     r0,  XCR(r1);                                               \
    mtcrf   0xff,r0;                                                    \
	/*restore XER*/                                                     \
	lwz     r0,  XXER(r1);                                              \
	mtxer   r0;                                                         \
	/*restore CTR*/                                                     \
	lwz     r0,  XCTR(r1);                                              \
	mtctr   r0;                                                         \
	/*restore LR：这个寄存器必须保存，以前我错误的认为可以不用*/        \
	lwz     r0,  XLR(r1);                                               \
	mtlr    r0;                                                         \
	/*restore SRR1*/                                                    \
	lwz     r0,  XSRR1(r1);                                             \
	mtspr   SRR1,r0;                                                    \
	/*restore SRR0*/                                                    \
	lwz     r0,  XSRR0(r1);                                             \
	mtspr   SRR0,r0;                                                    \
	/*restore USPRG*/                                                   \
	lwz     r0,  XUSPRG(r1);                                            \
	mtspr   USPRG0,r0;                                                  \
	/*restore SPEFSCR :服务于浮点运算，可以不用保存（如果不使用浮点）*/ \
	lwz     r0,  XSPEFSCR(r1);                                          \
	mtspr   SPEFSCR,r0

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
