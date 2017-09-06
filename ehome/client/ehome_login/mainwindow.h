#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "udp.h"
#include "global.h"
#include "msg.h"

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
    void on_getTempBtn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
