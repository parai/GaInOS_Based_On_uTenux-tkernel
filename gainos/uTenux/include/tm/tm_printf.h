#ifndef TM_PRINTF_H_H
#define TM_PRINTF_H_H

#include <stdarg.h>

#if 0
#  define TM_PRINTF_PRECISION   /* 是否打印小数 */
#  define TM_PRINTF_LONGLONG    /* 是否打印长整型 */
#  define TM_PRINTF_SPECIAL
#  define TM_TEST_ON_PC
#endif

/* 每次最多打印127个字符 */
#define TM_PRINTF_BUF_SIZE 128
void tm_printf(const char *fmt, ...);

#endif