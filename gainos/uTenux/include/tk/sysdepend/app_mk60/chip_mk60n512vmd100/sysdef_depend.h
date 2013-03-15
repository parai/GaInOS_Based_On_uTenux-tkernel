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
 *	 Create Date    : 2012/7/20-2013/1/15
 *	 Author	        : Zhangzl-Zhangzl
 *	 Description    : register Definition about cpu(tk/MK60N512VMD100).
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
#define FMC_BASE             0x4001f000

#define FMC_PFAPR            0x00
#define FMC_PFB0CR           0x04
#define FMC_PFB1CR           0x08

/* FMC_PFAPR defined */
#define FMC_PFAPR_M0PFD_MASK_ALL   0xff0000

/*
 * Multipurpose Clock Generator
 */
#define MCG_BASE            0x40064000
#define MCG_C1              0x00
#define MCG_C2              0x01
#define MCG_C3              0x02
#define MCG_C4              0x03
#define MCG_C5              0x04
#define MCG_C6              0x05
#define MCG_S               0x06
/* reserved 0x07 */
#define MCG_ATC             0x08
/* reserved 0x09 */
#define MCG_ATCVH           0x0a
#define MCG_ATCVL           0x0b

#define MCG_C1_FRDIV        0x18
#define MCG_C1_CLKS_MASK    0xc0
#define MCG_C2_RANGE        0x20
#define MCG_C2_HGO_MASK     0x8
#define MCG_C2_EREFS_MASK   0x4
#define MCG_C2_SET_VALUE    (MCG_C2_RANGE | MCG_C2_HGO_MASK | MCG_C2_EREFS_MASK)
#define MCG_C5_PRDIV        0x18
#define MCG_C6_VDIV         0x18
#define MCG_S_CLKST_SHIFT   2
#define MCG_S_PLLST_MASK    0x20
#define MCG_S_LOCK_MASK     0x40
#define MCG_S_OSCINIT_MASK  0x2
#define MCG_S_IREFST_MASK   0x10
#define MCG_S_CLKST_MASK    0xc


/* System integration module */
#define SIM_BASE       0x40048000
#define SIM_SOPT1      0x40047000
/* The SIM_SOPT1 register is located
 * at a different base address than the other SIM registers
 */
#define SIM_SOPT2            0x04
#define SIM_SOPT4            0x0c
#define SIM_SOPT5            0x10
#define SIM_SOPT6            0x14
#define SIM_SOPT7            0x18
#define SIM_SDID             0x24
#define SIM_SCGC1            0x28
#define SIM_SCGC2            0x2c
#define SIM_SCGC3            0x30
#define SIM_SCGC4            0x34
#define SIM_SCGC5            0x38
#define SIM_SCGC6            0x3c
#define SIM_SCGC7            0x40
#define SIM_CLKDIV1          0x44
#define SIM_CLKDIV2          0x48
#define SIM_FCFG1            0x4c
#define SIM_FCFG2            0x50
#define SIM_UIDH             0x54
#define SIM_UIDMH            0x58
#define SIM_UIDML            0x5c
#define SIM_UIDL             0x60

#define SIM_SCGC4_LLWU_MASK  0x10000000
#define SIM_SCGC4_UART3_MASK 0x2000
#define SIM_SCGC1_UART4_MASK 0x400
#define SIM_CLKDIV1_VALUE    0x01130000


/* Low-leakage wake-up unit */
#define LLWU_BASE             0x4007c000

#define LLWU_PE1              0x00
#define LLWU_PE2              0x01
#define LLWU_PE3              0x02
#define LLWU_PE4              0x03
#define LLWU_ME               0x04
#define LLWU_F1               0x05
#define LLWU_F2               0x06
#define LLWU_F3               0x07
#define LLWU_CS               0x08

#define LLWU_CS_ACKISO_MASK   0x80

/*
 *  Port
 */
#define PORTA_BASE           0x40049000 /* Port A  adress */
#define PORTB_BASE           0x4004a000 /* Port B  adress */
#define PORTC_BASE           0x4004b000 /* Port C  adress */
#define PORTD_BASE           0x4004c000 /* Port D  adress */
#define PORTE_BASE           0x4004d000 /* Port E  adress */

