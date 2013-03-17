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
 *      @(#)str_align_common.h (sys)
 *
 *	Bit alignment definitions for structure
 */

#ifndef __SYS_STR_ALIGN_COMMON_H__
#define __SYS_STR_ALIGN_COMMON_H__

#ifdef _APP_AT91SAM3_
#  include <sys/sysdepend/app_at91sam3/str_align_depend.h>
#endif

#ifdef _APP_AT91SAM4_
#  include <sys/sysdepend/app_at91sam4/str_align_depend.h>
#endif

#ifdef _APP_AT91SAM7_
#  include <sys/sysdepend/app_at91sam7/str_align_depend.h>
#endif

#ifdef _APP_STM32F1_
#  include <sys/sysdepend/app_stm32f1/str_align_depend.h>
#endif

#ifdef _APP_STM32F4_
#  include <sys/sysdepend/app_stm32f4/str_align_depend.h>
#endif

#ifdef _APP_LPC17_
#  include <sys/sysdepend/app_lpc17/str_align_depend.h>
#endif

#ifdef _APP_LPC18_
#  include <sys/sysdepend/app_lpc18/str_align_depend.h>
#endif

#ifdef _APP_MK60_
#  include <sys/sysdepend/app_mk60/str_align_depend.h>
#endif

#ifdef _APP_LM3S_
#  include <sys/sysdepend/app_lm3s/str_align_depend.h>
#endif

#ifdef _APP_LM4F_
#  include <sys/sysdepend/app_lm4f/str_align_depend.h>
#endif

#ifdef _APP_EFM32G_
#  include <sys/sysdepend/app_efm32g/str_align_depend.h>
#endif

#ifdef _APP_MB9BF5_
#  include <sys/sysdepend/app_mb9bf5/str_align_depend.h>
#endif

#ifdef _APP_XMC4000_
#  include <sys/sysdepend/app_xmc4000/str_align_depend.h>
#endif

#ifdef _APP_SIM3_
#  include <sys/sysdepend/app_sim3/str_align_depend.h>
#endif

#ifdef _APP_MC9S12_
#  include <sys/sysdepend/app_mc9s12/str_align_depend.h>
#endif

#ifdef _APP_MPC56XX_
#  include <sys/sysdepend/app_mpc56xx/str_align_depend.h>
#endif

#endif /* __SYS_STR_ALIGN_COMMON_H__ */
