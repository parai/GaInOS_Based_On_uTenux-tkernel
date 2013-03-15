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
 *	 Create Date    : 2012/9/6-2013/1/15
 *	 Author	        : Zhangzl-Zhangzl
 *	 Description    : register Definition about cpu(tk/XMC4500F144K1024).
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
#define FLASH0_BASE     0x58001000

#define FLASH0_ID       0x1008
#define FLASH0_FSR      0x1010
#define FLASH0_FCON     0x1014
#define FLASH0_MARP     0x1018
#define FLASH0_PROCON0  0x1020
#define FLASH0_PROCON1  0x1024
#define FLASH0_PROCON2  0x1028


/*
 * System Control Unit
 */
#define SCU_BASE            0x50004000

#define SCU_TRAPCLR         0x16c
#define SCU_PRSTAT0         0x40c
#define SCU_PRCLR0          0x414
#define SCU_CLKSTAT         0x600
#define	SCU_CLKSET          0x604
#define SCU_CLKCLR          0x608
#define SCU_SYSCLKCR	    0x60c
#define SCU_CPUCLKCR	    0x610
#define SCU_PBCLKCR	        0x614
#define SCU_USBCLKCR	    0x618
#define SCU_EBUCLKCR	    0x61c
#define SCU_CCUCLKCR	    0x620
#define SCU_WDTCLKCR	    0x624
#define SCU_EXTCLKCR	    0x628
#define SCU_SLEEPCR	        0x630
#define SCU_DSLEEPCR	    0x634
#define SCU_OSCHPSTAT	    0x700
#define SCU_OSCHPCTRL	    0x704
/* Reserved	0x708 */
#define SCU_CLKCALCONST	    0x70c
#define SCU_PLLSTAT	        0x710
#define SCU_PLLCON0	        0x714
#define SCU_PLLCON1	        0x718
#define SCU_PLLCON2	        0x71c
#define SCU_USBPLLSTAT	    0x720
#define SCU_USBPLLCON	    0x724
/* Reserved	0x726~0x734 */
#define SCU_CLKMXSTAT	    0x738

#define SCU_OSCHPCTRL_MODE      (0x0<<4)
#define SCU_OSCHPCTRL_OSCVAL    (0x2<<16)
#define SCU_PLLCON0_VCOBYP      (0x1<<0)
#define SCU_PLLCON0_VCOPWD      (0x1<<1)
#define SCU_PLLCON0_FINDIS      (0x1<<4)
#define SCU_PLLCON0_OSCDISCDIS  (0x1<<6)
#define SCU_PLLCON0_PLLPWD      (0x1<<16)
#define SCU_PLLCON0_OSCRES      (0x1<<17)
#define SCU_PLLCON0_RESLD       (0x1<<18)
#define SCU_PLLCON1_K1DIV       (0x1<<0)
#define SCU_PLLCON1_NDIV        (0x4f<<8)
#define SCU_PLLCON1_K2DIV       (0x3<<16)
#define SCU_PLLCON1_PDIV        (0x1<<24)
#define SCU_PLLCON2_PINSEL      (0x1<<0)
#define SCU_PLLSTAT_VCOBYST     (0x0<<0)
#define SCU_PLLSTAT_VCOLOCK     (0x1<<2)
#define SCU_PLLSTAT_K2RDY       (0x1<<5)
#define SCU_PLLSTAT_PLLLV       (0x1<<7)
#define SCU_PLLSTAT_PLLHV       (0x1<<8)
#define SCU_PLLSTAT_PLLSP       (0x1<<9)
#define SCU_CPUCLKCR_CPUDIV     (0x0<<0)
#define SCU_PBCLKCR_PBDIV       (0x0<<0)
#define SCU_CCUCLKCR_CCUDIV     (0x0<<0)
#define SCU_SYSCLKCR_SYSDIV     0x0
#define SCU_CLKMXSTAT_SYSCLKMUX 0x10
#define SCU_TRAPCLR_SOSCWDGT    (0x1<<0)
#define SCU_TRAPCLR_SVCOLCKT    (0x1<<2)
#define SCU_PRCLR0_USIC0RS      (0x1<<11)
#define SCU_PRSTAT0_USIC0RS     (0x0<<16)

/*
 *  Parallel IO
 */
#define P0_BASE      0x48028000
#define P1_BASE      0x48028100
#define P2_BASE      0x48028200
#define P3_BASE      0x48028300
#define P4_BASE      0x48028400
#define P5_BASE      0x48028500
#define P6_BASE      0x48028600
#define P14_BASE     0x4802e000
#define P15_BASE     0x4802f000

