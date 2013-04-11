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
import os, sys
import shutil 
from time import localtime, time,strftime
from Common import *
class CanFilterMaskMc9S12dp512():
    def __init__(self, name):
        self.name=name;
        self.idam='CAN_IDAM_2_32BIT';
        self.idar=['0', '0','0', '0','0', '0', '0','0'];
        self.idmr=['0xFF', '0xFF', '0xFF', '0xFF', '0xFF', '0xFF', '0xFF', '0xFF'];

class CanHohMc9S12dp512():
    def __init__(self, name):
        self.name=name;
        self.hohType='CAN_ARC_HANDLE_TYPE_BASIC';
        self.idType ='CAN_ID_TYPE_STANDARD';
        self.idValue =0;
        self.objType= 'CAN_OBJECT_TYPE_RECEIVE';
        self.filterMask = '';
        self.mbMask = '0x00000000';

class CanCtrlMc9S12dp512():
    def __init__(self, name):
        self.name = name;
        self.baudrate=250;
        self.propseg=0;
        self.seg1=13;
        self.seg2=2;
        self.hohList=[];

class CanGeneralMc9S12dp512():
    def __init__(self):
        self.CanDevErrorDetection=True;
        self.CanVersionInfoApi = False;
        self.CanTimeoutDuration=10;

class CanCfgMc9S12dp512():
    def __init__(self):
        self.CanGeneral = CanGeneralMc9S12dp512();
        self.CanFilterMaskList = [];
        self.CanCtrlList=[];

