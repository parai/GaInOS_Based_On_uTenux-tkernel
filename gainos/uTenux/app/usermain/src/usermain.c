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


typedef struct u_msg {
	VP	msgque[1];	/* Area for message queue,as same as T_MSG */
	UB  *usrmsg;    /* Area for message pointer */
} U_MSG;

void MbxSampleTaskA(W stacd,VP exinf);
void MbxSampleTaskB(W stacd,VP exinf);
void MbxSamplePutErcd(ER ercd);
UW ltostr(UW Val,B *pString,UB Base,UW Length);

static ID TaskID_A;
static ID TaskID_B;
static ID MbxID_S;
static ID MbxID_R;

/*
 *    Function Name	: MbxSample
 *    Create Date   : 2012/9/24-2012/10/18
 *    Author	    : Dengjk-Wangshb
 *    Description   : sample main program to create a mailbox.
 *    Param	        : None.
 *    Return Code   : TRUE-Sucess to create all task
 *                    FALSE-Fail to creat all task.
 */
ER MbxSample( void)
{
    ER ercd=E_OK;
    T_CTSK ctsk;
	T_CMBX cmbx;

    tm_putstring((UB*)"Mailbox sample create step 1-Create Task A;\n");
    ctsk.exinf = (VP)NULL;
    ctsk.tskatr = TA_HLNG|TA_RNG0;
    ctsk.task = MbxSampleTaskA;
    ctsk.itskpri = 20;
    ctsk.stksz = 512*4;
    TaskID_A = tk_cre_tsk(&ctsk);
    if(TaskID_A < E_OK) {
    	ercd=TaskID_A;
        return ercd;
    }
    
    tm_putstring((UB*)"Mailbox sample create step 2-Create Task B;\n");
    ctsk.exinf = (VP)NULL;
    ctsk.tskatr = TA_HLNG|TA_RNG0;
    ctsk.task = MbxSampleTaskB;
    ctsk.itskpri = 24;
    ctsk.stksz = 512*4;
    TaskID_B = tk_cre_tsk(&ctsk);
    if(TaskID_B < E_OK) {
    	ercd=TaskID_B;
        return ercd;
    }
    
    tm_putstring((UB*)"Mailbox sample create step 3-Create a send mailbox;\n");
    cmbx.exinf = (VP)NULL;
    cmbx.mbxatr = TA_TFIFO|TA_MFIFO;
    MbxID_S = tk_cre_mbx(&cmbx);
    if(MbxID_S < E_OK){
    	ercd=MbxID_S;
        return ercd;
    }

    tm_putstring((UB*)"Mailbox sample create step 4-Create a return mailbox;\n");
    cmbx.exinf = (VP)NULL;
    cmbx.mbxatr = TA_TFIFO|TA_MFIFO;
    MbxID_R = tk_cre_mbx(&cmbx);
    if(MbxID_R < E_OK){
      ercd=MbxID_R;
      return ercd;
    }

    tm_putstring((UB*)"Mailbox sample create step 5-Start Task A;\n");
    ercd = tk_sta_tsk(TaskID_A,0);
	if (E_OK != ercd){
		tm_putstring((UB*)"start Task A failed;\n");
	}
    return TRUE;
} 

/*
 *    Function Name	: MbxSampleTaskA
 *    Create Date   : 2012/9/24-2013/1/20
 *    Author	    : Dengjk-Dengjk
 *    Description   : Task A loop function.
 *    Param	        : stacd:parameter from start task
 *                  : exinf:
 *    Return Code   : None.
 */
