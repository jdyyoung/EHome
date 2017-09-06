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

    //显示版本号
    ui->swVersionLabel->setText(QString(QLatin1String((char*)v_info.s_version)));
    ui->hwVersionLabel->setText(QString(QLatin1String((char*)v_info.h_version)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_getTempBtn_clicked()
{
    int ret;
    int cmd = GET_TEMPERATURE;
    float temperature;

    ret=udp_write(CLIENT,(char *)&cmd,sizeof(int));
    if(ret==-1)
    {
        qDebug("udp_write");
        return;
    }

    //读取温度值
    ret = udp_read(CLIENT,(char*)&temperature,sizeof(float));
    if(ret == -1)
    {
        qDebug("udp_read error!");
    }

    //显示温度值
    ui->temperatureTB->setText(QString(QLatin1String((char*)&temperature)));



}
