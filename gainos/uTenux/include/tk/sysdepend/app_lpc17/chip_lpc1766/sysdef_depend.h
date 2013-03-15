/*
 *------------------------------------------------------------------------------
 *    Include/tk
 *
 *    Copyright (C) 2008-2012 by Dalian uLoong C&S Co.,Ltd. All rights reserved.
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
 *    Version:    1.3.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : sysdef_depend.h
 *	 Create Date    : 2011/02/11-2012/8/17
 *	 Author	        : Wangxd-Wangxd
 *	 Description    : register Definition about cpu(tk/LPC1766).
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
#define FAC_BASE             0x400fc000
#define FAC_FLASHCFG         0x00
#define FAC_FLASHCFG_VAL     0x0000503a

/*
 * System Control
 */
#define SC_BASE            0x400fc000
#define SC_SCS             0x1a0             /* system control and status */

/*
 * Clocking and Power Control
 */
#define CPC_BASE           0x400fc000
#define CPC_PLL0CON        0x080
#define CPC_PLL0CFG        0x084
#define CPC_PLL0STAT       0x088
#define CPC_PLL0FEED       0x08c
/* reserved */
#define CPC_PLL1CON        0x0a0
#define CPC_PLL1CFG        0x0a4
#define CPC_PLL1STAT       0x0a8
#define CPC_PLL1FEED       0x0ac
/* reserved */
#define CPC_PCON           0x0c0
#define CPC_PCONP          0x0c4
/* reserved */
#define CPC_CCLKCFG        0x104
#define CPC_USBCLKCFG      0x108
#define CPC_CLKSRCSEL      0x10c
/* reserved */
#define CPC_PCLKSEL0       0x1a8
#define CPC_PCLKSEL1       0x1ac
/* reserved */
#define CPC_CLKOUTCFG      0x1c8


/*
 *  General Purpose Input/Output (GPIO)
 */
#define PCB_BASE           0x4002c000       /* pin connect block */
#define GPIO0_BASE         0x2009c000
#define GPIO1_BASE         0x2009c020
#define GPIO2_BASE         0x2009c040
#define GPIO3_BASE         0x2009c060
#define GPIO4_BASE         0x2009c080
#define PCB_PINSEL0        0x00
#define PCB_PINSEL1        0x04
#define PCB_PINSEL2        0x08
#define PCB_PINSEL3        0x0c
#define PCB_PINSEL4        0x10
#define PCB_PINSEL5        0x14
#define PCB_PINSEL6        0x18
#define PCB_PINSEL7        0x1c
#define PCB_PINSEL8        0x20
#define PCB_PINSEL9        0x24
#define PCB_PINSEL10       0x28
#define PCB_PINMODE0       0x40
#define PCB_PINMODE1       0x44
#define PCB_PINMODE2       0x48
#define PCB_PINMODE3       0x4c
#define PCB_PINMODE4       0x50
#define PCB_PINMODE5       0x54
#define PCB_PINMODE6       0x58
#define PCB_PINMODE7       0x5c
#define PCB_PINMODE8       0x60
#define PCB_PINMODE9       0x64
#define PCB_PINMODE_OD0    0x68
#define PCB_PINMODE_OD1    0x6c
#define PCB_PINMODE_OD2    0x70
#define PCB_PINMODE_OD3    0x74
#define PCB_PINMODE_OD4    0x78
#define PCB_I2CPADCFG      0x7c
#define GPIO_FIODIR        0x00
#define GPIO_FIOMASK       0x10
#define GPIO_FIOPIN        0x14
#define GPIO_FIOSET        0x18
#define GPIO_FIOCLR        0x1c

/*
 * Nested Vectored Interrupt Controller
 */

/* Peripheral Identifiers Define */
#define PI_WDT               0         /* Watchdog Interrupt (WDINT) */
#define PI_TIMER0            1         /* Match 0 - 1 (MR0, MR1)
                                          Capture 0 - 1 (CR0, CR1)   */
#define PI_TIMER1            2         /* Match 0 - 2 (MR0, MR1, MR2)
                                          Capture 0 - 1 (CR0, CR1)   */
#define PI_TIMER2            3         /* Match 0-3
                                          Capture 0-1 */
#define PI_TIMER3            4         /* Match 0-3
                                          Capture 0-1 */
#define PI_UART0             5         /* Rx Line Status (RLS)
                                          Transmit Holding Register Empty (THRE)
                                          Rx Data Available (RDA)
                                          Character Time-out Indicator (CTI)
                                          End of Auto-Baud (ABEO)
                                          Auto-Baud Time-Out (ABTO) */
#define PI_UART1             6         /* Rx Line Status (RLS)
                                          Transmit Holding Register Empty (THRE)
                                          Rx Data Available (RDA)
                                          Character Time-out Indicator (CTI)
                                          Modem Control Change
                                          End of Auto-Baud (ABEO)
                                          Auto-Baud Time-Out (ABTO) */
#define PI_UART2             7        /*  Rx Line Status (RLS)
                                          Transmit Holding Register Empty (THRE)
                                          Rx Data Available (RDA)
                                          Character Time-out Indicator (CTI)
                                          End of Auto-Baud (ABEO)
                                          Auto-Baud Time-Out (ABTO) */
#define PI_UART3             8         /* Rx Line Status (RLS)
                                          Transmit Holding Register Empty (THRE)
                                          Rx Data Available (RDA)
                                          Character Time-out Indicator (CTI)
                                          End of Auto-Baud (ABEO)
                                          Auto-Baud Time-Out (ABTO) */