void MbxSampleTaskA(W stacd,VP exinf)
{
	B c;
	ER ercd;
	U_MSG *pk_rcvmsg;
	U_MSG sndmsg;

    tm_putstring((UB*)"Mailbox sample create step 6-Start Task B;\n\n");
    ercd = tk_sta_tsk(TaskID_B,0);
	if (E_OK != ercd){
		tm_putstring((UB*)"Task B is starting failed;\n");
	}

	for(;;){
		tm_putstring((UB*)"Task A is running,Input Command(e=exit):\n");
	

		sndmsg.usrmsg = (UB*)"1-2-3,Please Starting up....\n";
		tm_putstring((UB*)"Task A send a message to Task B:");
		tm_putstring((UB*)sndmsg.usrmsg);
		ercd = tk_snd_mbx(MbxID_S,(T_MSG*)&sndmsg);
		if(E_OK == ercd){
			tm_putstring((UB*)"Task A sent a message successfully;\n");
		}else{
			tm_putstring((UB*)"Task A can't send a message;\n");
		}

		tm_putstring((UB*)"Task A is waiting Task B return message;\n\n");
		ercd = tk_rcv_mbx(MbxID_R,(T_MSG**)&pk_rcvmsg,-1);
		if(E_OK == ercd){
			tm_putstring((UB*)"Task A have received return message: ");
			tm_putstring((UB*)pk_rcvmsg->usrmsg);
		}else{
			tm_putstring((UB*)"Task A can't receive return message: \n");
			MbxSamplePutErcd(ercd);
		}
    }

	tm_putstring((UB*)"Task A will delete mailbox;\n");
    tk_del_mbx(MbxID_S);
    tk_del_mbx(MbxID_R);
	tm_putstring((UB*)"Task A will terminate&delete task B;\n");
    tk_ter_tsk(TaskID_B);
    tk_del_tsk(TaskID_B);
	tm_putstring((UB*)"Task A will terminate&delete self;\n");
    tk_exd_tsk();
}
/*
 *    Function Name	: MbxSampleTaskB
 *    Create Date   : 2012/9/24-2013/1/20
 *    Author	    : Dengjk_Dengjk
 *    Description   : Task B loop functin.
 *    Param	        : stacd:parameter from start task
 *                  : exinf:
 *    Return Code   : None.
 */
void MbxSampleTaskB(W stacd,VP exinf)
{
	ER ercd;
	U_MSG *pk_rcvmsg;
	U_MSG sndmsg;
		
	for(;;){
		tm_putstring((UB*)"Task B is waiting a message;\n");
		ercd = tk_rcv_mbx(MbxID_S,(T_MSG**)&pk_rcvmsg,-1);
		if(E_OK == ercd){
			tm_putstring((UB*)"Task B have received a message: ");
			tm_putstring((UB*)pk_rcvmsg->usrmsg);
		}else{
			tm_putstring((UB*)"Task B can't receive a message: ");
			MbxSamplePutErcd(ercd);
		}

		sndmsg.usrmsg = (UB*)"I have got up...\n";
		tm_putstring((UB*)"Task B return a message to Task A:");
		tm_putstring((UB*)sndmsg.usrmsg);
		tm_putstring((UB*)"\n");
		ercd = tk_snd_mbx(MbxID_R,(T_MSG*)&sndmsg);
		if(E_OK != ercd){
			tm_putstring((UB*)"Task B can't return a message;\n");
		}
	}
}


/*
 *    Function Name	: MbxSamplePutErcd
 *    Create Date   : 2012/9/30-2013/1/21
 *    Author	    : wangshb
 *    Description   : Put error code.
 *    Param	        : ER ercd:error code
 *    Return Code   : None.
 */
void MbxSamplePutErcd(ER ercd)
{
    B ercds[10];

  	tm_putstring((UB*)"Error code is ");
    switch(ercd){
        case E_OK:
        	tm_putstring((UB*)"0:E_OK");
        	break;
        case E_SYS:
        	tm_putstring((UB*)"-5:E_SYS");
        	break;
        case E_NOSPT:
        	tm_putstring((UB*)"-9:E_NOSPT");
        	break;
        case E_RSATR:
        	tm_putstring((UB*)"-11:E_LIMIT");
        	break;
        case E_PAR:
        	tm_putstring((UB*)"-17:E_PAR");
        	break;
        case E_ID:
        	tm_putstring((UB*)"-18:E_ID");
        	break;
        case E_NOMEM:
        	tm_putstring((UB*)"-33:E_NOMEM");
        	break;
        case E_LIMIT:
        	tm_putstring((UB*)"-34:E_LIMIT");
        	break;
        case E_NOEXS:
        	tm_putstring((UB*)"-42:E_NOEXS");
        	break;
        case E_TMOUT:
        	tm_putstring((UB*)"-50:E_TMOUT");
        	break;
        default:
        	if(ercd>0){
        	    tm_putstring((UB*)">0,UNKNOWN:");
        	    ltostr((UW)ercd,ercds,16,10);
        	    tm_putstring((UB*)ercds);
        	} else{
        		if(ercd<-67){
        			tm_putstring((UB*)"<-67,UNKNOWN");
        		} else {
        			tm_putstring((UB*)"0,-67,UNKNOWN");
        		}
        	}
        	break;
    }
  	tm_putstring((UB*)"\n");
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
	    *pString='\0';
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
	MbxSample();
    for(;;); /* never return */
    return 0;
}
