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
 *	 Create Date    : 2011/02/11-2013/1/16
 *	 Author	        : Dengjk
 *	 Description    : register Definition about cpu(tk/LM4F232H5QD).
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
#define FLASH_BASE       		0x400fd000
#define FLASH_O_FMA             0x00
#define FLASH_O_FMD             0x04
#define FLASH_O_FMC             0x08
#define FLASH_O_FCRIS           0x0c
#define FLASH_O_FCIM            0x10
#define FLASH_O_FCMISC          0x14
#define FLASH_O_FMC2            0x20
#define FLASH_O_FWBVAL          0x30


/*
 * System Control
 */
#define SYSCTL_BASE    			0x400fe000
#define SYSCTL_O_DID0  			0x000  /* Device Identification 0   */
#define SYSCTL_O_DID1  			0x004  /* Device Identification 1  */
#define SYSCTL_O_DC0   			0x008  /*  Device Capabilities 0  */
#define SYSCTL_O_DC1   			0x010  /* Device Capabilities 1  */
#define SYSCTL_O_DC2   			0x014  /* Device Capabilities 2  */
#define SYSCTL_O_DC3   			0x018  /* Device Capabilities 3  */
#define SYSCTL_O_DC4   			0x01C  /* Device Capabilities 4  */
#define SYSCTL_O_DC5   			0x020  /* Device Capabilities 5  */
#define SYSCTL_O_DC6   			0x024  /* Device Capabilities 6  */
#define SYSCTL_O_DC7   			0x028  /* Device Capabilities 7  */
#define SYSCTL_O_DC8   			0x02C  /* Device Capabilities 8  */
#define SYSCTL_O_PBORCTL   		0x030  /* Brown-Out Reset Control  */
#define SYSCTL_O_SRCR0     		0x040  /* Software Reset Control 0   */
#define SYSCTL_O_SRCR1     		0x044  /* Software Reset Control 1  */
#define SYSCTL_O_SRCR2     		0x048  /* Software Reset Control 2  */
#define SYSCTL_O_RIS       		0x050  /* Raw Interrupt Status  */
#define SYSCTL_O_IMC       		0x054  /* Interrupt Mask Control  */
#define SYSCTL_O_MISC      		0x058  /* Masked Interrupt Status and Clear  */
#define SYSCTL_O_RESC      		0x05C  /*  Reset Cause */
#define SYSCTL_O_RCC       		0x060  /* Run-Mode Clock Configuration  */
#define SYSCTL_O_GPIOHBCTL 		0x06C  /* GPIO High-Performance Bus Control  */
#define SYSCTL_O_RCC2      		0x070  /*  Run-Mode Clock Configuration 2  */
#define SYSCTL_O_MOSCCTL   		0x07C  /* Main Oscillator Control  */
#define SYSCTL_O_RCGC0     		0x100  /* Run Mode Clock Gating Control Register 0  */
#define SYSCTL_O_RCGC1     		0x104  /*   Run Mode Clock Gating Control Register 1 */
#define SYSCTL_O_RCGC2     		0x108  /*  Run Mode Clock Gating Control Register 2  */
#define SYSCTL_O_SCGC0     		0x110  /* Sleep Mode Clock Gating Control Register 0  */
#define SYSCTL_O_SCGC1     		0x114  /*  Sleep Mode Clock Gating Control Register 1  */
#define SYSCTL_O_SCGC2     		0x118  /* Sleep Mode Clock Gating Control Register 2  */
#define SYSCTL_O_DCGC0        	0x120  /* Deep Sleep Mode Clock Gating Control Register 0  */
#define SYSCTL_O_DCGC1        	0x124  /* Deep-Sleep Mode Clock Gating Control Register 1  */
#define SYSCTL_O_DCGC2        	0x128  /* Deep Sleep Mode Clock Gating Control Register 2  */
#define SYSCTL_O_DSLPCLKCFG   	0x144  /* Deep Sleep Clock Configuration   */
#define SYSCTL_O_SYSPROP      	0x14C  /*  System Properties  */
#define SYSCTL_O_PIOSCCAL     	0x150  /* Precision Internal Oscillator Calibration  */
#define SYSCTL_O_PIOSCSTAT    	0x154  /* Precision Internal Oscillator Statistics   */
#define SYSCTL_O_PLLFREQ0     	0x160  /* PLL Frequency 0   */
#define SYSCTL_O_PLLFREQ1     	0x164  /* PLL Frequency 1   */
#define SYSCTL_O_PLLSTAT      	0x168  /* PLL Status   */
#define SYSCTL_O_DC9          	0x190  /* Device Capabilities 9  */
#define SYSCTL_O_NVMSTAT      	0x1A0  /* Non-Volatile Memory Information   */

