"""
Event Handler
    - keyPressEvent : 키보드를 눌렀을 때 동작
    - keyReleaseEvent : 키보드를 눌렀다가 뗄 때 동작
    - mouseDoubleClickEvent : 마우스를 더블클릭할 때 동작
    - mouseMoveEvent : 마우스를 움직일 때 동작
    - mousePressEvent : 마우스를 누를 때 동작
    - mouseReleaseEvent : 마우스를 눌렀다가 뗄 때 동작
    - moveEvent : 위젯이 이동할 때 동작
    - resizeEvent : 위젯의 크기를 변경할 때 동작
"""
import sys
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QApplication, QWidget, QLabel

class MyApp(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        # mouseMoveEvent
        x = 0
        y = 0

        self.text = 'x: {0}, y: {1}'.format(x, y)
        self.label = QLabel(self.text, self)
        self.label.move(20, 20)

        self.setMouseTracking(True)
        
        # Main
        self.setWindowTitle('Reimplementing event handler')
        self.setGeometry(300, 300, 300, 200)
        self.show()

    # mouseMoveEvent
    def mouseMoveEvent(self, e):
        x = e.x()
        y = e.y()

        text = 'x: {0}, y: {1}'.format(x, y)
        self.label.setText(text)
        self.label.adjustSize()

    # keyPressEvent
    def keyPressEvent(self, e):
        if e.key() == Qt.Key_Escape: # esc
            self.close()
        elif e.key() == Qt.Key_F: # 'F'
            self.showFullScreen()
        elif e.key() == Qt.Key_N: # 'N'
            self.showNormal()

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = MyApp()
    sys.exit(app.exec_())