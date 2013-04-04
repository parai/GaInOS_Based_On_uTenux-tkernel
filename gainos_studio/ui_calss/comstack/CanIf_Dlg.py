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

from PyQt4.QtGui import QDialog
from PyQt4.QtCore import pyqtSignature
from PyQt4.QtGui import QTreeWidgetItem, QMessageBox
from PyQt4.QtCore import QStringList,QString
from CanIfCfg import *
from Ui_CanIf_Dlg import Ui_CanIf_Dlg

class CanIf_Dlg(QDialog, Ui_CanIf_Dlg):
    """
    Class documentation goes here.
    """
    def __init__(self, cfg, parent = None):
        """
        Constructor
        """
        self.cfg=cfg;
        self.curobj=None;
        self.curtree=None;
        QDialog.__init__(self, parent);
        self.setupUi(self);
        self.initGui();

    def initButton(self):
        self.btnAdd.setDisabled(True);
        self.btnAdd2.setDisabled(True);
        self.btnDel.setDisabled(True);

    def disableAllTab(self):
        """禁止所有的Tab页"""
        for i in  range(0, 5):
            self.tabCfg.setTabEnabled(i, False);
    
    def enableTab(self, index):
        """使能xIndex指向的Tab页"""
        for i in  range(0, 5):
            if(i==index):
                self.tabCfg.setTabEnabled(i, True);
                self.tabCfg.setCurrentIndex(i);
            else:
                self.tabCfg.setTabEnabled(i, False); 

    def reloadTreeGui(self):
        tree=self.trCanIfCfg.topLevelItem(0);
        for index in range(0, tree.childCount()):
            temp=tree.takeChild(0);
            del temp;
        for obj in self.cfg.channelList:
            item=QTreeWidgetItem(tree,QStringList(obj.name));
            tree.addChild(item);
            for hoh in obj.hthList+obj.hrhList:
                item2=QTreeWidgetItem(item,QStringList(hoh.name));
                item.addChild(item2);
                for pdu in hoh.pduList:
                    item3=QTreeWidgetItem(item2,QStringList(pdu.name));
                    item2.addChild(item3);
                

    def initGui(self):
        #Init General 
        self.cbxDevErr.setChecked(self.cfg.General.DevErrorDetection);
        self.cbxVersionInfo.setChecked(self.cfg.General.VersionInfoApi);
        self.cbxDlcCheck.setChecked(self.cfg.General.DlcCheck);
        self.cbxRuntimePduCfg.setChecked(self.cfg.General.RuntimePduConfig);
        self.leBusoffNf.setText(self.cfg.General.BusoffNotification);
        self.leErrorNf.setText(self.cfg.General.ErrorNotification);
        self.cmbxSoftwareFilterType.setDisabled(True);
        #Init Button and Tab
        self.initButton();
        self.disableAllTab();
        #Init Tree
        self.reloadTreeGui();  

    def refreshButton(self):
        if(self.curtree==None):
            return;
        trname = self.curtree.text(0);
        if(trname=='Channels'):
            self.btnAdd.setText('Add Channel');
            self.btnAdd.setDisabled(False);
            self.btnAdd2.setDisabled(True);
            self.btnDel.setDisabled(True);
        elif(self.curtree.parent().text(0)=='Channels'):
            self.btnAdd.setText('Add Hth');
            self.btnAdd2.setText('Add Hrh');
            self.btnDel.setText('Del Channel');
            self.btnAdd.setDisabled(False);
            self.btnAdd2.setDisabled(False);            
            self.btnDel.setDisabled(False);
        elif(self.curtree.parent().parent().text(0)=='Channels'):
            self.btnAdd.setText('Add Pdu');
            self.btnDel.setText('Del Hoh');
            self.btnAdd.setDisabled(False);
            self.btnAdd2.setDisabled(True);
            self.btnDel.setDisabled(False);
        elif(self.curtree.parent().parent().parent().text(0)=='Channels'):
            self.btnDel.setText('Del Pdu');
            self.btnAdd.setDisabled(True);
            self.btnAdd2.setDisabled(True);
            self.btnDel.setDisabled(False);
    
    def delObj(self, list):
        list.remove(self.curobj);
        del self.curobj

    def findObj(self, list, name):
        for obj in list:
            if(name==obj.name):
                return obj;
        return None;

    def refreshChannelTab(self, name):
        obj = self.findObj(self.cfg.channelList, name);
        if(obj == None):
            return;
        self.curobj=obj;
        self.leChannelName.setText(obj.name);
        self.enableTab(0);
    
    def refreshHthTab(self, obj):
        self.curobj=obj;
        self.leHthName.setText(obj.name);
        self.enableTab(1);
    
    def refreshHrhTab(self, obj):
        self.curobj=obj;
        self.leHrhName.setText(obj.name);
        self.enableTab(2);
    
    def refreshHohTab(self, name):
        channel=self.findObj(self.cfg.channelList, self.curtree.parent().text(0));
        #首先搜索hthList
        obj = self.findObj(channel.hthList, name);
        if(obj==None):
            obj = self.findObj(channel.hrhList, name);
        if(obj==None):
            #搜索失败，直接返回
            return;
        if(obj.type=='hth'):
            self.refreshHthTab(obj);
        elif(obj.type=='hrh'):
            self.refreshHrhTab(obj);
        
    
    def refreshTab(self):
        if(self.curtree.parent() == None):
            self.disableAllTab();
            self.curobj=None;
            return;
        trname = self.curtree.parent().text(0);
        objname= self.curtree.text(0);
        if(trname  == 'Channels'):
            self.refreshChannelTab(objname);
        elif(self.curtree.parent().parent().text(0)=='Channels'):
            self.refreshHohTab(objname);

    @pyqtSignature("QTreeWidgetItem*, int")
    def on_trCanIfCfg_itemClicked(self, item, column):
        self.curtree=item;
        self.refreshButton();
        self.refreshTab();

    def addChannel(self):
        id = len(self.cfg.channelList);
        name='vCanIf_Channel%s'%(id);
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        self.curtree.setExpanded(True);
        obj=CanIfChannel(name);
        self.cfg.channelList.append(obj);

    def addHth(self):
        id = 0;
        name='vCanIf_Hth%s'%(id);
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        self.curtree.setExpanded(True);
        obj=CanIfHth(name);
        self.curobj.hthList.append(obj);

    def addHrh(self):
        id = 0;
        name='vCanIf_Hrh%s'%(id);
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        self.curtree.setExpanded(True);
        obj=CanIfHrh(name);
        self.curobj.hrhList.append(obj);

    def addPdu(self):
        id = 0;
        name='vCanIf_Pdu%s'%(id);
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        self.curtree.setExpanded(True);
        obj=CanIfPdu(name);
        self.curobj.pduList.append(obj);

    @pyqtSignature("")
    def on_btnAdd_clicked(self):
        text=self.btnAdd.text();
        if(text=='Add Channel'):
            self.addChannel();
        elif(text=='Add Hth'):
            self.addHth();
        elif(text=='Add Pdu'):
            self.addPdu();

    @pyqtSignature("")
    def on_btnAdd2_clicked(self):
        text=self.btnAdd2.text();
        if(text=='Add Hrh'):
            self.addHrh();
    
    @pyqtSignature("")
    def on_btnDel_clicked(self):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