#define P_OUT	     0x00
#define P_OMR	     0x04
#define P_IOCR0	     0x10
#define P_IOCR4	     0x14
#define P_IOCR8	     0x18
#define P_IOCR12	 0x1C
/* reserved 0x20 */
#define P_IN	     0x24
/* reserved 0x28~0x3C */
#define P_PDR0	     0x40
#define P_PDR1	     0x44
/* reserved 0x48~0x5c */
#define P_PDISC      0x60
#define P14_PDISC    0x60
#define P15_PDISC	 0x60
/* reserved 0x64~0x6c */
#define P_PPS	     0x70
#define P_HWSEL	     0x74

#define P_IOCR4_PC4  (0x9<<12)


/*
 * Nested Vectored Interrupt Controller
 */

/* Interrupt vectors Define  */
#define IRQ_SCU_0	     0      /* System Control */
#define IRQ_ERU0_0	     1      /* External Request Unit 0 */
#define IRQ_ERU0_1	     2      /* External Request Unit 0 */
#define IRQ_ERU0_2	     3      /* External Request Unit 0 */
#define IRQ_ERU0_3	     4      /* External Request Unit 0 */
#define IRQ_ERU1_0	     5      /* External Request Unit 1 */
#define IRQ_ERU1_1	     6      /* External Request Unit 1 */
#define IRQ_ERU1_2	     7      /* External Request Unit 1 */
#define IRQ_ERU1_3	     8      /* External Request Unit 1 */
/* Received 9~11 */             /* Received 9~11 */
#define IRQ_PMU0_0	     12     /* Program Management Unit */
/* Received 13 */               /* Received 13 */
#define IRQ_VADC0_C0_0	 14     /* Analog to Digital Converter Common Block 0 */
#define IRQ_VADC0_C0_1	 15     /* Analog to Digital Converter Common Block 0 */
#define IRQ_VADC0_C0_2	 16     /* Analog to Digital Converter Common Block 0 */
#define IRQ_VADC0_C0_3	 17     /* Analog to Digital Converter Common Block 0 */
#define IRQ_VADC0_G0_0	 18     /* Analog to Digital Converter Group 0 */
#define IRQ_VADC0_G0_1	 19     /* Analog to Digital Converter Group 0 */
#define IRQ_VADC0_G0_2	 20     /* Analog to Digital Converter Group 0 */
#define IRQ_VADC0_G0_3	 21     /* Analog to Digital Converter Group 0 */
#define IRQ_VADC0_G1_0	 22     /* Analog to Digital Converter Group 1 */
#define IRQ_VADC0_G1_1	 23     /* Analog to Digital Converter Group 1 */
#define IRQ_VADC0_G1_2	 24     /* Analog to Digital Converter Group 1 */
#define IRQ_VADC0_G1_3	 25     /* Analog to Digital Converter Group 1 */
#define IRQ_VADC0_G2_0	 26     /* Analog to Digital Converter Group 2 */
#define IRQ_VADC0_G2_1	 27     /* Analog to Digital Converter Group 2 */
#define IRQ_VADC0_G2_2	 28     /* Analog to Digital Converter Group 2 */
#define IRQ_VADC0_G2_3	 29     /* Analog to Digital Converter Group 2 */
#define IRQ_VADC0_G3_0	 30     /* Analog to Digital Converter Group 3 */
#define IRQ_VADC0_G3_1	 31     /* Analog to Digital Converter Group 3 */
#define IRQ_VADC0_G3_2	 32     /* Analog to Digital Converter Group 3 */
#define IRQ_VADC0_G3_3	 33     /* Analog to Digital Converter Group 3 */
#define IRQ_DSD0_0	     34     /* Delta Sigma Demodulator Main */
#define IRQ_DSD0_1	     35     /* Delta Sigma Demodulator Main */
#define IRQ_DSD0_2	     36     /* Delta Sigma Demodulator Main */
#define IRQ_DSD0_3	     37     /* Delta Sigma Demodulator Main */
#define IRQ_DSD0_4	     38     /* Delta Sigma Demodulator Auxiliary */
#define IRQ_DSD0_5	     39     /* Delta Sigma Demodulator Auxiliary */
#define IRQ_DSD0_6	     40     /* Delta Sigma Demodulator Auxiliary */
#define IRQ_DSD0_7	     41     /* Delta Sigma Demodulator Auxiliary */
#define IRQ_DAC0_0	     42     /* Digital to Analog Converter */
#define IRQ_DAC0_1	     43     /* Digital to Analog Converter */
#define IRQ_CCU40_0	     44     /* Capture Compare Unit 4 (Module 0) */
#define IRQ_CCU40_1	     45     /* Capture Compare Unit 4 (Module 0) */
#define IRQ_CCU40_2	     46     /* Capture Compare Unit 4 (Module 0) */
#define IRQ_CCU40_3	     47     /* Capture Compare Unit 4 (Module 0) */
#define IRQ_CCU41_0	     48     /* Capture Compare Unit 4 (Module 1) */
#define IRQ_CCU41_1 	 49     /* Capture Compare Unit 4 (Module 1) */
#define IRQ_CCU41_2	     50     /* Capture Compare Unit 4 (Module 1) */
#define IRQ_CCU41_3	     51     /* Capture Compare Unit 4 (Module 1) */
#define IRQ_CCU42_0	     52     /* Capture Compare Unit 4 (Module 2) */
#define IRQ_CCU42_1	     53     /* Capture Compare Unit 4 (Module 2) */
#define IRQ_CCU42_2	     54     /* Capture Compare Unit 4 (Module 2) */
#define IRQ_CCU42_3	     55     /* Capture Compare Unit 4 (Module 2) */
#define IRQ_CCU43_0	     56     /* Capture Compare Unit 4 (Module 3) */
#define IRQ_CCU43_1	     57     /* Capture Compare Unit 4 (Module 3) */
#define IRQ_CCU43_2	     58     /* Capture Compare Unit 4 (Module 3) */
#define IRQ_CCU43_3	     59     /* Capture Compare Unit 4 (Module 3) */
#define IRQ_CCU80_0	     60     /* Capture Compare Unit 8 (Module 0) */
#define IRQ_CCU80_1	     61     /* Capture Compare Unit 8 (Module 0) */
#define IRQ_CCU80_2	     62     /* Capture Compare Unit 8 (Module 0) */
#define IRQ_CCU80_3	     63     /* Capture Compare Unit 8 (Module 0) */
#define IRQ_CCU81_0	     64     /* Capture Compare Unit 8 (Module 1) */
#define IRQ_CCU81_1	     65     /* Capture Compare Unit 8 (Module 1) */
#define IRQ_CCU81_2	     66     /* Capture Compare Unit 8 (Module 1) */
#define IRQ_CCU81_3	     67     /* Capture Compare Unit 8 (Module 1) */
#define IRQ_POSIF0_0	 68     /* Position Interface (Module 0) */
#define IRQ_POSIF0_1	 69     /* Position Interface (Module 0) */
#define IRQ_POSIF1_0	 70     /* Position Interface (Module 1) */
#define IRQ_POSIF1_1	 71     /* Position Interface (Module 1) */
/* Received	72~75 */            /* Received	72~75 */
#define IRQ_CAN0_0	     76     /* MultiCAN */
#define IRQ_CAN0_1	     77     /* MultiCAN */
#define IRQ_CAN0_2	     78     /* MultiCAN */
#define IRQ_CAN0_3	     79     /* MultiCAN */
#define IRQ_CAN0_4	     80     /* MultiCAN */
#define IRQ_CAN0_5       81     /* MultiCAN */
#define IRQ_CAN0_6	     82     /* MultiCAN */
#define IRQ_CAN0_7	     83     /* MultiCAN */
#define IRQ_USIC0_0	     84     /* Universal Serial Interface Channel (Module 0) */
#define IRQ_USIC0_1	     85     /* Universal Serial Interface Channel (Module 0) */
#define IRQ_USIC0_2	     86     /* Universal Serial Interface Channel (Module 0) */
#define IRQ_USIC0_3    	 87     /* Universal Serial Interface Channel (Module 0) */
#define IRQ_USIC0_4	     88     /* Universal Serial Interface Channel (Module 0) */
#define IRQ_USIC0_5	     89     /* Universal Serial Interface Channel (Module 0) */
#define IRQ_USIC1_0	     90     /* Universal Serial Interface Channel (Module 1) */
#define IRQ_USIC1_1	     91     /* Universal Serial Interface Channel (Module 1) */
#define IRQ_USIC1_2	     92     /* Universal Serial Interface Channel (Module 1) */
#define IRQ_USIC1_3	     93     /* Universal Serial Interface Channel (Module 1) */
#define IRQ_USIC1_4	     94     /* Universal Serial Interface Channel (Module 1) */
#define IRQ_USIC1_5	     95     /* Universal Serial Interface Channel (Module 1) */
#define IRQ_USIC2_0	     96     /* Universal Serial Interface Channel (Module 2) */
#define IRQ_USIC2_1	     97     /* Universal Serial Interface Channel (Module 2) */
#define IRQ_USIC2_2		 98     /* Universal Serial Interface Channel (Module 2) */
#define IRQ_USIC2_3	 	 99     /* Universal Serial Interface Channel (Module 2) */
#define IRQ_USIC2_4		 100    /* Universal Serial Interface Channel (Module 2) */
#define IRQ_USIC2_5   	 101    /* Universal Serial Interface Channel (Module 2) */
#define IRQ_LEDTS0_0	 102    /* LED and Touch Sense Control Unit (Module 0) */
/* Received 103 */              /* Received 103 */
#define IRQ_FCE0_0	     104    /* Flexible CRC Engine */
#define IRQ_GPDMA0_0	 105    /* General Purpose DMA unit 0 */
#define IRQ_SDMMC0_0	 106    /* Multi Media Card Interface */
#define IRQ_USB0_0	     107    /* Universal Serial Bus */
#define IRQ_ETH0_0	     108    /* Ethernet (Module 0) */
/* Received	 109 */             /* Received	 109 */
#define IRQ_GPDMA1_0	 110    /* General Purpose DMA unit 1 */
/* Received	111 */              /* Received	111 */
#define IRQ_INT_NUMBER   112    /* Interrupt vectors Number*/

