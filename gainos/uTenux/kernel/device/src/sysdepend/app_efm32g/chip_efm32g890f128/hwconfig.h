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
 *    CPU:        CORTEX M3
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : hwconfig.h
 *	 Create Date    : 2011/02/12-2012/7/18
 *	 Author	        : Wangxd
 *	 Description    : hardware configuration(EFM32G890F128).
 *-------------------------------------------------------------------------------
 */

#ifndef _HWCONFIG_H_
#define _HWCONFIG_H_

#define USE_TMONITOR            1

#define CMU_IEN_DIS             0x00000000     /* Disable interrupt              */
#define CMU_OSCENCMD_HFRCO      0x00000199     /* Enable HFRCO                   */
#define CMU_CMD_HFRCO           0x00000001     /* Select HFRCO as HFCLK          */
#define CMU_HRCORECLKDIV_HFCLK  0x00000000     /* HFCLK=HFCORECLK                */
#define CMU_HFPERCLKDIV_HFCLK   0x00000100     /* HFPERCLK=HFCLK Enable HFPERCLK */

#define INTERNAL_RAM_SIZE       0x00004000
#define INTERNAL_RAM_START      0x20000000
#define INTERNAL_RAM_END        0x20004000

#define INTERNAL_FLASH_SIZE     0x00020000
#define INTERNAL_FLASH_START    0x00000000
#define INTERNAL_FLASH_END      0x00020000

#endif /* _HWCONFIG_H_ */
