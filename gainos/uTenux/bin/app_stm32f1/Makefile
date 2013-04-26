#
#------------------------------------------------------------------------------
#    Bin
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
#	 Create Date    : 2012/7/9-2012/7/9
#	 Author	        : WangShb
#	 Description    : bin Makefile for gmake.
#-------------------------------------------------------------------------------
#BD=F:/parai@foxmail.com/github/GaInOS_Based_On_uTenux-tkernel/gainos/uTenux
BD=D:/usr/GaInOS_Based_On_uTenux-tkernel/gainos/uTenux
export BD;
#CHIP selected
CHIP=STM32F107VC
export CHIP;
GCC_EXEC_PREFIX=c:/uLoong/uT-Studio/v300/gcc/libexec/gcc/
export GCC_EXEC_PREFIX;
GNUARM=c:/uLoong/uT-Studio/v300/gcc/arm-none-eabi
export GNUARM;
GNU_BD=c:/uLoong/uT-Studio/v300/gcc
export GNU_BD;
MODE=debug
export MODE;

# Tenux Target Type
MACHINE = stm32f1
TETYPE	= app

# default rules
include $(BD)/etc/makerules

#version of uTenux used
CFLAGS += -DMICRO_TENUX_VERSION=140

# source files (system-dependent)
SRC	= 

# include main makefile (common description)
include ../Makefile.common
