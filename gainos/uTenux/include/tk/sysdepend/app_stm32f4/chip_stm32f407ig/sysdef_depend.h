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
 *	 Create Date    : 2011/11/29-2013/1/15
 *	 Author	        : WangShb-Zhangzl
 *	 Description    : register Definition about cpu(tk/STM32F407IG).
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
 * Internal Flash Memroy Controller
 */
#define FLASH_BASE                  0x40023C00
#define FLASH_ACR                   0x00 /* Flash access control register */
#define FLASH_KEYR                  0x04 /* Flash key register */
#define FLASH_OPTKEYR               0x08 /* Flash option key register */
#define FLASH_SR                    0x0c /* Flash state register */
#define FLASH_CR                    0x10 /* Flash control register */
#define FLASH_OPTCR                 0x14 /* Flash option control register */

/* FLASH_ACR Register             */
#define FLASH_ACR_DCRST_SHIFT       0x0c
#define FLASH_ACR_ICRST_SHIFT       0x0b
#define FLASH_ACR_DCEN_SHIFT        0x0a
#define FLASH_ACR_ICEN_SHIFT        0x09
#define FLASH_ACR_PRFTEN_SHIFT      0x08
#define FLASH_ACR_LATENCY_MASK      0xfffffff8
#define FLASH_ACR_LATENCY_0         0x00000000
#define FLASH_ACR_LATENCY_1         0x00000001
#define FLASH_ACR_LATENCY_2         0x00000002
#define FLASH_ACR_LATENCY_3         0x00000003
#define FLASH_ACR_LATENCY_4         0x00000004
#define FLASH_ACR_LATENCY_5         0x00000005
#define FLASH_ACR_LATENCY_6         0x00000006
#define FLASH_ACR_LATENCY_7         0x00000007

/* FLASH_KEYR Register            */
#define FLASH_KEYR_KEY1             0x45670123
#define FLASH_KEYR_KEY2             0xCDEF89AB

/* FLASH_CR Register            */
#define FLASH_CR_LOCK_SHIFT         0x1F

/*
 * Reset and Clock Control
 */
#define RCC_BASE                    0x40023800
#define RCC_CR                      0x00 /* Clock control register */
#define RCC_PLLCFGR                 0x04 /* PLL clock configuration register */
#define RCC_CFGR                    0x08 /* Clock configuration register */
#define RCC_CIR                     0x0c /* Clock interrupt register */
#define RCC_AHB1RSTR                0x10 /* AHB1 peripheral reset register */
#define RCC_AHB2RSTR                0x14 /* AHB2 peripheral reset register */
#define RCC_AHB3RSTR                0x18 /* AHB3 peripheral reset register */
#define RCC_APB1RSTR                0x20 /* APB1 peripheral reset register */
#define RCC_APB2RSTR                0x24 /* APB2 peripheral reset register */
#define RCC_AHB1ENR                 0x30 /* AHB1 Peripheral Clock enable register */
#define RCC_AHB2ENR                 0x34 /* AHB2 Peripheral Clock enable register */
#define RCC_AHB3ENR                 0x38 /* AHB3 Peripheral Clock enable register */
#define RCC_APB1ENR                 0x40 /* APB1 peripheral clock enable register */
#define RCC_APB2ENR                 0x44 /* APB2 peripheral clock enable register */
#define RCC_AHB1LPENR               0x50 /* AHB1 Peripheral Low Power Clock enable register */
#define RCC_AHB2LPENR               0x54 /* AHB2 Peripheral Low Power Clock enable register */
#define RCC_AHB3LPENR               0x58 /* AHB3 Peripheral Low Power Clock enable register */
#define RCC_APB1LPENR               0x60 /* APB1 peripheral Low Power clock enable register */
#define RCC_APB2LPENR               0x64 /* APB2 peripheral Low Power clock enable register */
#define RCC_BDCR                    0x70 /* Backup domain control register */
#define RCC_CSR                     0x74 /* Control/status register */
#define RCC_SSCGR                   0x80 /* Spread spectrum clock generation register */
#define RCC_PLLI2SCFGR              0x84 /* PLLI2S configuration register */

