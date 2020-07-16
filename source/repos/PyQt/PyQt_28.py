import sys
from PyQt5.QtWidgets import (QApplication, QWidget, QLCDNumber, QDial, QPushButton, QVBoxLayout, QHBoxLayout)


class MyApp(QWidget):

    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        lcd = QLCDNumber(self)
        dial = QDial(self)
        btn1 = QPushButton('Big', self)
        btn2 = QPushButton('Small', self)

        hbox = QHBoxLayout() # [Big] [Small]
        hbox.addWidget(btn1)
        hbox.addWidget(btn2)

        vbox = QVBoxLayout()
        vbox.addWidget(lcd)     #     lcd
        vbox.addWidget(dial)    #     dial
        vbox.addLayout(hbox)    # [Big] [Small]
        
        self.setLayout(vbox)

        dial.valueChanged.connect(lcd.display)
        btn1.clicked.connect(self.resizeBig)
        btn2.clicked.connect(self.resizeSmall)

        self.setWindowTitle('Signal and Slot')
        self.setGeometry(200, 200, 200, 250)
        self.show()

    def resizeBig(self):
        self.resize(400, 500)
    def resizeSmall(self):
        self.resize(200, 250)

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = MyApp()
    sys.exit(app.exec_())