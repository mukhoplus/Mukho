""" QPushButton : 사용자가 프로그램에 명령을 내려서 어떤 동작을 하도록 할 때 사용되는 버튼
 - setCheckable() : True 설정 시, 누른 상태와 그렇지 않은 상태를 구분함
 - toggle() : 상태를 바꿈
 - setIcon() : 버튼의 아이콘을 설정
 - setEnabled() : False 설정 시, 버튼을 사용할 수 없음
 - isChecked() : 버튼의 선택 여부를 반환
 - setText() : 버튼에 표시될 텍스트를 설정
 - text() : 버튼에 표시된 텍스트를 반환
  - clicked() : 버튼을 클릭할 때 발생
  - pressed() : 버튼이 눌렸을 때 발생
  - released() : 버튼을 눌렀다 뗄 때 발생
  - toggled() : 버튼의 상태가 바뀔 때 발생
"""
""" QCheckBox
 - text() : 체크 박스의 라벨 텍스트를 반환
 - setText() : 체크 박스의 라벨 텍스트를 설정
 - isChecked() : 체크 박스의 상태를 반환 (T/F)
 - checkState() : 체크 박스의 상태를 반환 (2/1/0)
 - toggle() : 체크 박스의 상태를 변경
  - pressed() : 체크 박스를 누를 때 신호를 발생
  - released() : 체크 박스에서 뗄 때 신호를 발생
  - clicked() : 체크 박스를 클릭할 때 신호를 발생
  - stateChanged() : 체크 박스의 상태가 바뀔 때 신호를 발생
"""


import sys
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QVBoxLayout, QLabel, QCheckBox
from PyQt5.QtCore import Qt

class MyApp(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        # Button
        btn1 = QPushButton('&Button1', self)
        btn1.setCheckable(True)
        btn1.toggle()

        btn2 = QPushButton(self)
        btn2.setText('Button&2')

        btn3 = QPushButton('Button3', self)
        btn3.setEnabled(False)

        # Label
        label1 = QLabel('First Label', self)
        label1.setAlignment(Qt.AlignCenter)

        label2 = QLabel('Second Label', self)
        label2.setAlignment(Qt.AlignVCenter) # 수직 방향으로만 가운데정렬

        font1 = label1.font()
        font1.setPointSize(20)

        font2 = label2.font()
        font2.setFamily('Times New Roman')
        font2.setBold(True)

        label1.setFont(font1)
        label2.setFont(font2)

        # Check Box
        cb = QCheckBox('Show title', self)
        cb.move(20, 30)
        cb.toggle()
        cb.stateChanged.connect(self.changeTitle)


        temp = QVBoxLayout()
        temp.addWidget(btn1)
        temp.addWidget(label1)
        temp.addWidget(btn2)
        temp.addWidget(label2)
        temp.addWidget(btn3)

        self.setLayout(temp)

        self.setWindowTitle('PushButton & Label & CheckBox')
        self.setGeometry(300, 300, 300, 200)
        self.show()

    def changeTitle(self, state):
        if state == Qt.Checked:
            self.setWindowTitle('PushButton & Label & CheckBox')
        else:
                self.setWindowTitle(' ')

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = MyApp()
    sys.exit(app.exec_())