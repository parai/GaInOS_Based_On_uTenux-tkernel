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
 *	 Create Date    : 2012/7/9-2013/1/24
 *	 Author	        : WangShb
 *	 Description    : register Definition about cpu(tk/STM32F107VC).
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

/*
 * Internal Flash Memroy Controller
 */
#define FLASH_BASE                  0x40022000
#define FLASH_ACR                   0x00 /* Flash access control register */
#define FLASH_KEYR                  0x04 /* Flash key register */
#define FLASH_OPTKEYR               0x08 /* Flash option key register */
#define FLASH_SR                    0x0c /* Flash state register */
#define FLASH_CR                    0x10 /* Flash control register */
#define FLASH_AR                    0x14 /* Flash address register */
#define FLASH_OBR                   0x1c /* Flash option byte register */
#define FLASH_WRPR                  0x20 /* Flash write protect register */

/* FLASH_ACR Register             */
#define FLASH_ACR_PRFTBS_SHIFT      0x05
#define FLASH_ACR_PRFTBE_SHIFT      0x04
#define FLASH_ACR_LATENCY_MASK      0xfffffff8
#define FLASH_ACR_LATENCY_0         0x00000000
#define FLASH_ACR_LATENCY_1         0x00000001
#define FLASH_ACR_LATENCY_2         0x00000002

/*
 * Reset and Clock Control
 */
#define RCC_BASE                    0x40021000
#define RCC_CR                      0x00 /* Clock control register */
#define RCC_CFGR                    0x04 /* Clock configuration register */
#define RCC_CIR                     0x08 /* Clock interrupt register */
#define RCC_APB2RSTR                0x0c /* APB2 peripheral reset register */
#define RCC_APB1RSTR                0x10 /* APB1 peripheral reset register */
#define RCC_AHBENR                  0x14 /* AHB Peripheral Clock enable register */
#define RCC_APB2ENR                 0x18 /* APB2 peripheral clock enable register */
#define RCC_APB1ENR                 0x1c /* APB1 peripheral clock enable register */
#define RCC_BDCR                    0x20 /* Backup domain control register */
#define RCC_CSR                     0x24 /* Control/status register */

/* RCC_CR Register                */
#define RCC_CR_PLL3RDY_MASK         0xdfffffff
#define RCC_CR_PLL3RDY_SET          0x20000000
#define RCC_CR_PLL3ON_MASK          0xefffffff
#define RCC_CR_PLL3ON_SET           0x10000000
#define RCC_CR_PLL2RDY_MASK         0xf7ffffff
#define RCC_CR_PLL2RDY_SET          0x08000000
#define RCC_CR_PLL2ON_MASK          0xfbffffff
#define RCC_CR_PLL2ON_SET           0x04000000
#define RCC_CR_PLLRDY_MASK          0xfdffffff
#define RCC_CR_PLLRDY_SET           0x02000000
#define RCC_CR_PLLON_MASK           0xfeffffff
#define RCC_CR_PLLON_SET            0x01000000
#define RCC_CR_HSEBYP_MASK          0xfffbffff
#define RCC_CR_HSEBYP_SET           0x00040000
#define RCC_CR_HSERDY_MASK          0xfffdffff
#define RCC_CR_HSERDY_SET           0x00020000
#define RCC_CR_HSEON_MASK           0xfffeffff
#define RCC_CR_HSEON_SET            0x00010000
#define RCC_CR_HSIRDY_MASK          0xfffffffd
#define RCC_CR_HSIRDY_SET           0x00000002
#define RCC_CR_HSION_MASK           0xfffffffe
#define RCC_CR_HSION_SET            0x00000001

