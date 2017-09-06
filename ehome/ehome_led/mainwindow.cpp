#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_led_fd = led_open();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ledon_clicked()
{
    struct led_cmd led;
    led.cmd = 1;
    led.whichled = 1;
    led_config(m_led_fd, &led);
}

void MainWindow::on_ledoff_clicked()
{
    struct led_cmd led;
    led.cmd = 0;
    led.whichled = 1;
    led_config(m_led_fd, &led);
}
