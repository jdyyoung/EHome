#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ds18b20.h"
#include <QTimer>
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
    void get_temp(void);

private:
    Ui::MainWindow *ui;
    int m_ds18b20_fd;
    QTimer *timer;
};

#endif // MAINWINDOW_H