/* RCC_CR Register                */
#define RCC_CR_PLLI2SRDY_MASK       0xf7ffffff
#define RCC_CR_PLLI2SRDY_SET        0x08000000
#define RCC_CR_PLLI2SON_MASK        0xfbffffff
#define RCC_CR_PLLI2SON_SET         0x04000000
#define RCC_CR_PLLRDY_MASK          0xfdffffff
#define RCC_CR_PLLRDY_SET           0x02000000
#define RCC_CR_PLLON_MASK           0xfffffff
#define RCC_CR_PLLON_SET            0x01000000
#define RCC_CR_CSSON_MASK           0xfff7ffff
#define RCC_CR_CSSON_SET            0x00080000
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

/* RCC_PLLCFGR Register           */
#define RCC_PLLCFGR_PLLQ_MASK       0xf0ffffff
#define RCC_PLLCFGR_PLLQ_DIV(x)     ((x)<<24)   /*x is between 2 and 15 */
#define RCC_PLLCFGR_PLLSRC_MASK     0xffbfffff
#define RCC_PLLCFGR_PLLSRC_HSI      0x00000000
#define RCC_PLLCFGR_PLLSRC_HSE      0x00400000
#define RCC_PLLCFGR_PLLP_MASK       0xfffcffff
#define RCC_PLLCFGR_PLLP_DIV(x)     ((x)<<16)   /*x is between 2 and 8 */
#define RCC_PLLCFGR_PLLN_MASK       0xffff8f3f
#define RCC_PLLCFGR_PLLN_MUL(x)     ((x)<<6)   /*x is between 2 and 432 */
#define RCC_PLLCFGR_PLLM_MASK       0xffffffc0
#define RCC_PLLCFGR_PLLM_DIV(x)     ((x)<<0)   /*x is between 2 and 63 */

/* RCC_CFGR Register              */
#define RCC_CFGR_PPRE2_MASK         0xffff1fff
#define RCC_CFGR_PPRE2_DIV_1        0x00000000
#define RCC_CFGR_PPRE2_DIV_2        0x00008000
#define RCC_CFGR_PPRE2_DIV_4        0x0000a000
#define RCC_CFGR_PPRE2_DIV_8        0x0000c000
#define RCC_CFGR_PPRE2_DIV_16       0x0000e000
#define RCC_CFGR_PPRE1_MASK         0xffffe3ff
#define RCC_CFGR_PPRE1_DIV_1        0x00000000
#define RCC_CFGR_PPRE1_DIV_2        0x00001000
#define RCC_CFGR_PPRE1_DIV_4        0x00001400
#define RCC_CFGR_PPRE1_DIV_5        0x00001800
#define RCC_CFGR_PPRE1_DIV_16       0x00001c00
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


/* RCC_AHB1ENR Register           */
#define RCC_AHB1ENR_OTGHSULPIEN_SHIFT   0x1e
#define RCC_AHB1ENR_OTGHSEN_SHIFT       0x1d
#define RCC_AHB1ENR_ETHMACPTPEN_SHIFT   0x1c
#define RCC_AHB1ENR_ETHMACRXEN_SHIFT    0x1b
#define RCC_AHB1ENR_ETHMACRXEN_SHIFT    0x1b
#define RCC_AHB1ENR_ETHMACTXEN_SHIFT    0x1a
#define RCC_AHB1ENR_ETHMACEN_SHIFT      0x19
#define RCC_AHB1ENR_DMA2EN_SHIFT        0x16
#define RCC_AHB1ENR_DMA1EN_SHIFT        0x15
#define RCC_AHB1ENR_CCMDATARAMEN_SHIFT  0x14
#define RCC_AHB1ENR_BKPSRAMEN_SHIFT     0x12
#define RCC_AHB1ENR_CRCEN_SHIFT         0x0c
#define RCC_AHB1ENR_GPIOIEN_SHIFT       0x08
#define RCC_AHB1ENR_GPIOHEN_SHIFT       0x07
#define RCC_AHB1ENR_GPIOGEN_SHIFT       0x06
#define RCC_AHB1ENR_GPIOFEN_SHIFT       0x05
#define RCC_AHB1ENR_GPIOEEN_SHIFT       0x04
#define RCC_AHB1ENR_GPIODEN_SHIFT       0x03
#define RCC_AHB1ENR_GPIOCEN_SHIFT       0x02
#define RCC_AHB1ENR_GPIOBEN_SHIFT       0x01
#define RCC_AHB1ENR_GPIOAEN_SHIFT       0x00