/* -------- SYSCTL_RIS  SYSCTL Register          -------- */
#define SYSCTL_RIS_MOSCPUPRIS   0x00000100  /* MOSC Power Up Raw Interrupt Status */
#define SYSCTL_RIS_USBPLLLRIS   0x00000080  /* USB PLL Lock Raw Interrupt Status  */
#define SYSCTL_RIS_PLLLRIS      0x00000040  /* PLL Lock Raw Interrupt Status      */
#define SYSCTL_RIS_BORRIS       0x00000002  /* Brown-Out Reset Raw Interrupt Status */

/* -------- SYSCTL_MISC  SYSCTL Register         -------- */
#define SYSCTL_MISC_MOSCPUPMIS  0x00000100  /* MOSC Power Up Masked Interrupt Status */
#define SYSCTL_MISC_USBPLLLMIS  0x00000080  /* USB PLL Lock Masked Interrupt Status  */
#define SYSCTL_MISC_PLLLMIS     0x00000040  /* PLL Lock Masked Interrupt Status      */
#define SYSCTL_MISC_BORMIS      0x00000002  /* BOR Masked Interrupt Status  */

/* -------- SYSCTL_RCC  SYSCTL Register          -------- */
#define SYSCTL_RCC_ACG          0x08000000  /* Auto Clock Gating            */
#define SYSCTL_RCC_SYSDIV_M     0x07800000  /* System Clock Divisor         */
#define SYSCTL_RCC_SYSDIV_2     0x00800000  /* System clock /2              */
#define SYSCTL_RCC_SYSDIV_3     0x01000000  /* System clock /3              */
#define SYSCTL_RCC_SYSDIV_4     0x01800000  /* System clock /4              */
#define SYSCTL_RCC_SYSDIV_5     0x02000000  /* System clock /5              */
#define SYSCTL_RCC_SYSDIV_6     0x02800000  /* System clock /6              */
#define SYSCTL_RCC_SYSDIV_7     0x03000000  /* System clock /7              */
#define SYSCTL_RCC_SYSDIV_8     0x03800000  /* System clock /8              */
#define SYSCTL_RCC_SYSDIV_9     0x04000000  /* System clock /9              */
#define SYSCTL_RCC_SYSDIV_10    0x04800000  /* System clock /10             */
#define SYSCTL_RCC_SYSDIV_11    0x05000000  /* System clock /11             */
#define SYSCTL_RCC_SYSDIV_12    0x05800000  /* System clock /12             */
#define SYSCTL_RCC_SYSDIV_13    0x06000000  /* System clock /13             */
#define SYSCTL_RCC_SYSDIV_14    0x06800000  /* System clock /14             */
#define SYSCTL_RCC_SYSDIV_15    0x07000000  /* System clock /15             */
#define SYSCTL_RCC_SYSDIV_16    0x07800000  /* System clock /16             */
#define SYSCTL_RCC_USESYSDIV    0x00400000  /* Enable System Clock Divider  */
#define SYSCTL_RCC_USEPWMDIV    0x00100000  /* Enable PWM Clock Divisor     */
#define SYSCTL_RCC_PWMDIV_M     0x000E0000  /* PWM Unit Clock Divisor       */
#define SYSCTL_RCC_PWMDIV_2     0x00000000  /* PWM clock /2                 */
#define SYSCTL_RCC_PWMDIV_4     0x00020000  /* PWM clock /4                 */
#define SYSCTL_RCC_PWMDIV_8     0x00040000  /* PWM clock /8                 */
#define SYSCTL_RCC_PWMDIV_16    0x00060000  /* PWM clock /16                */
#define SYSCTL_RCC_PWMDIV_32    0x00080000  /* PWM clock /32                */
#define SYSCTL_RCC_PWMDIV_64    0x000A0000  /* PWM clock /64                */
#define SYSCTL_RCC_PWRDN        0x00002000  /* PLL Power Down               */
#define SYSCTL_RCC_OEN          0x00001000  /* PLL Output Enable            */
#define SYSCTL_RCC_BYPASS       0x00000800  /* PLL Bypass                   */
#define SYSCTL_RCC_XTAL_M       0x000007C0  /* Crystal Value                */
#define SYSCTL_RCC_XTAL_1MHZ    0x00000000  /* 1 MHz                        */
#define SYSCTL_RCC_XTAL_1_84MHZ 0x00000040  /* 1.8432 MHz                   */
#define SYSCTL_RCC_XTAL_2MHZ    0x00000080  /* 2 MHz                        */
#define SYSCTL_RCC_XTAL_2_45MHZ 0x000000C0  /* 2.4576 MHz                   */
#define SYSCTL_RCC_XTAL_3_57MHZ 0x00000100  /* 3.579545 MHz                 */
#define SYSCTL_RCC_XTAL_3_68MHZ 0x00000140  /* 3.6864 MHz                   */
#define SYSCTL_RCC_XTAL_4MHZ    0x00000180  /* 4 MHz                        */
#define SYSCTL_RCC_XTAL_4_09MHZ 0x000001C0  /* 4.096 MHz                    */
#define SYSCTL_RCC_XTAL_4_91MHZ 0x00000200  /* 4.9152 MHz                   */
#define SYSCTL_RCC_XTAL_5MHZ    0x00000240  /* 5 MHz                        */
#define SYSCTL_RCC_XTAL_5_12MHZ 0x00000280  /* 5.12 MHz                     */
#define SYSCTL_RCC_XTAL_6MHZ    0x000002C0  /* 6 MHz                        */
#define SYSCTL_RCC_XTAL_6_14MHZ 0x00000300  /* 6.144 MHz                    */
#define SYSCTL_RCC_XTAL_7_37MHZ 0x00000340  /* 7.3728 MHz                   */
#define SYSCTL_RCC_XTAL_8MHZ    0x00000380  /* 8 MHz                        */
#define SYSCTL_RCC_XTAL_8_19MHZ 0x000003C0  /* 8.192 MHz                    */
#define SYSCTL_RCC_XTAL_10MHZ   0x00000400  /* 10 MHz                       */
#define SYSCTL_RCC_XTAL_12MHZ   0x00000440  /* 12 MHz                       */
#define SYSCTL_RCC_XTAL_12_2MHZ 0x00000480  /* 12.288 MHz                   */
#define SYSCTL_RCC_XTAL_13_5MHZ 0x000004C0  /* 13.56 MHz                    */
#define SYSCTL_RCC_XTAL_14_3MHZ 0x00000500  /* 14.31818 MHz                 */
#define SYSCTL_RCC_XTAL_16MHZ   0x00000540  /* 16 MHz                       */
#define SYSCTL_RCC_XTAL_16_3MHZ 0x00000580  /* 16.384 MHz                   */
#define SYSCTL_RCC_PLLVER       0x00000400  /* PLL Verification             */
#define SYSCTL_RCC_OSCSRC_M     0x00000030  /* Oscillator Source            */
#define SYSCTL_RCC_OSCSRC_MAIN  0x00000000  /* MOSC                         */
#define SYSCTL_RCC_OSCSRC_INT   0x00000010  /* IOSC                         */
#define SYSCTL_RCC_OSCSRC_INT4  0x00000020  /* IOSC/4                       */
#define SYSCTL_RCC_OSCSRC_30    0x00000030  /* 30 kHz                       */
#define SYSCTL_RCC_IOSCVER      0x00000008  /* Internal Oscil Verif Timer   */
#define SYSCTL_RCC_MOSCVER      0x00000004  /* Main Oscil Verif Timer       */
#define SYSCTL_RCC_IOSCDIS      0x00000002  /* Internal Oscillator Disable  */
#define SYSCTL_RCC_MOSCDIS      0x00000001  /* Main Oscillator Disable      */
#define SYSCTL_RCC_SYSDIV_S     23          /* Shift to the SYSDIV field    */
#define SYSCTL_RCC_PWMDIV_S     17          /* Shift to the PWMDIV field    */
#define SYSCTL_RCC_XTAL_S       6           /* Shift to the XTAL field      */
#define SYSCTL_RCC_OSCSRC_S     4           /* Shift to the OSCSRC field    */

