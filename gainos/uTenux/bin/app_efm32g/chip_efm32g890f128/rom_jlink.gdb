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
#    CPU:        EFM32G890F128
#    RTOS:       uT-Kernel
#    Version:    1.4.00
#    Released by T-Engine China Open Source Society
#                  (http://www.tecoss.org).
#
#	 File Name      : rom_jlink.gdb
#	 Create Date    : 2011/02/27-2012/9/26
#	 Author	        : Wangxd-Dengjk
#	 Description    : Gdb Script for J-Link 4.36f above.
#-------------------------------------------------------------------------------

# Step1: Connect to the J-Link gdb server
target remote localhost:2331

# Step2: Set gdb server to little endian
monitor endian little

# Step3: Set specific flash device
monitor flash device = EFM32G890F128

# Step4: Enable flash download
monitor flash download = 1

# Step5: Enable flash breakpoint
monitor flash breakpoints = 1

# Step6: Sleep 100ms
monitor sleep 100

# Step7: Reset MCU to a known state 
monitor reset

# Step8: Set JTAG speed higher for faster downloading 
monitor speed 30

# Step8: Sleep 100ms
monitor sleep 100

# Step10: Load file
#load bin/app_efm32g/kernel-rom.mot

# Step11: Load symbol
#symbol-file bin/app_efm32g/kernel-rom.rom

# Step12: Sleep 100ms
#monitor sleep 100

# Step13: Perpheral reset RSTC_CR
#set * = 

# Step14: Initializing stack pointer
monitor reg sp=(0x00000000)

# Step15: Initializing PC
monitor reg pc=(0x00000004)

# Step16: Set breakpoint
break usermain

# Step17: Resume and go
continue