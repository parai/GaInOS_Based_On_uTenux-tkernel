/*
 *------------------------------------------------------------------------------
 *    Device
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
 *	 File Name      : hwconfig.h
 *	 Create Date    : 2011/11/29-2012/8/28
 *	 Author	        : WangShb
 *	 Description    : hardware configuration(STM32F407IG).
 *-------------------------------------------------------------------------------
 */

#ifndef _HWCONFIG_H_
#define _HWCONFIG_H_

#define USE_TMONITOR            1
#define CRYSTAL_ENABLE_MOSC     0x00010000 /*Set HSE oscilation as Source       */
#define CRYSTAL_ENABLE_PLL      0x01000000 /*Enable pll clock                   */
#define CRYSTAL_ENABLE_MCK      0x00405419 /*Set HSE as PLL Source,and PLLN/M/P */
#define CRYSTAL_ENABLE_PCK      0x00000002 /*Switch PLL as System Clock         */

#define INTERNAL_RAM_SIZE       0x0001C000
#define INTERNAL_RAM_START      0x20000000
#define INTERNAL_RAM_END        0x2001C000

#define INTERNAL_FLASH_SIZE     0x00100000
#define INTERNAL_FLASH_START    0x00000000
#define INTERNAL_FLASH_END      0x00100000

#endif /* _HWCONFIG_H_ */