/* -------- SYSCTL_RCC2  SYSCTL Register         -------- */
#define SYSCTL_RCC2_USERCC2     0x80000000  // Use RCC2
#define SYSCTL_RCC2_DIV400      0x40000000  // Divide PLL as 400 MHz vs. 200
                                            // MHz
#define SYSCTL_RCC2_SYSDIV2_M   0x1F800000  // System Clock Divisor 2
#define SYSCTL_RCC2_SYSDIV2_3   0x00800000  // System clock /3
#define SYSCTL_RCC2_SYSDIV2_5   0x01000000  // System clock /5
#define SYSCTL_RCC2_SYSDIV2_7   0x01800000  // System clock /7
#define SYSCTL_RCC2_SYSDIV2_9   0x02000000  // System clock /9
#define SYSCTL_RCC2_SYSDIV2_11  0x02800000  // System clock /11
#define SYSCTL_RCC2_SYSDIV2_13  0x03000000  // System clock /13
#define SYSCTL_RCC2_SYSDIV2LSB  0x00400000  // Additional LSB for SYSDIV2
#define SYSCTL_RCC2_USBPWRDN    0x00004000  // Power-Down USB PLL
#define SYSCTL_RCC2_PWRDN2      0x00002000  // Power-Down PLL 2
#define SYSCTL_RCC2_BYPASS2     0x00000800  // PLL Bypass 2
#define SYSCTL_RCC2_OSCSRC2_M   0x00000070  // Oscillator Source 2
#define SYSCTL_RCC2_OSCSRC2_MO  0x00000000  // MOSC
#define SYSCTL_RCC2_OSCSRC2_IO  0x00000010  // PIOSC
#define SYSCTL_RCC2_OSCSRC2_IO4 0x00000020  // PIOSC/4
#define SYSCTL_RCC2_OSCSRC2_30  0x00000030  // 30 kHz
#define SYSCTL_RCC2_OSCSRC2_419 0x00000060  // 4.194304 MHz
#define SYSCTL_RCC2_OSCSRC2_32  0x00000070  // 32.768 kHz
#define SYSCTL_RCC2_SYSDIV2_S   23

