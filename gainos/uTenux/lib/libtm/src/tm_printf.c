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
#include <tm/tm_printf.h>
/* private function */
#define isdigit(c)  ((unsigned)((c) - '0') < 10)

unsigned long tm_strlen(const char *s)
{
	const char *sc;

	for (sc = s; *sc != '\0'; ++sc) /* nothing */
		;

	return sc - s;
}

long divide(long *n, long base)
{
	long res;

	/* optimized for processor which does not support divide instructions. */
	if (base == 10)
	{
		res = ((unsigned long)*n) % 10U;
		*n = ((unsigned long)*n) / 10U;
	}
	else
	{
		res = ((unsigned long)*n) % 16U;
		*n = ((unsigned long)*n) / 16U;
	}

	return res;
}

int skip_atoi(const char **s)
{
	register int i=0;
	while (isdigit(**s))
		i = i * 10 + *((*s)++) - '0';

	return i;
}

#define ZEROPAD     (1 << 0)	/* pad with zero */
#define SIGN        (1 << 1)	/* unsigned/signed long */
#define PLUS        (1 << 2)	/* show plus */
#define SPACE       (1 << 3)	/* space if plus */
#define LEFT        (1 << 4)	/* left justified */
#define SPECIAL     (1 << 5)	/* 0x */
#define LARGE       (1 << 6)	/* use 'ABCDEF' instead of 'abcdef' */

#ifdef TM_PRINTF_PRECISION
static char *print_number(char *buf, char *end, long num, int base, int s, int precision, int type)
#else
static char *print_number(char *buf, char *end, long num, int base, int s, int type)
#endif
{
	char c, sign;
#ifdef TM_PRINTF_LONGLONG
	char tmp[32];
#else
	char tmp[16];
#endif
	const char *digits;
	static const char small_digits[] = "0123456789abcdef";
	static const char large_digits[] = "0123456789ABCDEF";
	register int i;
	register int size;

	size = s;

	digits = (type & LARGE) ? large_digits : small_digits;
	if (type & LEFT)
		type &= ~ZEROPAD;

	c = (type & ZEROPAD) ? '0' : ' ';

	/* get sign */
	sign = 0;
	if (type & SIGN)
	{
		if (num < 0)
		{
			sign = '-';
			num = -num;
		}
		else if (type & PLUS) sign = '+';
		else if (type & SPACE) sign = ' ';
	}

#ifdef TM_PRINTF_SPECIAL
	if (type & SPECIAL)
	{
		if (base == 16) size -= 2;
		else if (base == 8) size--;
	}
#endif

	i = 0;
	if (num == 0)
		tmp[i++]='0';
	else
	{
		while (num != 0)
			tmp[i++] = digits[divide(&num, base)];
	}

#ifdef TM_PRINTF_PRECISION
	if (i > precision)
		precision = i;
	size -= precision;
#else
	size -= i;
#endif

	if (!(type&(ZEROPAD | LEFT)))
	{
		while (size-->0)
		{
			if (buf <= end)
				*buf = ' ';
			++ buf;
		}
	}

	if (sign)
	{
		if (buf <= end)
		{
			*buf = sign;
			-- size;
		}
		++ buf;
	}

#ifdef TM_PRINTF_SPECIAL
	if (type & SPECIAL)
	{
		if (base==8)
		{
			if (buf <= end)
				*buf = '0';
			++ buf;
		}
		else if (base == 16)
		{
			if (buf <= end)
				*buf = '0';
			++ buf;
			if (buf <= end)
			{
				*buf = type & LARGE? 'X' : 'x';
			}
			++ buf;
		}
	}
#endif

	/* no align to the left */
	if (!(type & LEFT))
	{
		while (size-- > 0)
		{
			if (buf <= end)
				*buf = c;
			++ buf;
		}
	}

#ifdef TM_PRINTF_PRECISION
	while (i < precision--)
	{
		if (buf <= end)
			*buf = '0';
		++ buf;
	}
#endif

	/* put number in the temporary buffer */
	while (i-- > 0)
	{
		if (buf <= end)
			*buf = tmp[i];
		++ buf;
	}

	while (size-- > 0)
	{
		if (buf <= end)
			*buf = ' ';
		++ buf;
	}

	return buf;
}

