import sys
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QToolTip
from PyQt5.QtGui import QIcon
from PyQt5.QtCore import QCoreApplication
from PyQt5.QtGui import QFont

class MyApp(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()
    
    def initUI(self):
        # 툴팁
        QToolTip.setFont(QFont("SansSerif", 10))
        self.setToolTip('This is a <b>QWidget</b> widget')

        # 닫기 버튼 설정
        btn = QPushButton('Quit', self)
        btn.move(50, 50)
        btn.setToolTip('This is a <b>QPushButton</b> widget')
        btn.resize(btn.sizeHint())
        btn.clicked.connect(QCoreApplication.instance().quit)

        self.setWindowTitle('My First GUI Application') # 윈도우 창 제목 설정
        self.setWindowIcon(QIcon('web.png')) # 아이콘 설정
        # self.move(300, 300) 창의 위치
        # self.resize(400, 200) 창의 크기
        self.setGeometry(300, 300, 400, 200)

        # 보여주기
        self.show()
    
if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = MyApp()
    sys.exit(app.exec_())
