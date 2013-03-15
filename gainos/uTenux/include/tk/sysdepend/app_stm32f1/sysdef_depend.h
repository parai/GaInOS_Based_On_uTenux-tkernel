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
 *	 Description    : register Definition about cpu(tk/STM32F1).
 *-------------------------------------------------------------------------------
 */

#ifdef _CHIP_STM32F103ZE_
#include "chip_stm32f103ze/sysdef_depend.h"
#endif

#ifdef _CHIP_STM32F103VE_
#include "chip_stm32f103ve/sysdef_depend.h"
#endif

#ifdef _CHIP_STM32F107VC_
#include "chip_stm32f107vc/sysdef_depend.h"
#endif
