""" QSlider / QDial
    QSlider.setTickInterval() / .setTickPosition()

    .NoTicks : 틱을 표시하지 않음
    .TicksAbove : 틱을 수평 슬라이더 위쪽에 표시
    .TicksBelow : 틱을 수평 슬라이더 아래쪽에 표시
    .TicksBothSides : 틱을 수평 슬라이더 양쪽에 표시
    .TicksLeft : 틱을 수평 슬라이더 왼쪽에 표시
    .TicksRight : 틱을 수평 슬라이더 오른쪽에 표시

 - valueChanged() : 슬라이더의 값이 변할 때 발생
 - sliderPressed() : 슬라이더를 움직이기 시작할 때 발생
 - sliderMoved() : 슬라이더를 움직이면 발생
 sliderReleased() : 사용자가 슬라이더를 놓을 때 발생
"""
# Splitter : 경계를 드래그해서 자식 위젯의 크기를 조절할 수 있도록 함

import sys
from PyQt5.QtWidgets import QApplication, QWidget, QSlider, QDial, QPushButton, QHBoxLayout, QFrame, QSplitter
from PyQt5.QtCore import Qt


class MyApp(QWidget):

    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        # QSlider & QDial
        self.slider = QSlider(Qt.Horizontal, self)
        self.slider.move(30, 30)
        self.slider.setRange(0, 50)
        self.slider.setSingleStep(2)

        self.dial = QDial(self)
        self.dial.move(30, 50)
        self.dial.setRange(0, 50)

        btn = QPushButton('Defalut', self)
        btn.move(25, 160)

        self.slider.valueChanged.connect(self.dial.setValue)
        self.dial.valueChanged.connect(self.slider.setValue)
        btn.clicked.connect(self.button_clicked)

        # QSplitter
        hbox = QHBoxLayout()

        top = QFrame()
        top.setFrameShape(QFrame.Box)

        midleft = QFrame()
        midleft.setFrameShape(QFrame.StyledPanel)

        midright = QFrame()
        midright.setFrameShape(QFrame.Panel)

        bottom = QFrame()
        bottom.setFrameShape(QFrame.WinPanel)
        bottom.setFrameShadow(QFrame.Sunken)

        splitter1 = QSplitter(Qt.Horizontal)
        splitter1.addWidget(midleft)
        splitter1.addWidget(midright)
        splitter2 = QSplitter(Qt.Vertical)
        splitter2.addWidget(top)
        splitter2.addWidget(splitter1)
        splitter2.addWidget(bottom)

        hbox.addWidget(splitter2)
        self.setLayout(hbox)

        self.setWindowTitle('QSlider and QDial & QSplitter')
        self.setGeometry(300, 300, 400, 200)
        self.show()

    def button_clicked(self):
        self.slider.setValue(0)
        self.dial.setValue(0)


if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = MyApp()
    sys.exit(app.exec_())