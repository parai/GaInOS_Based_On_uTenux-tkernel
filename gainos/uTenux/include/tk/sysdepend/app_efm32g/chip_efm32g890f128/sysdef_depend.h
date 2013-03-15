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
 *	 Create Date    : 2011/02/11-2013/1/16
 *	 Author	        : Wangxd-dengjk
 *	 Description    : register Definition about cpu(tk/EFM32G890F128).
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

/* ------------------------------------------------------------------------ */


/* ------------------------------------------------------------------------ */

/*
 * Internal flash rom Controller
 */
#define MSC_BASE              0x400c0000
#define MSC_CTRL              0x00
#define MSC_READCTRL          0x04
#define MSC_WRITECTRL         0x08
#define MSC_WRITECMD          0x0c
#define MSC_ADDRB             0x10
#define MSC_WDATA             0x18
#define MSC_STATUS            0x1c
#define MSC_IF                0x2c
#define MSC_IFS               0x30
#define MSC_IFC               0x34
#define MSC_IEN               0x38
#define MSC_LOCK              0x3c
#define MSC_LOCK_UNLOCKVALUE  0x1b71     /* unlock MSC register */
#define MSC_LOCK_LOCKVALUE    0x0        /* lock MSC register   */

/*
 * Clock Management Controller Unit
 */
#define CMU_BASE              0x400c8000
#define CMU_CTRL              0x00
#define CMU_HFCORECLKDIV      0x04
#define CMU_HFPERCLKDIV       0x08
#define CMU_HFRCOCTRL         0x0c
#define CMU_LFRCOCTRL         0x10
#define CMU_AUXHFRCOCTRL      0x14
#define CMU_CALCTRL           0x18
#define CMU_CALCNT            0x1c
#define CMU_OSCENCMD          0x20
#define CMU_CMD               0x24
#define CMU_LFCLKSEL          0x28
#define CMU_STATUS            0x2c
#define CMU_IF                0x30
#define CMU_IFS               0x34
#define CMU_IFC               0x38
#define CMU_IEN               0x3c
#define CMU_HFCORECLKEN0      0x40
#define CMU_HFPERCLKEN0       0x44
#define CMU_SYNCBUSY          0x50
#define CMU_FREEZE            0x54
#define CMU_LFACLKEN0         0x58
#define CMU_LFBCLKEN0         0x60
#define CMU_LFAPRESC0         0x68
#define CMU_LFBPRESC0         0x70
#define CMU_PCNTCTRL          0x78
#define CMU_LCDCTRL           0x7C
#define CMU_ROUTE             0x80
#define CMU_LOCK              0x84
#define CMU_LOCK_UNLOCKVALUE  0x580e     /* unlock CMU register  */
#define CMU_LOCK_LOCKVALUE    0x0        /* lock CMU register    */

/*
 *  General Parallel IO
 */
#define GPIO_BASE             0x40006000
#define GPIO_PA_BASE          0x40006000
#define GPIO_PB_BASE          0x40006024
#define GPIO_PC_BASE          0x40006048
#define GPIO_PD_BASE          0x4000606c
#define GPIO_PE_BASE          0x40006090
#define GPIO_PF_BASE          0x400060b4
#define GPIO_CTRL             0x00
#define GPIO_MODEL            0x04
#define GPIO_MODEH            0x08
#define GPIO_DOUT             0x0c
#define GPIO_DOUTSET          0x10
#define GPIO_DOUTCLR          0x14
#define GPIO_DOUTTGL          0x18
#define GPIO_DIN              0x1c
#define GPIO_PINLOCKN         0x20
/* reserved  0x0D8~0x0FF */
#define GPIO_EXTIPSELL        0x100
#define GPIO_EXTIPSELH        0x104
#define GPIO_EXTIRISE         0x108
#define GPIO_EXTIFALL         0x10c
#define GPIO_IEN              0x110
#define GPIO_IF               0x114
#define GPIO_IFS              0x118
#define GPIO_IFC              0x11c
#define GPIO_ROUTE            0x120
#define GPIO_INSENSE          0x124
#define GPIO_LOCK             0x128
#define GPIO_LOCK_UNLOCKVALUE 0xa534
#define GPIO_LOCK_LOCKVALUE   0x0

