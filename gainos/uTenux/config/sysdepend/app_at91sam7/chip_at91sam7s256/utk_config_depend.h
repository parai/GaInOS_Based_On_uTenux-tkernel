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
 *    CPU:        AT91SAM7S256
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : utk_config_depend.h
 *	 Create Date    : 2009/7/27-2012/11/30
 *	 Author	        : WangShb
 *	 Description    : System Configuration Definition(at91sam7).
 *-------------------------------------------------------------------------------
 */

/* ROMINFO */
#define SYSTEMAREA_TOP	0x00002000	/* RAM system area top */
#define SYSTEMAREA_END	0x00010000	/* RAM system area end */


/* User definition */
#define RI_USERAREA_TOP	0x0000C000	/* RAM user area top */
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

#define CFN_REALMEMEND		((VP) 0x00010000)


/*
 * Initial task priority
 */
#define INIT_TASK_PRI	(MAX_PRI-2)

/*
 * Use zero-clear bss section
 */
#define USE_NOINIT	    (1)

/*
 * Stack size for each mode
 */
#define IRQ_STACK_SIZE  2048
#define FIQ_STACK_SIZE    16 /* 4 words */
#define ABT_STACK_SIZE     4 /* 1 word */
#define UND_STACK_SIZE     4 /* 1 word */
#define USR_STACK_SIZE     0 /* not used */
#define EXCEPTION_STACK_TOP     SYSTEMAREA_TOP


/*
 * Use dynamic memory allocation
 */
#define USE_IMALLOC	    (1)

/*
 * Use program trace function (in debugger support)
 */
#define USE_HOOK_TRACE	(0)

/*
 * Use clean-up sequence
 */
#define USE_CLEANUP	    (1)


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
    "      micro Tenux Version 1.4.00(build 0190)\n" \
    "        Supported MCU is ATMEL AT91SAM7S256 \n" \
	"Copyright(c) 2008-2013 by Dalian uLoong Co.,Ltd.\n" \
    "----------------------------------------------------\n" \
	"\n\0"