/* Software interrupt number for micro T-Kernel */
#define SWI_SVC		     129   /* micro T-Kernel system call/extension SVC */
#define SWI_RETINT	     130   /* tk_ret_int() system call,equal (SWI_SVC+1) */
#define SWI_DEBUG	     131   /* Debugger support function,equal (SWI_SVC+2) */

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
 * USIC
 */
#define USIC0_CH0_BASE 0x40030000

#define USIC_CCFG	    0x004
#define USIC_KSCFG      0x00c
#define USIC_FDR	    0x010
#define USIC_BRG	    0x014
#define USIC_INPR       0x018
#define USIC_DX0CR      0x01c
#define USIC_DX1CR      0x020
#define USIC_DX2CR      0x024
#define USIC_DX3CR      0x028
#define USIC_DX4CR      0x02c
#define USIC_DX5CR      0x030
#define USIC_SCTR       0x034
#define USIC_TCSR	    0x038
#define USIC_PCR	    0x03c
#define USIC_CCR	    0x040
#define USIC_PSR        0x048
#define USIC_PSCR	    0x04c
#define USIC_RBUFSR	    0x050
#define USIC_RBUF	    0x054
#define USIC_RBUFD	    0x058
#define USIC_RBUF0	    0x05c
#define USIC_RBUF1	    0x060
#define USIC_RBUF01SR	0x064
#define USIC_FMR	    0x068
#define USIC_TBUF(x)   (0x080 + x*4)

