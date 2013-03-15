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
 *    CPU:        CORTEX M3
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : sysdef_depend.h
 *	 Create Date    : 2012/7/19-2013/1/15
 *	 Author	        : WangShb-Zhangzl
 *	 Description    : register Definition about cpu(tk/MB9BF506R).
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
#define PSR_T		0x01000000	/* Thumb mode */

/*
 * Interrupt  mask register (Primask)
 */
#define PMK_D		0x1      	/* Interrupt disable */
#define PMK_E		0x0     	/* Interrupt enable */

/*
 * Except  mask register (Faultmask)
 */
#define FMK_D		0x1      	/* Except  disable */
#define FMK_E		0x0     	/* Except  enable */

/*
 * Control register (Control)
 */
#define CTL_MSP		0x0      	/* Select MSP */
#define CTL_PSP		0x2     	/* Select PSP */
#define CTL_SVC		0x0      	/* Select supervisor mode */
#define CTL_USR		0x1     	/* Select user mode */

/*
 * Exceptions Vector number Define
 */
#define EI_STACK_TOP    0x0     /* 00: Top of Main Stack           */
#define EI_RESET        0x1     /* 01: Reset                       */
#define EI_NMI          0x2     /* 02: NMI                         */
#define EI_HARDFAULT    0x3     /* 03: Hard Fault                  */
#define EI_MPUFAULT     0x4     /* 04: MPU Fault                   */
#define EI_BUSFAULT     0x5     /* 05: Bus Fault                   */
#define EI_USAGEFAULT   0x6     /* 06: Usage Fault                 */
                                /* 07: Reserved                    */
                                /* 08: Reserved                    */
                                /* 09: Reserved                    */
                                /* 10: Reserved                    */
#define EI_SVC          0xb     /* 11: SVCall                      */
#define EI_DEBUGMON     0xc     /* 12: Debug Monitor               */
                                /* 13: Reserved                    */
#define EI_PENDSV       0xe     /* 14: PendSV Handler              */
#define EI_SYSTICK      0xf     /* 15: Systick Handler             */


/*
 * Internal flash rom Controller
 */
#define FIF_BASE       0x40000000
#define FIF_FASZR      0x00
#define FIF_FRWTR      0x04
#define FIF_FSTR       0x08
#define FIF_FSYNDN     0x10
#define FIF_ASZ_0      0x00000000
#define FIF_ASZ_16     0x00000001
#define FIF_ASZ_32     0x00000002        /*after reset,default value,cpu mode */
#define FIF_RWT_60     0x00000000
#define FIF_RWT_80     0x00000002        /*after reset,default value,80MHz,2cyc wait */


/*
 * Clock and Reset Generation unit
 */
#define CRG_BASE       0x40010000
#define CRG_SCM_CTL    0x00
#define CRG_SCM_STR    0x04
#define CRG_STB_CTL    0x08
#define CRG_RST_STR    0x0c
#define CRG_BSC_PSR    0x10
#define CRG_APBC0_PSR  0x14
#define CRG_APBC1_PSR  0x18
#define CRG_APBC2_PSR  0x1c
#define CRG_SWC_PSR    0x20
/*Reserved             0x24 */
#define CRG_TTC_PSR    0x28
/* reserved            0x2c */
#define CRG_CSW_TMR    0x30
#define CRG_PSW_TMR    0x34
#define CRG_PLL_CTL1   0x38
#define CRG_PLL_CTL2   0x3c
#define CRG_CSV_CTL    0x40
#define CRG_CSV_STR    0x44
#define CRG_FCSWH_CTL  0x48
#define CRG_FCSWL_CTL  0x4c
#define CRG_FCSWD_CTL  0x50
#define CRG_DBWDT_CTL  0x54
/*Reserved             0x58 */
/*Reserved             0x5c */
#define CRG_INT_ENR    0x60
#define CRG_INT_STR    0x64
#define CRG_INT_CLR    0x68

/*CRG_SCM_STR Register Value         */
#define CRG_SCM_STR_MORDY  0x02          /*Main clock oscilation stable flag   */
#define CRG_SCM_STR_SORDY  0x08          /*Sub clock oscilation stable flag    */
#define CRG_SCM_STR_PLRDY  0x10          /*PLL oscilation stable flag          */
#define CRG_SCM_STR_MOMCK  0x20          /*Select Main clock as Master clock   */
#define CRG_SCM_STR_PLMCK  0x40          /*Select PLL clock as Master clock    */

/* CRG_CSW_TMR Register Value         */
#define CRG_CSW_TMR_MOWT   0x0C         /*Main clock stablilization time 33ms   */

/* CRG_PSW_TMR Register Value         */
#define CRG_PSW_TMR_POWT   0x00         /*PLL clock stablilization time 128us   */

