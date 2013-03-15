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
#    CPU:        LPC1788
#    RTOS:       uT-Kernel
#    Version:    1.4.00
#    Released by T-Engine China Open Source Society
#                  (http://www.tecoss.org).
#
#	 File Name      : rom_jlink.gdb
#	 Create Date    : 2011/02/27-2012/09/27
#	 Author	        : wangxd-wangxd
#	 Description    : Gdb Script for J-Link 4.36f above.(LPC1788)
#                     Step1: Connect to the J-Link gdb server
#                     Step2: Set gdb server to little endian
#                     Step3: Set specific flash device
#                     Step4: Enable flash download
#                     Step5: Enable flash breakpoint
#                     Step6: Sleep 100ms
#                     Step7: Reset MCU to a known state 
#                     Step8: Set JTAG speed higher for faster downloading 
#                     Step9: Sleep 100ms
#                     Step10: Load file
#                     Step11: Load symbol
#                     Step12: Sleep 100ms
#                     Step13: Perpheral reset 
#                     Step14: Initializing stack pointer
#                     Step15: Initializing PC
#                     Step16: Set breakpoint
#                     Step17: Resume and go
#-------------------------------------------------------------------------------

target remote localhost:2331

monitor endian little

monitor flash device = LPC1788

monitor flash download = 1

monitor flash breakpoints = 1

monitor sleep 100

monitor reset

monitor speed 30

monitor sleep 100

echo load bin/app_lpc17/kernel-rom.mot

echo symbol-file bin/app_lpc17/kernel-rom.rom

echo monitor sleep 100

echo set *  =

monitor reg sp=(0x00000000)

monitor reg pc=(0x00000004)

break usermain

continue