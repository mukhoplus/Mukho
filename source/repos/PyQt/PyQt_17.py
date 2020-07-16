import sys
from PyQt5.QtWidgets import (QApplication, QWidget, QLineEdit, QTextBrowser, QPushButton, QVBoxLayout)


class MyApp(QWidget):

    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        self.le = QLineEdit()
        self.le.returnPressed.connect(self.append_text) # Enter키를 누르면 append_text 메소드 출력

        # 입력한 문자열 출력하는 부분
        self.tb = QTextBrowser()
        self.tb.setAcceptRichText(True) # 서식 있는 텍스트 사용 가능
        self.tb.setOpenExternalLinks(True) # 외부 링크로의 연결이 가능

        self.clear_btn = QPushButton('Clear')
        self.clear_btn.pressed.connect(self.clear_text)

        vbox = QVBoxLayout()
        vbox.addWidget(self.le, 0)
        vbox.addWidget(self.tb, 1)
        vbox.addWidget(self.clear_btn, 2)

        self.setLayout(vbox)

        self.setWindowTitle('QTextBrowser')
        self.setGeometry(300, 300, 300, 300)
        self.show()

    def append_text(self):
        text = self.le.text()
        self.tb.append(text)
        self.le.clear()

    def clear_text(self):
        self.tb.clear()


if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = MyApp()
    sys.exit(app.exec_())