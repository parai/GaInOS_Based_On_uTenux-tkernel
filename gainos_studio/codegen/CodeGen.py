# -*- coding: utf-8 -*-

"""
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
"""
import os
import sys
import shutil 
from GaInOsCfg import *
from time import localtime, time,strftime
from Common import *
class CodeGen():
    """C 代码生成器"""
    def __init__(self, cfg, path):
        self.genOsekCfgC(cfg, '%s/osek_cfg.c'%(path));
        self.genOsekCfgH(cfg, '%s/osek_cfg.h'%(path));
        self.autosarCodeGen(cfg.arobjList, path);

    def autosarCodeGen(self, list, path):
        for obj in list:
            obj.codeGen(path);

    def backup(self, file):
        tm=localtime(time());
        file2=file+strftime("-%Y-%m-%d-%H-%M-%S",tm);
        shutil.copy(file, file2+'.bak');

    def genOsekCfgC(self, cfg, file):
        if os.path.isfile(file):
            self.backup(file);
        fp=open(file, 'w');
        fp.write('#include "osek_cfg.h"\n\n');
        #resource
        if(len(cfg.resourceList) > 0):
            fp.write('const T_CMTX OsekResourceTable[cfgOSEK_RESOURCE_NUM]=\n{\n');
            for obj in cfg.resourceList:
                fp.write('\tGenResourceCreInfo(%s),\t/* %s */\n'%(obj.ceilprio, obj.name));
            fp.write('};\n\n');
        #task
        ast=cre=stk=tcode=''
        for obj in cfg.taskList:
            stk+='GenTaskStack(%s,%s);\n'%(obj.name, obj.stksz);
            ast+='\t%s,\t/* %s */\n'%(TRUE(obj.autostart), obj.name);
            id='NULL';
            if(len(obj.eventList)>0):
                id='ID_%sEvent'%(obj.name);
            cre+='\tGenTaskCreInfo(%s,%s,%s),\n'%(obj.name, obj.prio, id);
            tcode+='TASK(%s)\n{\n'%(obj.name);
            tcode+='\ttm_putstring((UB*)"%s is running.\\r\\n");\n'%(obj.name);
            tcode+='\t(void)TerminateTask();\n}\n\n';
        fp.write('/* Generate Task Stack */\n');
        fp.write(stk);
        fp.write('/* Generate Task Create Information */\n');
        fp.write('const T_CTSK OsekTaskTable[cfgOSEK_TASK_NUM]=\n{\n%s};\n'%(cre));
        fp.write('/* Is Task auto-startable */\n');
        fp.write('const BOOL OsekTaskAuotStartable[cfgOSEK_TASK_NUM]=\n{\n%s};\n\n'%(ast));
        fp.write(tcode);
        #alarm
        alm=acode=''
        if(len(cfg.alarmList)>0):
            fp.write('ID OsekAlarmIdTable[cfgOSEK_ALARM_NUM];\n');
            fp.write('UB OsekAlarmTypeTable[cfgOSEK_ALARM_NUM];\n');
            for obj in cfg.alarmList:
                alm+='\tAlarmCallBackEntry(%s),\n'%(obj.name);
                acode+='ALARMCALLBACK(%s)\n{\n'%(obj.name);
                if(obj.type=='callback'):
                    acode+='\ttm_putstring((UB*)"%s cbk is running.\\r\\n");\n'%(obj.name);
                elif(obj.type=='task'):
                    acode+='\t(void)tk_sta_tsk(ID_%s,ID_%s);\n'%(obj.task, obj.task);
                elif(obj.type=='event'):
                    acode+='\t(void)SetEvent(ID_%s,%s);\n'%(obj.task, obj.event);
                acode+='}\n\n'
            fp.write('const FP OsekAlarmHandlerTable[cfgOSEK_ALARM_NUM]=\n{\n%s};\n'%(alm));
            fp.write(acode);
        fp.close();

    def genOsekCfgH(self, cfg, file):
        if os.path.isfile(file):
            self.backup(file);
        fp=open(file, 'w');
        fp.write('#ifndef _OSEK_CFG_H_\n');
        fp.write('#define _OSEK_CFG_H_\n');
        fp.write('#include "osek_os.h"\n\n'); 
        fp.write('/* #####################  TASK  ########################## */\n');
        fp.write('#define cfgOSEK_TASK_NUM %s\n'%(len(cfg.taskList)));
        fp.write('extern const T_CTSK OsekTaskTable[cfgOSEK_TASK_NUM];\n');
        fp.write('extern const BOOL   OsekTaskAuotStartable[cfgOSEK_TASK_NUM];\n');
        idtsk=ecd=ident='';
        id=entcnt=0;
        for obj in cfg.taskList:
            idtsk+='#define ID_%s\t\t (MIN_TSKID+%s)\n'%(obj.name,id);
            id+=1;
            ecd+='extern TASK(%s);\n'%(obj.name);
            if(len(obj.eventList)>0):
                ident+='#define ID_%sEvent\t\t(MIN_FLGID+%s)\n'%(obj.name,entcnt);
                entcnt+=1;
                for ent in obj.eventList:
                    ident+='#define %s\t\t %s\n'%(ent.name,ent.mask);
        fp.write(idtsk);
        fp.write(ecd);
        fp.write('/* #####################  EVENT ########################## */\n');
        fp.write('#define cfgOSEK_EVENTFLAG_NUM %s\n'%(entcnt));
        fp.write(ident);
        fp.write('/* #####################  ALARM ########################## */\n');
        fp.write('#define cfgOSEK_ALARM_NUM %s\n'%(len(cfg.alarmList)));
        if(len(cfg.alarmList)>0):
            fp.write('extern ID OsekAlarmIdTable[cfgOSEK_ALARM_NUM];\n');
            fp.write('extern UB OsekAlarmTypeTable[cfgOSEK_ALARM_NUM];\n');
            fp.write('extern const FP OsekAlarmHandlerTable[cfgOSEK_ALARM_NUM];\n');
        ident=ecd='';
        id=0;
        for obj in cfg.alarmList:
            ident+='#define ID_%s\t\t(%s)\n'%(obj.name,id);
            id+=1;
            ecd+='extern ALARMCALLBACK(%s);\n'%(obj.name);
        fp.write(ident);
        fp.write(ecd);
        fp.write('/*  ####################  RESOURCE ####################### */\n');
        fp.write('#define cfgOSEK_RESOURCE_NUM %s\n'%(len(cfg.resourceList)));
        if(len(cfg.resourceList)>0):
            fp.write('extern const T_CMTX OsekResourceTable[cfgOSEK_RESOURCE_NUM];\n');
        id=0;
        for obj in cfg.resourceList:
            fp.write('#define ID_%s\t\t (MIN_MTXID+%s)\n'%(obj.name,id));
            id+=1;                  
        fp.write('#endif /* _OSEK_CFG_H_ */\n\n');
