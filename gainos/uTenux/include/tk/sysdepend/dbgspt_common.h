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
 *	@(#)dbgspt_common.h (tk)
 *
 *	micro T-Kernel Debugger Support
 */

#ifndef __TK_DBGSPT_COMMON_H__
#define __TK_DBGSPT_COMMON_H__

/*
 * System-dependent definition
 */
#ifdef _APP_AT91SAM3_
#  include <tk/sysdepend/app_at91sam3/dbgspt_depend.h>
#endif

#ifdef _APP_AT91SAM4_
#  include <tk/sysdepend/app_at91sam4/dbgspt_depend.h>
#endif

#ifdef _APP_AT91SAM7_
#  include <tk/sysdepend/app_at91sam7/dbgspt_depend.h>
#endif

#ifdef _APP_STM32F1_
#  include <tk/sysdepend/app_stm32f1/dbgspt_depend.h>
#endif

#ifdef _APP_STM32F4_
#  include <tk/sysdepend/app_stm32f4/dbgspt_depend.h>
#endif

#ifdef _APP_LPC17_
#  include <tk/sysdepend/app_lpc17/dbgspt_depend.h>
#endif

#ifdef _APP_LPC18_
#  include <tk/sysdepend/app_lpc18/dbgspt_depend.h>
#endif

#ifdef _APP_MK60_
#  include <tk/sysdepend/app_mk60/dbgspt_depend.h>
#endif

#ifdef _APP_LM3S_
#  include <tk/sysdepend/app_lm3s/dbgspt_depend.h>
#endif

#ifdef _APP_LM4F_
#  include <tk/sysdepend/app_lm4f/dbgspt_depend.h>
#endif

#ifdef _APP_EFM32G_
#  include <tk/sysdepend/app_efm32g/dbgspt_depend.h>
#endif

#ifdef _APP_MB9BF5_
#  include <tk/sysdepend/app_mb9bf5/dbgspt_depend.h>
#endif

#ifdef _APP_XMC4000_
#  include <tk/sysdepend/app_xmc4000/dbgspt_depend.h>
#endif

#ifdef _APP_SIM3_
#  include <tk/sysdepend/app_sim3/dbgspt_depend.h>
#endif

#ifdef _APP_MC9S12_
#  include <tk/sysdepend/app_mc9s12/dbgspt_depend.h>
#endif

#ifdef _APP_MPC56XX_
#  include <tk/sysdepend/app_mpc56xx/dbgspt_depend.h>
#endif
#endif /* __TK_DBGSPT_COMMON_H__ */
