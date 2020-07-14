from PyQt5.QtCore import QDate, Qt, QTime, QDateTime
import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QLabel, QVBoxLayout
from PyQt5.QtCore import QDate, Qt

# 날짜
now = QDate.currentDate()
print(now.toString('yyyy-MM-dd dddd'))
print(now.toString())
print(now.toString('d.M.yy'))
print(now.toString('dd.MM.yyyy'))
print(now.toString('ddd.MMMM.yyyy'))
print(now.toString(Qt.ISODate))
print(now.toString(Qt.DefaultLocaleLongDate))
print('\n')

# 시간
time = QTime.currentTime()
print(time.toString('A hh:mm:ss'))
print(time.toString())
print(time.toString('h.m.s'))
print(time.toString('hh.mm.ss'))
print(time.toString('hh.mm.ss.zzz'))
print(time.toString(Qt.DefaultLocaleLongDate))
print(time.toString(Qt.DefaultLocaleShortDate))
print('\n')

# 날짜와 시간
datetime = QDateTime.currentDateTime()
print(datetime.toString('yyyy-MM-dd dddd A hh:mm:ss'))
print(datetime.toString())
print(datetime.toString('d.M.yy hh:mm:ss'))
print(datetime.toString('dd.MM.yyyy, hh:mm:ss'))
print(datetime.toString(Qt.DefaultLocaleLongDate))
print(datetime.toString(Qt.DefaultLocaleShortDate))

class MyApp(QMainWindow):

    def __init__(self):
        super().__init__()
        self.date = QDate.currentDate()
        self.initUI()

    def initUI(self):
        

        # 스타일 지정
        lbl_red = QLabel('red')
        lbl_green = QLabel('Green')
        lbl_blue = QLabel('blue')

        lbl_red.setStyleSheet("color: red;"
                             "border-style: solid;"
                             "border-width: 2px;"
                             "border-color: #FA8072;"
                             "border-radius: 3px")
        lbl_green.setStyleSheet("color: green;"
                               "background-color: #7FFFD4")
        lbl_blue.setStyleSheet("color: blue;"
                              "background-color: #87CEFA;"
                              "border-style: dashed;"
                              "border-width: 3px;"
                              "border-color: #1E90FF")

        # 수직 박스 레이아웃
        vbox = QVBoxLayout()
        vbox.addWidget(lbl_red)
        vbox.addWidget(lbl_green)
        vbox.addWidget(lbl_blue)

        self.setLayout(vbox)

        self.setWindowTitle('Date and Stylesheet')
        self.setGeometry(300, 300, 400, 200)
        self.statusBar().showMessage(self.date.toString(Qt.DefaultLocaleLongDate)) # 상태바에 현재 날짜 출력
        self.show()


if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = MyApp()
    sys.exit(app.exec_())