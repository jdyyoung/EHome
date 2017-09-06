#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_eeprom_fd = eeprom_open();

    struct eeprom_cmd eeprom;
    memset(&eeprom, 0 ,sizeof(eeprom));

    eeprom.cmd = SVERSION;
    strcpy((char *)eeprom.version, "S15041000");
    eeprom_write(m_eeprom_fd, &eeprom);

    eeprom.cmd = HVERSION;
    strcpy((char *)eeprom.version, "H15041000");
    eeprom_write(m_eeprom_fd, &eeprom);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_getVerPtn_clicked(void)
{
    struct eeprom_cmd eeprom;

    eeprom.cmd = SVERSION;
    eeprom_read(m_eeprom_fd, &eeprom);
    ui->sversioninfo->setText(QString::fromLocal8Bit((char *)eeprom.version, -1));

    eeprom.cmd = HVERSION;
    eeprom_read(m_eeprom_fd, &eeprom);
    ui->hversioninfo->setText(QString::fromLocal8Bit((char *)eeprom.version, -1));
}
