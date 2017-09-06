#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer();
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(get_temp()));

    m_ds18b20_fd = ds18b20_open();

    timer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::get_temp(void)
{
    struct ds18b20_cmd ds18b20;
    ds18b20_read(m_ds18b20_fd, &ds18b20);
    ui->tempValue->setText(QString::number(ds18b20.temperature, 'g', 2));
}