/* RCC_CFGR Register              */
#define RCC_CFGR_MCO_MASK           0xf0ffffff
#define RCC_CFGR_MCO_NULL           0x00000000
#define RCC_CFGR_MCO_SYSCLK         0x04000000
#define RCC_CFGR_MCO_RC8M           0x05000000
#define RCC_CFGR_MCO_HSE            0x06000000
#define RCC_CFGR_MCO_PLL_2          0x07000000
#define RCC_CFGR_MCO_PLL2           0x08000000
#define RCC_CFGR_MCO_PLL3_2         0x09000000
#define RCC_CFGR_MCO_XT1            0x0a000000
#define RCC_CFGR_MCO_PLL3           0x0b000000
#define RCC_CFGR_OTGFSPRE_MASK      0xffbfffff
#define RCC_CFGR_OTGFSPRE_DIV_2     0x00000000
#define RCC_CFGR_OTGFSPRE_DIV_3     0x00400000
#define RCC_CFGR_PLL_MASK           0xffc0ffff
#define RCC_CFGR_PLLMULL_MASK       0xffc3ffff
#define RCC_CFGR_PLLMULL_4          0x00080000
#define RCC_CFGR_PLLMULL_5          0x000c0000
#define RCC_CFGR_PLLMULL_6          0x00100000
#define RCC_CFGR_PLLMULL_7          0x00140000
#define RCC_CFGR_PLLMULL_8          0x00180000
#define RCC_CFGR_PLLMULL_9          0x001c0000
#define RCC_CFGR_PLLXTPRE_MASK      0xfffdffff
#define RCC_CFGR_PLLXTPRE_DIV_1     0x00000000
#define RCC_CFGR_PLLXTPRE_DIV_2     0x00020000
#define RCC_CFGR_PLLSRC_MASK        0xfffeffff
#define RCC_CFGR_PLLSRC_HSI_2       0x00000000
#define RCC_CFGR_PLLSRC_PREDIV      0x00010000
#define RCC_CFGR_ADCPRE_MASK        0xffff3fff
#define RCC_CFGR_ADCPRE_DIV_1       0x00000000
#define RCC_CFGR_ADCPRE_DIV_2       0x00004000
#define RCC_CFGR_ADCPRE_DIV_4       0x00008000
#define RCC_CFGR_ADCPRE_DIV_8       0x0000c000
#define RCC_CFGR_PPRE2_MASK         0xffffc7ff
#define RCC_CFGR_PPRE2_DIV_1        0x00000000
#define RCC_CFGR_PPRE2_DIV_2        0x00002000
#define RCC_CFGR_PPRE2_DIV_4        0x00002800
#define RCC_CFGR_PPRE2_DIV_8        0x00003000
#define RCC_CFGR_PPRE2_DIV_16       0x00003800
#define RCC_CFGR_PPRE1_MASK         0xfffff8ff
#define RCC_CFGR_PPRE1_DIV_1        0x00000000
#define RCC_CFGR_PPRE1_DIV_2        0x00000400
#define RCC_CFGR_PPRE1_DIV_4        0x00000500
#define RCC_CFGR_PPRE1_DIV_5        0x00000600
#define RCC_CFGR_PPRE1_DIV_16       0x00000700
#define RCC_CFGR_HPRE_MASK          0xffffff0f
#define RCC_CFGR_HPRE_DIV_1         0x00000000
#define RCC_CFGR_HPRE_DIV_2         0x00000080
#define RCC_CFGR_HPRE_DIV_4         0x00000090
#define RCC_CFGR_HPRE_DIV_8         0x000000a0
#define RCC_CFGR_HPRE_DIV_16        0x000000b0
#define RCC_CFGR_HPRE_DIV_64        0x000000c0
#define RCC_CFGR_HPRE_DIV_128       0x000000d0
#define RCC_CFGR_HPRE_DIV_256       0x000000e0
#define RCC_CFGR_HPRE_DIV_512       0x000000f0
#define RCC_CFGR_SWS_MASK           0xfffffff3
#define RCC_CFGR_SWS_HSI            0x00000000
#define RCC_CFGR_SWS_HSE            0x00000004
#define RCC_CFGR_SWS_PLL            0x00000008
#define RCC_CFGR_SW_MASK            0xfffffffc
#define RCC_CFGR_SW_HSI             0x00000000
#define RCC_CFGR_SW_HSE             0x00000001
#define RCC_CFGR_SW_PLL             0x00000002


/* RCC_AHBENR Register            */
#define RCC_AHBENR_ETHMACRXEN_SHIFT 0x10
#define RCC_AHBENR_ETHMACTXEN_SHIFT 0x0f
#define RCC_AHBENR_ETHMACEN_SHIFT   0x0e
#define RCC_AHBENR_OTGFSEN_SHIFT    0x0c
#define RCC_AHBENR_CRCEN_SHIFT      0x06
#define RCC_AHBENR_FLITFEN_SHIFT    0x04
#define RCC_AHBENR_SRAMEN_SHIFT     0x02
#define RCC_AHBENR_DMA2EN_SHIFT     0x01
#define RCC_AHBENR_DMA1EN_SHIFT     0x00

