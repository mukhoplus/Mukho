""" QRadioButton : 사용자에게 여러 개 중 하나의 옵션을 선택하도록 할 때 사용됨
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
""" QLineEdit : 한 줄의 문자열을 입력하고 수정할 수 있도록 하는 위젯
 - .Normal : 입력된 문자를 표시
 - .NoEcho : 문자열을 표시하지 않음(비밀번호의 글자수도 공개하지 않을 때 유용)
 - .Password : 입력된 문자 대신 비밀번호 가림용 문자를 표시
 - .PasswordEchoOnEdit : 입력할 때만 문자를 표시, 수정 중에는 다른 문자를 표시

 - cursorPositionChanged() : 커서가 움직일 때 발생하는 신호를 발생
 - editingFinished() : 편집이 끝났을 때(Return/Enter 버튼이 눌릴 때) 신호를 발생
 - returnPressed() : Return/Enter 버튼이 눌릴 때 신호를 발생
 - selectionChanged() : 선택 영역이 바뀔 때 신호를 발생 
 - textChanged() : 텍스트가 변경될 때 신호를 발생
 - textEdited()	: 텍스트가 편집될 때 신호를 발생
"""

import sys
from PyQt5.QtWidgets import QApplication, QWidget, QRadioButton, QComboBox, QLabel, QLineEdit

class MyApp(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()
    
    def initUI(self):
        # Radio Button
        rbtn1 = QRadioButton('First Button', self)
        rbtn1.move(50, 50)
        rbtn1.setChecked(True)
        rbtn2 = QRadioButton(self)
        rbtn2.move(50, 70)
        rbtn2.setText("Second Button")
        
        # Line Edit
        self.lb = QLabel(self)
        self.lb.move(200, 50)

        qle = QLineEdit(self)
        qle.move(200, 100)
        qle.textChanged[str].connect(self.onChanged)

        # Combo Box
        self.lbl = QLabel('-', self)
        self.lbl.move(50, 150)

        cb = QComboBox(self)
        cb.addItem('묵 호')
        cb.addItem('ITX 청춘')
        cb.addItem('Made By Google')
        cb.move(200, 150)

        cb.activated[str].connect(self.onActivated)

        self.setGeometry(300, 300, 350, 250)
        self.setWindowTitle('RadioButton & ComboBox & Line Edit')
        self.show()
    
    def onActivated(self, text):
        self.lbl.setText(text)
        self.lbl.adjustSize()
    
    def onChanged(self, text):
        self.lb.setText(text)
        self.lb.adjustSize()

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = MyApp()
    sys.exit(app.exec_())