/* -------- SYSCTL_RCGC1      SYSCTL Register      -------- */
#define SYSCTL_RCGC1_EPI0       0x40000000  /* EPI0 Clock Gating            */
#define SYSCTL_RCGC1_I2S0       0x10000000  /* I2S0 Clock Gating            */
#define SYSCTL_RCGC1_COMP2      0x04000000  /* Analog Comp 2 Clock Gating   */
#define SYSCTL_RCGC1_COMP1      0x02000000  /* Analog Comp 1 Clock Gating   */
#define SYSCTL_RCGC1_COMP0      0x01000000  /* Analog Comp 0 Clock Gating   */
#define SYSCTL_RCGC1_TIMER3     0x00080000  /* Timer 3 Clock Gating Control */
#define SYSCTL_RCGC1_TIMER2     0x00040000  /* Timer 2 Clock Gating Control */
#define SYSCTL_RCGC1_TIMER1     0x00020000  /* Timer 1 Clock Gating Control */
#define SYSCTL_RCGC1_TIMER0     0x00010000  /* Timer 0 Clock Gating Control */
#define SYSCTL_RCGC1_I2C1       0x00004000  /* I2C1 Clock Gating Control    */
#define SYSCTL_RCGC1_I2C0       0x00001000  /* I2C0 Clock Gating Control    */
#define SYSCTL_RCGC1_QEI1       0x00000200  /* QEI1 Clock Gating Control    */
#define SYSCTL_RCGC1_QEI0       0x00000100  /* QEI0 Clock Gating Control    */
#define SYSCTL_RCGC1_SSI1       0x00000020  /* SSI1 Clock Gating Control    */
#define SYSCTL_RCGC1_SSI0       0x00000010  /* SSI0 Clock Gating Control    */
#define SYSCTL_RCGC1_UART2      0x00000004  /* UART2 Clock Gating Control   */
#define SYSCTL_RCGC1_UART1      0x00000002  /* UART1 Clock Gating Control   */
#define SYSCTL_RCGC1_UART0      0x00000001  /* UART0 Clock Gating Control   */

/* -------- SYSCTL_RCGC2      SYSCTL Register      -------- */
#define SYSCTL_RCGC2_EPHY0      0x40000000  /* PHY0 Clock Gating Control    */
#define SYSCTL_RCGC2_EMAC0      0x10000000  /* MAC0 Clock Gating Control    */
#define SYSCTL_RCGC2_USB0       0x00010000  /* USB0 Clock Gating Control    */
#define SYSCTL_RCGC2_UDMA       0x00002000  /* MicroDMA Clock Gating Control*/
#define SYSCTL_RCGC2_GPIOJ      0x00000100  /* Port J Clock Gating Control  */
#define SYSCTL_RCGC2_GPIOH      0x00000080  /* Port H Clock Gating Control  */
#define SYSCTL_RCGC2_GPIOG      0x00000040  /* Port G Clock Gating Control  */
#define SYSCTL_RCGC2_GPIOF      0x00000020  /* Port F Clock Gating Control  */
#define SYSCTL_RCGC2_GPIOE      0x00000010  /* Port E Clock Gating Control  */
#define SYSCTL_RCGC2_GPIOD      0x00000008  /* Port D Clock Gating Control  */
#define SYSCTL_RCGC2_GPIOC      0x00000004  /* Port C Clock Gating Control  */
#define SYSCTL_RCGC2_GPIOB      0x00000002  /* Port B Clock Gating Control  */
#define SYSCTL_RCGC2_GPIOA      0x00000001  /* Port A Clock Gating Control  */

/*
 *  Parallel IO
 */
#define GPIO_PORTA_BASE  0x40004000     /* Port A APB adress                  */
#define GPIO_PORTB_BASE  0x40005000     /* Port B APB adress                  */
#define GPIO_PORTC_BASE  0x40006000     /* Port C APB adress                  */
#define GPIO_PORTD_BASE  0x40007000     /* Port D APB adress                  */
#define GPIO_PORTE_BASE  0x40024000     /* Port E APB adress                  */
#define GPIO_PORTF_BASE  0x40025000     /* Port F APB adress                  */
#define GPIO_PORTG_BASE  0x40026000     /* Port G APB adress                  */
#define GPIO_PORTH_BASE  0x40027000     /* Port H APB adress                  */
#define GPIO_PORTJ_BASE  0x4003d000     /* Port J APB adress                  */

