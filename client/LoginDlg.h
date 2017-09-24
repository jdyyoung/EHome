#ifndef LOGINDLG_H
#define LOGINDLG_H

#include <QDialog>
#include "udp.h"
#include "global.h"
#include "msg.h"
namespace Ui {
class LoginDlg;
}

class LoginDlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit LoginDlg(QWidget *parent = 0);
    ~LoginDlg();
    
private slots:
    void on_connect_btn_clicked();

    void on_cancel_btn_clicked();

private:
    Ui::LoginDlg *ui;
};

#endif // LOGINDLG_H