#define PI_PWM1              9         /* Match 0 - 6 of PWM1
                                          Capture 0-1 of PWM1 */
#define PI_I2C0             10         /* SI (state change) */
#define PI_I2C1             11         /* SI (state change) */
#define PI_I2C2             12         /* SI (state change) */
#define PI_SPI              13         /* SPI Interrupt Flag (SPIF)
                                          Mode Fault (MODF) */
#define PI_SSP0             14         /* Tx FIFO half empty of SSP0
                                          Rx FIFO half full of SSP0
                                          Rx Timeout of SSP0
                                          Rx Overrun of SSP0 */
#define PI_SSP1             15         /* Tx FIFO half empty of SSP1
                                          Rx FIFO half full of SSP1
                                          Rx Timeout of SSP1
                                          Rx Overrun of SSP1 */
#define PI_PLL0             16         /* PLL0 Lock (PLOCK0) */
#define PI_RTC              17         /* Counter Increment (RTCCIF)
                                          Alarm (RTCALF) */
#define PI_EINT0            18         /* External Interrupt 0 (EINT0) */
#define PI_EINT1            19         /* External Interrupt 1 (EINT1) */
#define PI_EINT2            20         /* External Interrupt 2 (EINT2) */
#define PI_EINT3            21         /* External Interrupt 3 (EINT3)
                                          Note: EINT3 channel is shared with GPIO interrupts */
#define PI_ADC              22         /* A/D Converter end of conversion */
#define PI_BOD              23         /* Brown Out detect */
#define PI_USB              24         /* USB_INT_REQ_LP
                                          USB_INT_REQ_HP
                                          USB_INT_REQ_DMA */
#define PI_CAN              25         /* CAN Common
                                          CAN 0 Tx
                                          CAN 0 Rx
                                          CAN 1 Tx
                                          CAN 1 Rx */
#define PI_DMA              26         /* IntStatus of DMA channel 0
                                          IntStatus of DMA channel 1 */
#define PI_I2S              27         /* irq
                                          dmareq1
                                          dmareq2 */
#define PI_ENET             28         /* WakeupInt
                                          SoftInt
                                          TxDoneInt
                                          TxFinishedInt
                                          TxErrorInt
                                          TxUnderrunInt
                                          RxDoneInt
                                          RxFinishedInt
                                          RxErrorInt
                                          RxOverrunInt */
#define PI_RIT              29         /* OSTINT */
#define PI_MCPWM            30         /* IPER[2:0]
                                          IPW[2:0]
                                          ICAP[2:0]
                                          FES */
#define PI_QEI              31         /* INX_Int
                                          TIM_Int
                                          VELC_Int
                                          DIR_Int
                                          ERR_Int
                                          ENCLK_Int
                                          POS0_Int
                                          POS1_Int
                                          POS2_Int
                                          REV_Int
                                          POS0REV_Int
                                          POS1REV_Int
                                          POS2REV_Int */
#define PI_PLL1             32         /* PLL1 Lock (PLOCK1) */
#define PI_USB              33         /* USB_NEED_CLK */
#define PI_CAN              34         /* CAN1WAKE, CAN2WAKE */
#define PI_INT_NUMBER       35         /* Interrupt vectors Number */


/* Software interrupt number for micro T-Kernel */
#define SWI_SVC		        51         /* micro T-Kernel system call/extension SVC    */
#define SWI_RETINT	        52         /* tk_ret_int() system call,equal (SWI_SVC+1)  */
#define SWI_DEBUG	        53         /* Debugger support function,equal (SWI_SVC+2) */

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
#define UART1_BASE          0x40010000
#define UART_U1RBR          0x00            /* Receiver Buffer Register               */
#define UART_U1THR          0x00            /* Transmit Holding Register              */
#define UART_U1DLL          0x00            /* Divisor Latch LSB                      */
#define UART_U1DLM          0x04            /* Divisor Latch MSB                      */
#define UART_U1IER          0x04            /* Interrupt Enable Register              */
#define UART_U1IIR          0x08            /* Interrupt ID Register                  */
#define UART_U1FCR          0x08            /* FIFO Control Register                  */
#define UART_U1LCR          0x0c            /* Line Control Register                  */
#define UART_U1MCR          0x10            /* Modem Control Register                 */
#define UART_U1LSR          0x14            /* Line Status Register                   */
#define UART_U1MSR          0x18            /* Modem Status Register                  */
#define UART_U1SCR          0x1c            /* Scratch Pad Register                   */
#define UART_U1ACR          0x20            /* Auto-baud Control Register             */
#define UART_U1FDR          0x28            /* Fractional Divider Register            */
#define UART_U1TER          0x30            /* Transmit Enable Register               */
#define UART_U1RS485CTRL    0x4c            /* RS-485/EIA-485 Control                 */
#define UART_U1ADRMATCH     0x50            /* RS-485/EIA-485 address match           */
#define UART_U1RS485Dly     0x54            /* RS-485/EIA-485 direction control delay */


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
#define WDT_BASE        0x40000000
#define WDT_WDMOD       0x00
#define WDT_WDTC        0x04
#define WDT_WDFEED      0x08
#define WDT_WDTV        0x0c
#define WDT_WDCLDSEL    0x10


#endif /* __TK_SYSDEF_DEPEND_H__ */