#define GPIO_O_DATA      0x000          /* Data register                      */
#define GPIO_O_DIR       0x400          /* Direction register                 */
#define GPIO_O_IS        0x404          /* Interrupt Sense register           */
#define GPIO_O_IBE       0x408          /* Interrupt Both Edges register      */
#define GPIO_O_IEV       0x40c          /* Interrupt Event register           */
#define GPIO_O_IM        0x410          /* Interrupt Mask register            */
#define GPIO_O_RIS       0x414          /* Raw Interrupt Status register      */
#define GPIO_O_MIS       0x418          /* Masked Interrupt Status register   */
#define GPIO_O_ICR       0x41c          /* Interrupt Clear register           */
#define GPIO_O_AFSEL     0x420          /* Alternate Function Select register */
#define GPIO_O_DR2R      0x500          /* 2-mA Drive Select register         */
#define GPIO_O_DR4R      0x504          /* 4-mA Drive Select register         */
#define GPIO_O_DR8R      0x508          /* 8-mA Drive Select register         */
#define GPIO_O_ODR       0x50c          /* Open Drain Select register         */
#define GPIO_O_PUR       0x510          /* Pull-Up Select register            */
#define GPIO_O_PDR       0x514          /* Pull-Down Select register          */
#define GPIO_O_SLR       0x518          /* Slew Rate Control Select register  */
#define GPIO_O_DEN       0x51c          /* Digital Enable register            */
#define GPIO_O_LOCK      0x520          /* Lock register                      */
#define GPIO_O_CR        0x524          /* Commit register                    */
#define GPIO_O_AMSEL     0x528          /* Analog Mode Select register        */
#define GPIO_O_PCTL      0x52c          /* Port Control register              */
#define GPIO_O_ADDCCTL   0x530          /*GPIO ADC Control                    */
#define GPIO_O_DMACTL    0x534          /*GPIO DMA Control                    */
#define GPIO_O_OSI       0x538          /*GPIO Select Interrupt               */

/* -------- GPIO_LOCK  Register            -------- */
#define GPIO_LOCK_M        0xffffffff     /* GPIO Lock                          */
#define GPIO_LOCK_UL  	   0x4c4f434b         /* Unlocks the GPIO_CR register       */

/* -------- GPIO_PCTL  Register            -------- */
#define GPIO_PCTL_PA0_M    0x0000000f /* PA0 mask                           */
#define GPIO_PCTL_PA0_U0RX 0x00000001 /* U0RX on PA0                        */
#define GPIO_PCTL_PA1_M    0x000000f0 /* PA1 mask                           */
#define GPIO_PCTL_PA1_U0TX 0x00000010 /* U0TX on PA1                        */

/*
 * Nested Vectored Interrupt Controller
 */

/* Peripheral Identifiers Define            */
#define INT_GPIOA		0	/*  GPIO Port A				*/
#define INT_GPIOB		1	/*  GPIO Port B				*/
#define INT_GPIOC		2	/*  GPIO Port C				*/
#define INT_GPIOD		3	/*  GPIO Port D				*/
#define INT_GPIOE		4	/*  GPIO Port E				*/
#define INT_UART0		5	/*  UART0					*/
#define INT_UART1		6	/*  UART1					*/
#define INT_SSI0		7	/*  SSI0					*/
#define INT_I2C0		8	/*  I2C0					*/
#define INT_PWM0 Fault	9	/*  PWM0 Fault				*/
#define INT_PWM0 		10	/*  PWM0 Generator 0		*/
#define INT_PWM1		11	/*  PWM0 Generator 1		*/
#define INT_PWM2		12	/*  PWM0 Generator 2		*/
#define INT_QEI0		13	/*  QEI0					*/
#define INT_ADC0SS0		14	/*  ADC0 Sequence 0			*/
#define INT_ADC1SS1		15	/*  ADC0 Sequence 1			*/
#define INT_ADC2SS2		16	/*  ADC0 Sequence 2			*/
#define INT_ADC3SS3		17	/*  ADC0 Sequence 3			*/
#define INT_WATCHDOG	18	/*  Watchdog Timers 0 and 1	*/
#define INT_Timer0A		19	/*  16/32-Bit Timer 0A		*/
#define INT_Timer0B		20	/*  16/32-Bit Timer 0B		*/
#define INT_Timer1A		21	/*  16/32-Bit Timer 1A		*/
#define INT_Timer1B		22	/*  16/32-Bit Timer 1B		*/
#define INT_Timer2A		23	/*  16/32-Bit Timer 2A		*/
#define INT_Timer2B		24	/*  16/32-Bit Timer 2B		*/
#define INT_Analog0		25	/*  Analog Comparator 0     */
#define INT_Analog1		26	/*  Analog Comparator 1		*/
#define INT_Analog2		27	/*  Analog Comparator 2     */
#define INT_SYSCTL		28	/*  System Control			*/
#define INT_FLASH		29	/*  Flash Memory Control and EEPROM Control */
#define INT_GPIOF		30	/*  GPIO Port F				*/
#define INT_GPIOG		31	/*  GPIO Port G				*/
#define INT_GPIOH		32	/*  GPIO Port H				*/
#define INT_UART2		33	/*  UART2					*/
#define INT_SSI1		34	/*  SSI1					*/
#define INT_Timer3A		35	/*  16/32-Bit Timer 3A		*/
#define INT_Timer3B		36	/*  16/32-Bit Timer 3B		*/
#define INT_I2C1		37	/*  I2C1					*/
#define INT_QEI1		38	/*  QEI1					*/
#define INT_CAN0		39	/*  CAN0					*/
#define INT_CAN1		40	/*  CAN1					*/
		/*41-42	Reserved*/
