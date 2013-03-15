/*
 *------------------------------------------------------------------------------
 *    Config
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
 *	 File Name      : utk_config_depend.h
 *	 Create Date    : 2012/7/18-2013/1/15
 *	 Author	        : WangShb-Zhangzl
 *	 Description    : System Configuration Definition(STM32F103VE).
 *-------------------------------------------------------------------------------
 */

/* RAMINFO */
#define SYSTEMAREA_TOP	0x20000000	/* SRAM system area top */
#define SYSTEMAREA_END	0x2000C000	/* SRAM system area end */


/* User definition */
#define RI_USERAREA_TOP	0x20007000	/* SRAM user area middle */
#define RI_USERINIT	NULL	        /* User initialization program */

/* SYSCONF */
#define CFN_TIMER_PERIOD	10
#define CFN_MAX_TSKID		10
#define CFN_MAX_SEMID		4
#define CFN_MAX_FLGID		4
#define CFN_MAX_MBXID		2
#define CFN_MAX_MTXID		2
#define CFN_MAX_MBFID		2
#define CFN_MAX_PORID		2
#define CFN_MAX_MPLID		2
#define CFN_MAX_MPFID		2
#define CFN_MAX_CYCID		2
#define CFN_MAX_ALMID		2

#define CFN_VER_MAKER		0
#define CFN_VER_PRID		0
#define CFN_VER_SPVER		0x6101
#define CFN_VER_PRVER		0x0101
#define CFN_VER_PRNO1		0
#define CFN_VER_PRNO2		0
#define CFN_VER_PRNO3		0
#define CFN_VER_PRNO4		0

#define CFN_REALMEMEND		((VP) 0x2000C000)

/*
 * Initial task priority
 */
#define INIT_TASK_PRI	(MAX_PRI-2)

/*
 * Use zero-clear bss section
 */
#define USE_NOINIT	(1)

/*
 * Stack size for each mode
 */
#define MAIN_STACK_SIZE       /*now not used */
#define PROCESS_STACK_SIZE    /*now not used */
#define STACK_TOP     0x20010000	/* SRAM system area end */

/*
 * Use dynamic memory allocation
 */
#define USE_IMALLOC		(1)

/*
 * Use program trace function (in debugger support)
 */
#define USE_HOOK_TRACE	(0)

/*
 * Use clean-up sequence
 */
#define USE_CLEANUP		(1)


/*
 * Use high level programming language support routine
 */
#define USE_HLL_INTHDR	(1)

/*
 * User defined boot message
 */
#define USER_BOOT_MESSAGE \
	"\n" \
    "----------------------------------------------------\n" \
    "        micro Tenux Version 1.4.00(build 0100)      \n" \
    "            Supported MCU is ST STM32F103VE         \n" \
	"   Copyright(c) 2008-2013 by Dalian uLoong Co.,Ltd. \n" \
    "----------------------------------------------------\n" \
	"\n\0"

