import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QAction, qApp, QDesktopWidget
from PyQt5.QtGui import QIcon

class MyApp(QMainWindow):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        self.statusBar().showMessage('Ready') # 하단 상태표시줄

        exitAction = QAction(QIcon('exit.png'), 'Exit', self) # Exit라벨을 갖는 Action을 만듬
        exitAction.setShortcut('Ctrl+Q') # 단축키 설정
        exitAction.setStatusTip('Exit app') # 상태팁
        exitAction.triggered.connect(qApp.quit) # 앱 종료 연결
        self.statusBar()

        menubar = self.menuBar() # 메뉴바 생성
        menubar.setNativeMenuBar(False)
        filemenu = menubar.addMenu('&File') # 메뉴를 만듬, Alt+F가 단축키가 됨
        filemenu.addAction(exitAction) # 동작 추가

        self.toolbar = self.addToolBar('Exit') # 툴바 추가
        self.toolbar.addAction(exitAction) # 툴바에 동작 추가

        self.setWindowTitle('Happy Coding')
        #self.setGeometry(300, 200, 400, 250)
        self.resize(400, 250)

        self.center()
        self.show()

    def center(self):
        qr = self.frameGeometry() # 창의 위치와 크기 정보를 가져옴
        cp = QDesktopWidget().availableGeometry().center() # 사용하는 모니터 화면의 가운데 위치를 파악
        qr.moveCenter(cp) # 창의 직사각형 위치를 화면의 중심 위치로 옮김
        self.move(qr.topLeft()) # 현재 창을 화면의 중심으로 이동했던 직사각형(qr)의 위치로 이동

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = MyApp()
    sys.exit(app.exec_())