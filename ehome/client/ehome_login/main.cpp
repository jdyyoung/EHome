#include <QApplication>
#include<QTextCodec>
#include<QTranslator>
#include "LoginDlg.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));

    QApplication a(argc, argv);

    QTranslator tr;
    //tr.load("qt_" + QLocale::system().name(),"/usr/share/qt4/translations");
    tr.load("qt_zh_CN" ,"/usr/share/qt4/translations");
    a.installTranslator(&tr);
    LoginDlg login;
    login.show();
    if(login.exec() == QDialog::Accepted)
    {
        MainWindow w;
        w.show();

        return a.exec();
    }
    else
    {
        return -1;
    }
}