static long tm_vsnprintf(char *buf, unsigned long size, const char *fmt, va_list args)
{
#ifdef TM_PRINTF_LONGLONG
	unsigned long long num;
#else
	unsigned long num;
#endif
	int i, len;
	char *str, *end, c;
	const char *s;

	unsigned char base;			/* the base of number */
	unsigned char flags;			/* flags to print number */
	unsigned char qualifier;		/* 'h', 'l', or 'L' for integer fields */
	long field_width;		/* width of output field */

#ifdef TM_PRINTF_PRECISION
	int precision;		/* min. # of digits for integers and max for a string */
#endif

	str = buf;
	end = buf + size - 1;

	/* Make sure end is always >= buf */
	if (end < buf)
	{
		end = ((char *)-1);
		size = end - buf;
	}

	for (; *fmt ; ++fmt)
	{
		if (*fmt != '%')
		{
			if (str <= end)
				*str = *fmt;
			++ str;
			continue;
		}

		/* process flags */
		flags = 0;

		while (1)
		{
			/* skips the first '%' also */
			++ fmt;
			if (*fmt == '-') flags |= LEFT;
			else if (*fmt == '+') flags |= PLUS;
			else if (*fmt == ' ') flags |= SPACE;
			else if (*fmt == '#') flags |= SPECIAL;
			else if (*fmt == '0') flags |= ZEROPAD;
			else break;
		}

		/* get field width */
		field_width = -1;
		if (isdigit(*fmt)) field_width = skip_atoi(&fmt);
		else if (*fmt == '*')
		{
			++ fmt;
			/* it's the next argument */
			field_width = va_arg(args, int);
			if (field_width < 0)
			{
				field_width = -field_width;
				flags |= LEFT;
			}
		}

#ifdef TM_PRINTF_PRECISION
		/* get the precision */
		precision = -1;
		if (*fmt == '.')
		{
			++ fmt;
			if (isdigit(*fmt)) precision = skip_atoi(&fmt);
			else if (*fmt == '*')
			{
				++ fmt;
				/* it's the next argument */
				precision = va_arg(args, int);
			}
			if (precision < 0) precision = 0;
		}
#endif
		/* get the conversion qualifier */
		qualifier = 0;
#ifdef TM_PRINTF_LONGLONG
		if (*fmt == 'h' || *fmt == 'l' || *fmt == 'L')
#else
		if (*fmt == 'h' || *fmt == 'l')
#endif
		{
			qualifier = *fmt;
			++ fmt;
#ifdef TM_PRINTF_LONGLONG
			if (qualifier == 'l' && *fmt == 'l')
			{
				qualifier = 'L';
				++ fmt;
			}
#endif
		}

		/* the default base */
		base = 10;

		switch (*fmt)
		{
		case 'c':
			if (!(flags & LEFT))
			{
				while (--field_width > 0)
				{
					if (str <= end) *str = ' ';
					++ str;
				}
			}

			/* get character */
			c = (unsigned char)va_arg(args, int);
			if (str <= end) *str = c;
			++ str;

			/* put width */
			while (--field_width > 0)
			{
				if (str <= end) *str = ' ';
				++ str;
			}
			continue;

		case 's':
			s = va_arg(args, char *);
			if (!s) s = "(NULL)";

			len = tm_strlen(s);
#ifdef TM_PRINTF_PRECISION
			if (precision > 0 && len > precision) len = precision;
#endif

			if (!(flags & LEFT))
			{
				while (len < field_width--)
				{
					if (str <= end) *str = ' ';
					++ str;
				}
			}

			for (i = 0; i < len; ++i)
			{
				if (str <= end) *str = *s;
				++ str;
				++ s;
			}

			while (len < field_width--)
			{
				if (str <= end) *str = ' ';
				++ str;
			}
			continue;

		case 'p':
			if (field_width == -1)
			{
				field_width = sizeof(void *) << 1;
				flags |= ZEROPAD;
			}
#ifdef TM_PRINTF_PRECISION
			str = print_number(str, end,
							   (long)va_arg(args, void *),
							   16, field_width, precision, flags);
#else
			str = print_number(str, end,
							   (long)va_arg(args, void *),
							   16, field_width, flags);
#endif
			continue;

		case '%':
			if (str <= end) *str = '%';
			++ str;
			continue;

			/* integer number formats - set up the flags and "break" */
		case 'o':
			base = 8;
			break;

		case 'X':
			flags |= LARGE;
		case 'x':
			base = 16;
			break;

		case 'd':
		case 'i':
			flags |= SIGN;
		case 'u':
			break;

		default:
			if (str <= end) *str = '%';
			++ str;

			if (*fmt)
			{
				if (str <= end) *str = *fmt;
				++ str;
			}
			else
			{
				-- fmt;
			}
			continue;
		}

#ifdef TM_PRINTF_LONGLONG
		if (qualifier == 'L') num = va_arg(args, long long);
		else if (qualifier == 'l')
#else
		if (qualifier == 'l')
#endif
		{
			num = va_arg(args, unsigned long);
			if (flags & SIGN) num = (long)num;
		}
		else if (qualifier == 'h')
		{
			num = (unsigned short)va_arg(args, long);
			if (flags & SIGN) num = ( short)num;
		}
		else
		{
			num = va_arg(args, unsigned long);
			if (flags & SIGN) num = (long)num;
		}
#ifdef TM_PRINTF_PRECISION
		str = print_number(str, end, num, base, field_width, precision, flags);
#else
		str = print_number(str, end, num, base, field_width, flags);
#endif
	}

	if (str <= end) *str = '\0';
	else *end = '\0';

	/* the trailing null byte doesn't count towards the total
	* ++str;
	*/
	return str - buf;
}