#define PORT_PCR0            0x00
#define PORT_PCR1            0x04
#define PORT_PCR2            0x08
#define PORT_PCR3            0x0c
#define PORT_PCR4            0x10
#define PORT_PCR5            0x14
#define PORT_PCR6            0x18
#define PORT_PCR7            0x1c
#define PORT_PCR8            0x20
#define PORT_PCR9            0x24
#define PORT_PCR10           0x28
#define PORT_PCR11           0x2c
#define PORT_PCR12           0x30
#define PORT_PCR13           0x34
#define PORT_PCR14           0x38
#define PORT_PCR15           0x3c
#define PORT_PCR16           0x40
#define PORT_PCR17           0x44
#define PORT_PCR18           0x48
#define PORT_PCR19           0x4c
#define PORT_PCR20           0x50
#define PORT_PCR21           0x54
#define PORT_PCR22           0x58
#define PORT_PCR23           0x5c
#define PORT_PCR24           0x60
#define PORT_PCR25           0x64
#define PORT_PCR26           0x68
#define PORT_PCR27           0x6c
#define PORT_PCR28           0x70
#define PORT_PCR29           0x74
#define PORT_PCR30           0x78
#define PORT_PCR31           0x7c
#define PORT_GPCLR           0x80
#define PORT_GPCHR           0x84
#define PORT_ISFR            0xa0
#define PORT_DFER            0xc0
#define PORT_DFCR            0xc4
#define PORT_DFWR            0xc8

#define PORT_PCR_MUX_MASK    0x700
#define PORT_PCR_MUX_SHIFT   8

/*
 * GPIO
 */
#define GPIOA_BASE           0x400ff000
#define GPIOB_BASE           0x400ff040
#define GPIOC_BASE           0x400ff080
#define GPIOD_BASE           0x400ff0c0
#define GPIOE_BASE           0x400ff100

#define GPIO_PDOR            0x00
#define GPIO_PSOR            0x04
#define GPIO_PCOR            0x08
#define GPIO_PTOR            0x0c
#define GPIO_PDIR            0x10
#define GPIO_PDDR            0x14


/*
 * Nested Vectored Interrupt Controller
 */
#define  INT_DMA0                     0      /* DMA Channel 0 Transfer Complete */
#define  INT_DMA1                     1      /* DMA Channel 1 Transfer Complete */
#define  INT_DMA2                     2      /* DMA Channel 2 Transfer Complete */
#define  INT_DMA3                     3      /* DMA Channel 3 Transfer Complete */
#define  INT_DMA4                     4      /* DMA Channel 4 Transfer Complete */
#define  INT_DMA5                     5      /* DMA Channel 5 Transfer Complete */
#define  INT_DMA6                     6      /* DMA Channel 6 Transfer Complete */
#define  INT_DMA7                     7      /* DMA Channel 7 Transfer Complete */
#define  INT_DMA8                     8      /* DMA Channel 8 Transfer Complete */
#define  INT_DMA9                     9      /* DMA Channel 9 Transfer Complete */
#define  INT_DMA10                    10     /* DMA Channel 10 Transfer Complete */
#define  INT_DMA11                    11     /* DMA Channel 11 Transfer Complete */
#define  INT_DMA12                    12     /* DMA Channel 12 Transfer Complete */
#define  INT_DMA13                    13     /* DMA Channel 13 Transfer Complete */
#define  INT_DMA14                    14     /* DMA Channel 14 Transfer Complete */
#define  INT_DMA15                    15     /* DMA Channel 15 Transfer Complete */
#define  INT_DMA_Error                16     /* DMA Error Interrupt */
#define  INT_MCM                      17     /* Normal Interrupt */
#define  INT_FTFL                     18     /* FTFL Interrupt */
#define  INT_Read_Collision           19     /* Read Collision Interrupt */
#define  INT_LVD_LVW                  20     /* Low Voltage Detect, Low Voltage Warning */
#define  INT_LLW                      21     /* Low Leakage Wakeup */
#define  INT_Watchdog                 22     /* WDOG Interrupt */
#define  INT_RNG                      23     /* RNGB Interrupt */
#define  INT_I2C0                     24     /* I2C0 interrupt */
#define  INT_I2C1                     25     /* I2C1 interrupt */
#define  INT_SPI0                     26     /* SPI0 Interrupt */
#define  INT_SPI1                     27     /* SPI1 Interrupt */
#define  INT_SPI2                     28     /* SPI2 Interrupt */
#define  INT_CAN0_ORed_Message_buffer 29     /* CAN0 OR'd Message Buffers Interrupt */
#define  INT_CAN0_Bus_Off             30     /* CAN0 Bus Off Interrupt */
#define  INT_CAN0_Error               31     /* CAN0 Error Interrupt */
#define  INT_CAN0_Tx_Warning          32     /* CAN0 Tx Warning Interrupt */
#define  INT_CAN0_Rx_Warning          33     /* CAN0 Rx Warning Interrupt */
#define  INT_CAN0_Wake_Up             34     /* CAN0 Wake Up Interrupt */
 /* Reserved interrupt 35/36 */
