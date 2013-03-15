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
 *	 Author	        : dengjk-dengjk
 *	 Description    : register Definition about cpu(tk/SIM3U167).
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
 * Internal Flash Memroy Controller
 */
#define FLASHCTRL0_BASE             0x4002e000
#define FLASHCTRL0_CONFIG           0x00 	/*Controller Configuration*/
#define FLASHCTRL0_CONFIG_SET       0x04
#define FLASHCTRL0_CONFIG_CLR       0x08
						/*reserved	0x0c*/
#define FLASHCTRL0_WRADDR           0xa0	    /*Flash Write Address	  */
						/*reserved	0xa4*/
						/*reserved	0xa8*/
						/*reserved	0xac*/
#define FLASHCTRL0_WRDATA           0xb0     /*Flash Write Data        */
						/*reserved	0xb4*/
						/*reserved	0xb8*/
						/*reserved	0xbc*/
#define FLASHCTRL0_KEY              0xc0     /*Flash Modification Key  */
						/*reserved	0xc4*/
						/*reserved	0xc8*/
						/*reserved	0xcc*/
#define FLASHCTRL0_TCONTROL         0xd0     /*Flash Timing Control    */
						/*reserved	0xd4*/
						/*reserved	0xd8*/
						/*reserved	0xdc*/

/*
 * Power Management Controller
 */
#define CLKCTRL0_BASE               0x4002d000
#define PLL0_BASE         			0x4003b000

#define CLKCTRL0_CONTROL 		    0x00
						/*reserved	0x04*/
						/*reserved	0x08*/
						/*reserved	0x0c*/
#define CLKCTRL0_AHBCLKG 		    0x10
#define CLKCTRL0_AHBCLKG_SET 		0x14
#define CLKCTRL0_AHBCLKG_CLR		0x18
						/*reserved	0x1c*/
#define CLKCTRL0_APBCLKG0		    0x20
#define CLKCTRL0_APBCLKG0_SET		0x24
#define CLKCTRL0_APBCLKG0_CLR		0x28
						/*reserved	0x2c*/
#define CLKCTRL0_APBCLKG1			0x30
#define CLKCTRL0_APBCLKG1_SET		0x34
#define CLKCTRL0_APBCLKG1_CLR		0x38
						/*reserved	0x3c*/
#define CLKCTRL0_PM3CN   			0x40
						/*reserved	0x44*/
						/*reserved	0x48*/
						/*reserved	0x4c*/
#define PLL0_DIVIDER      			0x00   /*Reference Divider Setting*/
						/*reserved	0x04*/
						/*reserved	0x08*/
						/*reserved	0x0c*/
#define PLL0_CONTROL     			0x10   /*Module Control*/
#define PLL0_CONTROL_SET  			0x14
#define PLL0_CONTROL_CLR  			0x18
						/*reserved	0x1c*/
#define PLL0_SSPR         			0x20   /*Spectrum Spreading Control*/
						/*reserved	0x24*/
						/*reserved	0x28*/
						/*reserved	0x2c*/
#define PLL0_CALCONFIG   		 	0x30   /*Calibration Configuration*/
						/*reserved	0x34*/
						/*reserved	0x38*/
						/*reserved	0x3c*/
/*
 *  General-purpose IO
 */
#define	PBCFG0_BASE      0x4002A000
#define	PBSTD0_BASE 	 0x4002A0A0 /* Port Bank 0 adress */
#define	PBSTD1_BASE 	 0x4002A140 /* Port Bank 1 adress */
#define	PBSTD2_BASE 	 0x4002A1E0 /* Port Bank 2 adress */
#define	PBSTD3_BASE 	 0x4002A320 /* Port Bank 3 adress */
#define	PBHD4_BASE       0x4002A3C0

/*base address as PBCFG0_BASE 0x4002a000*/
#define	PBCFG0_CONTROL0	        0x00
#define	PBCFG0_CONTROL0_SET	    0x04
#define	PBCFG0_CONTROL0_CLR	    0x08
                  /*reserved	0x0c*/