#define INT_HIBERNATE	43	/*  Hibernation Module		*/
#define INT_USB			44	/*  USB						*/
#define INT_PWM3		45	/*  PWM Generator 3			*/
#define INT_UDMA		46	/*  ¦ÌDMA Software			*/
#define INT_UDMAERR		47	/*  ¦ÌDMA Error				*/
#define INT_ADC1SS0		48	/*  ADC1 Sequence 0			*/
#define INT_ADC1SS1		49	/*  ADC1 Sequence 1			*/
#define INT_ADC1SS2		50	/*  ADC1 Sequence 2			*/
#define INT_ADC1SS3		51	/*  ADC1 Sequence 3			*/
		/*52-53	Reserved*/
#define INT_GPIOJ		54	/*  GPIO Port J				*/
#define INT_GPIOK		55	/*  GPIO Port K				*/
#define INT_GPIOL		56	/*  GPIO Port L				*/
#define INT_SSI2		57	/*  SSI2					*/
#define INT_SSI3		58	/*  SSI3					*/
#define INT_UART3		59	/*  UART3					*/
#define INT_UART4		60	/*  UART4					*/
#define INT_UART5		61	/*  UART5					*/
#define INT_UART6		62	/*  UART6					*/
#define INT_UART7		63	/*  UART7					*/
		/*64-67	Reserved*/
#define INT_I2C2		68	/*  I2C2					*/
#define INT_I2C3		69	/*  I2C3					*/
#define INT_Timer4A		70	/*  16/32-Bit Timer 4A		*/
#define INT_Timer4B		71	/*  16/32-Bit Timer 4B		*/
		/*72-91	Reserved*/
#define INT_Timer5A	92	/*  16/32-Bit Timer 5A			*/
#define INT_Timer5B	93	/*  16/32-Bit Timer 5B			*/
#define INT_DTimer0A	94	/*  32/64-Bit Timer 0A		*/
#define INT_DTimer0B	95	/*  32/64-Bit Timer 0B		*/
#define INT_DTimer1A	96	/*  32/64-Bit Timer 1A		*/
#define INT_DTimer1B	97	/*  32/64-Bit Timer 1B		*/
#define INT_DTimer2A	98	/*  32/64-Bit Timer 2A		*/
#define INT_DTimer2B	99	/*  32/64-Bit Timer 2B		*/
#define INT_DTimer3A	100	/*  32/64-Bit Timer 3A		*/
#define INT_DTimer3B	101	/*  32/64-Bit Timer 3B		*/
#define INT_DTimer4A	102	/*  32/64-Bit Timer 4A		*/
#define INT_DTimer4B	103	/*  32/64-Bit Timer 4B		*/
#define INT_DTimer5A	104	/*  32/64-Bit Timer 5A		*/
#define INT_DTimer5B	105	/*  32/64-Bit Timer 5B		*/
#define INT_SYSEXC		106	/*  System Exception (imprecise)*/
		/*107-108 Reserved*/
#define INT_I2C4		109	/*  I2C4					*/
#define INT_I2C5		110	/*  I2C5					*/
#define INT_GPIOM		111	/*  GPIO Port M				*/
#define INT_GPION		112	/*  GPIO Port N				*/
		/*113-115 Reserved*/