#define  INT_CAN1_ORed_Message_buffer 37     /* CAN1 OR'd Message Buffers Interrupt */
#define  INT_CAN1_Bus_Off             38     /* CAN1 Bus Off Interrupt */
#define  INT_CAN1_Error               39     /* CAN1 Error Interrupt */
#define  INT_CAN1_Tx_Warning          40     /* CAN1 Tx Warning Interrupt */
#define  INT_CAN1_Rx_Warning          41     /* CAN1 Rx Warning Interrupt */
#define  INT_CAN1_Wake_Up             42     /* CAN1 Wake Up Interrupt */
 /* Reserved interrupt 59/60 */
#define  INT_UART0_RX_TX              45     /* UART0 Receive/Transmit interrupt */
#define  INT_UART0_ERR                46     /* UART0 Error interrupt */
#define  INT_UART1_RX_TX              47     /* UART1 Receive/Transmit interrupt */
#define  INT_UART1_ERR                48     /* UART1 Error interrupt */
#define  INT_UART2_RX_TX              49     /* UART2 Receive/Transmit interrupt */
#define  INT_UART2_ERR                50     /* UART2 Error interrupt */
#define  INT_UART3_RX_TX              51     /* UART3 Receive/Transmit interrupt */
#define  INT_UART3_ERR                52     /* UART3 Error interrupt */
#define  INT_UART4_RX_TX              53     /* UART4 Receive/Transmit interrupt */
#define  INT_UART4_ERR                54     /* UART4 Error interrupt */
#define  INT_UART5_RX_TX              55     /* UART5 Receive/Transmit interrupt */
#define  INT_UART5_ERR                56     /* UART5 Error interrupt */
#define  INT_ADC0                     57     /* ADC0 interrupt */
#define  INT_ADC1                     58     /* ADC1 interrupt */
#define  INT_CMP0                     59     /* CMP0 interrupt */
#define  INT_CMP1                     60     /* CMP1 interrupt */
#define  INT_CMP2                     61     /* CMP2 interrupt */
#define  INT_FTM0                     62     /* FTM0 fault, overflow and channels interrupt */
#define  INT_FTM1                     63     /* FTM1 fault, overflow and channels interrupt */
#define  INT_FTM2                     64     /* FTM2 fault, overflow and channels interrupt */
#define  INT_CMT                      65     /* CMT interrupt */
#define  INT_RTC                      66     /* RTC interrupt */
 /* Reserved interrupt 67 */
#define  INT_PIT0                     68     /* PIT timer channel 0 interrupt */
#define  INT_PIT1                     69     /* PIT timer channel 1 interrupt */
#define  INT_PIT2                     70     /* PIT timer channel 2 interrupt */
#define  INT_PIT3                     71     /* PIT timer channel 3 interrupt */
#define  INT_PDB0                     72     /* PDB0 Interrupt */
#define  INT_USB0                     73     /* USB0 interrupt */
#define  INT_USBDCD                   74     /* USBDCD Interrupt */
#define  INT_ENET_1588_Timer          75     /* Ethernet MAC IEEE 1588 Timer Interrupt */
#define  INT_ENET_Transmit            76     /* Ethernet MAC Transmit Interrupt */
#define  INT_ENET_Receive             77     /* Ethernet MAC Receive Interrupt */
#define  INT_ENET_Error               78     /* Ethernet MAC Error and miscelaneous Interrupt */
#define  INT_I2S0                     79     /* I2S0 Interrupt */
#define  INT_SDHC                     80     /* SDHC Interrupt */
#define  INT_DAC0                     81     /* DAC0 interrupt */
#define  INT_DAC1                     82     /* DAC1 interrupt */
#define  INT_TSI0                     83     /* TSI0 Interrupt */
#define  INT_MCG                      84     /* MCG Interrupt */
#define  INT_LPTimer                  85     /* LPTimer interrupt */
 /* Reserved interrupt 86 */
