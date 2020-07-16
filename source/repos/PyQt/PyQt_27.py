import sys
from PyQt5.QtWidgets import QApplication, QWidget, QLCDNumber, QDial, QVBoxLayout

class MyApp(QWidget):

    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        lcd = QLCDNumber(self)
        dial = QDial(self) # 회전해서 값을 조절하는 위젯

        vbox = QVBoxLayout()
        vbox.addWidget(lcd) # 수신자
        vbox.addWidget(dial) # 송신자
        self.setLayout(vbox)

        dial.valueChanged.connect(lcd.display)

        self.setWindowTitle('Signal and Slot')
        self.setGeometry(300, 300, 200, 200)
        self.show()


if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = MyApp()
    sys.exit(app.exec_())