from DlgCan_MC9S12DP512 import *
class CanObj_MC9S12DP512():
    def __init__(self):
        self.cfg=CanCfgMc9S12dp512();
    
    def toString(self):
        str='  Double Clicked to Start to Configure the Can!\n';
        return str;

    def show(self, cfg):
        dlg=DlgCanMC9S12DP512(self.cfg);
        dlg.exec_();

    def save(self, fp):
        """保存配置信息"""
        self.saveGeneral(fp);
        self.saveFilterMask(fp);
        self.saveCtrl(fp);
    
    def doParseGeneral(self, node):
        self.cfg.CanGeneral.CanDevErrorDetection=bool(node.find('CanDevErrorDetection').attrib['value']);
        self.cfg.CanGeneral.CanVersionInfoApi=bool(node.find('CanVersionInfoApi').attrib['value']);
        self.cfg.CanGeneral.CanTimeoutDuration=int(node.find('CanTimeoutDuration').attrib['value']);

    def doParseFilterMask(self, list):
        for node in list:
            obj=CanFilterMaskMc9S12dp512(node.attrib['name']);
            obj.idam=node.attrib['idam'];
            obj.idar[0]=node.attrib['idar0'];
            obj.idar[1]=node.attrib['idar1'];
            obj.idar[2]=node.attrib['idar2'];
            obj.idar[3]=node.attrib['idar3'];
            obj.idar[4]=node.attrib['idar4'];
            obj.idar[5]=node.attrib['idar5'];
            obj.idar[6]=node.attrib['idar6'];
            obj.idar[7]=node.attrib['idar7'];
            obj.idmr[0]=node.attrib['idmr0'];
            obj.idmr[1]=node.attrib['idmr1'];
            obj.idmr[2]=node.attrib['idmr2'];
            obj.idmr[3]=node.attrib['idmr3'];
            obj.idmr[4]=node.attrib['idmr4'];
            obj.idmr[5]=node.attrib['idmr5'];
            obj.idmr[6]=node.attrib['idmr6'];
            obj.idmr[7]=node.attrib['idmr7'];
            self.cfg.CanFilterMaskList.append(obj);

    def doParseCtrl(self, list):
        for node in list:
            obj = CanCtrlMc9S12dp512(node.attrib['name']);
            obj.propseg=int(node.attrib['propseg']);
            obj.seg1=int(node.attrib['seg1']);
            obj.seg2=int(node.attrib['seg2']);
            obj.baudrate=int(node.attrib['baudrate']);
            for nd in node.find('CanHohList'):
                hoh=CanHohMc9S12dp512(nd.attrib['name']);
                hoh.hohType=nd.attrib['hohType'];
                hoh.idType=nd.attrib['idType'];
                hoh.mbMask=nd.attrib['mbMask'];
                hoh.objType=nd.attrib['objType'];
                hoh.filterMask=nd.attrib['filterMask'];
                hoh.idValue=int(nd.attrib['idValue']);
                obj.hohList.append(hoh);
            self.cfg.CanCtrlList.append(obj);

    def doParse(self, arxml):
        self.doParseGeneral(arxml.find('CanGeneral'));
        self.doParseFilterMask(arxml.find('CanFilterMaskList'));
        self.doParseCtrl(arxml.find('CanCtrlList'));

    def saveGeneral(self, fp):
        fp.write('<CanGeneral>\n');
        fp.write('<CanDevErrorDetection value="%s"></CanDevErrorDetection>\n'%(
                    self.cfg.CanGeneral.CanDevErrorDetection));
        fp.write('<CanVersionInfoApi value="%s"></CanVersionInfoApi>\n'%(
                    self.cfg.CanGeneral.CanVersionInfoApi));
        fp.write('<CanTimeoutDuration value="%s"></CanTimeoutDuration>\n'%(
                    self.cfg.CanGeneral.CanTimeoutDuration));
        fp.write('</CanGeneral>\n');

    def saveFilterMask(self, fp):
        fp.write('<CanFilterMaskList>\n');
        for obj in self.cfg.CanFilterMaskList:
            attrib='name="%s" '%(obj.name);
            attrib+='idam="%s" '%(obj.idam);
            attrib+='idar0="%s" '%(obj.idar[0]);
            attrib+='idar1="%s" '%(obj.idar[1]);
            attrib+='idar2="%s" '%(obj.idar[2]);
            attrib+='idar3="%s" '%(obj.idar[3]);
            attrib+='idar4="%s" '%(obj.idar[4]);
            attrib+='idar5="%s" '%(obj.idar[5]);
            attrib+='idar6="%s" '%(obj.idar[6]);
            attrib+='idar7="%s" '%(obj.idar[7]);
            attrib+='idmr0="%s" '%(obj.idmr[0]);
            attrib+='idmr1="%s" '%(obj.idmr[1]);
            attrib+='idmr2="%s" '%(obj.idmr[2]);
            attrib+='idmr3="%s" '%(obj.idmr[3]);
            attrib+='idmr4="%s" '%(obj.idmr[4]);
            attrib+='idmr5="%s" '%(obj.idmr[5]);
            attrib+='idmr6="%s" '%(obj.idmr[6]);
            attrib+='idmr7="%s" '%(obj.idmr[7]);
            fp.write('<CanFilterMask %s></CanFilterMask>\n'%(attrib));
        fp.write('</CanFilterMaskList>\n');

    def saveCtrl(self, fp):
        fp.write('<CanCtrlList>\n');
        for obj in self.cfg.CanCtrlList:
            attrib='name="%s" '%(obj.name);
            attrib+='baudrate="%s" '%(obj.baudrate);
            attrib+='propseg="%s" '%(obj.propseg);
            attrib+='seg1="%s" '%(obj.seg1);
            attrib+='seg2="%s" '%(obj.seg2);
            fp.write('<CanCtrl %s>\n'%(attrib));
            fp.write('<CanHohList>\n');
            for hoh in obj.hohList:
                attrib2='name="%s" '%(hoh.name);
                attrib2+='hohType="%s" '%(hoh.hohType);
                attrib2+='idType="%s" '%(hoh.idType);
                attrib2+='idValue="%s" '%(hoh.idValue);
                attrib2+='objType="%s" '%(hoh.objType);
                attrib2+='filterMask="%s" '%(hoh.filterMask);
                attrib2+='mbMask="%s" '%(hoh.mbMask);
                fp.write('<CanHoh %s></CanHoh>\n'%(attrib2));
            fp.write('</CanHohList>\n');
            fp.write('</CanCtrl>\n');
        fp.write('</CanCtrlList>\n'); 
    
    def codeGen(self, path):
        path1=path+'/autosar/mcal/config/Can/sysdepend/app_mc9s12/chip_mc9s12dp512';
        try:
            os.mkdir(path+'/autosar');
        except:
            print "nothing serious!file already exists."
        try:
            os.mkdir(path+'/autosar/mcal');
        except:
            print "nothing serious!file already exists."            
        try:
            os.mkdir(path+'/autosar/mcal/config');
        except:
            print "nothing serious!file already exists."
        try:
            os.mkdir(path+'/autosar/mcal/config/Can');
        except:
            print "nothing serious!file already exists."
        try:
           os.mkdir(path+'/autosar/mcal/config/Can/sysdepend');
        except:
            print "nothing serious!file already exists."            
        try:
            os.mkdir(path+'/autosar/mcal/config/Can/sysdepend/app_mc9s12');
        except: 
            print "nothing serious!file already exists."
        try:
            os.mkdir(path+'/autosar/mcal/config/Can/sysdepend/app_mc9s12/chip_mc9s12dp512');
        except:
            print "nothing serious!file already exists."
        self.codeGenH(path1);
        self.codeGenC(path1);

    def backup(self, file):
        tm=localtime(time());
        file2=file+strftime("-%Y-%m-%d-%H-%M-%S",tm);
        shutil.copy(file, file2+'.bak');

    def codeGenH(self, path):
        file=path+'/Can_Cfg.h';
        if os.path.isfile(file):
            self.backup(file);
        fp=open(file, 'w');
        fp.write('#ifndef CAN_CFG_H_\n#define CAN_CFG_H_\n\n');
        fp.write('/* ################ Can General ################ */\n');
        fp.write('#define CAN_DEV_ERROR_DETECT %s\n'%(
                gSTD_ON(self.cfg.CanGeneral.CanDevErrorDetection)));
        fp.write('#define CAN_VERSION_INFO_API %s\n'%(
                gSTD_ON(self.cfg.CanGeneral.CanVersionInfoApi)));
        fp.write('#define CAN_TIMEOUT_DURATION %s /* ms */\n'%(
                self.cfg.CanGeneral.CanTimeoutDuration));
        fp.write('\n/* Number of controller configs */\n')
        fp.write('#define CAN_CTRL_CONFIG_CNT %s\n\n'%(len(self.cfg.CanCtrlList)));
        fp.write('/* Info used by CanIF,index of configure in Can_ControllerCfgData[] */\n');
        index=0;
        for obj in self.cfg.CanCtrlList:
            fp.write('#define INDEX_OF_%s %s\n'%(obj.name,index));
            index+=1;
        fp.write('\n');
        hths=hrhs='typedef enum {\n'
        for obj in self.cfg.CanCtrlList:
            for hoh in obj.hohList:
                if(hoh.objType=='CAN_OBJECT_TYPE_RECEIVE'):
                    hrhs+='\t%s,\n'%(hoh.name);
                elif(hoh.objType=='CAN_OBJECT_TYPE_TRANSMIT'):
                    hths+='\t%s,\n'%(hoh.name);
        hths+='\tNUM_OF_HTHS\n} Can_Arc_HTHType;\n\n'
        hrhs+='\tNUM_OF_HRHS\n} Can_Arc_HRHType;\n\n'
        fp.write(hths);
        fp.write(hrhs);
        fp.write('IMPORT const Can_ConfigType Can_ConfigData;\n');
        fp.write('#endif /* CAN_CFG_H_ */\n\n')
        fp.close();

    def codeGenC(self, path):
        file=path+'/Can_PBcfg.c';
        if os.path.isfile(file):
            self.backup(file);
        fp=open(file, 'w');
        fp.write('#include "Can.h"\n#include "Can_Cfg.h"\n\n');
        mask=''
        for obj in self.cfg.CanFilterMaskList:
            mask+='LOCAL const Can_FilterMaskType %s=\n{\n'%(obj.name)
            mask+='\t{%s,%s,%s,%s,%s,%s,%s,%s},\n'%(
                obj.idmr[0],obj.idmr[1],obj.idmr[2],obj.idmr[3],
                obj.idmr[4],obj.idmr[5],obj.idmr[6],obj.idmr[7]);
            mask+='\t{%s,%s,%s,%s,%s,%s,%s,%s},\n'%(
                obj.idar[0],obj.idar[1],obj.idar[2],obj.idar[3],
                obj.idar[4],obj.idar[5],obj.idar[6],obj.idar[7]);
            mask+='\t%s\n'%(obj.idam);
            mask+='};\n\n'
        fp.write(mask);
        hohs='';
        for obj in self.cfg.CanCtrlList:
            hohs+='LOCAL const Can_HardwareObjectType %s_HOHCfgData[]=\n{\n'%(obj.name);
            eol=0;
            for hoh in obj.hohList:
                eol+=1;
                hohs+='\t{\n';
                hohs+='\t\t%s,\n'%(hoh.hohType);
                hohs+='\t\t%s,\n'%(hoh.idType);
                hohs+='\t\t%s,\n'%(hoh.idValue);
                hohs+='\t\t%s,\n'%(hoh.name);
                hohs+='\t\t%s,\n'%(hoh.objType);
                hohs+='\t\t&%s,\n'%(hoh.filterMask);
                hohs+='\t\t%s,/* mbMask */\n'%(hoh.mbMask);
                if(eol==len(obj.hohList)):
                    hohs+='\t\tTRUE\n';
                else:
                    hohs+='\t\tFALSE\n';
                hohs+='\t},\n'
            hohs+='};\n\n';
        fp.write(hohs);
        ctrls='EXPORT const Can_ControllerConfigType  Can_ControllerCfgData[]=\n{\n';
        for obj in self.cfg.CanCtrlList:
            ctrls+='\t{\n';
            ctrls+='\t\t%s,\n'%(obj.name);
            ctrls+='\t\tCAN_PROCESS_TYPE_INTERRUPT,\n\t\tCAN_PROCESS_TYPE_INTERRUPT,\n\t\tCAN_PROCESS_TYPE_INTERRUPT,\n\t\tCAN_PROCESS_TYPE_INTERRUPT,\n';
            ctrls+='\t\t%s, /* baudrate(kbs) */\n'%(obj.baudrate);
            ctrls+='\t\t%s, /* propseg(SJW) */\n'%(obj.propseg);
            ctrls+='\t\t%s, /* seg1 */\n'%(obj.seg1);
            ctrls+='\t\t%s, /* seg2 */\n'%(obj.seg2);
            ctrls+='\t\t%s_HOHCfgData,\n'%(obj.name);
            ctrls+='\t\tFALSE\t/* LoopBack */\n';
            ctrls+='\t},\n';
        ctrls+='};\n';
        fp.write(ctrls);
        fp.write('EXPORT const Can_ConfigSetType Can_ConfigSetData ={Can_ControllerCfgData};\n'); 
        fp.write('EXPORT const Can_ConfigType Can_ConfigData ={&Can_ConfigSetData};\n');
        fp.close();