#define  INT_PORTA                    87     /* Port A interrupt */
#define  INT_PORTB                    88     /* Port B interrupt */
#define  INT_PORTC                    89     /* Port C interrupt */
#define  INT_PORTD                    90     /* Port D interrupt */
#define  INT_PORTE                    91     /* Port E interrupt */
#define  INT_NUMBER                   92    /* Interrupt vectors Number*/
/* Software interrupt number for micro T-Kernel */
#define SWI_SVC		                  109    /* micro T-Kernel system call/extension SVC */
#define SWI_RETINT	                  110    /* tk_ret_int() system call,equal (SWI_SVC+1) */
#define SWI_DEBUG	                  111    /* Debugger support function,equal (SWI_SVC+2) */

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
#define UART0_BASE           0x4006a000
#define UART1_BASE           0x4006b000
#define UART2_BASE           0x4006c000
#define UART3_BASE           0x4006d000
#define UART4_BASE           0x400ea000
#define UART5_BASE           0x400eb000

#define UART_BDH             0x00
#define UART_BDL             0x01
#define UART_C1              0x02
#define UART_C2              0x03
#define UART_S1              0x04
#define UART_S2              0x05
#define UART_C3              0x06
#define UART_D               0x07
#define UART_MA1             0x08
#define UART_MA2             0x09
#define UART_C4              0x0a
#define UART_C5              0x0b
#define UART_ED              0x0c
#define UART_MODEM           0x0d
#define UART_IR              0x0e
/* reserved 0x0f */
#define UART_PFIFO           0x10
#define UART_CFIFO           0x11
#define UART_SFIFO           0x12
#define UART_TWFIFO          0x13
#define UART_TCFIFO          0x14
#define UART_RWFIFO          0x15
#define UART_RCFIFO          0x16
/* reserved 0x17 */
#define UART_C7816           0x18
#define UART_IE7816          0x19
#define UART_IS7816          0x1a
#define UART_WP7816T0        0x1b
#define UART_WP7816T1        0x1b
#define UART_WN7816          0x1c
#define UART_WF7816          0x1d
#define UART_ET7816          0x1e
#define UART_TL7816          0x1f

#define UART_C2_TE_MASK      0x8
#define UART_C2_RE_MASK      0x4
#define UART_C4_BRFA_MASK    0x1f
#define UART_C4_BRFA_SHIFT   0
#define UART_S1_RDRF_MASK    0x20
#define UART_S1_TDRE_MASK    0x80
#define UART_S1_TC_MASK      0x40
#define UART_BDH_SBR_SHIFT   0
#define UART_BDH_SBR_MASK    0x1f
#define UART_BDL_SBR_MASK    0xff
#define UART_BDH_SBR         ((0x1f<<UART_BDH_SBR_SHIFT) & UART_BDH_SBR_MASK)
#define UART_C4_BRFA         ((0x1f<<UART_C4_BRFA_SHIFT) & UART_C4_BRFA_MASK)
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
#define WDOG_BASE           0x40052000
#define WDOG_STCTRLH        0x00
#define WDOG_STCTRLL        0x02
#define WDOG_TOVALH         0x04
#define WDOG_TOVALL         0x06
#define WDOG_WINH           0x08
#define WDOG_WINL           0x0a
#define WDOG_REFRESH        0x0c
#define WDOG_UNLOCK         0x0e
#define WDOG_TMROUTH        0x10
#define WDOG_TMROUTL        0x12
#define WDOG_RSTCNT         0x14
#define WDOG_PRESC          0x16
#define WDOG_UNLOCK_VALUE   0xc520
#define WDOG_UNLOCK_CMLETE  0xd928
#define WDOG_DISABLE        (~0x1)


#endif /* __TK_SYSDEF_DEPEND_H__ */
