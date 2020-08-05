// 2020-08-05 수
// 출처 : http://blog.daum.net/goodgodgd/10

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
