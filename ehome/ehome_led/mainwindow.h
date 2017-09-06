#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "led.h"

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
    void on_ledon_clicked();

    void on_ledoff_clicked();

private:
    Ui::MainWindow *ui;
    int m_led_fd;
};

#endif // MAINWINDOW_H
