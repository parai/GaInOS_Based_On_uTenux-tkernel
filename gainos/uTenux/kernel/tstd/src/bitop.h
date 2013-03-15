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
 *	bitop.h (tstdlib)
 *
 *	T-Kernel common standard library
 *
 */

#ifndef	_BITOP_
#define _BITOP_

#include <stdtype.h>
#include "utk_config.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef	__size_t
typedef __size_t	size_t;
#undef	__size_t
#endif

#ifdef	__wchar_t
typedef __wchar_t	wchar_t;
#undef	__wchar_t
#endif
#ifndef NULL
#define NULL		0
#endif

extern void knl_tstdlib_bitclr( VP base, W offset );
extern void knl_tstdlib_bitset( VP base, W offset );

extern W knl_tstdlib_bitsearch1( VP base, W offset, W width );

#ifdef __cplusplus
}
#endif
#endif /* _BITOP_ */
