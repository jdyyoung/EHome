#ifndef _LOGINDLG_H
#define _LOGINDLG_H

#include<QDialog>
#include "ui_LoginDlg.h"
class LoginDlg : public QDialog,public Ui::LoginDlg
{
    Q_OBJECT
    public:
        LoginDlg(QWidget* parent = NULL);
    private slots:
        void onAccepted(void);//处理确定按钮
        void onRejected(void);//处理取消按钮
};
#endif //_LOGINDLG_H