/* RCC_APB2ENR Register           */
#define RCC_APB2ENR_USART1EN_SHIFT  0x0e
#define RCC_APB2ENR_SPI1EN_SHIFT    0x0c
#define RCC_APB2ENR_TIM1EN_SHIFT    0x0b
#define RCC_APB2ENR_ADC2EN_SHIFT    0x0a
#define RCC_APB2ENR_ADC1EN_SHIFT    0x09
#define RCC_APB2ENR_IOPGEN_SHIFT    0x08
#define RCC_APB2ENR_IOPFEN_SHIFT    0x07
#define RCC_APB2ENR_IOPEEN_SHIFT    0x06
#define RCC_APB2ENR_IOPDEN_SHIFT    0x05
#define RCC_APB2ENR_IOPCEN_SHIFT    0x04
#define RCC_APB2ENR_IOPBEN_SHIFT    0x03
#define RCC_APB2ENR_IOPAEN_SHIFT    0x02
#define RCC_APB2ENR_AFIOEN_SHIFT    0x00


/* RCC_APB1ENR Register           */
#define RCC_APB1ENR_DACEN_SHIFT     0x1d
#define RCC_APB1ENR_PWREN_SHIFT     0x1c
#define RCC_APB1ENR_BKPEN_SHIFT     0x1b
#define RCC_APB1ENR_CAN2EN_SHIFT    0x1a
#define RCC_APB1ENR_CAN1EN_SHIFT    0x19
#define RCC_APB1ENR_I2C2EN_SHIFT    0x16
#define RCC_APB1ENR_I2C1EN_SHIFT    0x15
#define RCC_APB1ENR_UART5EN_SHIFT   0x14
#define RCC_APB1ENR_UART4EN_SHIFT   0x13
#define RCC_APB1ENR_UART3EN_SHIFT   0x12
#define RCC_APB1ENR_UART2EN_SHIFT   0x11
#define RCC_APB1ENR_SPI3EN_SHIFT    0x0f
#define RCC_APB1ENR_SPI2EN_SHIFT    0x0e
#define RCC_APB1ENR_SPI3EN_SHIFT    0x0f
#define RCC_APB1ENR_WWDGEN_SHIFT    0x0b
#define RCC_APB1ENR_TIM7EN_SHIFT    0x05
#define RCC_APB1ENR_TIM6EN_SHIFT    0x04
#define RCC_APB1ENR_TIM5EN_SHIFT    0x03
#define RCC_APB1ENR_TIM4EN_SHIFT    0x02
#define RCC_APB1ENR_TIM3EN_SHIFT    0x01
#define RCC_APB1ENR_TIM2EN_SHIFT    0x00

/*
 *  General-purpose IO
 */
#define GPIOA_BASE                  0x40010800 /* Port A  adress */
#define GPIOB_BASE  			    0x40010C00 /* Port B  adress */
#define GPIOC_BASE                  0x40011000 /* Port C  adress */
#define GPIOD_BASE                  0x40011400 /* Port D  adress */
#define GPIOE_BASE                  0x40011800 /* Port E  adress */
#define GPIO_CRL                    0x00 /* Port configuration register low */
#define GPIO_CRH                    0x04 /* Port configuration register high */
#define GPIO_IDR                    0x08 /* Port input data register */
#define GPIO_ODR                    0x0c /* Port output data register */
#define GPIO_BSRR                   0x10 /* Port bit set/reset register */
#define GPIO_BRR                    0x14 /* Port bit reset register */
#define GPIO_LCKR                   0x18 /* Port configuration lock register */

/* GPIO_CRL and CRH Register      */
#define GPIO_CR_CNF_MASK            0x03
#define GPIO_CR_CNF_IN_ANALOG       0x00
#define GPIO_CR_CNF_IN_FLOATING     0x01
#define GPIO_CR_CNF_IN_PULLUPDOWN   0x02
#define GPIO_CR_CNF_OUT_GP_PP       0x00
#define GPIO_CR_CNF_OUT_GP_OD       0x01
#define GPIO_CR_CNF_OUT_AF_PP       0x02
#define GPIO_CR_CNF_OUT_AF_OD       0x03
#define GPIO_CR_MODE_MASK           0x03
#define GPIO_CR_MODE_IN             0x00
#define GPIO_CR_MODE_OUT_10M        0x01
#define GPIO_CR_MODE_OUT_2M         0x02
#define GPIO_CR_MODE_OUT_50M        0x03

/* GPIO_CRL Register               */
#define GPIO_CRL_SHIFT(x)           (0x04*(x))

/* GPIO_CRH Register               */
#define GPIO_CRH_SHIFT(x)           (0x04*(x-8))

/*
 * Nested Vectored Interrupt Controller
 */

