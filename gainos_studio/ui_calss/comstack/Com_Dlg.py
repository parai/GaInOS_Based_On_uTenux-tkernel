# -*- coding: utf-8 -*-

"""
Module implementing Com_Dlg.
"""

from PyQt4.QtGui import QDialog
from PyQt4.QtCore import pyqtSignature
from PyQt4.QtGui import QTreeWidgetItem, QMessageBox
from PyQt4.QtCore import QStringList,QString
from Ui_Com_Dlg import Ui_Com_Dlg
from ComCfg import *

class Com_Dlg(QDialog, Ui_Com_Dlg):
    """
    Class documentation goes here.
    """
    def __init__(self, cfg, parent = None):
        self.cfg=cfg;
        self.curobj=None;
        self.curtree=None;       
        QDialog.__init__(self, parent)
        self.setupUi(self)
        self.initGui();

    def initButton(self):
        self.btnAdd.setDisabled(True);
        self.btnAdd2.setDisabled(True);
        self.btnDel.setDisabled(True);

    def initGui(self):
        #self.reloadTreeGui();
        self.initButton();
        self.disableAllTab();
    
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

    def delObj(self, list):
        list.remove(self.curobj);
        del self.curobj

    def findObj(self, list, name):
        for obj in list:
            if(name==obj.name):
                return obj;
        return None;

    def addPduGroup(self):
        id = len(self.cfg.IPduGroupList);
        name='vCom_IPduGrp%s'%(id);
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        self.curtree.setExpanded(True);
        obj=ComIPduGroup(name);
        self.cfg.IPduGroupList.append(obj);

    def addIPdu(self):
        id = len(self.cfg.IPduList);
        name='vCom_IPdu%s'%(id);
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        self.curtree.setExpanded(True);
        obj=ComIPdu(name);
        self.cfg.IPduList.append(obj);

    def addSignal(self):
        if(self.curobj == None):
            return;
        id = len(self.curobj.signalList);
        name='%s_Signal%s'%(self.curobj.name, id);
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        self.curtree.setExpanded(True);
        obj=ComSignal(name);
        self.curobj.signalList.append(obj);

    def addSignalGroup(self):
        if(self.curobj == None):
            return;
        id = len(self.curobj.signalGroupList);
        name='%s_SigGrp%s'%(self.curobj.name, id);
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        self.curtree.setExpanded(True);
        obj=ComSignalGroup(name);
        self.curobj.signalGroupList.append(obj);

    def addGroupSignal(self):
        if(self.curobj == None):
            return;
        id = len(self.curobj.groupSignalList);
        name='%s_Signal%s'%(self.curobj.name, id);
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        self.curtree.setExpanded(True);
        obj=ComSignal(name);
        self.curobj.groupSignalList.append(obj);

    @pyqtSignature("")
    def on_btnAdd_clicked(self):
        text = self.btnAdd.text();
        if(text == 'Add Pdu Group'):
            self.addPduGroup();
        elif(text == 'Add IPdu'):
            self.addIPdu();
        elif(text == 'Add Signal'):
            self.addSignal();
        elif(text == 'Add Group Signal'):
            self.addGroupSignal();

    @pyqtSignature("")
    def on_btnAdd2_clicked(self):
        text = self.btnAdd2.text();
        if(text == 'Add Signal Group'):
            self.addSignalGroup();

    @pyqtSignature("")
    def on_btnDel_clicked(self):
        if(text == 'Del Pdu Group'):
            return
        elif(text == 'Del Signal'):
            return
        elif(text == 'Del Group Signal'):
            return;
        elif(text == 'Del Signal Group'):
            return;

    def refreshButton(self):
        if(self.curtree==None):
            return;
        trname = self.curtree.text(0);
        if(trname=='Pdu Group'):
            self.btnAdd.setText('Add Pdu Group');
            self.btnAdd.setDisabled(False);
            self.btnAdd2.setDisabled(True);
            self.btnDel.setDisabled(True);
        elif(trname=='Pdus'):
            self.btnAdd.setText('Add IPdu');
            self.btnAdd.setDisabled(False);
            self.btnAdd2.setDisabled(True);
            self.btnDel.setDisabled(True);
        elif(self.curtree.parent().text(0)=='Pdus'):
            self.btnAdd.setText('Add Signal');
            self.btnAdd2.setText('Add Signal Group');
            self.btnDel.setText('Del IPdu');
            self.btnAdd.setDisabled(False);
            self.btnAdd2.setDisabled(False);
            self.btnDel.setDisabled(False);
        elif(self.curtree.parent().text(0)=='Pdu Group'):
            self.btnDel.setText('Del Pdu Group');
            self.btnAdd.setDisabled(True);
            self.btnAdd2.setDisabled(True);
            self.btnDel.setDisabled(False);
        elif(self.curtree.parent().parent().text(0)=='Pdus'):
            pname = self.curtree.parent().text(0);
            name = self.curtree.text(0);
            Ipdu = self.findObj(self.cfg.IPduList, pname);
            sig = self.findObj(Ipdu.signalList+Ipdu.signalGroupList, name);
            if(sig.isSignalGroup==False):#if it is a general signal
                self.btnDel.setText('Del Signal');
                self.btnAdd.setDisabled(True);
                self.btnAdd2.setDisabled(True);
                self.btnDel.setDisabled(False);
            else:#if it is a signal group
                self.btnAdd.setText('Add Group Signal');
                self.btnDel.setText('Del Signal Group');
                self.btnAdd.setDisabled(False);
                self.btnAdd2.setDisabled(True);
                self.btnDel.setDisabled(False);
        elif(self.curtree.parent().parent().text(0)=='Pdus'):
            self.btnDel.setText('Del Group Signal');
            self.btnAdd.setDisabled(True);
            self.btnAdd2.setDisabled(True);
            self.btnDel.setDisabled(False);
        else:
            self.btnAdd.setDisabled(True);
            self.btnAdd2.setDisabled(True);
            self.btnDel.setDisabled(True);

    def refreshPduGroupTab(self, name):
        self.curobj= obj = self.findObj(self.cfg.IPduGroupList, name);
        if(obj == None):
            return;
        self.lePduGrpName.setText(obj.name);
        self.enableTab(0);

    def refreshIPduTab(self, name):
        self.curobj= obj = self.findObj(self.cfg.IPduList, name);
        if(obj == None):
            return;
        self.leIPduName.setText(obj.name);
        self.enableTab(1);

    def refreshGeneralSignalTab(self, sig):
        self.curobj = sig;
        self.leSignalName.setText(sig.name);
        self.enableTab(2);

    def refreshSignalGroupTab(self, sig):
        self.curobj = sig;
        self.leSignalGrpName.setText(sig.name);
        self.enableTab(3);
    
    def refreshSignalTab(self, name):
        pname = self.curtree.parent().text(0);
        Ipdu = self.findObj(self.cfg.IPduList, pname);
        sig = self.findObj(Ipdu.signalGroupList+Ipdu.signalList, name);
        if(sig == None):
            return;
        if(sig.isSignalGroup == True):
            self.refreshSignalGroupTab(sig);
        else:
            self.refreshGeneralSignalTab(sig);

    def refreshGroupSignalTab(self, name):
        ppname = self.curtree.parent().parent().text(0);
        pname = self.curtree.parent().text(0);
        Ipdu = self.findObj(self.cfg.IPduList, ppname);
        sigGrp = self.findObj(Ipdu.signalGroupList, pname);
        sig = self.findObj(sigGrp.groupSignalList,name);
        self.leGrpSignalName.setText(sig.name);
        self.enableTab(4);

    def refreshTab(self):
        if(self.curtree.parent() == None):
            self.disableAllTab();
            self.curobj=None;
            return;
        trname = self.curtree.parent().text(0);
        objname= self.curtree.text(0);
        if(trname  == 'Pdu Group'):
            self.refreshPduGroupTab(objname);
        elif(trname  == 'Pdus'):
            self.refreshIPduTab(objname);
        elif(self.curtree.parent().parent().text(0) == 'Pdus'):
            self.refreshSignalTab(objname);
        elif(self.curtree.parent().parent().parent().text(0) == 'Pdus'):
            self.refreshGroupSignalTab(objname);
    
    @pyqtSignature("QTreeWidgetItem*, int")
    def on_trComCfg_itemClicked(self, item, column):
        self.curtree=item;
        self.refreshButton();
        self.refreshTab();
