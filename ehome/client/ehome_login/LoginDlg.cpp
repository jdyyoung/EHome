#include "LoginDlg.h"
#include "ui_LoginDlg.h"
#include "log.h"
#include<QtGui>
//#include<QDialog>

LoginDlg::LoginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDlg)
{
    ui->setupUi(this);
}

LoginDlg::~LoginDlg()
{
    delete ui;
}

char ip_addr[64];
struct version_info v_info={"hello","world"};
void LoginDlg::on_connect_btn_clicked()
{
    struct passwd_info info={};
    int ret;
    int cmd = LOGIN_EHOME;

    //判断输入是否为空
    if(0 == ui->username_edit->displayText().length())
    {
        //ui->state->setText(tr("Please input user name!"));
        QMessageBox msgBox(QMessageBox::Critical,windowTitle(),tr("请输入用户名！"),QMessageBox::Ok,this);
        msgBox.exec();
        return;
    }

    if(0 == ui->password_edit->displayText().length())
    {
        //ui->state->setText("Please input user password!");
        QMessageBox msgBox(QMessageBox::Critical,windowTitle(),tr("请输入密码！"),QMessageBox::Ok,this);
        msgBox.exec();
        return;
    }

    if(0 == ui->IPaddr_edit ->displayText().length())
    {
        //ui->state->setText(tr("Please input IP!"));
        QMessageBox msgBox(QMessageBox::Critical,windowTitle(),tr("请输入IP地址！"),QMessageBox::Ok,this);
        msgBox.exec();
        return;
    }

    //获取用户输入的ip，用户名，密码消息
    strcpy(info.user,ui->username_edit->text().toAscii().data());
    strcpy(info.pwd,ui->password_edit->text().toAscii().data());
    strcpy(ip_addr,ui->IPaddr_edit->text().toLocal8Bit().data());
    //qDebug("name=%s,pwd=%s,ip=%s",info.user,info.pwd,ip_addr);


    ret=udp_init(CLIENT,ip_addr,8888);
    if(ret == -1)
    {
        qDebug("init socket error!");
    }

    ret=udp_write(CLIENT,(char *)&cmd,sizeof(int));
    if(ret==-1)
    {
        qDebug("udp_write");
        return;
    }

    ret=udp_write(CLIENT,(char *)&info,sizeof(struct passwd_info));
    if(ret==-1)
    {
        qDebug("udp_write");
        return;
    }

    //读取返回的登录结果
    int result = 0;
    ret = udp_read(CLIENT,(char*)&result,sizeof(char));
    if(ret == -1)
    {
        qDebug("udp_read error!");
    }
    else
    {
        if(result == LOGIN_SUCCESS)
        {
            qDebug("login success!");
            QDialog::accept();//???
        }
        else
        {
            //qDebug("login failed:user or password error!");
            //弹出提示框，用户名或密码错误，请重新输入
            QMessageBox msgBox(QMessageBox::Critical,windowTitle(),tr("用户名或密码错误，请重新输入！"),QMessageBox::Ok,this);
            msgBox.exec();
        }
    }
}

void LoginDlg::on_cancel_btn_clicked()
{
    //您确定要退出登录，点是退出，点否返回登录界面
    QMessageBox msgBox(QMessageBox::Question,windowTitle(),tr("您真的要取消登录吗？"),QMessageBox::Yes | QMessageBox::No,this);
    if(msgBox.exec() == QMessageBox::Yes)
    {
        close();
    }
}
