"""
QInputDialog
    - getText() 문자열
    - getMultiLineText() 여러 줄의 문자열
    - getInt() 정수형 숫자
    - getDouble() 실수형 숫자
    - getItem() 아이템
"""

import sys
from PyQt5.QtWidgets import (QApplication, QWidget, QPushButton, QLineEdit, QInputDialog, QFrame, QColorDialog)
from PyQt5.QtGui import QColor

class MyApp(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        # QInputDialog
        self.btn = QPushButton('Dialog', self)
        self.btn.move(30, 30)
        self.btn.clicked.connect(self.showDialog)

        self.le = QLineEdit(self)
        self.le.move(120, 35)

        # QColorDialog
        col = QColor(0, 0, 0)

        self.frm = QFrame(self)
        self.frm.setStyleSheet('QWidget { background-color: %s }' % col.name())
        self.frm.setGeometry(130, 70, 100, 100)

        # main
        self.setWindowTitle('Input dialog & Color Dialog')
        self.setGeometry(300, 300, 300, 200)
        self.show()

    def showDialog(self):
        text, ok = QInputDialog.getText(self, 'Input Dialog', 'Enter your name: ')
        col = QColorDialog.getColor()

        if ok:
            self.le.setText(str(text))
        if col.isValid():
            self.frm.setStyleSheet('QWidget { background-color: %s }' % col.name())
        

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = MyApp()
    sys.exit(app.exec_())
