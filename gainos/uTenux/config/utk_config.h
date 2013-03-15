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
 *	utk_config.h
 *	System Configuration Definition
 */

#ifndef _UTK_CONFIG_H_
#define _UTK_CONFIG_H_

#include "config.h"

#ifdef _APP_AT91SAM3_
#include "sysdepend/app_at91sam3/utk_config_depend.h"
#endif

#ifdef _APP_AT91SAM4_
#include "sysdepend/app_at91sam4/utk_config_depend.h"
#endif

#ifdef _APP_AT91SAM7_
#include "sysdepend/app_at91sam7/utk_config_depend.h"
#endif

#ifdef _APP_STM32F1_
#include "sysdepend/app_stm32f1/utk_config_depend.h"
#endif

#ifdef _APP_STM32F4_
#include "sysdepend/app_stm32f4/utk_config_depend.h"
#endif

#ifdef _APP_LPC17_
#include "sysdepend/app_lpc17/utk_config_depend.h"
#endif

#ifdef _APP_LPC18_
#include "sysdepend/app_lpc18/utk_config_depend.h"
#endif

#ifdef _APP_MK60_
#include "sysdepend/app_mk60/utk_config_depend.h"
#endif

#ifdef _APP_LM3S_
#include "sysdepend/app_lm3s/utk_config_depend.h"
#endif

#ifdef _APP_LM4F_
#include "sysdepend/app_lm4f/utk_config_depend.h"
#endif

#ifdef _APP_EFM32G_
#include "sysdepend/app_efm32g/utk_config_depend.h"
#endif

#ifdef _APP_MB9BF5_
#include "sysdepend/app_mb9bf5/utk_config_depend.h"
#endif

#ifdef _APP_XMC4000_
#include "sysdepend/app_xmc4000/utk_config_depend.h"
#endif

#ifdef _APP_SIM3_
#include "sysdepend/app_sim3/utk_config_depend.h"
#endif

#include "utk_config_func.h"

#if !USE_TRAP && !(USE_DBGSPT && USE_HOOK_TRACE)
#include "tksvcproxy.h"
#include "tdsvcproxy.h"
#endif

#endif /* _UTK_CONFIG_H_ */