/* CRG_BSC_PSR Register Value         */
#define CRG_BSC_PSR_DIV    0x00         /*Set Base clock ratio as 1/1  */

/* CRG_APBC0_PSR Register Value         */
#define CRG_APBC0_PSR_DIV  0x01         /*Set APBC0 clock ratio as 1/2 */

/* CRG_APBC1_PSR Register Value         */
#define CRG_APBC1_PSR_DIV  0x82         /*Set APBC1 clock ratio as 1/4,and Enable output */

/* CRG_APBC2_PSR Register Value         */
#define CRG_APBC2_PSR_DIV  0x81         /*Set APBC2 clock ratio as 1/2,and Enable Output */

/* CRG_SWC_PSR Register Value         */
#define CRG_SWC_PSR_DIV  0x83         /*Set Soft watch dog clock ratio as 1/8 */

/* CRG_TTC_PSR Register Value         */
#define CRG_TTC_PSR_DIV  0x00         /*Set Trace clock ratio as 1/1 */

/* CRG_PLL_CTL1 Register Value         */
#define CRG_PLL_CTL1_DIV  0x00        /*Set Pll clock ratio1 as 1/1 */

/* CRG_PLL_CTL2 Register Value         */
#define CRG_PLL_CTL2_DIV  0x13         /*Set Pll clock ratio1 as 1/20 */

/*
 *  IO PORT
 */
#define IOP_BASE  0x40033000
#define IOP_PFR0       0x00
#define IOP_PFR1       0x04
#define IOP_PFR2       0x08
#define IOP_PFR3       0x0C
#define IOP_PFR4       0x10
#define IOP_PFR5       0x14
#define IOP_PFR6       0x18
#define IOP_PFR7       0x1C
#define IOP_PFR8       0x20
#define IOP_PCR0       0x100
#define IOP_PCR1       0x104
#define IOP_PCR2       0x108
#define IOP_PCR3       0x10C
#define IOP_PCR4       0x110
#define IOP_PCR5       0x114
#define IOP_PCR6       0x118
#define IOP_PCR7       0x11C
#define IOP_PCR8       0x120
#define IOP_DDR0       0x200
#define IOP_DDR1       0x204
#define IOP_DDR2       0x208
#define IOP_DDR3       0x20C
#define IOP_DDR4       0x210
#define IOP_DDR5       0x214
#define IOP_DDR6       0x218
#define IOP_DDR7       0x21C
#define IOP_DDR8       0x220
#define IOP_PDIR0      0x300
#define IOP_PDIR1      0x304
#define IOP_PDIR2      0x308
#define IOP_PDIR3      0x30C
#define IOP_PDIR4      0x310
#define IOP_PDIR5      0x314
#define IOP_PDIR6      0x318
#define IOP_PDIR7      0x31C
#define IOP_PDIR8      0x320
#define IOP_PDOR0      0x400
#define IOP_PDOR1      0x404
#define IOP_PDOR2      0x408
#define IOP_PDOR3      0x40C
#define IOP_PDOR4      0x410
#define IOP_PDOR5      0x414
#define IOP_PDOR6      0x418
#define IOP_PDOR7      0x41C
#define IOP_PDOR8      0x420
#define IOP_ADE        0x500
#define IOP_SPSR       0x580
#define IOP_EPFR00     0x600
#define IOP_EPFR01     0x604
#define IOP_EPFR02     0x608
#define IOP_EPFR03     0x60C
#define IOP_EPFR04     0x610
#define IOP_EPFR05     0x614
#define IOP_EPFR06     0x618
#define IOP_EPFR07     0x61C
#define IOP_EPFR08     0x620
#define IOP_EPFR09     0x61C
#define IOP_EPFR10     0x620

/*
 * Nested Vectored Interrupt Controller
 */

