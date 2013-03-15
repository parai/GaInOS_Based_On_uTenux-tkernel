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

#include <typedef.h>
#include <stddef.h>
#include <tk/syslib.h>

IMPORT void sio_send_frame( const UB* buf, INT size );
IMPORT void sio_recv_frame( UB* buf, INT size );

INT tm_command ( UB *buff )
{
	for(;;) {
		;
	}
}

void tm_exit( INT mode )
{
	for(;;) {
		;
	}
}

/*
 * supported only on wait != 0 (polling not supported)
 */
EXPORT INT tm_getchar( INT wait )
{
	UB	p;
	UINT	imask;

	DI(imask);

	sio_recv_frame(&p, 1);

	EI(imask);

	return (INT)p;
}


/*
 * special key is not supported
 */
EXPORT INT tm_getline( UB *buff )
{
	UB* p = buff;
	int len = 0;
	static const char LF = 0x0a;
	INT imask;

	DI(imask);

	for (;;) {
		sio_recv_frame(p, 1);
		sio_send_frame(p, 1); /* echo back */
		if (*p == 0x0d) {
			sio_send_frame((const VP)&LF, 1);
			*p = 0x00;
			goto err_ret;
		} else if (*p == 0x03) {
			*p = 0x00;
			len = -1;
			goto err_ret;
		}
		p++;
		len++;
	}

err_ret:
	EI(imask);

	return len;
}

EXPORT void tm_monitor( void )
{
	for(;;) {
		;
	}
}

/*
 * Ctrl-C is not supported
 */
EXPORT INT tm_putchar( INT c )
{
	static const char CR = 0x0d;
	UB buf = (UB)c;

	if (buf == 0x0a) {
		sio_send_frame((const UB*)&CR, 1);
	}
	sio_send_frame(&buf, 1);

	return 0;
}

/*
 * Ctrl-C is not supported
 */
EXPORT INT tm_putstring( UB *buff )
{
	const UB* p = buff;
	static const char CR = 0x0d;
	INT imask;

	DI(imask);

	while (*p != NULL) {
		if (*p == 0x0a) { /* LF */
			sio_send_frame((const VP)&CR, 1);
			sio_send_frame((const VP)p, 1);
		} else {
			sio_send_frame((const VP)p, 1);
		}
		p++;
	}

	EI(imask);

	return 0;
}
