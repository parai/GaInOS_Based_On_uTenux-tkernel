# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'F:\parai@foxmail.com\nt\gainos-tkernel\gainos_studio\ui_forms\DlgArAdd.ui'
#
# Created: Sat Apr 20 18:39:05 2013
#      by: PyQt4 UI code generator 4.8.3
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    _fromUtf8 = lambda s: s

class Ui_DlgArAdd(object):
    def setupUi(self, DlgArAdd):
        DlgArAdd.setObjectName(_fromUtf8("DlgArAdd"))
        DlgArAdd.resize(258, 410)
        self.trArCom = QtGui.QTreeWidget(DlgArAdd)
        self.trArCom.setGeometry(QtCore.QRect(20, 20, 221, 341))
        self.trArCom.setObjectName(_fromUtf8("trArCom"))
        self.layoutWidget = QtGui.QWidget(DlgArAdd)
        self.layoutWidget.setGeometry(QtCore.QRect(40, 370, 158, 25))
        self.layoutWidget.setObjectName(_fromUtf8("layoutWidget"))
        self.horizontalLayout = QtGui.QHBoxLayout(self.layoutWidget)
        self.horizontalLayout.setMargin(0)
        self.horizontalLayout.setObjectName(_fromUtf8("horizontalLayout"))
        self.btnAdd = QtGui.QPushButton(self.layoutWidget)
        self.btnAdd.setObjectName(_fromUtf8("btnAdd"))
        self.horizontalLayout.addWidget(self.btnAdd)
        self.btnCancel = QtGui.QPushButton(self.layoutWidget)
        self.btnCancel.setObjectName(_fromUtf8("btnCancel"))
        self.horizontalLayout.addWidget(self.btnCancel)

        self.retranslateUi(DlgArAdd)
        QtCore.QMetaObject.connectSlotsByName(DlgArAdd)

    def retranslateUi(self, DlgArAdd):
        DlgArAdd.setWindowTitle(QtGui.QApplication.translate("DlgArAdd", "Add Autosar Component", None, QtGui.QApplication.UnicodeUTF8))
        self.trArCom.headerItem().setText(0, QtGui.QApplication.translate("DlgArAdd", "Autosar Component", None, QtGui.QApplication.UnicodeUTF8))
        self.btnAdd.setText(QtGui.QApplication.translate("DlgArAdd", "Add", None, QtGui.QApplication.UnicodeUTF8))
        self.btnCancel.setText(QtGui.QApplication.translate("DlgArAdd", "Cancel", None, QtGui.QApplication.UnicodeUTF8))


if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    DlgArAdd = QtGui.QDialog()
    ui = Ui_DlgArAdd()
    ui.setupUi(DlgArAdd)
    DlgArAdd.show()
    sys.exit(app.exec_())