/* Interrupt vectors Define            */
#define PI_FCS	        0            /* Anomalous Frequency Detection by Clock Supervisor (FCS) */
#define PI_SWDT	        1            /* Software Watchdog Timer */
#define PI_LVD	        2            /* Low Voltage Detector (LVD) */
#define PI_WFG	        3            /* MFT unit0, unit1 Wave Form Generator / DTIF(Motor Emergency Stop) */
#define PI_EXTI0        4            /* External Interrupt Request ch.0 to ch.7 */
#define PI_EXTI8        5            /* External Interrupt Request ch.8 to ch.15 */
#define PI_DT_QDU       6            /* Dual Timer / Quadrature Position/Resolution Counter (QPRC) ch.0, ch.1 */
#define PI_MFSI_RX0     7            /* Reception Interrupt Request of Multi-Function Serial Interface ch.0 */
#define PI_MFSI_TX0     8            /* Transmission Interrupt Request and Status Interrupt Request of Multi-Function Serial Interface ch.0 */
#define PI_MFSI_RX1     9            /* Reception Interrupt Request of Multi-Function Serial Interface ch.1 */
#define PI_MFSI_TX1	    10           /* Transmission Interrupt Request and Status Interrupt Request of Multi-Function Serial Interface ch.1 */
#define PI_MFSI_RX2	    11           /* Reception Interrupt Request of Multi-Function Serial Interface ch.2 */
#define PI_MFSI_TX2	    12           /* Transmission Interrupt Request and Status Interrupt Request of Multi-Function Serial Interface ch.2 */
#define PI_MFSI_RX3     13           /* Reception Interrupt Request of Multi-Function Serial Interface ch.3 */
#define PI_MFSI_TX3     14           /* Transmission Interrupt Request and Status Interrupt Request of Multi-Function Serial Interface ch.3 */
#define PI_MFSI_RX4     15           /* Reception Interrupt Request of Multi-Function Serial Interface ch.4 */
#define PI_MFSI_TX4     16           /* Transmission Interrupt Request and Status Interrupt Request of Multi-Function Serial Interface ch.4 */
#define PI_MFSI_RX5     17           /* Reception Interrupt Request of Multi-Function Serial Interface ch.5 */
#define PI_MFSI_TX5     18           /* Transmission Interrupt Request and Status Interrupt Request of Multi-Function Serial Interface ch.5 */
#define PI_TMFSI_RX6	19           /* Reception Interrupt Request of Multi-Function Serial Interface ch.6 */
#define PI_MFSI_TX6     20           /* Transmission Interrupt Request and Status Interrupt Request of Multi-Function Serial Interface ch.6 */
#define PI_MFSI_RX7	    21           /* Reception Interrupt Request of Multi-Function Serial Interface ch.7 */
#define PI_MFSI_TX7     22           /* Transmission Interrupt Request and Status Interrupt Request of Multi-Function Serial Interface ch.7 */
#define PI_PPG	        23           /* PPG ch.0/2/4/8/10/12 */
#define PI_CLK	        24           /* External Main OSC / External Sub OSC / Main PLL / PLL for USB/ Watch Counter */
#define PI_ADC0	        25           /* A/D Converter unit0 */
#define PI_ADC1	        26           /* A/D Converter unit1 */
#define PI_ADC2	        27           /* A/D Converter unit2 */
#define PI_FRTIM	    28           /* MFT unit0, unit1 Free-run Timer */
#define PI_CAP	        29           /* MFT unit0, unit1 Input Capture */
#define PI_COM          30           /* MFT unit0, unit1 Output Compare */
#define PI_BTIM	        31           /* Base Timer ch.0 to ch.7 */
#define PI_CAN0         32           /* CAN ch.0 */
#define PI_CAN1         33           /* CAN ch.1 */
#define PI_USB_1        34           /* USB Function (DRQ of End Point 1 to 5) */
#define PI_USB_2        35           /* USB Function (DRQI of End Point 0, DRQO and each status) / USB HOST (each status) */
/* #define reserved     36 */        /* Reserved */
/* #define reserved     37 */        /* Reserved */
#define PI_DMA_CH0      38           /* DMA Controller (DMAC) ch.0 */
#define PI_DMA_CH1      39           /* DMA Controller (DMAC) ch.1 */
#define PI_DMA_CH2      40           /* DMA Controller (DMAC) ch.2 */
#define PI_DMA_CH3      41           /* DMA Controller (DMAC) ch.3 */
#define PI_DMA_CH4      42           /* DMA Controller (DMAC) ch.4 */
#define PI_DMA_CH5      43           /* DMA Controller (DMAC) ch.5 */
#define PI_DMA_CH6      44           /* DMA Controller (DMAC) ch.6 */
#define PI_DMA_CH7      45           /* DMA Controller (DMAC) ch.7 */
/* #define reserved     46 */        /* Reserved */
/* #define reserved     47 */        /* Reserved */
#define PI_INT_NUMBER   48           /* Interrupt vectors Number*/

/* Software interrupt number for micro T-Kernel */
#define SWI_SVC		    65           /* micro T-Kernel system call/extension SVC */
#define SWI_RETINT	    66           /* tk_ret_int() system call,equal (SWI_SVC+1) */
#define SWI_DEBUG	    67           /* Debugger support function,equal (SWI_SVC+2) */