/* RCC_APB1ENR Register           */
#define RCC_APB1ENR_DACEN_SHIFT     0x1d
#define RCC_APB1ENR_PWREN_SHIFT     0x1c
#define RCC_APB1ENR_CAN2EN_SHIFT    0x1a
#define RCC_APB1ENR_CAN1EN_SHIFT    0x19
#define RCC_APB1ENR_I2C3EN_SHIFT    0x17
#define RCC_APB1ENR_I2C2EN_SHIFT    0x16
#define RCC_APB1ENR_I2C1EN_SHIFT    0x15
#define RCC_APB1ENR_UART5EN_SHIFT   0x14
#define RCC_APB1ENR_UART4EN_SHIFT   0x13
#define RCC_APB1ENR_USART3EN_SHIFT  0x12
#define RCC_APB1ENR_USART2EN_SHIFT  0x11
#define RCC_APB1ENR_SPI3EN_SHIFT    0x0f
#define RCC_APB1ENR_SPI2EN_SHIFT    0x0e
#define RCC_APB1ENR_WWDGEN_SHIFT    0x0b
#define RCC_APB1ENR_TIM14EN_SHIFT   0x08
#define RCC_APB1ENR_TIM13EN_SHIFT   0x07
#define RCC_APB1ENR_TIM12EN_SHIFT   0x06
#define RCC_APB1ENR_TIM7EN_SHIFT    0x05
#define RCC_APB1ENR_TIM6EN_SHIFT    0x04
#define RCC_APB1ENR_TIM5EN_SHIFT    0x03
#define RCC_APB1ENR_TIM4EN_SHIFT    0x02
#define RCC_APB1ENR_TIM3EN_SHIFT    0x01
#define RCC_APB1ENR_TIM2EN_SHIFT    0x00

/* RCC_APB2ENR Register           */
#define RCC_APB1ENR_TIM11EN_SHIFT   0x12
#define RCC_APB1ENR_TIM10EN_SHIFT   0x11
#define RCC_APB1ENR_TIM9EN_SHIFT    0x10
#define RCC_APB2ENR_SYSCFGEN_SHIFT  0x0e
#define RCC_APB2ENR_SPI1EN_SHIFT    0x0c
#define RCC_APB2ENR_SDIOEN_SHIFT    0x0b
#define RCC_APB2ENR_ADC3EN_SHIFT    0x0a
#define RCC_APB2ENR_ADC2EN_SHIFT    0x09
#define RCC_APB2ENR_ADC1EN_SHIFT    0x08
#define RCC_APB2ENR_USART6EN_SHIFT  0x05
#define RCC_APB2ENR_USART1EN_SHIFT  0x04
#define RCC_APB2ENR_TIM8EN_SHIFT    0x01
#define RCC_APB2ENR_TIM1EN_SHIFT    0x00

/*
 *  General-purpose IO
 */
