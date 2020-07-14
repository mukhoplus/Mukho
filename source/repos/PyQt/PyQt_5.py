# 박스 레이아웃
# QHBoxLayout, QVBoxLayout : 여러 위젯을 수평, 수직으로 정렬하는 레이아웃 클래스
# 각 레이아웃의 생성자는 수평, 수직의 박스를 하나 만드는데, 다른 레이아웃 박스를 넣을 수도 있고 위젯을 배치할 수도 있다.

import sys
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QHBoxLayout, QVBoxLayout

class MyApp(QWidget):

    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        # 두개의 버튼을 제작
        okButton = QPushButton('OK')
        cancelButton = QPushButton('Cancel')

        # 수평 박스를 하나 만들고, 두 개의 버튼과 양 쪽에 빈 공간을 추가함 [ '      ' 'OK' 'Cancel' '      ' ]
        # 두 버튼 양쪽의 stretch factor가 1로 같기 때문에 이 두 빈 공간의 크기는 창의 크기가 변화해도 항상 같다.
        hbox = QHBoxLayout()
        hbox.addStretch(1)
        hbox.addWidget(okButton)
        hbox.addWidget(cancelButton)
        hbox.addStretch(1)

        # 수직 박스를 하나 만들고, 위와 아래의 빈 공간의 크기를 3:1로 유지함.
        vbox = QVBoxLayout()
        vbox.addStretch(3)
        vbox.addLayout(hbox)
        vbox.addStretch(1)

        # 수직 박스를 창의 메인 레이아웃으로 설정
        self.setLayout(vbox)

        self.setWindowTitle('Box Layout')
        self.setGeometry(300, 300, 300, 200)
        self.show()


if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = MyApp()
    sys.exit(app.exec_())