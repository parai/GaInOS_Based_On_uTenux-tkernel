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
 *    CPU:        AT91SAM7S256
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : sysdef_depend.h
 *	 Create Date    : 2009/7/27-2012/9/21
 *	 Author	        : WangShb
 *	 Description    : register Definition about cpu(tk/AT91SAM7).
 *-------------------------------------------------------------------------------
 */

#ifndef __TK_SYSDEF_DEPEND_H__
#define __TK_SYSDEF_DEPEND_H__

/*
 * Program status register (PSR)
 */
#define PSR_N		0x80000000	/* Condition flag Negative */
#define PSR_Z		0x40000000	/* Zero */
#define PSR_C		0x20000000	/* Carry */
#define PSR_V		0x10000000	/* Overflow */

#define PSR_I		0x00000080	/* Interrupt (IRQ) disable */
#define PSR_F		0x00000040	/* Fast Interrupt (FIQ) disable */
#define PSR_T		0x00000020	/* Thumb mode */

#define PSR_DI		(PSR_I | PSR_F)	/* All Interrupts disable */

#define PSR_M(n)	( n )		/* Processor mode 0-31 */
#define PSR_USR		PSR_M(16)	/* User mode */
#define PSR_FIQ		PSR_M(17)	/* Fast Interrupt (FIQ) mode */
#define PSR_IRQ		PSR_M(18)	/* Interrupt (IRQ) mode */
#define PSR_SVC		PSR_M(19)	/* Supervisor mode */
#define PSR_ABT		PSR_M(23)	/* Abort mode */
#define PSR_UND		PSR_M(27)	/* Undefined order mode */
#define PSR_SYS		PSR_M(31)	/* System mode */

/* ------------------------------------------------------------------------ */

/*
 * Software interrupt number for micro T-Kernel
 */
#define SWI_SVC		    36	/* micro T-Kernel system call/extension SVC */
#define SWI_RETINT	    37	/* tk_ret_int() system call */
#define SWI_DISPATCH	38	/* Task dispatcher */
#define SWI_DEBUG	    39	/* Debugger support function */

/* ------------------------------------------------------------------------ */

/*
 * External Bus Interface
 */
#define MC_BASE   0xffffff00
#define MC_RCR    0x00
#define MC_FMR    0x60
#define MC_FCR    0x64
#define MC_FSR    0x68


/*
 * Power Management Controller
 */
#define PMC_BASE       0xfffffc00
#define PMC_SCER       0x00
#define PMC_SCDR       0x04
#define PMC_SCSR       0x08
/* reserved            0x0c */
#define PMC_PCER       0x10
#define PMC_PCDR       0x14
#define PMC_PCSR       0x18
/* reserved            0x1c */
#define PMC_CKGR_MOR   0x20
#define PMC_CKGR_MCFR  0x24
/* reserved            0x28 */
#define PMC_CKGR_PLLR  0x2c
#define PMC_MCKR       0x30
/* reserved            0x34-3c */
#define PMC_PCK0       0x40
#define PMC_PCK1       0x44
#define PMC_PCK2       0x48
/* reserved            0x4c-5c */
#define PMC_IER        0x60
#define PMC_IDR        0x64
#define PMC_SR         0x68
#define PMC_IMR        0x6c

/* CKGR_MOR Register           */
#define PMC_MOSC_EN    0x01
#define PMC_MOSC_BYP   0x02

/*PMC_MCKR Register                */
#define PMC_PRES_NONE  (0x00 << 4)
#define PMC_PRES_DIV2  (0x01 << 4)
#define PMC_PRES_DIV4  (0x02 << 4)
#define PMC_PRES_DIV8  (0x03 << 4)
#define PMC_PRES_DIV16 (0x04 << 4)
#define PMC_PRES_DIV32 (0x05 << 4)
#define PMC_PRES_DIV64 (0x06 << 4)

#define PMC_CSS_LF     0x00
#define PMC_CSS_MOSC   0x01
#define PMC_CSS_PLL    0x03