#define GPIOA_BASE                  0x40020000 /* Port A  adress */
#define GPIOB_BASE  			    0x40020400 /* Port B  adress */
#define GPIOC_BASE                  0x40020800 /* Port C  adress */
#define GPIOD_BASE                  0x40020C00 /* Port D  adress */
#define GPIOE_BASE                  0x40021000 /* Port E  adress */
#define GPIOF_BASE                  0x40021400 /* Port F  adress */
#define GPIOG_BASE                  0x40021800 /* Port G  adress */
#define GPIOH_BASE                  0x40021C00 /* Port H  adress */
#define GPIOI_BASE                  0x40022000 /* Port I  adress */
#define GPIO_MODER                  0x00 /* Port mode register*/
#define GPIO_OTYPER                 0x04 /* Port output type register*/
#define GPIO_OSPEEDR                0x08 /* Port output speed register*/
#define GPIO_PUPDR                  0x0c /* Port pull-up/pull-down register*/
#define GPIO_IDR                    0x10 /* Port input data register */
#define GPIO_ODR                    0x14 /* Port output data register */
#define GPIO_BSRR                   0x18 /* Port bit set/reset register */
#define GPIO_LCKR                   0x1c /* Port configuration lock register */
#define GPIO_AFRL                   0x20 /* Alternate function low register */
#define GPIO_AFRH                   0x24 /* Alternate function high register */

/* GPIO_MODER   Register          */
#define GPIO_MODER_MASK             0x03
#define GPIO_MODER_INPUT            0x00
#define GPIO_MODER_OUTPUT           0x01
#define GPIO_MODER_AF               0x02
#define GPIO_MODER_ANALOG           0x03
#define GPIO_MODER_SHIFT(x)         (0x02*(x))

/* GPIO_OTYPER  Register          */
#define GPIO_OTYPER_MASK            0x01
#define GPIO_OTYPER_PUSHPULL        0x00
#define GPIO_OTYPER_OPENDRAIN       0x01
#define GPIO_OTYPER_SHIFT(x)        (0x01*(x))

/* GPIO_OSPEEDR Register          */
#define GPIO_OSPEEDR_MASK           0x03
#define GPIO_OSPEEDR_2M             0x00
#define GPIO_OSPEEDR_25M            0x01
#define GPIO_OSPEEDR_50M            0x02
#define GPIO_OSPEEDR_100M           0x03
#define GPIO_OSPEEDR_SHIFT(x)       (0x02*(x))

/* GPIO_PUPDR Register            */
#define GPIO_PUPDR_MASK             0x03
#define GPIO_PUPDR_NO               0x00
#define GPIO_PUPDR_PULLUP           0x01
#define GPIO_PUPDR_PULLDOWN         0x02
#define GPIO_PUPDR_SHIFT(x)         (0x02*(x))

/* GPIO_IDR Register              */
#define GPIO_IDR_SHIFT(x)          (0x01*(x))

/* GPIO_ODR Register              */
#define GPIO_ODR_SHIFT(x)          (0x01*(x))

/* GPIO_AFRL and AFRH Register   */
#define GPIO_AFR_MASK              0x04
#define GPIO_AFR_AF0               0x00
#define GPIO_AFR_AF1               0x01
#define GPIO_AFR_AF2               0x02
#define GPIO_AFR_AF3               0x03
#define GPIO_AFR_AF4               0x04
#define GPIO_AFR_AF5               0x05
#define GPIO_AFR_AF6               0x06
#define GPIO_AFR_AF7               0x07
#define GPIO_AFR_AF8               0x08
#define GPIO_AFR_AF9               0x09
#define GPIO_AFR_AF10              0x0a
#define GPIO_AFR_AF11              0x0b
#define GPIO_AFR_AF12              0x0c
#define GPIO_AFR_AF13              0x0d
#define GPIO_AFR_AF14              0x0e
#define GPIO_AFR_AF15              0x0f
#define GPIO_AFRH_SHIFT(x)         (0x04*(x-8))
#define GPIO_AFRL_SHIFT(x)         (0x04*(x))

/*
 * Nested Vectored Interrupt Controller
 */

