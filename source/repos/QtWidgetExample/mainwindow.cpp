#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_timer = new QTimer;
    connect(m_timer, SIGNAL(timeout()), this, SLOT(on_timer_count()));
    // QTimer class object인 m_timer의 timeout() 이라는 SIGNAL을 MainWindow class의 on_timer_count()라는 SLOT과 connect.
    // signal로 선언된 함수와 slot으로 선언된 함수를 연결해주면 signal 이벤트가 발생했을 때 slot 함수를 실행해줌.
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    static int count = 0;
    QString qstr;
    qstr = QString("%1 %2 %3...").arg(count).arg(count+1).arg(count+2);
    ui->lineEdit->setText(qstr);
    count++;
}

void MainWindow::on_pushButton_timer_clicked()
{
    m_timer->start(100);
}

void MainWindow::on_timer_count()
{
    static int count = 0;
    static QVector<int> integers;
    integers.push_back(count);

    QString qstr;
    qstr = QString("%1 %2 %3..").arg(integers[0]).arg(integers.last()).arg(integers.size());
    // integers[0] or integers.first() : 첫번째 원소(여기서는 0)
    // integers.last() : 마지막 원소(99가 정상임.)
    // integers.size() : 원소의 개수
    // remove(int i) : 특정 원소 제거

    ui->lineEdit_2->setText(qstr);

    count++;
    if(count == 100)
    {
        count = 0;
        integers.clear();
        m_timer->stop();
    }
}