#define	PBCFG0_CONTROL1	        0x10
#define	PBCFG0_CONTROL1_SET	    0x14
#define	PBCFG0_CONTROL1_CLR	    0x18
                  /*reserved	0x1c*/
#define	PBCFG0_XBAR0L	        0x20
#define	PBCFG0_XBAR0L_SET	    0x24
#define	PBCFG0_XBAR0L_CLR	    0x28
                  /*reserved	0x2c*/
#define	PBCFG0_XBAR0H	        0x30
#define	PBCFG0_XBAR0H_SET	    0x34
#define	PBCFG0_XBAR0H_CLR	    0x38
                  /*reserved	0x3c*/
#define	PBCFG0_XBAR1	        0x40
#define	PBCFG0_XBAR1_SET	    0x44
#define	PBCFG0_XBAR1_CLR	    0x48
                  /*reserved    0x4c*/
#define	PBCFG0_PBKEY	        0x50
                  /*reserved	0x54*/
                  /*reserved	0x58*/
                  /*reserved	0x5c*/

/*base address as PBSTD0_BASE 0x4002a0a0*/
#define	PBSTD_PB	            0x00
#define	PBSTD_PB_SET	        0x04
#define	PBSTD_PB_CLR	        0x08
#define	PBSTD_PB_MSK	        0x0c
#define	PBSTD_PBPIN	            0x10
					/*reserved	0x14*/
					/*reserved	0x18*/
					/*reserved	0x1c*/
#define	PBSTD_PBMDSEL	        0x20
#define	PBSTD_PBMDSEL_SET	    0x24
#define	PBSTD_PBMDSEL_CLR	    0x28
					/*reserved	0x2c*/
#define	PBSTD_PBSKIPEN	        0x30
#define	PBSTD_PBSKIPEN_SET	    0x34
#define	PBSTD_PBSKIPEN_CLR	    0x38
					/*reserved	0x3c*/
#define	PBSTD_PBOUTMD	        0x40
#define	PBSTD_PBOUTMD_SET	    0x44
#define	PBSTD_PBOUTMD_CLR	    0x48
					/*reserved	0x4c*/
#define	PBSTD_PBDRV	            0x50
#define	PBSTD_PBDRV_SET	        0x54
#define	PBSTD_PBDRV_CLR	        0x58
					/*reserved	0x5c*/
#define	PBSTD_PM	            0x60
#define	PBSTD_PM_SET	        0x64
#define	PBSTD_PM_CLR	        0x68
					/*reserved	0x6c*/
#define	PBSTD_PMEN	            0x70
#define	PBSTD_PMEN_SET	        0x74
#define	PBSTD_PMEN_CLR	        0x78
					/*reserved	0x7c*/
#define	PBSTD_PBLOCK	        0x80
					/*reserved	0x84*/
					/*reserved	0x88*/
					/*reserved	0x8c*/
#define	PBSTD_PBPGEN	        0x90
					/*reserved	0x94*/
					/*reserved	0x98*/
					/*reserved	0x9c*/
#define	PBSTD_PBPGPHASE	        0xa0
					/*reserved	0xa4*/
					/*reserved	0xa8*/
					/*reserved	0xac*/

/*base address as PBHD4_BASE 0x4002a3c0*/
#define	PBHD4_PB 	  			0x00
#define	PBHD4_PB_SET 			0x04
#define	PBHD4_PB_CLR			0x08
#define	PBHD4_PB_MASK			0x0c
#define	PBHD4_PBPIN 			0x10
					/*reserved	0x14*/
					/*reserved	0x18*/
					/*reserved	0x1c*/
#define	PBHD4_PBMDSEL 			0x20
#define	PBHD4_PBMDSEL_SET 		0x24
#define	PBHD4_PBMDSEL_CLR		0x28
					/*reserved	0x2c*/
#define	PBHD4_PBDEN 			0x30
#define	PBHD4_PBDEN_SET 		0x34
#define	PBHD4_PBDEN_CLR 		0x38
					/*reserved	0x3c*/
#define	PBHD4_PBDRV 			0x40
#define	PBHD4_PBDRV_SET 		0x44
#define	PBHD4_PBDRV_CLR 		0x48
					/*reserved	0x4c*/
