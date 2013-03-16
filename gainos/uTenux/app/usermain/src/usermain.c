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
 *	usermain.c (usermain)
 *	User Main
 */

#include <basic.h>
#include <tk/tkernel.h>
#include <tm/tmonitor.h>
#include <tm/tm_printf.h>

void CycHandler(void);
void Delay(void);

UW   count;

/*
 *    Function Name : CycSample
 *    Create Date   : 2010/03/23-2012/08/29
 *    Author        : cheny-zhangzl
 *    Description   : create a cyclic handler, start it, wait for a moment
 *                    to see how it runs then stop it and delete it.
 *    Param	        : none
 *    Return Code   : E_OK
 */
EXPORT ER CycSample( void )
{
    ER ercd;
    ID cycid;
    T_CCYC ccyc;

    ccyc.exinf=NULL;
    ccyc.cycatr=TA_HLNG;
    ccyc.cychdr=CycHandler;
    ccyc.cycphs=1000;
    ccyc.cyctim=10000;
    cycid=tk_cre_cyc(&ccyc);
    if(cycid>E_OK) {
        tm_putstring((UB*)"cycle is created successfully!\n");
    } else {
        tm_putstring((UB*)"can't create cycle!\n");
        goto err1;
    }

    ercd=tk_sta_cyc(cycid);
    if(E_OK==ercd) {
        tm_putstring((UB*)"cycle is started successfully,interval time is 10s!\n");
    } else {
        tm_putstring((UB*)"can't start cycle!\n");
        goto err2;
    }

    Delay();

    ercd=tk_stp_cyc(cycid);
    if(E_OK==ercd) {
        tm_putstring((UB*)"cycle is stopped successfully!\n");
    } else {
        tm_putstring((UB*)"can't stop cycle!\n");
        goto err2;
    }

    ercd=tk_del_cyc(cycid);
    if(E_OK==ercd) {
        tm_putstring((UB*)"cycle is deleted successfully!\n");
    } else {
        tm_putstring((UB*)"can't delete cycle!\n");
        goto err2;
    }

    return E_OK;

err1:
    tm_putchar(cycid+48);
    tm_putstring((UB*)" error!\n");
    return cycid;
err2:
    tm_putchar(ercd+48);
    tm_putstring((UB*)" error!\n");
    return ercd;
}

/*
 *    Function Name : CycHandler
 *    Create Date   : 2010/03/23-2012/8/29
 *    Author        : cheny-zhangzl
 *    Description   : Cyclic handler,that put cycle times
 *    Param         : none
 *    Return Code   : none
 */
void CycHandler(void)
{
	count++;
    tm_putstring((UB*)"The times of cycle is: ");
    tm_putchar(count+48);
    tm_putstring((UB*)" !\n");
}

/*
 *    Function Name : Delay
 *    Create Date   : 2010/03/23-2013/1/16
 *    Author        : zhangzl-wangshb
 *    Description   : Time delay
 *    Param         : void
 *    Return Code   : none
 */
void Delay(void)
{
    UINT i=0x20000000;

    for(;i>0;i--);
}



/*
 * Entry routine for the user application.
 * At this point, Initialize and start the user application.
 *
 * Entry routine is called from the initial task for Kernel,
 * so system call for stopping the task should not be issued
 * from the contexts of entry routine.
 * We recommend that:
 * (1)'usermain()' only generates the user initial task.
 * (2)initialize and start the user application by the user
 * initial task.
 */
EXPORT	INT	usermain( void )
{
    CycSample();
    for(;;); /* never return */

    return 0;
}