/* Interrupt vectors Define            */
#define PI_WWDG                     0    /* Window watchdog interrupt */
#define PI_PVD                      1    /* PVD through EXTI Line detection interrupt  */
#define PI_TAMPER                   2    /* Tamper interrupt  */
#define PI_RTC                      3    /* RTC global interrupt  */
#define PI_FLASH                    4    /* Flash global interrupt  */
#define PI_RCC                      5    /* RCC global interrupt  */
#define PI_EXTI0                    6    /* EXTI Line0 interrupt  */
#define PI_EXTI1                    7    /* EXTI Line1 interrupt  */
#define PI_EXTI2                    8    /* EXTI Line2 interrupt  */
#define PI_EXTI3                    9    /* EXTI Line3 interrupt  */
#define PI_EXTI4                    10   /* EXTI Line4 interrupt  */
#define PI_DMA11                    11   /* DMA1 Channel1 global interrupt  */
#define PI_DMA12                    12   /* DMA1 Channel2 global interrupt  */
#define PI_DMA13                    13   /* DMA1 Channel3 global interrupt  */
#define PI_DMA14                    14   /* DMA1 Channel4 global interrupt  */
#define PI_DMA15                    15   /* DMA1 Channel5 global interrupt  */
#define PI_DMA16                    16   /* DMA1 Channel6 global interrupt  */
#define PI_DMA17                    17   /* DMA1 Channel7 global interrupt  */
#define PI_ADC1_2                   18   /* ADC1 and ADC2 global interrupt  */
#define PI_USB_HP_CAN_TX            19   /* USB High Priority or CAN TX interrupts  */
#define PI_USB_LP_CAN_RX0           20   /* USB Low Priority or CAN RX0 interrupts  */
#define PI_CAN1_RX1                 21   /* CAN RX1 interrupt  */
#define PI_CAN1_SCE                 22   /* CAN SCE interrupt  */
#define PI_EXTI9_5                  23   /* EXTI Line[9:5] interrupts  */
#define PI_TIM1_BRK                 24   /* TIM1 Break interrupt  */
#define PI_TIM1_UP                  25   /* TIM1 Update interrupt  */
#define PI_TIM1_TRG_COM             26   /* TIM1 Trigger and Commutation interrupts  */
#define PI_TIM1_CC                  27   /* TIM1 Capture Compare interrupt  */
#define PI_TIM2                     28   /* TIM2 global interrupt  */
#define PI_TIM3                     29   /* TIM3 global interrupt  */
#define PI_TIM4                     30   /* TIM4 global interrupt  */
#define PI_I2C1_EV                  31   /* I2C1 event interrupt  */
#define PI_I2C1_ER                  32   /* I2C1 error interrupt  */
#define PI_I2C2_EV                  33   /* I2C2 event interrupt  */
#define PI_I2C2_ER                  34   /* I2C2 error interrupt  */
#define PI_SPI1                     35   /* SPI1 global interrupt  */
#define PI_SPI2                     36   /* SPI2 global interrupt  */
#define PI_USART1                   37   /* USART1 global interrupt  */
#define PI_USART2                   38   /* USART2 global interrupt  */
#define PI_USART3                   39   /* USART3 global interrupt  */
#define PI_EXTI15_10                40   /* EXTI Line[15:10] interrupts  */
#define PI_RTCAlarm                 41   /* RTC alarm through EXTI line interrupt  */
#define PI_USB_WKUP                 42   /* USB wakeup from suspend through EXTI line interrupt  */
#define PI_TIM8_BRK                 43   /* TIM8 Break interrupt  */
#define PI_TIM8_UP                  44   /* TIM8 Update interrupt  */
#define PI_TIM8_TRG_COM             45   /* TIM8 Trigger and Commutation interrupts  */
#define PI_TIM8_CC                  46   /* TIM8 Capture Compare interrupt  */
#define PI_ADC3                     47   /* ADC3 global interrupt  */
#define PI_FSMC                     48   /* FSMC global interrupt  */
#define PI_SDIO                     49   /* SDIO global interrupt  */
#define PI_TIM5                     50   /* TIM5 global interrupt  */
#define PI_SPI3                     51   /* SPI3 global interrupt  */
#define PI_UART4                    52   /* UART4 global interrupt  */
#define PI_UART5                    53   /* UART5 global interrupt  */
#define PI_TIM6                     54   /* TIM6 global interrupt  */
#define PI_TIM7                     55   /* TIM7 global interrupt  */
#define PI_DMA21                    56   /* DMA2 Channel1 global interrupt  */
#define PI_DMA22                    57   /* DMA2 Channel2 global interrupt  */
#define PI_DMA23                    58   /* DMA2 Channel3 global interrupt  */
#define PI_DMA24_5                  59   /* DMA2 Channel4 and DMA2 Channel5 global interrupts  */
#define PI_INT_NUMBER               60   /* Interrupt vectors Number*/

