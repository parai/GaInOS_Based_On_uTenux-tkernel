/*****************************************************
 hidef.h - ANSI-C library: machine dependent stuff
 ----------------------------------------------------
 Copyright (c) Metrowerks, Basel, Switzerland
               All rights reserved
                  Do not modify!
 *****************************************************/

#ifndef _H_HIDEF_
#define _H_HIDEF_

#ifdef __cplusplus
extern "C" {
#endif

/**** Version for MC68HC12 */
#ifdef __HC12__ /* not for XGATE */

#include "default2.sgm"

#ifdef  __BANKED__
#define __MEDIUM__
#endif

#endif /* __HC12__ */

#include <stdtypes.h>
#include <stddef.h>

#pragma NO_STRING_CONSTR   /* allow '#' in HLI below */
#if defined(__HC12__)

#ifdef _USE_BGND_ /* ICD12 Target interface needs BGND */
#define HALT               {__asm CLRB; __asm BGND;}
#define HALTX(x)           {/*lint -e522 */ __asm LDAB x; __asm BGND; /*lint +e522 */}
#else
#define HALT               {__asm CLRB; __asm SWI;}
#define HALTX(x)           {/*lint -e522 */ __asm LDAB x; __asm SWI; /*lint +e522 */}
#endif /* _USE_BGND_ */

#define HALT_AND_QUIT      HALTX(#32)
#define EnableInterrupts   {__asm CLI;}
#define DisableInterrupts  {__asm SEI;}
#define __XGFUN_MANG2(name) __X_ ## name        /* indirection, necessary if name is a macro. */
#define __XGFUN_MANG(name) __XGFUN_MANG2(name)  /* XGATE function names are mangled with a __X_ for the HC12 (so the XGATE can use its own ANSI library functions) */

#elif defined(__XGATE__)

#define HALT               { __asm SWI;}
#define HALTX(x)           {/*lint -e522 */ __asm ldl r5, #0x0F; __asm tfr ccr, r5; __asm ldl r5, x; __asm BRK; /*lint +e522 */}
#define HALT_AND_QUIT      HALTX(#32)
#define EnableInterrupts   {} /* XGATE thread cannot be interrupted */
#define DisableInterrupts  {} /* XGATE thread cannot be interrupted */

#undef FAR     /* */
#undef NEAR    /* */
#undef _FAR    /* */
#undef _NEAR   /* */
#define FAR    /* */
#define NEAR   /* */
#define _FAR   /* */
#define _NEAR  /* */

#define __XGFUN_MANG(name) name 

/* The XGATE can allocate constants/code either in RAM or in FLASH. Access to the flash are considerably slower than accesses to the RAM. */
/* In a mixed HCS12X/XGATE application, the HCS12X is responsible to copy all the XGATE constants, XGATE strings and the XGATE code into RAM. */
/* For the default projects this is handled by the normal HCS12X startup code by placing all XGATE code/constants/strings into the sections */
/* XGATE_CODE, XGATE_CONST and XGATE_STRING. Then these sections are allocated in the PRM file into a READ_WRITE segment. */
/* Note: if you are using other code/const/string sections in XGATE code, make sure they are copied into RAM as well. */
   
#pragma CODE_SEG   XGATE_CODE   /* for the HCS12X/XGATE shared setup, the XGATE code must be in special sections. */
#pragma CONST_SEG  XGATE_CONST
#pragma STRING_SEG XGATE_STRING

#pragma DATA_SEG   XGATE_DATA  /* also place XGATE data in a special section */
 
#define __GPAGE_SEG /* nothing: This is to share segment pragmas between the HCS12X and the XGATE. Use #pragma CONST_SEG __GPAGE_SEG XGATE_CONST */
                    /* if the HCS12X should access such objects with far accesses. This define avoids that the XGATE issues warnings about inconsitent section qualifiers. */
#else

#error "Target not supported by this hidef.h"

#endif /* __HC12__ */

/* COP macros */
#if defined(_HCS12) || defined(HCS12) || defined(__HCS12__) || defined(__XGATE__)
#define _COPCTL_ADR  (0x34+0x08)
#define _COP_RST_ADR (0x34+0x0B) /* ARMCOP */
#else
#define _COPCTL_ADR  0x16
#define _COP_RST_ADR 0x17
#endif

/* Note COPCTL is write once. */
#define _ENABLE_COP(period)   ((*(volatile unsigned char*)_COPCTL_ADR)= (period)) /* Note: 7 longest possible COP duration. 0 == COP disabled. */
#define _ENABLE_COP_X() _ENABLE_COP(7) /* as long as possible */
#define _DISABLE_COP() _ENABLE_COP(0x00) /* COP is disabled if period is 0 */
#define _FEED_COP()   ((*(volatile unsigned char*)_COP_RST_ADR)= 0x55,(*(volatile unsigned char*)_COP_RST_ADR)= 0xAA)

#if __STDC__ && 0
  /* with strict ANSI, the far/near keywords are not allowed */
  #define far
  #define near
#endif

#ifndef __XGATE__

/* assumes a linker version of at least V5.0.10 */
extern char __SEG_END_SSTACK[];
#define INIT_SP_FROM_STARTUP_DESC() __asm LDS #__SEG_END_SSTACK;


/*-------------------- tabled functions used with options -ot -oilib=g ----------------*/

/* 1 << char */
extern const unsigned char _PowOfTwo_8[8];
/* 1 << int */
extern const unsigned short _PowOfTwo_16[16];
/* 1L << long */
extern const unsigned long _PowOfTwo_32[32];


/* PIC support for runtime library. Generate all calls PIC, if option is present */

#ifdef __PIC__
#define __PIC_JSR(dest) JSR dest,pcr
#define __PIC_JMP(dest) JMP dest,pcr
#else
#define __PIC_JSR(dest) JSR dest
#define __PIC_JMP(dest) JMP dest
#endif

#endif /* __XGATE__ */


#ifdef __cplusplus
 }
#endif

#endif
/*****************************************************/
/* end hidef.h */