/**
 * This function will fill a formatted string to buffer
 *
 * @param buf the buffer to save formatted string
 * @param size the size of buffer
 * @param fmt the format
 */
long tm_snprintf(char *buf, unsigned long size, const char *fmt, ...)
{
	long n;
	va_list args;

	va_start(args, fmt);
	n = tm_vsnprintf(buf, size, fmt, args);
	va_end(args);

	return n;
}

/**
 * This function will fill a formatted string to buffer
 *
 * @param buf the buffer to save formatted string
 * @param arg_ptr the arg_ptr
 * @param format the format
 */
long tm_vsprintf(char *buf, const char *format, va_list arg_ptr)
{
	return tm_vsnprintf(buf, (unsigned long) -1, format, arg_ptr);
}

/**
 * This function will fill a formatted string to buffer
 *
 * @param buf the buffer to save formatted string
 * @param format the format
 */
long rt_sprintf(char *buf, const char *format, ...)
{
	long n;
	va_list arg_ptr;

	va_start(arg_ptr, format);
	n = tm_vsprintf(buf ,format, arg_ptr);
	va_end(arg_ptr);

	return n;
}
#ifdef TM_TEST_ON_PC
#  include <stdio.h>
int main(int argc,char* argv[])
{
	tm_printf("Hello World!\r\nAuthor:%s\r\nEmail:%s\r\n","parai","parai@foxmail.com");
	tm_printf("test long:%8d\r\n",12345);
	tm_printf("test hex:0x%x\r\n",0xDEADBEEF);
	tm_printf("test char:%c\r\n",'p');
}
#else
#include <typedef.h>
#include <stddef.h>
#include <tk/syslib.h>
#include <tm/tmonitor.h>
#endif

 #ifdef _APP_MC9S12_
 #include <stdio.h>
 #endif
/**
 * This function will print a formatted string on system console
 *
 * @param fmt the format
 */
void tm_printf(const char *fmt, ...)
{
	va_list args;
	unsigned long length;
	static char tm_log_buf[TM_PRINTF_BUF_SIZE];
	INT imask;

	DI(imask);
	va_start(args, fmt);
	#ifdef _APP_MC9S12_
	length = vsprintf((char*)tm_log_buf,(char *)fmt,args);
	#else
	length = tm_vsnprintf(tm_log_buf, sizeof(tm_log_buf), fmt, args);
	#endif
#ifdef TM_TEST_ON_PC	
	printf(tm_log_buf);
#else
	if(length > 0)
	{
		tm_putstring((UB*)tm_log_buf);
	}
#endif
	va_end(args);
	EI(imask);
}

