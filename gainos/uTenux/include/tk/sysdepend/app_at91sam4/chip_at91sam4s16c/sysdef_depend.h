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
 *    CPU:        CORTEX M4
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : sysdef_depend.h
 *	 Create Date    : 2012/08/22-2013/1/24
 *	 Author	        : wangxd-zhangzl
 *	 Description    : register Definition about cpu(tk/AT91SAM4S16C).
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
#define EFC_BASE       0x400e0a00
#define EEFC_FMR_VAL   0x00000400
#define EFC_FMR        0x00
#define EFC_FCR        0x04
#define EFC_FSR        0x08
#define EFC_FRR        0x0c


/*
 * Power Management Controller
 */
#define PMC_BASE       0x400e0400
#define PMC_SCER       0x00
#define PMC_SCDR       0x04
#define PMC_SCSR       0x08
/* reserved            0x0c */
#define PMC_PCER       0x10
#define PMC_PCDR       0x14
#define PMC_PCSR       0x18
#define PMC_CKGR_UCKR  0x1c
#define PMC_CKGR_MOR   0x20
#define PMC_CKGR_MCFR  0x24
#define PMC_CKGR_PLLR  0x28
/* reserved            0x2c */
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
#define PMC_MOSCSXTS   0x01
#define PMC_PLL_LOCKA  0x02
#define PMC_MCKRDY     0x08

/*
 *  Parallel IO
 */
#define PIOA_BASE 0x400e0e00
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
#define PIO_ABSR  0x70
/* reserved       0x74-78 */
/* reserved       0x7c-9c */
#define PIO_OWER  0xA0
#define PIO_OWDR  0xA4
#define PIO_OWSR  0xA8

/*
 * Nested Vectored Interrupt Controller
 */

/* Peripheral Identifiers Define            */
#define PI_SUPC	         0           /* Supply Controller */
#define PI_RSTC	         1           /* Reset Controller */
#define PI_RTC 	         2           /* Real Time Clock */
#define PI_RTT	         3           /* Real Time Timer */
#define PI_WDT	         4           /* Watchdog Timer */
#define PI_PMC	         5           /* Power Management Controller */
#define PI_EEFC          6           /* Enhanced Embedded Flash Controller */
/* #define    7 */                   /* reserved */
#define PI_UART0         8           /* UART 0 */
#define PI_UART1         9           /* UART 1 */
#define PI_SMC	        10           /* SMC */
#define PI_PIOA	        11           /* Parallel I/O Controller A */
#define PI_PIOB	        12           /* Parallel I/O Controller B */
#define PI_PIOC         13           /* Parallel I/O Controller C */
#define PI_USART0       14           /* USART 0 */
#define PI_USART1       15           /* USART 1 */
/* #define    16 */                  /* reserved */
/* #define    17 */                  /* reserved */
#define PI_HSMCI        18           /* High Speed Multimedia Card Interface */
#define PI_TWI0	        19           /* Two Wire Interface 0 */
#define PI_TWI1	        20           /* Two Wire Interface 1 */
#define PI_SPI	        21           /* Serial Peripheral Interface */
#define PI_SSC	        22           /* Synchronous Serial Controller */
#define PI_TC0	        23           /* Timer/Counter 0 */
#define PI_TC1	        24           /* Timer/Counter 1 */
#define PI_TC2	        25           /* Timer/Counter 2 */
#define PI_TC3	        26           /* Timer/Counter 3 */
#define PI_TC4	        27           /* Timer/Counter 4 */
#define PI_TC5	        28           /* Timer/Counter 5 */
#define PI_ADC	        29           /* Analog-to-Digital Converter */
#define PI_DACC         30           /* Digital-to-Analog Converter */
#define PI_PWM	        31           /* Pulse Width Modulation */
#define PI_CRCCU        32           /* CRC Calculation Unit */
#define PI_ACC          33           /* Analog Comparator */
#define PI_UDP          34           /* USB Device Port */
#define PI_INT_NUMBER   35           /* Interrupt vectors Number */

/* Software interrupt number for micro T-Kernel */
#define SWI_SVC		    52   /* micro T-Kernel system call/extension SVC */
#define SWI_RETINT	    53   /* tk_ret_int() system call,equal (SWI_SVC+1) */
#define SWI_DEBUG	    54   /* Debugger support function,equal (SWI_SVC+2) */


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
 * USART
 */
#define USART0_BASE     0x40024000
#define USART1_BASE     0x40028000
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
 * UART
 */
#define UART0_BASE     0x400e0600
#define UART_CR        0x00             /* Control Register                 */
#define UART_MR        0x04             /* Mode Register                    */
#define UART_IER       0x08             /* Interrupt Enable Register        */
#define UART_IDR       0x0c             /* Interrupt Disable Register       */
#define UART_IMR       0x10             /* Interrupt Mask Register          */
#define UART_CSR       0x14             /* Channel Status Register          */
#define UART_RHR       0x18             /* Receiver Holding Register        */
#define UART_THR       0x1c             /* Transmitter Holding Register     */
#define UART_BRGR      0x20             /* Baud Rate Generator Register     */

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
#define WDT_BASE       0x400e1450
#define WDT_CR         0x00
#define WDT_MR         0x04
#define WDT_SR         0x08

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