/* Interrupt vectors Define            */
#define PI_WWDG                     0    /*  Window Watchdog interrupt */
#define PI_PVD                      1    /*  PVD through EXTI line detection interrupt */
#define PI_TAMP_STAMP               2    /*  Tamper and TimeStamp interrupts through the EXTI line */
#define PI_RTC_WKUP                 3    /*  RTC Wakeup interrupt through the EXTI line */
#define PI_FLASH                    4    /*  Flash global interrupt */
#define PI_RCC                      5    /*  RCC global interrupt */
#define PI_EXTI0                    6    /*  EXTI Line0 interrupt */
#define PI_EXTI1                    7    /*  EXTI Line1 interrupt */
#define PI_EXTI2                    8    /*  EXTI Line2 interrupt */
#define PI_EXTI3                    9    /*  EXTI Line3 interrupt */
#define PI_EXTI4                    10   /*  EXTI Line4 interrupt */
#define PI_DMA1_STREAM0             11   /*  DMA1 Stream0 global interrupt */
#define PI_DMA1_STREAM1             12   /*  DMA1 Stream1 global interrupt */
#define PI_DMA1_STREAM2             13   /*  DMA1 Stream2 global interrupt */
#define PI_DMA1_STREAM3             14   /*  DMA1 Stream3 global interrupt */
#define PI_DMA1_STREAM4             15   /*  DMA1 Stream4 global interrupt */
#define PI_DMA1_STREAM5             16   /*  DMA1 Stream5 global interrupt */
#define PI_DMA1_STREAM6             17   /*  DMA1 Stream6 global interrupt */
#define PI_ADC                      18   /*  ADC1, ADC2 and ADC3 global interrupts */
#define PI_CAN1_TX                  19   /*  CAN1 TX interrupts */
#define PI_CAN1_RX0                 20   /*  CAN1 RX0 interrupts */
#define PI_CAN1_RX1                 21   /*  CAN1 RX1 interrupt */
#define PI_CAN1_SCE                 22   /*  CAN1 SCE interrupt */
#define PI_EXTI9_5                  23   /*  EXTI Line[9:5] interrupts */
#define PI_TIM1_BRK_TIM9            24   /*  TIM1 Break interrupt and TIM9 global interrupt */
#define PI_TIM1_UP_TIM10            25   /*  TIM1 Update interrupt and TIM10 global interrupt */
#define PI_TIM1_TRG_COM_TIM11       26   /*  TIM1 Trigger and Commutation interrupts and TIM11 global interrupt */
#define PI_TIM1_CC                  27   /*  TIM1 Capture Compare interrupt */
#define PI_TIM2                     28   /*  TIM2 global interrupt */
#define PI_TIM3                     29   /*  TIM3 global interrupt */
#define PI_TIM4                     30   /*  TIM4 global interrupt */
#define PI_I2C1_EV                  31   /*  I2C1 event interrupt */
#define PI_I2C1_ER                  32   /*  I2C1 error interrupt */
#define PI_I2C2_EV                  33   /*  I2C2 event interrupt */
#define PI_I2C2_ER                  34   /*  I2C2 error interrupt */
#define PI_SPI1                     35   /*  SPI1 global interrupt */
#define PI_SPI2                     36   /*  SPI2 global interrupt */
#define PI_USART1                   37   /*  USART1 global interrupt */
#define PI_USART2                   38   /*  USART2 global interrupt */
#define PI_USART3                   39   /*  USART3 global interrupt */
#define PI_EXTI15_10                40   /*  EXTI Line[15:10] interrupts */
#define PI_RTC_ALARM                41   /*  RTC Alarms (A and B) through EXTI line interrupt */
#define PI_OTG_FS_WKUP              42   /*  USB On-The-Go FS Wakeup through EXTI line interrupt */
#define PI_TIM8_BRK_TIM12           43   /*  TIM8 Break interrupt and TIM12 global interrupt */
#define PI_TIM8_UP                  44   /*  TIM8 Update interrupt and TIM13 global interrupt */
#define PI_TIM8_TRG_COM             45   /*  TIM8 Trigger and Commutation interrupts and TIM14 global interrupt */
#define PI_TIM8_CC                  46   /*  TIM8 Capture Compare interrupt */
#define PI_DMA1_STREAM7             47   /*  DMA1 Stream7 global interrupt */
#define PI_FSMC                     48   /*  FSMC global interrupt */
#define PI_SDIO                     49   /*  SDIO global interrupt */
#define PI_TIM5                     50   /*  TIM5 global interrupt */
#define PI_SPI3                     51   /*  SPI3 global interrupt */
#define PI_UART4                    52   /*  UART4 global interrupt */
#define PI_UART5                    53   /*  UART5 global interrupt */
#define PI_TIM6_DAC                 54   /*  TIM6 global interrupt, DAC1 and DAC2 underrun error interrupts */
#define PI_TIM7                     55   /*  TIM7 global interrupt */
#define PI_DMA2_STREAM0             56   /*  DMA2 Stream0 global interrupt */
#define PI_DMA2_STREAM1             57   /*  DMA2 Stream1 global interrupt */
#define PI_DMA2_STREAM2             58   /*  DMA2 Stream2 global interrupt */
#define PI_DMA2_STREAM3             59   /*  DMA2 Stream3 global interrupt */
#define PI_DMA2_STREAM4             60   /*  DMA2 Stream4 global interrupt */
#define PI_ETH                      61   /*  Ethernet global interrupt */
#define PI_ETH_WKUP                 62   /*  Ethernet Wakeup through EXTI line interrupt */
#define PI_CAN2_TX                  63   /*  CAN2 TX interrupts */
#define PI_CAN2_RX0                 64   /*  CAN2 RX0 interrupts */
#define PI_CAN2_RX1                 65   /*  CAN2 RX1 interrupt */
#define PI_CAN2_SCE                 66   /*  CAN2 SCE interrupt */
#define PI_OTG_FS                   67   /*  USB On The Go FS global interrupt */
#define PI_DMA2_STREAM5             68   /*  DMA2 Stream5 global interrupt */
#define PI_DMA2_STREAM6             69   /*  DMA2 Stream6 global interrupt */
#define PI_DMA2_STREAM7             70   /*  DMA2 Stream7 global interrupt */
#define PI_USART6                   71   /*  USART6 global interrupt */
#define PI_I2C3_EV                  72   /*  I2C3 event interrupt */
#define PI_I2C3_ER                  73   /*  I2C3 error interrupt */
#define PI_OTG_HS_EP1_OUT           74   /*  USB On The Go HS End Point 1 Out global interrupt */
#define PI_OTG_HS_EP1_IN            75   /*  USB On The Go HS End Point 1 In global interrupt */
#define PI_OTG_HS_WKUP              76   /*  USB On The Go HS Wakeup through EXTI interrupt */
#define PI_OTG_HS                   77   /*  USB On The Go HS global interrupt */
#define PI_DCMI                     78   /*  DCMI global interrupt */
#define PI_CRYP                     79   /*  CRYP crypto global interrupt */
#define PI_HASH_RNG                 80   /*  Hash and Rng global interrupt */
#define PI_FPU                      81   /*  FPU global interrupt */
#define PI_INT_NUMBER               82    /* Interrupt vectors Number*/