/*PMC_SR Register              */
#define PMC_MOSCS      0x01
#define PMC_PLL_LOCK   0x04
#define PMC_MCKRDY     0x08

/*
 *  Parallel IO
 */
#define PIOA_BASE 0xfffff400
#define PIO_PER   0x00
#define PIO_PDR   0x04
#define PIO_PSR   0x08
/* reserved       0x0c */
#define PIO_OER   0x10
#define PIO_ODR   0x14
#define PIO_OSR   0x18
/* reserved       0x1c */
#define PIO_IFER  0x20
#define PIO_IFDR  0x24
#define PIO_IFSR  0x28
/* reserved       0x2c */
#define PIO_SODR  0x30
#define PIO_CODR  0x34
#define PIO_ODSR  0x38
#define PIO_PDSR  0x3c
#define PIO_IER   0x40
#define PIO_IDR   0x44
#define PIO_IMR   0x48
#define PIO_ISR   0x4c
#define PIO_MDER  0x50
#define PIO_MDDR  0x54
#define PIO_MDSR  0x58
/* reserved       0x5c */
#define PIO_PUDR  0x60
#define PIO_PUER  0x64
#define PIO_PUSR  0x68
/* reserved       0x6c */
#define PIO_ASR   0x70
#define PIO_BSR   0x74
#define PIO_ABSR  0x78
/* reserved       0x7c-9c */
#define PIO_OWER  0xA0
#define PIO_OWDR  0xA4
#define PIO_OWSR  0xA8



/*
 * Advanced Interrupt Controller
 */
#define FIQ        0
#define SYSIRQ     1
#define PIOAIRQ    2
#define ADCIRQ     4
#define SPIRQ      5
#define US0IRQ     6
#define US1IRQ     7
#define SSCIRQ     8
#define TWIIRQ     9
#define PMCIRQ    10
#define UDPIRQ    11
#define TC0IRQ    12
#define TC1IRQ    13
#define TC2IRQ    14
#define IRQ0      30
#define IRQ1      31


#define AIC_BASE  0xfffff000
#define AIC_SMR0  0x0000
#define AIC_SMR1  0x0004
#define AIC_SMR2  0x0008
#define AIC_SMR3  0x000c
#define AIC_SMR4  0x0010
#define AIC_SMR5  0x0014
#define AIC_SMR6  0x0018
#define AIC_SMR7  0x001c
#define AIC_SMR8  0x0020
#define AIC_SMR9  0x0024
#define AIC_SMR10 0x0028
#define AIC_SMR11 0x002c
#define AIC_SMR12 0x0030
#define AIC_SMR13 0x0034
#define AIC_SMR14 0x0038
#define AIC_SMR15 0x003c
#define AIC_SMR16 0x0040
#define AIC_SMR17 0x0044
#define AIC_SMR18 0x0048
#define AIC_SMR19 0x004c
#define AIC_SMR20 0x0050
#define AIC_SMR21 0x0054
#define AIC_SMR22 0x0058
#define AIC_SMR23 0x005c
#define AIC_SMR24 0x0060
#define AIC_SMR25 0x0064
#define AIC_SMR26 0x0068
#define AIC_SMR27 0x006c
#define AIC_SMR28 0x0070
#define AIC_SMR29 0x0074
#define AIC_SMR30 0x0078
#define AIC_SMR31 0x007c
#define AIC_SVR0  0x0080
#define AIC_SVR1  0x0084
#define AIC_SVR2  0x0088
#define AIC_SVR3  0x008c
#define AIC_SVR4  0x0090
#define AIC_SVR5  0x0094
#define AIC_SVR6  0x0098
#define AIC_SVR7  0x009c
#define AIC_SVR8  0x00a0
#define AIC_SVR9  0x00a4
#define AIC_SVR10 0x00a8
#define AIC_SVR11 0x00ac
#define AIC_SVR12 0x00b0
#define AIC_SVR13 0x00b4
#define AIC_SVR14 0x00b8
#define AIC_SVR15 0x00bc
#define AIC_SVR16 0x00c0
#define AIC_SVR17 0x00c4
#define AIC_SVR18 0x00c8
#define AIC_SVR19 0x00cc
#define AIC_SVR20 0x00d0
#define AIC_SVR21 0x00d4
#define AIC_SVR22 0x00d8
#define AIC_SVR23 0x00dc
#define AIC_SVR24 0x00e0
#define AIC_SVR25 0x00e4
#define AIC_SVR26 0x00e8
#define AIC_SVR27 0x00ec
#define AIC_SVR28 0x0070
#define AIC_SVR29 0x00f4
#define AIC_SVR30 0x00f8
#define AIC_SVR31 0x00fc
#define AIC_IVR   0x0100
#define AIC_FVR   0x0104
#define AIC_ISR   0x0108
#define AIC_IPR   0x010c
#define AIC_IMR   0x0110
#define AIC_CISR  0x0114
/* reserved       0x0118 */
/* reserved       0x011c */
#define AIC_IECR  0x0120
#define AIC_IDCR  0x0124
#define AIC_ICCR  0x0128
#define AIC_ISCR  0x012c
#define AIC_EOICR 0x0130
#define AIC_SPU   0x0134
#define AIC_DCR   0x0138


