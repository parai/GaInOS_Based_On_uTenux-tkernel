#
#------------------------------------------------------------------------------
#    autosar
#
#    Copyright (C) 2008-2013 by Dalian uLoong Co.,Ltd. All rights reserved.
#
#    This program is open source software; developer can redistribute it and/or 
#    modify it under the terms of the U-License as published by the T-Engine China 
#    Open Source Society; either version 1 of the License, or (at developer option) 
#    any later Version.
#    
#    This program is distributed in the hope that it will be useful,but WITHOUT ANY 
#    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR 
#    A PARTICULAR PURPOSE.  See the U-License for more details.
#    
#    Developer should have received a copy of the U-License along with this program; 
#    if not, download from www.tecoss.org(the web page of the T-Engine China Open 
#    Source Society).
#
#    CPU:        CORTEX M3
#    RTOS:       uT-Kernel
#    Version:    1.4.00
#    Released by T-Engine China Open Source Society
#                  (http://www.tecoss.org).
#
#	 File Name      : makefile
#	 Create Date    : 2009/9/16-2012/6/10
#	 Author	        : WangShb
#	 Description    : library main Makefile for gmake.
#-------------------------------------------------------------------------------

# Tenux Target Type
MACHINE = stm32f1
TETYPE = app
CPU_ARCH = cortex

# default rules
include ../../../etc/makerules
#here add the special files(such as standard library)

# just add the CAN Driver
SRC += $(BD)/autosar/mcal/arch/$(MACHINE)/STM32F10x_StdPeriph_Driver/src/stm32f10x_can.c	\
$(BD)/autosar/mcal/arch/$(MACHINE)/STM32F10x_StdPeriph_Driver/src/stm32f10x_rcc.c

#defined STM32F10X_CL for STM32F107VC
CFLAGS +=-DSTM32F10X_CL	\
	-I$(BD)/autosar/mcal/arch/$(MACHINE)/STM32F10x_StdPeriph_Driver/inc	\
	-I$(BD)/autosar/mcal/arch/$(MACHINE)/cm3
# include main makefile (common description)
include ../../Makefile.common
