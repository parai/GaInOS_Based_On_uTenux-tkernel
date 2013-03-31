# -*- coding: utf-8 -*-

"""
Module implementing DlgComAdd.
"""

from PyQt4.QtGui import QDialog
from PyQt4.QtCore import pyqtSignature
from PyQt4.QtGui import QTreeWidgetItem, QMessageBox
from PyQt4.QtCore import QStringList,QString

from Ui_ComDlgAdd import Ui_DlgComAdd

class DlgComAdd(QDialog, Ui_DlgComAdd):
    """
    Class documentation goes here.
    """
    def __init__(self, list, parent = None):
        """
        Constructor
        """
        self.result=False;
        self.item='';
        QDialog.__init__(self, parent)
        self.setupUi(self)
        self.initGUI(list);

    def initGUI(self, list):
        for ar in list:
            item=QTreeWidgetItem(self.trArCom,QStringList(ar));
            self.trArCom.insertTopLevelItem(0, item);
        self.trArCom.sortColumn();
        
    @pyqtSignature("")
    def on_btnAdd_clicked(self):
        if(self.item != ''):
            self.result=True;
        else:
            self.result=False;
        self.close();
    
    @pyqtSignature("")
    def on_btnCancel_clicked(self):
        self.close();
    
    @pyqtSignature("QTreeWidgetItem*, int")
    def on_trArCom_itemClicked(self, item, column):
        self.item=item.text(0);
    
    @pyqtSignature("QTreeWidgetItem*, int")
    def on_trArCom_itemDoubleClicked(self, item, column):
        self.item=item.text(0);
        self.result=True;
        self.close();
