#
#------------------------------------------------------------------------------
#    App
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
#	 Description    : App Makefile for gmake.
#-------------------------------------------------------------------------------

# Tenux Target Type
MACHINE = stm32f1
TETYPE = app
CPU_ARCH = cortex

# default rules
include ../../../etc/makerules

# include main makefile (common description)
#include ../../src/Makefile.common
#by parai, just put the common file here

# source file dependencies (generated automatically)
DEPS = Dependencies
DEPENDENCIES_OUTPUT := $(DEPS)

# ----------------------------------------------------------------------------

# target object
TARGET	= libautosar.a

S	= ../../
MKFF	= $(BD)/etc/mkfuncfiles

# common source files (not to be devided)
SRC	+=		\
./comstack/CanIf/CanIf.c     \
./comstack/CanTp/CanTp.c     \
./comstack/Com/Com.c     \
./comstack/Com/Com_Com.c     \
./comstack/Com/Com_misc.c     \
./comstack/Com/Com_Sched.c     \
./comstack/config/CanIf/CanIf_Cfg.c     \
./comstack/config/CanTp/CanTp_Cfg.c     \
./comstack/config/Com/Com_CalloutNotification.c     \
./comstack/config/Com/Com_PbCfg.c     \
./comstack/config/PduR/PduR_PbCfg.c     \
./comstack/PduR/PduR.c     \
./comstack/PduR/PduR_CanIf.c     \
./comstack/PduR/PduR_CanTp.c     \
./comstack/PduR/PduR_Com.c     \
./comstack/PduR/PduR_Dcm.c     \
./comstack/PduR/PduR_J1939Tp.c     \
./comstack/PduR/PduR_LinIf.c     \
./comstack/PduR/PduR_Logic.c     \
./comstack/PduR/PduR_Routing.c     \
./comstack/PduR/PduR_SoAd.c     \
./diag/Det/Det.c     \
./mcal/config/Can/sysdepend/$(TETYPE)_$(MACHINE)/$(CHIP)/Can_PBCfg.c \
./mcal/driver/Can/sysdepend/$(TETYPE)_$(MACHINE)/$(CHIP)/Can_Hw.c     \
./mcal/driver/Can/Can.c


VPATH	+= $(S)
HEADER	+= $(S)

# additional source files (cpu-dependent)
VPATH   += ../../../cpu/src/sysdepend/$(CPU_ARCH)
HEADER	+= ../../../cpu/src/sysdepend/$(CPU_ARCH)

# additional source files (device-dependent)
VPATH   += ../../../device/src/sysdepend/$(TETYPE)_$(MACHINE)
HEADER	+= ../../../device/src/sysdepend/$(TETYPE)_$(MACHINE)

# header file path (T-Kernel common standard library)
HEADER  += ../../../tstd/src

# config file path (kernel settings)
HEADER  += ../../../../config

# syscall source files (cpu-dependent)
VPATH   += ../../../cpu/src/sysdepend/$(CPU_ARCH)
HEADER	+= ../../../cpu/src/sysdepend/$(CPU_ARCH)


OBJ = $(addsuffix .o, $(basename $(SRC)))
OBJ += $(FUNCOBJ)

ASM_SRC = $(filter %.S, $(SRC))
ASM_OBJ	= $(addsuffix .o, $(basename $(ASM_SRC)))

# compiler options
CFLAGS += $(CFLAGS_WARNING) \
	-I$(BD)/kernel/tkernel/src	\
	-I$(BD)/config -I$(BD)/kernel/cpu/src/sysdepend/$(CPU_ARCH)	\
	-I$(BD)/kernel/osek/src/config	\
	-I$(BD)/kernel/osek/src	\
	-I$(BD)/autosar/include	\
	-I$(BD)/autosar/comstack/CanIf/ \
	-I$(BD)/autosar/comstack/CanTp/ \
	-I$(BD)/autosar/comstack/Com/ \
	-I$(BD)/autosar/comstack/config/CanIf/ \
	-I$(BD)/autosar/comstack/config/CanTp/ \
	-I$(BD)/autosar/comstack/config/Com/ \
	-I$(BD)/autosar/comstack/config/PduR/ \
	-I$(BD)/autosar/comstack/PduR/ \
	-I$(BD)/autosar/diag/Dem/ \
	-I$(BD)/autosar/diag/Det/ \
	-I$(BD)/autosar/ecual/EcuM/ \
	-I$(BD)/autosar/include/sysdepend/ \
	-I$(BD)/autosar/mcal/driver/Can/ \
	-I$(BD)/autosar/mcal/config/Can/sysdepend/$(TETYPE)_$(MACHINE)/$(CHIP)/ \
	-I$(BD)/autosar/mcal/driver/Can/sysdepend/$(TETYPE)_$(MACHINE)/$(CHIP)/

# ----------------------------------------------------------------------------

.PHONY: all clean install

ALL = $(TARGET) 

all: $(ALL)

$(TARGET): $(OBJ)
	$(AR) $(ARFLAGS) $@ $?
  ifdef RANLIB
	$(RANLIB) $@
  endif

install: $(addprefix $(KNL_INSTALLDIR)/, $(ALL))

clean:
	@$(RM) $(OBJ) $(TARGET) $(DEPS)

# generate dependencies
$(DEPS): ; touch $(DEPS)
-include $(DEPS)