/* Software interrupt number for micro T-Kernel */
#define SWI_SVC		                99   /* micro T-Kernel system call/extension SVC */
#define SWI_RETINT	                100  /* tk_ret_int() system call,equal (SWI_SVC+1) */
#define SWI_DEBUG	                101  /* Debugger support function,equal (SWI_SVC+2) */

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
 * Universal synchronous asynchronous receiver transmitter
 */
#define USART1_BASE                 0x40011000
#define USART2_BASE                 0x40004400
#define USART3_BASE                 0x40004800
#define UART4_BASE                  0x40004C00
#define UART5_BASE                  0x40005000
#define USART6_BASE                 0x40014000
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
#define USART_CR3_ONEBIT_SHIFT      0x0b
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
#define IWDG_BASE                   0x40003000
#define IWDG_KR                     0x00 /* Key register */
#define IWDG_PR                     0x04 /* Prescaler register */
#define IWDG_RL                     0x08 /* Reload register */
#define IWDG_SR                     0x0c /* State register */

/*
 * Window Watch Dog
 */
#define WWDG_BASE                   0x40002c00
#define WWDG_CR                     0x00 /* Control register */
#define WWDG_CFR                    0x04 /* Configuration register */
#define WWDG_SR                     0x08 /* Status register */

#endif /* __TK_SYSDEF_DEPEND_H__ */