/*
 * Timer Counter
 */
#define TCB0_BASE 0xfffa0000
#define TC_C0     0x00
#define TC_C1     0x40
#define TC_C2     0x80
#define TC_CCR    0x00
#define TC_CMR    0x04
/* reserved       0x08 */
/* reserved       0x0c */
#define TC_CVR    0x10
#define TC_RA     0x14
#define TC_RB     0x18
#define TC_RC     0x1c
#define TC_SR     0x20
#define TC_IER    0x24
#define TC_IDR    0x28
#define TC_IMR    0x2c
#define TC_BCR    0xc0
#define TC_BMR    0xc4

#define TC_CLKEN  0x01
#define TC_CLKDIS 0x02
#define TC_SWTRG  0x04

#define TC_CLKS_MCK2    0x00
#define TC_CLKS_MCK8    0x01
#define TC_CLKS_MCK32   0x02
#define TC_CLKS_MCK128  0x03
#define TC_CLKS_MCK1024 0x04
#define TC_CLKS_XC0     0x05
#define TC_CLKS_XC1     0x06
#define TC_CLKS_XC2     0x07
#define TC_CLKI         0x08
#define TC_BURST_NONE   0x00
#define TC_BURST_XC0    0x10
#define TC_BURST_XC1    0x20
#define TC_BURST_XC2    0x30
#define TC_LDBSTOP      0x40
#define TC_LDBDIS       0x80
#define TC_ETRGEDG_EDGE_NONE    0x0000
#define TC_ETRGEDG_RIDING_EDGE  0x0100
#define TC_ETRGEDG_FALLING_EDGE 0x0200
#define TC_ETRGEDG_BOTH_EDGE    0x0300
#define TC_ABETRG_TIOB          0x0000
#define TC_ABETRG_TIOA          0x0400
#define TC_CPCTRG               0x4000
#define TC_WAVE                 0x8000
#define TC_LDRA_EDGE_NONE       0x0000
#define TC_LDRA_RISING_EDGE     0x010000
#define TC_LDRA_FALLING_EDGE    0x020000
#define TC_LDRA_BOTH_EDGE       0x030000
#define TC_LDRB_EDGE_NONE       0x000000
#define TC_LDRB_RISING_EDGE     0x040000
#define TC_LDRB_FALLING_EDGE    0x080000
#define TC_LDRB_BOTH_EDGE       0x0c0000

/*
 * USART
 */
#define USART0_BASE     0xfffc0000
#define USART1_BASE     0xfffc4000
#define US_CR           0x00
#define US_MR           0x04
#define US_IER          0x08
#define US_IDR          0x0c
#define US_IMR          0x10
#define US_CSR          0x14
#define US_RHR          0x18
#define US_THR          0x1c
#define US_BRGR         0x20
#define US_RTOR         0x24
#define US_TTGR         0x28
/* reserved             0x2c */
#define PERIPH_RPR     0x100
#define PERIPH_RCR     0x104
#define PERIPH_TPR     0x108
#define PERIPH_TCR     0x10C
#define PERIPH_RNPR    0x110
#define PERIPH_RNCR    0x114
#define PERIPH_TNPR    0x118
#define PERIPH_TNCR    0x11C
#define PERIPH_PTCR    0x120
#define PERIPH_PTSR    0x124