/*
 * Nested Vectored Interrupt Controller
 */

/* Peripheral Identifiers Define            */
#define PI_DMA             0
#define PI_GPIO_EVEN       1
#define PI_TIMER0          2
#define PI_USART0_RX       3
#define PI_USART0_TX       4
#define PI_ACMP0/ACMP1     5
#define PI_ADC0            6
#define PI_DAC0            7
#define PI_I2C0            8
#define PI_GPIO_ODD        9
#define PI_TIMER1          10
#define PI_TIMER2          11
#define PI_USART1_RX       12
#define PI_USART1_TX       13
#define PI_USART2_RX       14
#define PI_USART2_TX       15
#define PI_UART0_RX        16
#define PI_UART0_TX        17
#define PI_LEUART0         18
#define PI_LEUART1         19
#define PI_LETIMER0        20
#define PI_PCNT0           21
#define PI_PCNT1           22
#define PI_PCNT2           23
#define PI_RTC             24
#define PI_CMU             25
#define PI_VCMP            26
#define PI_LCD             27
#define PI_MSC             28
#define PI_AES             29
#define PI_INT_NUMBER      30   /* Interrupt vectors Number*/

/* Software interrupt number for micro T-Kernel */
#define SWI_SVC		                37   /* micro T-Kernel system call/extension SVC */
#define SWI_RETINT	                38   /* tk_ret_int() system call,equal (SWI_SVC+1) */
#define SWI_DEBUG	                39   /* Debugger support function,equal (SWI_SVC+2) */

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
#define USART0_BASE       0x4000c000
#define USART1_BASE       0x4000c400
#define USART2_BASE       0x4000c800
#define USART_CTRL        0x00
#define USART_FRAME       0x04
#define USART_TRIGCTRL    0x08
#define USART_CMD         0x0c
#define USART_STATUS      0x10
#define USART_CLKDIV      0x14
#define USART_RXDATAX     0x18
#define USART_RXDATA      0x1c
#define USART_RXDOUBLEX   0x20
#define USART_RXDOUBLE    0x24
#define USART_RXDATAXP    0x28
#define USART_RXDOUBLEXP  0x2c
#define USART_TXDATAX     0x30
#define USART_TXDATA      0x34
#define USART_TXDOUBLEX   0x38
#define USART_TXDOUBLE    0x3c
#define USART_IF          0x40
#define USART_IFS         0x44
#define USART_IFC         0x48
#define USART_IEN         0x4c
#define USART_IRCTRL      0x50
#define USART_ROUTE       0x54
/*
 * UART0
 */
#define UART0_BASE        0x4000e000

#define UART_CTRL         0x00
#define UART_FRAME        0x04
#define UART_TRIGCTRL     0x08
#define UART_CMD          0x0c
#define UART_STATUS       0x10
#define UART_CLKDIV       0x14
#define UART_RXDATAX      0x18
#define UART_RXDATA       0x1c
#define UART_RXDOUBLEX    0x20
#define UART_RXDOUBLE     0x24
#define UART_RXDATAXP     0x28
#define UART_RXDOUBLEXP   0x2c
#define UART_TXDATAX      0x30
#define UART_TXDATA       0x34
#define UART_TXDOUBLEX    0x38
#define UART_TXDOUBLE     0x3c
#define UART_IF           0x40
#define UART_IFS          0x44
#define UART_IFC          0x48
#define UART_IEN          0x4c
#define UART_IRCTRL       0x50
#define UART_ROUTE        0x54

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
#define WDOG_BASE             0x40088000
#define WDOG_CTRL             0x00
#define WDOG_CMD              0x04
#define WDOG_SYNCBUSY         0x08

#endif /* __TK_SYSDEF_DEPEND_H__ */
