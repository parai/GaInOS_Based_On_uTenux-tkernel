# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'F:\parai@foxmail.com\nt\gainos-tkernel\gainos_studio\ui_forms\comstack\EcuC_Dlg.ui'
#
# Created: Fri Apr 05 15:31:02 2013
#      by: PyQt4 UI code generator 4.8.3
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    _fromUtf8 = lambda s: s

class Ui_EcuC_Dlg(object):
    def setupUi(self, EcuC_Dlg):
        EcuC_Dlg.setObjectName(_fromUtf8("EcuC_Dlg"))
        EcuC_Dlg.resize(802, 471)
        self.groupBox = QtGui.QGroupBox(EcuC_Dlg)
        self.groupBox.setGeometry(QtCore.QRect(0, 90, 781, 371))
        self.groupBox.setObjectName(_fromUtf8("groupBox"))
        self.trEcucCfg = QtGui.QTreeWidget(self.groupBox)
        self.trEcucCfg.setGeometry(QtCore.QRect(20, 30, 256, 321))
        self.trEcucCfg.setObjectName(_fromUtf8("trEcucCfg"))
        item_0 = QtGui.QTreeWidgetItem(self.trEcucCfg)
        self.tabCfg = QtGui.QTabWidget(self.groupBox)
        self.tabCfg.setGeometry(QtCore.QRect(410, 20, 351, 91))
        self.tabCfg.setObjectName(_fromUtf8("tabCfg"))
        self.tab = QtGui.QWidget()
        self.tab.setObjectName(_fromUtf8("tab"))
        self.layoutWidget_2 = QtGui.QWidget(self.tab)
        self.layoutWidget_2.setGeometry(QtCore.QRect(20, 20, 301, 27))
        self.layoutWidget_2.setObjectName(_fromUtf8("layoutWidget_2"))
        self.horizontalLayout_36 = QtGui.QHBoxLayout(self.layoutWidget_2)
        self.horizontalLayout_36.setMargin(0)
        self.horizontalLayout_36.setObjectName(_fromUtf8("horizontalLayout_36"))
        self.label_33 = QtGui.QLabel(self.layoutWidget_2)
        self.label_33.setObjectName(_fromUtf8("label_33"))
        self.horizontalLayout_36.addWidget(self.label_33)
        self.lePduName = QtGui.QLineEdit(self.layoutWidget_2)
        self.lePduName.setText(_fromUtf8(""))
        self.lePduName.setObjectName(_fromUtf8("lePduName"))
        self.horizontalLayout_36.addWidget(self.lePduName)
        self.tabCfg.addTab(self.tab, _fromUtf8(""))
        self.layoutWidget = QtGui.QWidget(self.groupBox)
        self.layoutWidget.setGeometry(QtCore.QRect(290, 50, 101, 54))
        self.layoutWidget.setObjectName(_fromUtf8("layoutWidget"))
        self.verticalLayout = QtGui.QVBoxLayout(self.layoutWidget)
        self.verticalLayout.setMargin(0)
        self.verticalLayout.setObjectName(_fromUtf8("verticalLayout"))
        self.btnAdd = QtGui.QPushButton(self.layoutWidget)
        self.btnAdd.setObjectName(_fromUtf8("btnAdd"))
        self.verticalLayout.addWidget(self.btnAdd)
        self.btnDel = QtGui.QPushButton(self.layoutWidget)
        self.btnDel.setObjectName(_fromUtf8("btnDel"))
        self.verticalLayout.addWidget(self.btnDel)

        self.retranslateUi(EcuC_Dlg)
        self.tabCfg.setCurrentIndex(0)
        QtCore.QMetaObject.connectSlotsByName(EcuC_Dlg)

    def retranslateUi(self, EcuC_Dlg):
        EcuC_Dlg.setWindowTitle(QtGui.QApplication.translate("EcuC_Dlg", "EcuC Config", None, QtGui.QApplication.UnicodeUTF8))
        self.groupBox.setTitle(QtGui.QApplication.translate("EcuC_Dlg", "GroupBox", None, QtGui.QApplication.UnicodeUTF8))
        self.trEcucCfg.headerItem().setText(0, QtGui.QApplication.translate("EcuC_Dlg", "EcuC", None, QtGui.QApplication.UnicodeUTF8))
        __sortingEnabled = self.trEcucCfg.isSortingEnabled()
        self.trEcucCfg.setSortingEnabled(False)
        self.trEcucCfg.topLevelItem(0).setText(0, QtGui.QApplication.translate("EcuC_Dlg", "Pdus", None, QtGui.QApplication.UnicodeUTF8))
        self.trEcucCfg.setSortingEnabled(__sortingEnabled)
        self.label_33.setText(QtGui.QApplication.translate("EcuC_Dlg", "Name:", None, QtGui.QApplication.UnicodeUTF8))
        self.tabCfg.setTabText(self.tabCfg.indexOf(self.tab), QtGui.QApplication.translate("EcuC_Dlg", "Pdu", None, QtGui.QApplication.UnicodeUTF8))
        self.btnAdd.setText(QtGui.QApplication.translate("EcuC_Dlg", "Add Pdu", None, QtGui.QApplication.UnicodeUTF8))
        self.btnDel.setText(QtGui.QApplication.translate("EcuC_Dlg", "Del", None, QtGui.QApplication.UnicodeUTF8))


if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    EcuC_Dlg = QtGui.QDialog()
    ui = Ui_EcuC_Dlg()
    ui.setupUi(EcuC_Dlg)
    EcuC_Dlg.show()
    sys.exit(app.exec_())