/* NVIC Register Define                     */
#define NVIC_BASE  0xe000e000
#define NVIC_ICTR  0x004       /* Interrupt Control Type Register */
#define NVIC_ISER  0x100       /* Interrupt Set-enable Registers base*/
#define NVIC_ICER  0x180       /* Interrupt Clear-enable Registers base */
#define NVIC_ISPR  0x200       /* Interrupt Set-pending Registers base */
#define NVIC_ICPR  0x280       /* Interrupt Clear-pending Registers base */
#define NVIC_IABR  0x300       /* Interrupt Active Bit Registers base */
#define NVIC_IPR   0x400       /* Interrupt Priority Registers base */
#define NVIC_ICSR  0xd04       /* Interrupt Control and State Register */
#define NVIC_VTOR  0xd08       /* Vector Table Offset Register */
#define NVIC_AIRCR 0xd0c       /* Appl Interrupt Reset Control Register */
#define NVIC_SCR   0xd10       /* System Control Register*/
#define NVIC_CCR   0xd14       /* Configuration and Control Register */
#define NVIC_SHPR  0xd18       /* System Handler Priority Register base */
#define NVIC_SHCRS 0xd24       /* System Handler Control State Register */
#define NVIC_STIR  0xf00       /* Software Trigger Interrupt Register*/

/*NVIC_ICSR Register           */
#define NVIC_ICSR_NMIPENDSET  (0x01<<31)
#define NVIC_ICSR_PENDSVSET   (0x01<<28)
#define NVIC_ICSR_PENDSVCLR   (0x01<<27)
#define NVIC_ICSR_PENDSTSET   (0x01<<26)
#define NVIC_ICSR_PENDSTCLR   (0x01<<25)
#define NVIC_ICSR_ISRPREEMPT  (0x01<<23)
#define NVIC_ICSR_ISRPENDING  (0x01<<22)

/*
 * UART
 */
#define UART0_BASE      0x40038000
#define UART_SMR        0x00             /* Serial Mode Register             */
#define UART_SCR        0x01             /* Serial Control Register          */
#define UART_ESCR       0x04             /* Extended Communication Control Register*/
#define UART_SSR        0x05             /* Serial Status Register           */
#define UART_RDR        0x08             /* Receive Data Register            */
#define UART_TDR        0x08             /* Transmit Data Register           */
#define UART_BGR        0x0C             /* Baud Rate Generator Register     */
#define UART_FCR        0x14             /* FIFO Control Register            */
#define UART_FBYTE1     0x18             /* FIFO1 Byte Register              */
#define UART_FBYTE2     0x19             /* FIFO2 Byte Register              */

/*
 * SYSTICK
 */
#define SYSTICK_BASE    0xe000e000
#define SYSTICK_CTRL    0x10
#define SYSTICK_LOAD    0x14
#define SYSTICK_VAL     0x18
#define SYSTICK_CALIB   0x1c

/* Usual used value macro */
#define SYSTICK_ENABLE    (0x1 << 0)      /* enable couter            */
#define SYSTICK_TICKINT   (0x1 << 1)      /* enable exception request */
#define SYSTICK_CLKSOURCE (0x1 << 2)      /* clock source is MCK      */
#define SYSTICK_COUNTFLAG (0x1 << 16)     /* timer count set flag     */

/*
 * SYSTEM CONTROL BLOCK
 */
#define SCB_BASE         0xe000e000
#define SCB_ACTLR        0x008       /* Auxiliary Control Register */
#define SCB_CPUID        0xd00       /* CPUID Base Register */
#define SCB_CFSR         0xd28       /* Configurable Fault Status Registers */
#define SCB_HFSR         0xd2c       /* Hard Fault Status Register */
#define SCB_DFSR         0xd30       /* Debug Fault Status Register */
#define SCB_MMFAR        0xd34       /* Memory Manage Fault Address Register */
#define SCB_BFAR         0xd38       /* Bus Fault Address Register */
#define SCB_AFSR         0xd3c       /* Auxiliary Fault Status Register */

/*
 * WATCH DOG
 */
#define WDG_BASE        0x40011000
#define WDG_LDR         0x00
#define WDG_VLR         0x04
#define WDG_CTL         0x08
#define WDG_ICL         0x0C
#define WDG_RIS         0x10
#define WDG_LCK         0xC00
/* -------- WDG_CTL  Watchdog Control Register -------- */
#define WDG_RESEN       0x02            /* Hardware Watchdog Reset Enable */
#define WDG_INTEN       0x01            /* Hardware Watchdog Interrupt and counter Enable */
/* -------- WDG_LCK  Watchdog Lock Register -------- */
#define WDG_LCKCTL      0x1ACCE551      /* Hardware Watchdog lock control register */
#define WDG_LCKREL      0xE5331AAE      /* Hardware Watchdog release lock */

#endif /* __TK_SYSDEF_DEPEND_H__ */
