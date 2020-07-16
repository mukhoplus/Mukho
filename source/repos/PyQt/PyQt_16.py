import sys
from PyQt5.QtWidgets import QApplication, QWidget, QLabel, QDateEdit, QTimeEdit, QDateTimeEdit, QVBoxLayout
from PyQt5.QtCore import QDate, QTime, QDateTime

class MyApp(QWidget):

    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        # QDateEdit
        lbl = QLabel('QDateEdit')

        dateedit = QDateEdit(self)
        dateedit.setDate(QDate.currentDate())
        dateedit.setMinimumDate(QDate(1990, 1, 1))
        dateedit.setMaximumDate(QDate(2099, 12, 31))
        # dateedit.setDateRange(QDate(1990, 1, 1), QDate(2099, 12, 31))

        # QTimeEdit
        lbl_ = QLabel('QTimeEdit')

        timeedit = QTimeEdit(self)
        timeedit.setTime(QTime.currentTime())
        timeedit.setTimeRange(QTime(0, 00, 00), QTime(23, 59, 59))
        timeedit.setDisplayFormat('hh:mm:ss')

        # QTimeEdit
        lbl__ = QLabel('QTimeEdit')

        datetimeedit = QDateTimeEdit(self)
        datetimeedit.setDateTime(QDateTime.currentDateTime())
        datetimeedit.setDateTimeRange(QDateTime(1990, 1, 1, 00, 00, 00), QDateTime(2099, 12, 31, 23, 59, 59))
        datetimeedit.setDisplayFormat('yyyy-MM-dd hh:mm:ss')

        vbox = QVBoxLayout()
        vbox.addWidget(lbl)
        vbox.addWidget(dateedit)
        vbox.addStretch()
        vbox.addWidget(lbl_)
        vbox.addWidget(timeedit)
        vbox.addStretch()
        vbox.addWidget(lbl__)
        vbox.addWidget(datetimeedit)

        self.setLayout(vbox)

        self.setWindowTitle('QDateEdit & QTimeEdit')
        self.setGeometry(300, 300, 300, 200)
        self.show()

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = MyApp()
    sys.exit(app.exec_())