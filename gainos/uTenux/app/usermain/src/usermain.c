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

void MtxSampleTaskA(W stacd,VP exinf);
void MtxSampleTaskB(W stacd,VP exinf);
UW ltostr(UW Val,B *pString,UB Base,UW Length);
void PutTaskPriority(ID taskid);
void Delay(void);

static ID TaskID_A;
static ID TaskID_B;
static ID MtxID;
static UB *GlobalData;

/*
 *    Function Name	: MtxSample
 *    Create Date   : 2012/09/28-2013/01/20
 *    Author	    : wangxd-wangxd
 *    Description   : sample main program to create all tasks and mutex.
 *    Param	        : None.
 *    Return Code   : TRUE-Sucess to create all task
 *                    FALSE-Fail to creat all task.
 */
ER MtxSample( void)
{
    T_CMTX cmtx;
    T_CTSK ctskA;
    T_CTSK ctskB;

    tm_putstring((UB*)"Mutex sample step 1-Create Mutex;\n");
    cmtx.exinf  = (VP)NULL;
    cmtx.mtxatr = TA_TPRI|TA_CEILING;
    cmtx.ceilpri = 15;    /* priority ceiling for mutex */
    MtxID = tk_cre_mtx(&cmtx);
    if(MtxID>0) {
        tm_putstring((UB*)"Mutex sample create step 1-Create Mutex, ID is ");
        tm_putchar(MtxID+48);
        tm_putstring((UB*)" !\n");
    } else {
        tm_putstring((UB*)"Error code is ");
        tm_putchar(MtxID+48);
        tm_putstring((UB*)" !\n");
    }

    ctskA.exinf   = (VP)NULL;
    ctskA.tskatr  = TA_HLNG | TA_RNG0;
    ctskA.task    = MtxSampleTaskA;
    ctskA.itskpri = 20;
    ctskA.stksz   = 512*4;
    TaskID_A      = tk_cre_tsk(&ctskA);
    if(TaskID_A>0) {
        tm_putstring((UB*)"Mutex sample create step 2-Create Task A, ID is ");
        tm_putchar(TaskID_A+48);
        tm_putstring((UB*)" !\n");
    } else {
        tm_putstring((UB*)"Error code is ");
        tm_putchar(TaskID_A+48);
        tm_putstring((UB*)" !\n");
    }

    ctskB.exinf   = (VP)NULL;
    ctskB.tskatr  = TA_HLNG | TA_RNG0;
    ctskB.task    = MtxSampleTaskB;
    ctskB.itskpri = 20;
    ctskB.stksz   = 512*4;
    TaskID_B      = tk_cre_tsk(&ctskB);
    if(TaskID_B>0) {
        tm_putstring((UB*)"Mutex sample create step 3-Create Task B, ID is ");
        tm_putchar(TaskID_B+48);
        tm_putstring((UB*)" !\n");
    } else {
        tm_putstring((UB*)"Error code is ");
        tm_putchar(TaskID_B+48);
        tm_putstring((UB*)" !\n");
    }

    tm_putstring((UB*)"Mutex sample create step 4-Start Task B;\n\n");
    tk_sta_tsk(TaskID_B,0);

    return E_OK;
} 
 

 /*
 *    Function Name	: MtxSampleTaskA
 *    Create Date   : 2012/09/28-2013/01/20
 *    Author	    : wangxd-wangxd
 *    Description   : Task A visits the mutex and shows information.
 *    Param	        : stacd:parameter from start task
 *                  : exinf:
 *    Return Code   : None.
 */
void MtxSampleTaskA(W stacd,VP exinf)
{
	tm_putstring((UB*)"Task A start successfully!\n");
	while(1){
        PutTaskPriority(TaskID_A);
		tk_loc_mtx(MtxID, TMO_FEVR);
		tm_putstring((UB*)"Task A locked the mutex successfully!\n");
        PutTaskPriority(TaskID_A);
		GlobalData = (UB*)"Task A is visiting GlobalData...\n";
		tm_putstring((UB*)GlobalData);
        Delay();
        tm_putstring((UB*)"======================================\n");
        Delay();
		tm_putstring((UB*)"Task A will unlock the mutex!\n\n");
		tk_unl_mtx(MtxID);
	}
}

/*
 *    Function Name	: MtxSampleTaskB
 *    Create Date   : 2012/09/28-2013/01/21
 *    Author	    : wangxd-wangxd
 *    Description   : Task B visits the mutex and shows information.
 *    Param	        : stacd:parameter from start task
 *                  : exinf:
 *    Return Code   : None.
 */