/*
 * REAL TIME  TIMER
 */
#define RTT_BASE        0xfffffd20
#define RTT_MR          0x00            /* Mode Register   */
#define RTT_AR          0x04            /* Alarm Register  */
#define RTT_VR          0x08            /* Value Register  */
#define RTT_SR          0x0C            /* Status Register */

/* Usual used value macro */
#define RTT_RTPRES     (0xffff <<  0)   /* Real-time Timer Prescaler Value */
#define RTT_ALMIEN     (0x1 << 16)      /* Alarm Interrupt Enable */
#define RTT_RTTINCIEN  (0x1 << 17)      /* Real Time Timer Increment Interrupt Enable */
#define RTT_RTTRST     (0x1 << 18)      /* Real Time Timer Restart */
/* -----RTT_RTAR : (RTTC Offset: 0x4) Real-time Alarm Register -------- */
#define RTT_ALMV       (0x0 <<  0)      /* Alarm Value */
/* -----RTT_RTVR:  (RTTC Offset: 0x8) Current Real-time Value Register -------- */
#define RTT_CRTV       (0x0 <<  0)      /* Current Real-time Value */
/* -----RTT_RTSR:  (RTTC Offset: 0xc) Real-time Status Register -------- */
#define RTT_ALMS       (0x1 <<  0)      /* Real-time Alarm Status */
#define RTT_RTTINC     (0x1 <<  1)      /* Real-time Timer Increment */
#define RTT_PRE32768   (32768    )      /* prescaler value for 1 second per increase*/

#define RTT_MINUTE     (60            ) /* seconds in a minute */
#define RTT_HOUR       (60*RTT_MINUTE ) /* seconds in a hour */
#define RTT_DAY        (24*RTT_HOUR   ) /* seconds in a day */
#define RTT_YEAR       (365*RTT_DAY   ) /* seconds in a year */
#define RTT_STARTYEAR  (70            ) /* Start from 1970*/


/*
 * WATCH DOG TIMER
 */
#define WDT_BASE        0xfffffd40
#define WDT_CR          0x00
#define WDT_MR          0x04
#define WDT_SR          0x08

// -------- WDT_CR  Periodic Interval Image Register --------
#define WDT_WDRSTT     (0x1 <<  0)     /* (WDT) Watchdog Restart */
#define WDT_KEY        (0xFF << 24)    /* (WDT) Watchdog KEY Password */
// -------- WDT_MR  Watchdog Mode Register --------
#define WDT_WDV        (0xFFF <<  0)   /* (WDT) Watchdog Timer Restart */
#define WDT_WDFIEN     (0x1 << 12)     /* (WDT) Watchdog Fault Interrupt Enable */
#define WDT_WDRSTEN    (0x1 << 13)     /* (WDT) Watchdog Reset Enable */
#define WDT_WDRPROC    (0x1 << 14)     /* (WDT) Watchdog Timer Restart */
#define WDT_WDDIS      (0x1 << 15)     /* (WDT) Watchdog Disable */
#define WDT_WDD        (0xFFF << 16)   /* (WDT) Watchdog Delta Value */
#define WDT_WDDBGHLT   (0x1 << 28)     /* (WDT) Watchdog Debug Halt */
#define WDT_WDIDLEHLT  (0x1 << 29)     /* (WDT) Watchdog Idle Halt */
// -------- WDT_SR  Watchdog Status Register --------
#define WDT_WDUNF      (0x1 <<  0)     /* (WDT) Watchdog Underflow */
#define WDT_WDERR      (0x1 <<  1)     /* (WDT) Watchdog Error */

#endif /* __TK_SYSDEF_DEPEND_H__ */
