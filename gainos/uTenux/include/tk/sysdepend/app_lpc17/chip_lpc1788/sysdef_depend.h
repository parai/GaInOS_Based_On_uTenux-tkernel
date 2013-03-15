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
 *	 Create Date    : 2011/02/11-2013/1/24
 *	 Author	        : Wangxd-zhangzl
 *	 Description    : register Definition about cpu(tk/LPC1788).
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
#define CPC_EMCCLKSEL      0x100
#define CPC_CCLKSEL        0x104
#define CPC_USBCLKSEL      0x108
#define CPC_CLKSRCSEL      0x10c
/* reserved */
#define CPC_PCLKSEL        0x1a8
/* reserved */
#define CPC_CLKOUTCFG      0x1c8

#define CPC_USBCLKSEL_VAL  (0x00000001|(0x02<<8))
#define CPC_EMCCLKSEL_VAL  0x00000001
#define CPC_PCLKSEL_VAL    0x00000002

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
 * GPIO CONTROL
 */
#define IOCONP0_BASE       0x4002c000
#define IOCONP1_BASE       0x4002c080
#define IOCONP2_BASE       0x4002c100
#define IOCONP3_BASE       0x4002c180
#define IOCONP4_BASE       0x4002c200
#define IOCONP5_BASE       0x4002c280
#define IOCONP_00          0x00
#define IOCONP_01          0x04
#define IOCONP_02          0x08
#define IOCONP_03          0x0c
#define IOCONP_04          0x10
#define IOCONP_05          0x14
#define IOCONP_06          0x18
#define IOCONP_07          0x1c
#define IOCONP_08          0x20
#define IOCONP_09          0x24
#define IOCONP_10          0x28
#define IOCONP_11          0x2c
#define IOCONP_12          0x30
#define IOCONP_13          0x34
#define IOCONP_14          0x38
#define IOCONP_15          0x3c
#define IOCONP_16          0x40
#define IOCONP_17          0x44
#define IOCONP_18          0x48
#define IOCONP_19          0x4c
#define IOCONP_20          0x50
#define IOCONP_21          0x54
#define IOCONP_22          0x58
#define IOCONP_23          0x5c
#define IOCONP_24          0x60
#define IOCONP_25          0x64
#define IOCONP_26          0x68
#define IOCONP_27          0x6c
#define IOCONP_28          0x70
#define IOCONP_29          0x74
#define IOCONP_30          0x78
#define IOCONP_31          0x7c


/*
 * Nested Vectored Interrupt Controller
 */

/* Peripheral Identifiers Define */
#define PI_WDT                    0        /* Watchdog Timer Interrupt               */
#define PI_TIMER0                 1        /* Timer0 Interrupt                       */
#define PI_TIMER1                 2        /* Timer1 Interrupt                       */
#define PI_TIMER2                 3        /* Timer2 Interrupt                       */
#define PI_TIMER3                 4        /* Timer3 Interrupt                       */
#define PI_UART0                  5        /* UART0 Interrupt                        */
#define PI_UART1                  6        /* UART1 Interrupt                        */
#define PI_UART2                  7        /* UART2 Interrupt                        */
#define PI_UART3                  8        /* UART3 Interrupt                        */
#define PI_PWM1                   9        /* PWM1 Interrupt                         */
#define PI_I2C0                   10       /* I2C0 Interrupt                         */
#define PI_I2C1                   11       /* I2C1 Interrupt                         */
#define PI_I2C2                   12       /* I2C2 Interrupt                         */
#define PI_Reserved0              13       /* Reserved                               */
#define PI_SSP0                   14       /* SSP0 Interrupt                         */
#define PI_SSP1                   15       /* SSP1 Interrupt                         */
#define PI_PLL0                   16       /* PLL0 Lock (Main PLL) Interrupt         */
#define PI_RTC                    17       /* Real Time Clock Interrupt              */
#define PI_EINT0                  18       /* External Interrupt 0 Interrupt         */
#define PI_EINT1                  19       /* External Interrupt 1 Interrupt         */
#define PI_EINT2                  20       /* External Interrupt 2 Interrupt         */
#define PI_EINT3                  21       /* External Interrupt 3 Interrupt         */
#define PI_ADC                    22       /* A/D Converter Interrupt                */
#define PI_BOD                    23       /* Brown-Out Detect Interrupt             */
#define PI_USB                    24       /* USB Interrupt                          */
#define PI_CAN                    25       /* CAN Interrupt                          */
#define PI_DMA                    26       /* General Purpose DMA Interrupt          */
#define PI_I2S                    27       /* I2S Interrupt                          */
#define PI_ENET                   28       /* Ethernet Interrupt                     */
#define PI_MCI                    29       /* SD/MMC card I/F Interrupt              */
#define PI_MCPWM                  30       /* Motor Control PWM Interrupt            */
#define PI_QEI                    31       /* Quadrature Encoder Interface Interrupt */
#define PI_PLL1                   32       /* PLL1 Lock (USB PLL) Interrupt          */
#define PI_USBActivity            33       /* USB Activity interrupt                 */
#define PI_CANActivity            34       /* CAN Activity interrupt                 */
#define PI_UART4                  35       /* UART4 Interrupt                        */
#define PI_SSP2                   36       /* SSP2 Interrupt                         */
#define PI_LCD                    37       /* LCD Interrupt                          */
#define PI_GPIO                   38       /* GPIO Interrupt                         */
#define PI_PWM0                   39       /* PWM0 Interrupt                         */
#define PI_EEPROM                 40       /* EEPROM Interrupt                       */
#define PI_INT_NUMBER             41       /* Interrupt vectors Number */

