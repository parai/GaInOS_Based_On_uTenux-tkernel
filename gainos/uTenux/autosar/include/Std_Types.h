/* Copyright 2012, Fan Wang(Parai)
 *
 * This file is part of GaInOS.
 *
 * GaInOS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *             
 * Linking GaInOS statically or dynamically with other modules is making a
 * combined work based on GaInOS. Thus, the terms and conditions of the GNU
 * General Public License cover the whole combination.
 *
 * In addition, as a special exception, the copyright holders of GaInOS give
 * you permission to combine GaInOS program with free software programs or
 * libraries that are released under the GNU LGPL and with independent modules
 * that communicate with GaInOS solely through the GaInOS defined interface. 
 * You may copy and distribute such a system following the terms of the GNU GPL
 * for GaInOS and the licenses of the other code concerned, provided that you
 * include the source code of that other code when and as the GNU GPL requires
 * distribution of source code.
 *
 * Note that people who make modified versions of GaInOS are not obligated to
 * grant this special exception for their modified versions; it is their choice
 * whether to do so. The GNU General Public License gives permission to release
 * a modified version without this exception; this exception also makes it
 * possible to release a modified version which carries forward this exception.
 * 
 * GaInOS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GaInOS. If not, see <http://www.gnu.org/licenses/>.
 *
 */
/* |---------+-------------------| */
/* | Author: | Wang Fan(parai)   | */
/* |---------+-------------------| */
/* | Email:  | parai@foxmail.com | */
/* |---------+-------------------| */

#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_
/* =============================== MACROS FOR CPU =============================== */
#define CPU_TYPE_16    		16
#define CPU_TYPE_32			32
#define CPU_TYPE_64			64

#define MSB_FIRST 0
#define MSB_LAST  1

#define HIGH_BYTE_FIRST 0
#define HIGH_BYTE_LAST  1
/* ================================== INCLUDES  ================================= */
#include "Platform_Types.h"
/* shit when integrated with uTenux V1.5 */
/* this file should be named <FullInclude.h>*/
/* define the MICRO_TENUX_VERSION in your toolchain compiler preprocessor.
 * For example: -DMICRO_TENUX_VERSION=150 */
#if(MICRO_TENUX_VERSION == 140)
#  include <basic.h>
#  include <tk/errno.h>
#  include <tk/syslib.h>
#else if(MICRO_TENUX_VERSION == 150)
#  include <ts_basic.h>
#  include <tk/tk_typedef.h>
#  include <tk/tk_errno.h>
#  include <stdlib.h> /* as V1.5 has removed the <syslib.h>, so add compiler stdlib */
#endif  /* MICRO_TENUX_VERSION */

#ifndef FALSE
#define FALSE		(boolean)0
#endif
#ifndef TRUE
#define TRUE		(boolean)1
#endif

#ifndef 	NULL
//lint -esym(960,20.2) // PC-Lint LINT EXCEPTION
#define	NULL	0
#endif

#ifndef MIN
#define MIN(_x,_y) (((_x) < (_y)) ? (_x) : (_y))
#endif
#ifndef MAX
#define MAX(_x,_y) (((_x) > (_y)) ? (_x) : (_y))
#endif

typedef struct {
	// TODO: not done!!
	uint16 vendorID;
	uint16 moduleID;
	uint8  instanceID;

	uint8 sw_major_version;    /**< Vendor numbers */
	uint8 sw_minor_version;    /**< Vendor numbers */
	uint8 sw_patch_version;    /**< Vendor numbers */

	uint8 ar_major_version;    /**< Autosar spec. numbers */
	uint8 ar_minor_version;    /**< Autosar spec. numbers */
	uint8 ar_patch_version;    /**< Autosar spec. numbers */
} Std_VersionInfoType;

/** make compare number... #if version > 10203  ( 1.2.3 ) */
#define STD_GET_VERSION (_major,_minor,_patch) (_major * 10000 + _minor * 100 + _patch)

/** Create Std_VersionInfoType */
// PC-Lint Exception MISRA rule 19.12
//lint -save -esym(960,19.12)
#define STD_GET_VERSION_INFO(_vi,_module) \
	if(_vi != NULL) {\
		((_vi)->vendorID =  _module ## _VENDOR_ID);\
		((_vi)->moduleID = _module ## _MODULE_ID);\
		((_vi)->sw_major_version = _module ## _SW_MAJOR_VERSION);\
		((_vi)->sw_minor_version =  _module ## _SW_MINOR_VERSION);\
		((_vi)->sw_patch_version =  _module ## _SW_PATCH_VERSION);\
		((_vi)->ar_major_version =  _module ## _AR_MAJOR_VERSION);\
		((_vi)->ar_minor_version =  _module ## _AR_MINOR_VERSION);\
		((_vi)->ar_patch_version =  _module ## _AR_PATCH_VERSION);\
	}
//lint -restore

typedef INT Std_ReturnType;     /* Should be the same type with "ER",As based on tkernel */

/* #define E_OK 					((Std_ReturnType)0) */
#define E_NOT_OK 				((Std_ReturnType)-103)

#define STD_HIGH		0x01
#define STD_LOW			0x00

#define STD_ACTIVE		0x01
#define STD_IDLE		0x00

#define STD_ON			0x01
#define STD_OFF			0x00

#define AR_ASSERT(_cs)                          \
    do{                                         \
        if(!_cs)                                \
        {                                       \
            for(;;);                            \
        }                                       \
    }while(0)

#endif /* _STD_TYPES_H_ */

