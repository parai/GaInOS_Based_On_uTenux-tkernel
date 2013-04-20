# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'F:\parai@foxmail.com\nt\gainos-tkernel\gainos_studio\ui_forms\Common\ComDlgAdd.ui'
#
# Created: Sat Apr 20 18:39:07 2013
#      by: PyQt4 UI code generator 4.8.3
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    _fromUtf8 = lambda s: s

class Ui_DlgComAdd(object):
    def setupUi(self, DlgComAdd):
        DlgComAdd.setObjectName(_fromUtf8("DlgComAdd"))
        DlgComAdd.resize(263, 390)
        self.layoutWidget = QtGui.QWidget(DlgComAdd)
        self.layoutWidget.setGeometry(QtCore.QRect(40, 360, 158, 25))
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
        self.trArCom = QtGui.QTreeWidget(DlgComAdd)
        self.trArCom.setGeometry(QtCore.QRect(20, 10, 221, 341))
        self.trArCom.setObjectName(_fromUtf8("trArCom"))

        self.retranslateUi(DlgComAdd)
        QtCore.QMetaObject.connectSlotsByName(DlgComAdd)

    def retranslateUi(self, DlgComAdd):
        DlgComAdd.setWindowTitle(QtGui.QApplication.translate("DlgComAdd", "Dialog", None, QtGui.QApplication.UnicodeUTF8))
        self.btnAdd.setText(QtGui.QApplication.translate("DlgComAdd", "Add", None, QtGui.QApplication.UnicodeUTF8))
        self.btnCancel.setText(QtGui.QApplication.translate("DlgComAdd", "Cancel", None, QtGui.QApplication.UnicodeUTF8))
        self.trArCom.headerItem().setText(0, QtGui.QApplication.translate("DlgComAdd", "Items", None, QtGui.QApplication.UnicodeUTF8))


if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    DlgComAdd = QtGui.QDialog()
    ui = Ui_DlgComAdd()
    ui.setupUi(DlgComAdd)
    DlgComAdd.show()
    sys.exit(app.exec_())