void MtxSampleTaskB(W stacd,VP exinf)
{
	B c;

    tm_putstring((UB*)"Task B will start task A;\n\n");
    tk_sta_tsk(TaskID_A,0);

	while(1){
        tm_putstring((UB*)"Task B is running,input Command(e=exit):\n");
        c = tm_getchar(0);
        if(c=='e') {
    	    break;
        }

        PutTaskPriority(TaskID_B);
		tk_loc_mtx(MtxID, TMO_FEVR);
    	tm_putstring((UB*)"Task B locked the mutex successfully!\n");
        PutTaskPriority(TaskID_B);
		GlobalData = (UB*)"Task B is visiting GlobalData...\n";
		tm_putstring((UB*)GlobalData);
        Delay();
        tm_putstring((UB*)"======================================\n");
        Delay();
		tm_putstring((UB*)"Task B will unlock the mutex!\n\n");
		tk_unl_mtx(MtxID);
	}
	tm_putstring((UB*)"Task B will delete mutex;\n");
    tk_del_mbx(MtxID);
	tm_putstring((UB*)"Task B will terminate&delete task A;\n");
    tk_ter_tsk(TaskID_A);
    tk_del_tsk(TaskID_A);
	tm_putstring((UB*)"Task B will terminate&delete self;\n");
    tk_exd_tsk();
}

/*
 *    Function Name : ltostr
 *    Create Date   : 2009/04/09-2012/8/5
 *    Author        : wangwhb-wangshb
 *    Description   : Change long to string according the base number
 *    Param         : UW Val      Source long number to change
 *                    B *pString  Destination  string to store result
 *                    UB Base     The number to used to change
 *                    UW Length   pString's max length
 *    Return Code   : UW          Actual pString's length
*/
UW ltostr(UW Val,B *pString,UB Base,UW Length)
{
	B  c, *pInit;
	UB  i,j;
	UW Len,SwapLen;

	*pString='\0';
	pInit=pString;
	if(Val==0) {
	    *pString++='0';
	    *pString='\0';              /*added by cheny to deal with the case that input number is zero 2009-04-15*/
	}
	switch(Base) {
		case 10:                    /* Base is 10,convert to 10 base string */
		    for(;Val>0;) {
		        i=Val%Base;
		        Val=Val/Base;
		        *pString++=(B)((UB)'0'+i);
		    }
		    *pString='\0';
		    break;
		case 16:                    /* Base is 16,convert to 16 base string */
		    for(;Val>0;) {
		        i=Val%Base;
		        Val=Val/Base;
		        if(i<=9) {
		            *pString++=(B)((UB)'0'+i);
		        } else {
		            *pString++=(B)((UB)'A'+i-10);
		        }
		    }
		    *pString='\0';
		    break;
		default:
		    break;
	}

	Len=strlen(pInit);
	SwapLen=Len;
	/*fill '\0' from string end to right */
	if(Length>Len) {
		for(i=Len;i<Length;i++) {
			*(pInit+i)='\0';
		}
		*(pInit+Length)='\0';
	}

	/* swap high and low order */
	if(SwapLen>0) {
		for(i=0,j=SwapLen - 1;i<j;i++,j--) {
		    c=*(pInit+i);
		    *(pInit+i)=*(pInit+j);
		    *(pInit+j)=c;
		}
	}
    return SwapLen;
}

/*
 *    Function Name : PutTaskPriority
 *    Create Date   : 2010/01/21-2013/01/21
 *    Author        : wangxd-wangxd
 *    Description   : refer task priority.
 *    Param         : ID taskid     task ID number
 *    Return Code   : none
 */
void PutTaskPriority(ID taskid)
{
    T_RTSK rtsk;
    ER ercd;
    B tskpri[10];

    ercd = tk_ref_tsk(taskid, &rtsk);
    if(E_OK == ercd){
    	if(taskid == TaskID_A){
    	    tm_putstring((UB*)"Task A");
    	}else{
    	    tm_putstring((UB*)"Task B");
    	}
      	tm_putstring((UB*)" current priority is ");
    	ltostr(rtsk.tskpri,tskpri,10,10);
      	tm_putstring((UB*)tskpri);
      	tm_putstring((UB*)"\n");
    }
}

/*
 *    Function Name : Delay
 *    Create Date   : 2010/03/23-2013/01/21
 *    Author        : cheny-wangxd
 *    Description   : Time delay
 *    Param         : void
 *    Return Code   : none
 */
void Delay(void)
{
    UINT i=0x1000000;
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
	MtxSample();
    for(;;); /* never return */
    return 0;
}