#define	PBHD4_PBILIMIT			0x50
#define	PBHD4_PBILIMIT_SET		0x54
#define	PBHD4_PBILIMIT_CLR		0x58
					/*reserved	0x5c*/
#define	PBHD4_PBFSEL			0x70
					/*reserved	0x74*/
					/*reserved	0x78*/
					/*reserved	0x7c*/
#define	PBHD4_PBSS				0x80
#define	PBHD4_PBSS_SET			0x74
#define	PBHD4_PBSS_CLR			0x78
					/*reserved	0x8c*/
#define	PBHD4_PBLOCK			0x90
					/*reserved	0x94*/
					/*reserved	0x98*/
					/*reserved	0x9c*/

/*
 * Nested Vectored Interrupt Controller
 */
#define	PI_WDTIMER0 	0	/*	First threshold crossed 	*/
#define	PI_PBEXT0		1	/*	External pin (INT0x) rising edge	*/
#define	PI_PBEXT1		2	/*	External pin (INT1x) rising edge	*/
#define	PI_RTC0ALRM 	3	/*	Alarm 0	*/
#define	PI_DMACH0 		4	/*	DMA Channel 0 done 	*/
#define	PI_DMACH1 		5	/*	DMA Channel 1 done 	*/
#define	PI_DMACH2 		6	/*	DMA Channel 2 done 	*/
#define	PI_DMACH3		7	/*	DMA Channel 3 done 	*/
#define	PI_DMACH4		8	/*	DMA Channel 4 done	*/
#define	PI_DMACH5 		9	/*	DMA Channel 5 done 	*/
#define	PI_DMACH6		10	/*	DMA Channel 6 done 	*/
#define	PI_DMACH7		11	/*	DMA Channel 7 done 	*/
#define	PI_DMACH8		12	/*	DMA Channel 8 done 	*/
#define	PI_DMACH9		13	/*	DMA Channel 9 done 	*/
#define	PI_DMACH10 		14	/*	DMA Channel 10 done 	*/
#define	PI_DMACH11		15	/*	DMA Channel 11 done 	*/
#define	PI_DMACH12		16	/*	DMA Channel 12 done 	*/
#define	PI_DMACH13		17	/*	DMA Channel 13 done 	*/
#define	PI_DMACH14		18	/*	DMA Channel 14 done 	*/
#define	PI_DMACH15		19	/*	DMA Channel 15 done 	*/
#define	PI_TIMER0L		20	/*	TIMER0 Low overflow 	*/
#define	PI_TIMER0H		21	/*	TIMER0 High overflow 	*/
#define	PI_TIMER1L		22	/*	TIMER1 Low overflow 	*/
#define	PI_TIMER1H		23	/*	TIMER1 High overflow 	*/
#define	PI_EPCA0		24	/*	Counter overflow	*/
#define	PI_PCA0			25	/*	Counter overflow	*/
#define	PI_PCA1			26	/*	Counter overflow	*/
#define	PI_USART0		27	/*	Receive frame error	*/
#define	PI_USART1 		28	/*	Receive frame error	*/
#define	PI_SPI0			29	/*	Shift Register empty	*/
#define	PI_SPI1			30	/*	Shift Register empty	*/
#define	PI_SPI2			31	/*	Shift Register empty	*/
#define	PI_I2C0 		32	/*	Start	*/
#define	PI_I2C1 		33	/*	Start	*/
#define	PI_USB0 		34	/*	Endpoint 0 data	*/
#define	PI_SARADC0		35	/*	Conversion complete	*/
#define	PI_SARADC1		36	/*	Conversion complete	*/
#define	PI_CMP0			37	/*	Rising edge occurred	*/
#define	PI_CMP1			38	/*	Rising edge occurred	*/
#define	PI_CAPSENSE0	39	/*	Conversion complete	*/
#define	PI_I2S0RX		40	/*	Receive FIFO overflow	*/
#define	PI_I2S0TX 		41	/*	Transmit FIFO underflow	*/
#define	PI_AES0 		42	/*	Operation complete	*/
#define	PI_VDDLOW 		43	/*	VDD falls below the early warning threshold 	*/
#define	PI_RTC0FAIL		44	/*	RTC0 Oscillator failed 	*/
#define	PI_PMATCH0		45	/*	Port Match event	*/
#define	PI_UART0		46	/*	Receive frame error	*/
#define	PI_UART1 		47	/*	Receive frame error	*/
#define	PI_IDAC0 		48	/*	Data buffer overrun	*/
#define	PI_IDAC1 		49	/*	Data buffer overrun	*/
#define	PI_LPTIMER0		50	/*	Timer overflow	*/
#define	PI_PLL0			51	/*	Lock saturation high or low	*/
#define	PI_VBUS 		52	/*	The VBUS input is below the valid 	*/
#define	PI_VREGLOW		53	/*	VREGIN / 4 falls below the early warning 	*/
#define PI_INT_NUMBER   54   /* Interrupt vectors Number*/

