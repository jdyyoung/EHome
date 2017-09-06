#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int ret;
    //读取软件版本号
    ret = udp_read(CLIENT,(char*)v_info.s_version,10);
    if(ret ==-1)
    {
        qDebug("udp_read error!");
    }
    //读取硬件版本号
    ret = udp_read(CLIENT,(char*)v_info.h_version,10);
    if(ret == -1)
    {
        qDebug("udp_read error!");
    }

    ui->swVersionLabel->setText(QString(QLatin1String((char*)v_info.s_version)));
    ui->hwVersionLabel->setText(QString(QLatin1String((char*)v_info.h_version)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