#define INT_GPIOP 		116	/*  GPIO Port P (Summary or P0)	*/
#define INT_GPIOP1		117	/*  GPIO Port P1			*/
#define INT_GPIOP2		118	/*  GPIO Port P2			*/
#define INT_GPIOP3		119	/*  GPIO Port P3			*/
#define INT_GPIOP4		120	/*  GPIO Port P4			*/
#define INT_GPIOP5		121	/*  GPIO Port P5			*/
#define INT_GPIOP6		122	/*  GPIO Port P6			*/
#define INT_GPIOP7		123	/*  GPIO Port P7			*/
		/*124-133 Reserved*/
#define INT_PWM1GEN0	134	/*  PWM1 Generator 0		*/
#define INT_PWM1GEN1	135	/*  PWM1 Generator 1		*/
#define INT_PWM1GEN2	136	/*  PWM1 Generator 2		*/
#define INT_PWM1GEN3	137	/*  PWM1 Generator 3		*/
#define INT_PWM1_FAULT	138	/*  PWM1 Fault				*/
#define INT_NUMBER      139 /* Interrupt vectors Number */

/* Software interrupt number for micro T-Kernel */
#define SWI_SVC		                156   /* micro T-Kernel system call/extension SVC */
#define SWI_RETINT	                157   /* tk_ret_int() system call,equal (SWI_SVC+1) */
#define SWI_DEBUG	                158   /* Debugger support function,equal (SWI_SVC+2) */

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
 * Timer Counter
 */


/*
 * UART
 */
#define UART0_BASE        0x4000C000
#define UART_O_DR         0x00   /* UART Data */
#define UART_O_RSR    	  0x04   /* UART Receive Status/Error Clear */
#define UART_O_FR         0x18   /* UART Flag */
#define UART_O_ILPR       0x20   /* UART IrDA Low-Power Register */
#define UART_O_IBRD       0x24   /* UART Integer Baud-Rate Divisor */
#define UART_O_FBRD       0x28   /* UART Fractional Baud-Rate Divisor */
#define UART_O_LCRH       0x2c   /* UART Line Control*/
#define UART_O_CTL        0x30   /* UART Control */
#define UART_O_IFLS       0x34   /* UART Interrupt FIFO Level Select */
#define UART_O_IM         0x38   /* UART Interrupt Mask */
#define UART_O_RIS        0x3c   /* UART Raw Interrupt Status*/
#define UART_O_MIS        0x40   /* UART Masked Interrupt Status*/
#define UART_O_ICR        0x44   /* UART Interrupt Clear */
#define UART_O_DMACTL     0x48   /* UART DMA Control*/
#define UART_O_LCTL       0x90   /* UART LIN Control*/
#define UART_O_LSS        0x94   /* UART LIN Snap Shot */
#define UART_O_LTIM       0x98   /* UART LIN Timer */
#define UART_O_9BITADDR   0xA4   /* UART 9-Bit Self Address*/
#define UART_O_9BITAMASK  0xA8   /* UART 9-Bit Self Address Mask*/
#define UART_O_PP         0xFC0  /* UART Peripheral Properties */
#define UART_O_CC         0xFC8  /* UART Clock Configuration*/
/* -------- UART_DR  UART Register             -------- */
#define UART_DR_DATA_M        0x000000ff /* UART data                  */

/* -------- UART_FR  UART Register             -------- */
#define UART_FR_RI            0x00000100  /* Ring Indicator             */
#define UART_FR_TXFE          0x00000080  /* UART Transmit FIFO Empty   */
#define UART_FR_RXFF          0x00000040  /* UART Receive FIFO Full     */
#define UART_FR_TXFF          0x00000020  /* UART Transmit FIFO Full    */
#define UART_FR_RXFE          0x00000010  /* UART Receive FIFO Empty    */
#define UART_FR_BUSY          0x00000008  /* UART Busy                  */
#define UART_FR_DCD           0x00000004  /* Data Carrier Detect        */
#define UART_FR_DSR           0x00000002  /* Data Set Ready             */
#define UART_FR_CTS           0x00000001  /* Clear To Send              */

/* -------- UART_IBRD  UART Register             -------- */
#define UART_IBRD_DIVINT_M    0x0000ffff  /* Integer Baud-Rate Divisor  */
#define UART_IBRD_DIVINT_S    0

/* -------- UART_FBRD  UART Register             -------- */
#define UART_FBRD_DIVFRAC_M   0x0000003f  /* Fractional Baud-Rate Divisor*/
#define UART_FBRD_DIVFRAC_S   0

/* -------- UART_LCRH  UART Register             -------- */
#define UART_LCRH_SPS         0x00000080  /* UART Stick Parity Select   */
#define UART_LCRH_WLEN_M      0x00000060  /* UART Word Length           */
#define UART_LCRH_WLEN_5      0x00000000  /* 5 bits (default)           */
#define UART_LCRH_WLEN_6      0x00000020  /* 6 bits                     */
#define UART_LCRH_WLEN_7      0x00000040  /* 7 bits                     */
#define UART_LCRH_WLEN_8      0x00000060  /* 8 bits                     */
#define UART_LCRH_FEN         0x00000010  /* UART Enable FIFOs          */
#define UART_LCRH_STP2        0x00000008  /* UART Two Stop Bits Select  */
#define UART_LCRH_EPS         0x00000004  /* UART Even Parity Select    */
#define UART_LCRH_PEN         0x00000002  /* UART Parity Enable         */
#define UART_LCRH_BRK         0x00000001  /* UART Send Break            */