#define USIC_KSCFG_MODEN    (0x1<<0)
#define USIC_KSCFG_BPMODEN  (0x1<<1)
#define USIC_CCR_UART_MODE  (0x2<<0)
#define USIC_CCFG_UART_MODE (0x1<<1)
#define USIC_CCR_PM         (0x0<<8)
#define USIC_SCTR_PDL       (0x1<<1)
#define USIC_SCTR_TRM       (0x01<<8)
#define USIC_SCTR_FLE       (0x7<<16)
#define USIC_SCTR_WLE       (0x7<<24)
#define USIC_TCSR_TDSSM     (0x1<<8)
#define USIC_TCSR_TDEN      (0x1<<10)
#define USIC_PCR_SMD        (0x1<<0)
#define USIC_PCR_SP         (0x7<<8)
#define USIC_PCR_RSTEN      (1<<16)
#define USIC_PCR_TSTEN      (1<<17)
#define USIC_FDR_DM         (0x2<<14)
#define USIC_FDR_STEP       (0x200<<0)
#define USIC_BRG_CLKSEL     (0x3<<0)
#define USIC_BRG_PCTQ       (0x01<<8)
#define USIC_BRG_DCTQ       (0xf<<10)
#define USIC_BRG_PDIV       (0xf<<16)
#define USIC_DX0CR_DSEL      0x001
#define USIC_PSR_RFF        (0x1<<7)
#define USIC_PSR_TFF        (0x1<<8)
#define USIC_PSR_BUSY       (0x1<<9)
#define USIC_PSR_TSIF       (0x1<<12)
#define USIC_PSR_RIF        (0x1<<14)
#define USIC_PSR_AIF        (0x1<<15)
#define USIC_PSCR_CTSIF     (0x1<<12)
#define USIC_PSCR_CRIF      (0x1<<14)
#define USIC_PSCR_CAIF      (0x1<<15)

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
#define WDT_BASE       0x50008000

#define WDT_ID         0x00
#define WDT_CTR        0x04
#define WDT_SRV        0x08
#define WDT_TIM        0x0c
#define WDT_WLB        0x10
#define WDT_WUB        0x14
#define WDT_WDTSTS     0x18
#define WDT_WDTCLR     0x1c

#endif /* __TK_SYSDEF_DEPEND_H__ */