/* Software interrupt number for micro T-Kernel */
#define SWI_SVC		                71   /* micro T-Kernel system call/extension SVC */
#define SWI_RETINT	                72   /* tk_ret_int() system call,equal (SWI_SVC+1) */
#define SWI_DEBUG	                73   /* Debugger support function,equal (SWI_SVC+2) */

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
#define UART0_BASE          0x40002000
#define UART1_BASE          0x40003000
#define	UART_CONFIG 	    0x00
#define	UART_CONFIG_SET 	0x04
#define	UART_CONFIG_CLR 	0x08
				/*reserved	0x0c*/
#define	UART_MODE 	        0x10
#define	UART_MODE_SET  	0x14
#define	UART_MODE_CLR 		0x18
				/*reserved	0x1c*/
#define	UART_FLOWCN 		0x20
#define	UART_FLOWCN_SET  	0x24
#define	UART_FLOWCN_CLR 	0x28
				/*reserved	0x2c*/
#define	UART_CONTROL 		0x30
#define	UART_CONTROL_SET  	0x34
#define	UART_CONTROL_CLR 	0x38
				/*reserved	0x3c*/
#define	UART_IPDELAY 		0x40
				/*reserved	0x44*/
				/*reserved	0x48*/
				/*reserved	0x4c*/
#define	UART_BAUDRATE 		0x50
				/*reserved	0x54*/
				/*reserved	0x58*/
				/*reserved	0x5c*/
#define	UART_FIFOCN 		0x60
#define	UART_FIFOCN_SET  	0x64
#define	UART_FIFOCN_CLR	0x68
				/*reserved	0x6c*/
#define	UART_DATA 		    0x70
				/*reserved	0x74*/
				/*reserved	0x78*/
				/*reserved	0x7c*/

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
#define SCB_ACTLR        0x008
#define SCB_CPUID        0xd00
#define SCB_CFSR         0xd28
#define SCB_BFSR         0xd28
#define SCB_UFSR         0xd2a
#define SCB_HFSR         0xd2c
#define SCB_MMAR         0xd34

/*
 * WATCH DOG
 */
#define WDTIMER_BASE   	            0x40030000
#define WDTIMER0_CONTROL	        0x00	    /* Module Control   */
#define WDTIMER0_STATUS	            0x10	    /* Module Status    */
#define WDTIMER0_THRESHOLD	        0x20	    /* Threshold Values */
#define WDTIMER0_WDTKEY	            0x30	    /* Module Key       */

/*
 *Reset Sources
 */
#define RSTSRC0_BASE                0x4002d060
#define RSTSRC0_RESETEN 		    0x00
#define RSTSRC0_RESETEN_SET	        0x04
#define RSTSRC0_RESETEN_CLR	        0x08
						/*reserved	0x0c*/
#define RSTSRC0_RESETFLAG		    0x10
						/*reserved	0x14*/
						/*reserved	0x18*/
						/*reserved	0x1c*/
#define RSTSRC0_CONFIG   		    0x20
#define RSTSRC0_CONFIG_SET		    0x24
#define RSTSRC0_CONFIG_CLR		    0x28
						/*reserved	0x2c*/


#endif /* __TK_SYSDEF_DEPEND_H__ */