/* -------- UART_CTL  UART Register              -------- */
#define UART_CTL_CTSEN        0x00008000  /* Enable Clear To Send       */
#define UART_CTL_RTSEN        0x00004000  /* Enable Request to Send     */
#define UART_CTL_RTS          0x00000800  /* Request to Send            */
#define UART_CTL_DTR          0x00000400  /* Data Terminal Ready        */
#define UART_CTL_RXE          0x00000200  /* UART Receive Enable        */
#define UART_CTL_TXE          0x00000100  /* UART Transmit Enable       */
#define UART_CTL_LBE          0x00000080  /* UART Loop Back Enable      */
#define UART_CTL_LIN          0x00000040  /* LIN Mode Enable            */
#define UART_CTL_HSE          0x00000020  /* High-Speed Enable          */
#define UART_CTL_EOT          0x00000010  /* End of Transmission        */
#define UART_CTL_SMART        0x00000008  /* ISO 7816 Smart Card Support*/
#define UART_CTL_SIRLP        0x00000004  /* UART SIR Low-Power Mode    */
#define UART_CTL_SIREN        0x00000002  /* UART SIR Enable            */
#define UART_CTL_UARTEN       0x00000001  /* UART Enable                */

/* -------- UART_IM  UART Register               -------- */
#define UART_IM_ALLIM         0x0000e7ff  /* All Mask                   */
#define UART_IM_LME5IM        0x00008000  /* LIN Mode Edge 5 Mask       */
#define UART_IM_LME1IM        0x00004000  /* LIN Mode Edge 1 Mask       */
#define UART_IM_LMSBIM        0x00002000  /* LIN Mode Sync Break Mask   */
#define UART_IM_OEIM          0x00000400  /* UART Overrun Error Mask    */
#define UART_IM_BEIM          0x00000200  /* UART Break Error Mask      */
#define UART_IM_PEIM          0x00000100  /* UART Parity Error Mask     */
#define UART_IM_FEIM          0x00000080  /* UART Framing Error Mask    */
#define UART_IM_RTIM          0x00000040  /* UART Receive Time-Out Mask */
#define UART_IM_TXIM          0x00000020  /* UART Transmit Mask         */
#define UART_IM_RXIM          0x00000010  /* UART Receive Mask          */
#define UART_IM_DSRMIM        0x00000008  /* UART Data Set Ready Modem Mask       */
#define UART_IM_DCDMIM        0x00000004  /* UART Data Carrier Detect Modem Mask  */
#define UART_IM_CTSMIM        0x00000002  /* UART Clear to Send Modem Mask  */
#define UART_IM_RIMIM         0x00000001  /* UART Ring Indicator Modem Mask */

/* -------- UART_DMACTL  UART Register           -------- */
#define UART_DMACTL_DMAERR    0x00000004  /* DMA on Error               */
#define UART_DMACTL_TXDMAE    0x00000002  /* Transmit DMA Enable        */
#define UART_DMACTL_RXDMAE    0x00000001  /* Receive DMA Enable */


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
#define WATCHDOG0_BASE        0x40000000
#define WATCHDOG1_BASE        0x40001000

#define WDT_O_LOAD            0x00   /*Watchdog Load*/
#define WDT_O_VALUE           0x04   /*Watchdog Value*/
#define WDT_O_CTL             0x08   /*Watchdog Control*/
#define WDT_O_ICR             0x0C   /*Watchdog Interrupt Clear*/
#define WDT_O_RIS             0x10   /*Watchdog Raw Interrupt Status*/
#define WDT_O_MIS             0x14   /*Watchdog Masked Interrupt Status*/
#define WDT_O_TEST            0x418  /*Watchdog Test*/
#define WDT_O_LOCK            0xC00  /*Watchdog Lock*/

/* -------- WDT_CTL  Watchdog Control Register -------- */
#define WDT_CTL_RESEN         0x02      /* Watchdog Reset Enable      */
#define WDT_CTL_INTEN         0x01      /* Watchdog Interrupt Enable  */
/* -------- WDT_LOCK  Watchdog Lock Register   -------- */
#define WDT_LOCK_UL     0x1acce551      /* Unlocks the watchdog timer */
#define WDT_LOCK_M      0xffffffff      /* locks the watchdog timer   */

#endif /* __TK_SYSDEF_DEPEND_H__ */
