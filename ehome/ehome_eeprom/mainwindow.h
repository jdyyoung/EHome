#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "eeprom.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_getVerPtn_clicked(void);

private:
    Ui::MainWindow *ui;
    int m_eeprom_fd;
};

#endif // MAINWINDOW_H
