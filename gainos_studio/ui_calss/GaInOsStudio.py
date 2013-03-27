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
from PyQt4.QtGui import QMainWindow
from PyQt4.QtCore import pyqtSignature
from Ui_GaInOsStudio import Ui_wMainClass
from PyQt4.QtGui import QMainWindow, QFileDialog
from PyQt4.QtGui import QTreeWidgetItem, QMessageBox
from PyQt4.QtCore import QStringList,QString
from DlgStart import  DlgStart

from GaInOsCfg import *
from ArxmlParser import *
from ArxmlSaver import *
from CodeGen import *
from DlgArAdd import *
from AutosarCfg import *
class wMainClass(QMainWindow, Ui_wMainClass):
    """
    Class documentation goes here.
    """
    def __init__(self,argc,argv,parent = None):
        """
        Constructor
        """
        QMainWindow.__init__(self, parent)
        self.setupUi(self);
        self.arxml='';
        self.cfg=GaInOsCfg();
        #curtree 对应Gui树目录控件中被选中项
        self.curtree=None;
        #curobj则和curtree相互协调一致，但curobj是GaInOS的一个对象，
        #可能为Task、Event、Alarm或者Resource
        self.curobj=None;
        if(argc == 3 and argv[1]== "--eclipse"):
            dir = self.getProject(argv[2]);
            if(dir != argv[2]+'/'):
                self.getCfgArxml(dir);
                LoadArxml(self.cfg,self.arxml);
            else:
                QMessageBox(QMessageBox.Information, 'GaInOS Info', 
                    'Cann\'t locate a ture exist OSEK(uTenux) Project,you can load/new arxml by hand!').exec_();
                self.arxml=argv[2]+'/';
                #sys.exit(-1);
        self.initGui();

    def initButton(self):
        self.btnAdd.setDisabled(True);
        self.btnDel.setDisabled(True);

    def initTab(self):
        #基于tkernel，默认任务为扩展任务ECC
        self.cmbxTskType.setDisabled(True);
        self.cmbxTskType.setCurrentIndex(1);
        #基于tkernel，默认任务为可剥夺
        self.cbxTskPreemtable.setDisabled(True);
        self.cbxTskPreemtable.setChecked(True);
        #基于tkernel，默认任务最大激活次数为1
        self.spbxTskMaxActivateCount.setDisabled(True);
        self.spbxTskMaxActivateCount.setValue(1);
        #Autosar 配置信息显示控件
        self.pteInfo.setDisabled(True);

    def initSpbxRange(self):
        self.spbxResCeilPrio.setRange(1, 140);
        self.spbxTskPrio.setRange(1, 140);
        self.spbxTskStkSize.setRange(32, 1024*10);
    
    def reloadTaskGui(self):
        tree=self.trGaInOsCfgList.topLevelItem(0);
        for index in range(0, tree.childCount()):
            temp=tree.takeChild(0);
            del temp;
        for obj in self.cfg.taskList:
            item=QTreeWidgetItem(tree,QStringList(obj.name));
            tree.addChild(item);
            for ent in obj.eventList:
                item2=QTreeWidgetItem(item,QStringList(ent.name));
                item.addChild(item2);

    def reloadTreeGui(self, trindex, list):
        tree=self.trGaInOsCfgList.topLevelItem(trindex);
        for index in range(0, tree.childCount()):
            temp=tree.takeChild(0);
            del temp;
        for obj in list:
            item=QTreeWidgetItem(tree,QStringList(obj.name));
            tree.addChild(item);

    def reloadGui(self):
        self.reloadTaskGui();
        self.reloadTreeGui(1, self.cfg.resourceList);
        self.reloadTreeGui(2, self.cfg.alarmList);
        self.reloadTreeGui(3, self.cfg.arobjList);
        self.fileSavedIndicate();

    def initMenu(self):
        """关联快捷键"""
        self.actionOpen.setShortcut('Ctrl+O');
        self.actionSave.setShortcut('Ctrl+S');
        self.actionSave_As.setShortcut('Ctrl+Shift+S');
        self.actionNew.setShortcut('Ctrl+N');
        
    def initGui(self):
        self.leFileOpened.setText(self.arxml);
        self.leFileOpened.setDisabled(True);
        #暂时只支持一个芯片MC9S12DP512的Autosar各组建配置
        self.cmbxMcuChip.setDisabled(True);
        self.setWindowTitle('GaInOS Studio(parai@foxmail.com)');
        self.initButton();
        self.initTab();
        self.initMenu();
        self.disableAllTab();
        self.initSpbxRange();
        self.reloadGui();

    def getProject(self, root):
        """返回选择的工程的绝对路径"""
        dlg = DlgStart(root);
        dlg.show();
        dlg.exec_();
        if(dlg.result == True):
            return root+'/'+dlg.proj;
        else:
            return root+'/';

    def getCfgArxml(self, dir):
        """如果存在gainoscfg.arxml配置文件，则返回之，
        否则，将新建一个空的文件"""
        arxml = dir+'/kernel/osek/src/config'+'/gainoscfg.arxml'
        if(False == os.path.isfile(arxml)):
            gnewArxml(arxml);
        self.arxml=arxml;

    def refreshButton(self):
        if(self.curtree==None):
            return;
        trname = self.curtree.text(0);
        if(trname=='Task'):
            self.btnAdd.setText('Add Task');
            self.btnAdd.setDisabled(False);
            self.btnDel.setDisabled(True);
        elif(trname=='Resource'):
            self.btnAdd.setText('Add Resource');
            self.btnAdd.setDisabled(False);
            self.btnDel.setDisabled(True);
        elif(trname=='Alarm'):
            self.btnAdd.setText('Add Alarm');
            self.btnAdd.setDisabled(False);
            self.btnDel.setDisabled(True);
        elif(trname=='Autosar'):
            self.btnAdd.setText('Add ...');
            self.btnAdd.setDisabled(False);
            self.btnDel.setDisabled(True);
        elif(self.curtree.parent().text(0)=='Task'):
            self.btnAdd.setText('Add Event');
            self.btnDel.setText('Delete Task');
            self.btnAdd.setDisabled(False);
            self.btnDel.setDisabled(False);
        elif(self.curtree.parent().text(0)=='Resource'):
            self.btnDel.setText('Delete Resource');
            self.btnAdd.setDisabled(True);
            self.btnDel.setDisabled(False);
        elif(self.curtree.parent().text(0)=='Alarm'):
            self.btnDel.setText('Delete Alarm');
            self.btnAdd.setDisabled(True);
            self.btnDel.setDisabled(False);
        elif(self.curtree.parent().text(0)=='Autosar'):
            self.btnDel.setText('Delete ...');
            self.btnAdd.setDisabled(True);
            self.btnDel.setDisabled(False);
        elif(self.curtree.parent().parent().text(0)=='Task'):
            self.btnDel.setText('Delete Event');
            self.btnAdd.setDisabled(True);
            self.btnDel.setDisabled(False);

    def disableAllTab(self):
        """禁止所有的Tab页"""
        for i in  range(0, 6):
            self.tblGaInOsCfg.setTabEnabled(i, False);
    
    def enableTab(self, index):
        """使能xIndex指向的Tab页"""
        for i in  range(0, 6):
            if(i==index):
                self.tblGaInOsCfg.setTabEnabled(i, True);
                self.tblGaInOsCfg.setCurrentIndex(i);
            else:
                self.tblGaInOsCfg.setTabEnabled(i, False);
        
    def findObj(self, list, name):
        for obj in list:
            if(name==obj.name):
                return obj;
        return None;

    def refreshTaskTab(self, name):
        self.curobj=self.findObj(self.cfg.taskList, name);
        self.leTskName.setText(name);
        self.spbxTskStkSize.setValue(self.curobj.stksz);
        self.cbxTskAutoStart.setChecked(self.curobj.autostart);
        self.spbxTskPrio.setValue(self.curobj.prio);
        self.enableTab(0);

    def refreshResourceTab(self, name):
        self.curobj=self.findObj(self.cfg.resourceList, name);
        self.leResName.setText(name);
        self.spbxResCeilPrio.setValue(self.curobj.ceilprio);
        self.enableTab(1);

    def refreshAlarmTabCmbx(self):
        """根据Alarm的类型刷新Alarm tab中的combox组建"""
        self.cmbxAlarmTask.clear();
        self.cmbxAlarmEvent.clear();
        if(self.curobj.type == 'callback'):
            index = 0;
            self.cmbxAlarmTask.setDisabled(True);
            self.cmbxAlarmEvent.setDisabled(True);
        elif(self.curobj.type == 'task'):
            index = 1;
            self.cmbxAlarmTask.setDisabled(False);
            self.cmbxAlarmEvent.setDisabled(True);
            self.lblAlarmTask.setText('Alarm Activate Task:');
            #task
            ri=i=-1;
            for obj in self.cfg.taskList:
                self.cmbxAlarmTask.addItem(obj.name);
                i+=1;
                if(self.curobj.task == obj.name):
                    #find it
                    ri=i;
            self.cmbxAlarmTask.setCurrentIndex(ri);
        elif(self.curobj.type == 'event'):
            index = 2;
            self.cmbxAlarmTask.setDisabled(False);
            self.cmbxAlarmEvent.setDisabled(False);
            self.lblAlarmTask.setText('Alarm Event Task:');
            #task
            tsk=None;
            ri=i=-1;
            for obj in self.cfg.taskList:
                self.cmbxAlarmTask.addItem(obj.name);
                i+=1;
                if(self.curobj.task == obj.name):
                    #find it
                    tsk=obj;
                    ri=i;
            self.cmbxAlarmTask.setCurrentIndex(ri);
            #task event
            ri=i=-1;
            if(tsk != None):
                for obj in tsk.eventList:
                    self.cmbxAlarmEvent.addItem(obj.name);
                    i+=1;
                    if(self.curobj.event == obj.name):
                        #find it
                        ri=i;
            self.cmbxAlarmEvent.setCurrentIndex(ri);
        self.cmbxAlarmType.setCurrentIndex(index);
            
    def refreshAlarmTab(self, name):
        self.curobj=self.findObj(self.cfg.alarmList, name);
        self.leAlarmName.setText(name);
        self.refreshAlarmTabCmbx();        
        self.enableTab(3);

    def refreshEventTab(self, name):
        tsk=self.findObj(self.cfg.taskList, self.curtree.parent().text(0));
        self.curobj=self.findObj(tsk.eventList, name);
        self.leEventName.setText(self.curobj.name);
        self.leEventMask.setText(self.curobj.mask);
        self.enableTab(4);

    def refreshAutosarTab(self, name):
        self.curobj=self.findObj(self.cfg.arobjList, name);
        self.enableTab(5);
        self.pteInfo.setPlainText(self.curobj.toString());

    def refreshTab(self):
        if(self.curtree.parent() == None):
            self.disableAllTab();
            self.curobj=None;
            return;
        trname = self.curtree.parent().text(0);
        objname= self.curtree.text(0);
        if(trname == 'Task'):
            self.refreshTaskTab(objname);
        elif(trname == 'Resource'):
            self.refreshResourceTab(objname);
        elif(trname == 'Alarm'):
            self.refreshAlarmTab(objname);
        elif(trname == 'Autosar'):
            self.refreshAutosarTab(objname);
        elif(self.curtree.parent().parent().text(0) == 'Task'):
            self.refreshEventTab(objname);
    
    @pyqtSignature("QTreeWidgetItem*, int")
    def on_trGaInOsCfgList_itemClicked(self, item, column):
        self.curtree=item;
        self.refreshButton();
        self.refreshTab();

    def addTask(self):
        """添加一个任务节点，使用默认名称"""
        id = len(self.cfg.taskList);
        name=QString('vTask%d'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        obj=Task(name,id+1,512);
        self.cfg.taskList.append(obj);
        self.curtree.setExpanded(True);

    def addResource(self):
        """添加一个资源节点，使用默认名称"""
        id = len(self.cfg.resourceList);
        name=QString('vRes%d'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        obj=Resource(name,id+1);
        self.cfg.resourceList.append(obj);
        self.curtree.setExpanded(True);

    def addAlarm(self):
        """添加一个报警器节点，使用默认名称"""
        id = len(self.cfg.alarmList);
        name=QString('vAlarm%d'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        obj=Alarm(name);
        self.cfg.alarmList.append(obj);
        self.curtree.setExpanded(True);

    def addEvent(self):
        """添加一个报警器节点，使用默认名称"""
        id = len(self.curobj.eventList);
        name=QString('%sEvent%d'%(self.curobj.name,id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        obj=Event(name, hex(1<<id));
        self.curobj.eventList.append(obj);
        self.curtree.setExpanded(True);

    def fileChangedIndicate(self):
       self.btnFileSave.setText('Save**');
       self.setWindowTitle('GaInOS Studio(parai@foxmail.com)       (unsaved)');

    def fileSavedIndicate(self):
        self.btnFileSave.setText('Save');
        self.setWindowTitle('GaInOS Studio(parai@foxmail.com)');

    def addAutosar(self):
        dlg=DlgArAdd(self.cfg.arobjList);
        dlg.exec_();
        if(dlg.result==True):
            item=QTreeWidgetItem(self.curtree,QStringList(dlg.comp));
            self.curtree.addChild(item);
            self.curtree.setExpanded(True);
            obj=AutosarObj(str(dlg.comp), self.cfg.chip);
            self.cfg.arobjList.append(obj);

    @pyqtSignature("")
    def on_btnAdd_clicked(self):
        text=self.btnAdd.text();
        if(text=='Add Task'):
            self.addTask();
        elif(text=='Add Resource'):
            self.addResource();
        elif(text=='Add Alarm'):
            self.addAlarm();
        elif(text=='Add Event'):
            self.addEvent();
        elif(text=='Add ...'):
            self.addAutosar();
        self.fileChangedIndicate();

    def delObj(self, list):
        list.remove(self.curobj);
        del self.curobj

    @pyqtSignature("")
    def on_btnDel_clicked(self):
        parent = self.curtree.parent();
        index = parent.indexOfChild(self.curtree);
        parent.takeChild(index);
        text=self.btnDel.text();
        if(text=='Delete Task'):
            self.delObj(self.cfg.taskList);
        elif(text=='Delete Resource'):
            self.delObj(self.cfg.resourceList);
        elif(text=='Delete Alarm'):
            self.delObj(self.cfg.alarmList);
        elif(text=='Delete Event'):
            tsk=self.findObj(self.cfg.taskList, parent.text(0));
            self.delObj(tsk.eventList);
        elif(text=='Delete ...'):
            self.delObj(self.cfg.arobjList);
        del self.curtree;
        #reselect a tree item,software trigger on_trGaInOsCfgList_itemClicked()
        if(index>0):
            parent.child(index-1).setSelected(True);
            self.on_trGaInOsCfgList_itemClicked(parent.child(index-1), 0);
        else:
            parent.setSelected(True);
            self.on_trGaInOsCfgList_itemClicked(parent, 0);
        self.fileChangedIndicate();

   
    @pyqtSignature("QString")
    def on_cmbxAlarmType_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.type!=p0):
                self.curobj.type=p0;
                self.refreshAlarmTabCmbx();
                self.fileChangedIndicate();
    
    @pyqtSignature("QString")
    def on_cmbxAlarmTask_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.task!=p0):
                self.curobj.task=p0;
                self.refreshAlarmTabCmbx();
                self.fileChangedIndicate();

    @pyqtSignature("QString")
    def on_cmbxAlarmEvent_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.event!=p0):
                self.curobj.event=p0;
                self.fileChangedIndicate();
    
    @pyqtSignature("int")
    def on_spbxResCeilPrio_valueChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.ceilprio!=p0):
                self.curobj.ceilprio=p0;
                self.fileChangedIndicate();
    
    @pyqtSignature("int")
    def on_spbxTskStkSize_valueChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.stksz!=p0):
                self.curobj.stksz=p0;
                self.fileChangedIndicate();
    
    @pyqtSignature("int")
    def on_spbxTskPrio_valueChanged(self, p0):
        if(self.curobj!=None):  
            if(self.curobj.prio!=p0):
                self.curobj.prio=p0
                self.fileChangedIndicate();
    
    @pyqtSignature("bool")
    def on_cbxTskAutoStart_clicked(self, checked):
        if(self.curobj!=None):
            if(self.curobj.autostart!=checked):
                self.curobj.autostart=checked;
                self.fileChangedIndicate();
 
    @pyqtSignature("QString")
    def on_leEventName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileChangedIndicate();
    
    @pyqtSignature("QString")
    def on_leEventMask_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.mask!=p0):
                self.curobj.mask=p0;
                self.fileChangedIndicate();
    
    @pyqtSignature("QString")
    def on_leAlarmName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileChangedIndicate();
    
    @pyqtSignature("QString")
    def on_leCntName_textChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.name=p0;
            self.curtree.setText(0, p0);
            self.fileChangedIndicate();
    
    @pyqtSignature("QString")
    def on_leResName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileChangedIndicate();
    
    @pyqtSignature("QString")
    def on_leTskName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileChangedIndicate();
 
    @pyqtSignature("")
    def on_btnCheck_clicked(self):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
    
    def saveArxml(self):
        if(self.arxml.find('.arxml')==-1):
            self.arxml=QFileDialog.getSaveFileName(self, 'Save GaInOS Configure File.', 
                '%s/%s'%(self.arxml,'gainoscfg.arxml'), 'GaInOsCfgFile(*.arxml)');
            self.arxml=str(self.arxml);
        if(self.arxml.find('.arxml')!=-1):
            self.leFileOpened.setText(self.arxml);
            ArxmlSaver(self.cfg, self.arxml);
            self.fileSavedIndicate();
    
    @pyqtSignature("")
    def on_btnFileSave_clicked(self):
        self.saveArxml();
    
    @pyqtSignature("")
    def on_btnGen_clicked(self):
        self.saveArxml();
        CodeGen(self.cfg, os.path.dirname(self.arxml));
        QMessageBox(QMessageBox.Information, 'GaInOS Info', 
                'Gen C Code Successfully at <%s>!'%(
                os.path.dirname(self.arxml))).exec_();

    def openArxml(self):
        """加载配置文件"""
        arxml=QFileDialog.getOpenFileName(self, 'Open GaInOS Configure File.', 
                '%s/%s'%(self.arxml,'gainoscfg.arxml'), 'GaInOsCfgFile(*.arxml)');
        if(arxml!=''):
            self.arxml=arxml;
            self.leFileOpened.setText(arxml);
            LoadArxml(self.cfg,self.arxml);
            self.initGui();
            QMessageBox(QMessageBox.Information, 'GaInOS Info', 
                'Load Configure File <%s> Done!'%(arxml)).exec_();

    @pyqtSignature("")
    def on_btnFileOpen_clicked(self):
        self.openArxml();
        self.fileSavedIndicate();
    
    @pyqtSignature("")
    def on_actionNew_triggered(self):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
    
    @pyqtSignature("")
    def on_actionOpen_triggered(self):
        self.openArxml();
    
    @pyqtSignature("")
    def on_actionOpen_Recent_Files_triggered(self):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
    
    @pyqtSignature("")
    def on_actionSave_triggered(self):
        self.saveArxml();
    
    @pyqtSignature("")
    def on_actionSave_As_triggered(self):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
    
    @pyqtSignature("")
    def on_actionQuit_triggered(self):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError

    @pyqtSignature("QTreeWidgetItem*, int")
    def on_trGaInOsCfgList_itemDoubleClicked(self, item, column):
        if(item.parent()!=None
           and item.parent().text(0)=='Autosar'):
               obj=self.findObj(self.cfg.arobjList, item.text(0));
               obj.show();
               self.fileChangedIndicate();
