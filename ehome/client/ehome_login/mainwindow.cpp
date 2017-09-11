#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtGui>

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
    ret=udp_init(CLIENT,ip_addr,8888);
    if(ret == -1)
    {
        qDebug("init socket error!");
    }
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
    qDebug("now temperature=%f",temperature);
    //显示温度值
    ui->temperatureTB->setText( QString("%1 \260C").arg(temperature));

}

void MainWindow::on_systemInfoBtn_clicked()
{
    int ret;
    int cmd = GET_HARDWARE_INFO;
    struct hardware_info
    {
        int cpu_freq;
        int free_mem;
        int free_disk;
    }hw_info;

    ret=udp_init(CLIENT,ip_addr,8888);
    if(ret == -1)
    {
        qDebug("init socket error!");
    }
    //
    ret=udp_write(CLIENT,(char *)&cmd,sizeof(int));
    if(ret==-1)
    {
        qDebug("udp_write");
        return;
    }
    //
    ret = udp_read(CLIENT,(char*)&hw_info,sizeof(struct hardware_info));
    if(ret == -1)
    {
        qDebug("udp_read error!");
    }
    qDebug("cpu_freq=%d",hw_info.cpu_freq);
    qDebug("free_mem=%d",hw_info.free_mem);
    qDebug("free_disk=%d",hw_info.free_disk);
    //
    ui->CPUfreqTB->setText( QString("%1 MHz" ).arg(hw_info.cpu_freq));
    ui->memspaceTB->setText( QString("%1 kb").arg(hw_info.free_mem));
    ui->diskspaceTB->setText( QString("%1 Mb").arg(hw_info.free_disk));
}

void MainWindow::on_kernelUpdateBtn_clicked()
{
    int ret,result;
    int cmd = KERNEL_UPDATE;
    ret=udp_init(CLIENT,ip_addr,8888);
    if(ret == -1)
    {
        qDebug("init socket error!");
    }
    //
    ret=udp_write(CLIENT,(char *)&cmd,sizeof(int));
    if(ret==-1)
    {
        qDebug("udp_write");
        return;
    }

    ret = udp_read(CLIENT,(char*)&result,sizeof(int));
    if(ret == -1)
    {
        qDebug("udp_read error!");
    }
    else
    {
        if(result == UPDATE_SUCCESS)
        {
            //弹出进度条，然后弹出更新成功的显示框
            QMessageBox msgBox(QMessageBox::Critical,windowTitle(),tr("内核更新成功！"),QMessageBox::Ok,this);
            msgBox.exec();

        }
        else
        {
            //弹出更新失败的显示框
            QMessageBox msgBox(QMessageBox::Critical,windowTitle(),tr("内核更新失败，请检查U盘根目录下有文件名为zImage的内核镜像文件！"),QMessageBox::Ok,this);
            msgBox.exec();
        }
    }
}

void MainWindow::on_LEDonBtn_clicked()
{
    int ret;
    int cmd = ZIGBEE_LED_ON;
    ret=udp_init(CLIENT,ip_addr,8888);
    if(ret == -1)
    {
        qDebug("init socket error!");
    }
    //
    ret=udp_write(CLIENT,(char *)&cmd,sizeof(int));
    if(ret==-1)
    {
        qDebug("udp_write failed");
        return;
    }
}

void MainWindow::on_LEDoffBtn_clicked()
{
    int ret;
    int cmd = ZIGBEE_LED_OFF;
    ret=udp_init(CLIENT,ip_addr,8888);
    if(ret == -1)
    {
        qDebug("init socket error!");
    }
    //
    ret=udp_write(CLIENT,(char *)&cmd,sizeof(int));
    if(ret==-1)
    {
        qDebug("udp_write failed");
        return;
    }
}
