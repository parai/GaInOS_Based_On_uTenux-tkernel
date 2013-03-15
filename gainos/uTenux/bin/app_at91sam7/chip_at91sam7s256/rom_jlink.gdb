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
#    CPU:        AT91SAM7S256
#    RTOS:       uT-Kernel
#    Version:    1.4.00
#    Released by T-Engine China Open Source Society
#                  (http://www.tecoss.org).
#
#	 File Name      : rom_jlink.gdb
#	 Create Date    : 2009/7/27-2012/9/24
#	 Author	        : Cheny-wangshb
#	 Description    : Gdb Script for J-Link 4.14f above.
#                     Step1:  Connect to the J-Link gdb server
#                     Step2:  Set gdb server to little endian
#                     Step3:  Set specific flash device
#                     Step4:  Enable flash download
#                     Step5:  Enable flash breakpoint
#                     Step6:  Sleep 100ms
#                     Step7:  Reset MCU to a known state 
#                     Step8:  Set JTAG speed higher for faster downloading 
#                     Step9:  Sleep 100ms
#                     Step10: Load file
#                     Step11: Load symbol
#                     Step12: Sleep 100ms
#                     Step13: Perpheral reset
#                             WDT_MR, disable watchdog
#                             CKGR_MOR set
#                             CKGR_PLLR set
#                             PMC_MCKR set
#                             PMC_IER set
#                     Step14: Set breakpoint
#                     Step15: Resume and go
#-------------------------------------------------------------------------------

target remote localhost:2331

monitor endian little

monitor flash device = AT91SAM7S256

monitor flash download = 1

monitor flash breakpoints = 1

monitor sleep 100

monitor reset

monitor speed 30

monitor sleep 100

echo load bin/app_at91sam7/kernel-rom.mot

echo symbol-file bin/app_at91sam7/kernel-rom.rom

echo monitor sleep 100

monitor writeu32 0xFFFFFD44 = 0x00008000
monitor writeu32 0xFFFFFC20 = 0x00000601
monitor sleep 10
monitor writeu32 0xFFFFFC2C = 0x00480a0e
monitor sleep 10
monitor writeu32 0xFFFFFC30 = 0x00000007
monitor sleep 10
monitor writeu32 0xFFFFFF60 = 0x00480100
monitor sleep 100

break usermain

continue