/* Software interrupt number for micro T-Kernel */
#define SWI_SVC		              58   /* micro T-Kernel system call/extension SVC */
#define SWI_RETINT	              59   /* tk_ret_int() system call,equal (SWI_SVC+1) */
#define SWI_DEBUG	              60   /* Debugger support function,equal (SWI_SVC+2) */

/* NVIC Register Define  */
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
#define UART0_BASE        0x4000c000
#define UART1_BASE        0x40010000
#define UART2_BASE        0x40098000
#define UART3_BASE        0x4009c000
#define UART4_BASE        0x400a4000
#define UART_RBR          0x00            /* Receiver Buffer Register               */
#define UART_THR          0x00            /* Transmit Holding Register              */
#define UART_DLL          0x00            /* Divisor Latch LSB                      */
#define UART_DLM          0x04            /* Divisor Latch MSB                      */
#define UART_IER          0x04            /* Interrupt Enable Register              */
#define UART_IIR          0x08            /* Interrupt ID Register                  */
#define UART_FCR          0x08            /* FIFO Control Register                  */
#define UART_LCR          0x0c            /* Line Control Register                  */
#define UART_MCR          0x10            /* Modem Control Register                 */
#define UART_LSR          0x14            /* Line Status Register                   */
#define UART_MSR          0x18            /* Modem Status Register                  */
#define UART_SCR          0x1c            /* Scratch Pad Register                   */
#define UART_ACR          0x20            /* Auto-baud Control Register             */
#define UART_FDR          0x28            /* Fractional Divider Register            */
#define UART_TER          0x30            /* Transmit Enable Register               */
#define UART_RS485CTRL    0x4c            /* RS-485/EIA-485 Control                 */
#define UART_ADRMATCH     0x50            /* RS-485/EIA-485 address match           */
#define UART_RS485Dly     0x54            /* RS-485/EIA-485 direction control delay */


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


/*
 *  LCD CONTROL
 */
#define LCD_CFG         0x400fc1b8
#define LCD_BASE        0x20088000
#define LCD_TIMH        0x000
#define LCD_TIMV        0x004
#define LCD_POL         0x008
#define LCD_LE          0x00c
#define LCD_UPBASE      0x010
#define LCD_LPBASE      0x014
#define LCD_CTRL        0x018
#define LCD_INTMSK      0x01c
#define LCD_INTRAW      0x020
#define LCD_INTSTAT     0x024
#define LCD_INTCLR      0x028
#define LCD_UPCURR      0x02c
#define LCD_LPCURR      0x030
/* reserved   */
#define LCD_PAL         0x200
/* reserved   */
#define CRSR_IMG        0x800
#define CRSR_CTRL       0xc00
#define CRSR_CFG        0xc04
#define CRSR_PAL0       0xc08
#define CRSR_PAL1       0xc0c
#define CRSR_XY         0xc10
#define CRSR_CLIP       0xc14
/* reserved   */
#define CRSR_INTMSK     0xc20
#define CRSR_INTCLR     0xc24
#define CRSR_INTRAW     0xc28
#define CRSR_INTSTAT    0xc2c


#endif /* __TK_SYSDEF_DEPEND_H__ */

