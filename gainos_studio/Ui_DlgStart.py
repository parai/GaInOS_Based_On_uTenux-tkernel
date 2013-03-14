# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'D:\usr\com\gainos_studio\DlgStart.ui'
#
# Created: Wed Mar 13 23:29:50 2013
#      by: PyQt4 UI code generator 4.8.3
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    _fromUtf8 = lambda s: s

class Ui_DlgStart(object):
    def setupUi(self, DlgStart):
        DlgStart.setObjectName(_fromUtf8("DlgStart"))
        DlgStart.resize(414, 110)
        self.widget = QtGui.QWidget(DlgStart)
        self.widget.setGeometry(QtCore.QRect(20, 20, 373, 22))
        self.widget.setObjectName(_fromUtf8("widget"))
        self.gridLayout = QtGui.QGridLayout(self.widget)
        self.gridLayout.setMargin(0)
        self.gridLayout.setObjectName(_fromUtf8("gridLayout"))
        self.label = QtGui.QLabel(self.widget)
        self.label.setObjectName(_fromUtf8("label"))
        self.gridLayout.addWidget(self.label, 0, 0, 1, 1)
        self.cmbxProj = QtGui.QComboBox(self.widget)
        self.cmbxProj.setMinimumSize(QtCore.QSize(301, 0))
        self.cmbxProj.setObjectName(_fromUtf8("cmbxProj"))
        self.gridLayout.addWidget(self.cmbxProj, 0, 1, 1, 1)
        self.widget1 = QtGui.QWidget(DlgStart)
        self.widget1.setGeometry(QtCore.QRect(100, 60, 158, 25))
        self.widget1.setObjectName(_fromUtf8("widget1"))
        self.horizontalLayout = QtGui.QHBoxLayout(self.widget1)
        self.horizontalLayout.setMargin(0)
        self.horizontalLayout.setObjectName(_fromUtf8("horizontalLayout"))
        self.btnYes = QtGui.QPushButton(self.widget1)
        self.btnYes.setObjectName(_fromUtf8("btnYes"))
        self.horizontalLayout.addWidget(self.btnYes)
        self.btnNo = QtGui.QPushButton(self.widget1)
        self.btnNo.setObjectName(_fromUtf8("btnNo"))
        self.horizontalLayout.addWidget(self.btnNo)

        self.retranslateUi(DlgStart)
        QtCore.QMetaObject.connectSlotsByName(DlgStart)

    def retranslateUi(self, DlgStart):
        DlgStart.setWindowTitle(QtGui.QApplication.translate("DlgStart", "Choose Project", None, QtGui.QApplication.UnicodeUTF8))
        self.label.setText(QtGui.QApplication.translate("DlgStart", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'SimSun\'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Project:</span></p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.btnYes.setText(QtGui.QApplication.translate("DlgStart", "Yes", None, QtGui.QApplication.UnicodeUTF8))
        self.btnNo.setText(QtGui.QApplication.translate("DlgStart", "No", None, QtGui.QApplication.UnicodeUTF8))


if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    DlgStart = QtGui.QDialog()
    ui = Ui_DlgStart()
    ui.setupUi(DlgStart)
    DlgStart.show()
    sys.exit(app.exec_())

