#include<QtGui>
#include "LoginDlg.h"
LoginDlg::LoginDlg(QWidget* parent /*= NULL*/):QDialog(parent)
{
    setupUi (this);//完成对话框的初始化
    connect (m_btnBox,SIGNAL(accepted (void)),this,SLOT (onAccepted(void)));
    connect (m_btnBox,SIGNAL(rejected (void)),this,SLOT (onRejected(void)));
}
//处理确定按钮
void LoginDlg::onAccepted(void)
{
    if(m_editUserame->text () == "tarena" && m_editPassword->text () == "123456")
    {
        close();
    }
    else
    {
        QMessageBox msgBox (QMessageBox::Critical,windowTitle(),tr("用户名或密码不正确，登录失败！"),QMessageBox::Ok,this);
        msgBox.exec ();
    }
}
//处理取消按钮
void LoginDlg::onRejected(void)
{ 
    QMessageBox msgBox (QMessageBox::Question,windowTitle(),tr("您真的要取消登录吗？"),QMessageBox::Yes | QMessageBox::No,this);
    if(msgBox.exec () == QMessageBox::Yes)
    {
        close();
    }
}