/* Software interrupt number for micro T-Kernel */
#define SWI_SVC		                77   /* micro T-Kernel system call/extension SVC */
#define SWI_RETINT	                78   /* tk_ret_int() system call,equal (SWI_SVC+1) */
#define SWI_DEBUG	                79   /* Debugger support function,equal (SWI_SVC+2) */

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
//#define USART1_BASE                 0x40013800
#define USART2_BASE                 0x40004400
#define USART_SR                    0x00 /* Status register */
#define USART_DR                    0x04 /* Data register */
#define USART_BRR                   0x08 /* Baud rate register */
#define USART_CR1                   0x0c /* Control register 1 */
#define USART_CR2                   0x10 /* Control register 2 */
#define USART_CR3                   0x14 /* Control register 3 */
#define USART_GTPR                  0x18 /* Guard time and prescaler register */

/* USART_SR Register              */
#define USART_SR_CTS_SHIFT          0x09
#define USART_SR_LBD_SHIFT          0x08
#define USART_SR_TXE_SHIFT          0x07
#define USART_SR_TC_SHIFT           0x06
#define USART_SR_RXNE_SHIFT         0x05
#define USART_SR_IDLE_SHIFT         0x04
#define USART_SR_ORE_SHIFT          0x03
#define USART_SR_NE_SHIFT           0x02
#define USART_SR_FE_SHIFT           0x01
#define USART_SR_PE_SHIFT           0x00

/* USART_DR Register              */
#define USART_DR_MASK               0x000001ff

/* USART_BRR Register             */
#define USART_BRR_MANTISSA_SHIFT    0x04

/* USART_CR1 Register             */
#define USART_CR1_UE_SHIFT          0x0d
#define USART_CR1_M_SHIFT           0x0c
#define USART_CR1_WAKE_SHIFT        0x0b
#define USART_CR1_PCE_SHIFT         0x0a
#define USART_CR1_PS_SHIFT          0x09
#define USART_CR1_PEIE_SHIFT        0x08
#define USART_CR1_TXEIE_SHIFT       0x07
#define USART_CR1_TCEIE_SHIFT       0x06
#define USART_CR1_RXNEIE_SHIFT      0x05
#define USART_CR1_IDLEIE_SHIFT      0x04
#define USART_CR1_TE_SHIFT          0x03
#define USART_CR1_RE_SHIFT          0x02
#define USART_CR1_RWU_SHIFT         0x01
#define USART_CR1_SBK_SHIFT         0x00


/* USART_CR2 Register             */
#define USART_CR2_LINEN_SHIFT       0x0e
#define USART_CR2_STOP_SHIFT        0x0c
#define USART_CR2_CLKEN_SHIFT       0x0b
#define USART_CR2_CPOL_SHIFT        0x0a
#define USART_CR2_CPHA_SHIFT        0x09
#define USART_CR2_LBCL_SHIFT        0x08
#define USART_CR2_LBDIE_SHIFT       0x06
#define USART_CR2_LBDL_SHIFT        0x05
#define USART_CR2_ADD_SHIFT         0x00

/* USART_CR3 Register             */
#define USART_CR3_CTSIE_SHIFT       0x0a
#define USART_CR3_CTSE_SHIFT        0x09
#define USART_CR3_RTSE_SHIFT        0x08
#define USART_CR3_DMAT_SHIFT        0x07
#define USART_CR3_DMAR_SHIFT        0x06
#define USART_CR3_SCEN_SHIFT        0x05
#define USART_CR3_NACK_SHIFT        0x04
#define USART_CR3_HDSEL_SHIFT       0x03
#define USART_CR3_IRLP_SHIFT        0x02
#define USART_CR3_IREN_SHIFT        0x01
#define USART_CR3_EIE_SHIFT         0x00

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
 * Independent Watch Dog
 */
#define IWDT_BASE                   0x40003000
#define IWDG_KR                     0x00 /* Key register */
#define IWDG_PR                     0x04 /* Prescaler register */
#define IWDG_RL                     0x08 /* Reload register */
#define IWDG_SR                     0x0c /* State register */

/*
 * Window Watch Dog
 */
#define WWDT_BASE                   0x40002c00
#define WWDG_CR                     0x00 /* Control register */
#define WWDG_CFR                    0x04 /* Configuration register */
#define WWDG_SR                     0x08 /* Status register */

#endif /* __TK_SYSDEF_DEPEND_H__ */
