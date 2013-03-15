/*
 *----------------------------------------------------------------------
 *    micro T-Kernel
 *
 *    Copyright (C) 2006-2008 by Ken Sakamura. All rights reserved.
 *    micro T-Kernel is distributed under the micro T-License.
 *----------------------------------------------------------------------
 *
 *    Version:   1.01.00
 *    Released by T-Engine Forum(http://www.t-engine.org) at 2008/02/25.
 *
 *----------------------------------------------------------------------
 */

/*
 *	@(#)imalloc.h (sys)
 *
 *	Kernel memory allocation 
 *
 *	A function for allocating memory used in parts of micro T-Kernel.
 *	Not for general use.
 */

#ifndef __SYS_IMALLOC_H__
#define __SYS_IMALLOC_H__

#include <basic.h>
#include <tk/typedef.h>

#ifdef __cplusplus
extern "C" {
#endif

IMPORT void* knl_Imalloc( size_t size );
IMPORT void* knl_Icalloc( size_t nmemb, size_t size );
IMPORT void  knl_Ifree( void *ptr );

#ifdef __cplusplus
}
#endif
#endif /* __SYS_IMALLOC_H__ */
