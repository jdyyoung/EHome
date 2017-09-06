#include<QTextCodec>
#include<QApplication>
#include "LoginDlg.h"

int main(int argc,char* argv[])
{
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));
    QApplication app (argc,argv);
    LoginDlg dlg;
    dlg.show();
    return app.exec();
}

