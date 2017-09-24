/********************************************************************************
** Form generated from reading UI file 'LoginDlg.ui'
**
** Created: Sun Aug 20 11:41:23 2017
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDLG_H
#define UI_LOGINDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginDlg
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *username_edit;
    QLabel *label_2;
    QLineEdit *IPaddr_edit;
    QLineEdit *password_edit;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *connect_btn;
    QPushButton *cancel_btn;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *LoginDlg)
    {
        if (LoginDlg->objectName().isEmpty())
            LoginDlg->setObjectName(QString::fromUtf8("LoginDlg"));
        LoginDlg->resize(602, 492);
        verticalLayout = new QVBoxLayout(LoginDlg);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 105, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(LoginDlg);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(LoginDlg);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        username_edit = new QLineEdit(LoginDlg);
        username_edit->setObjectName(QString::fromUtf8("username_edit"));

        gridLayout->addWidget(username_edit, 0, 1, 1, 1);

        label_2 = new QLabel(LoginDlg);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        IPaddr_edit = new QLineEdit(LoginDlg);
        IPaddr_edit->setObjectName(QString::fromUtf8("IPaddr_edit"));

        gridLayout->addWidget(IPaddr_edit, 2, 1, 1, 1);

        password_edit = new QLineEdit(LoginDlg);
        password_edit->setObjectName(QString::fromUtf8("password_edit"));
        password_edit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(password_edit, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer_2 = new QSpacerItem(20, 106, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        connect_btn = new QPushButton(LoginDlg);
        connect_btn->setObjectName(QString::fromUtf8("connect_btn"));

        horizontalLayout->addWidget(connect_btn);

        cancel_btn = new QPushButton(LoginDlg);
        cancel_btn->setObjectName(QString::fromUtf8("cancel_btn"));

        horizontalLayout->addWidget(cancel_btn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 105, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        QWidget::setTabOrder(username_edit, password_edit);
        QWidget::setTabOrder(password_edit, IPaddr_edit);
        QWidget::setTabOrder(IPaddr_edit, connect_btn);
        QWidget::setTabOrder(connect_btn, cancel_btn);

        retranslateUi(LoginDlg);

        QMetaObject::connectSlotsByName(LoginDlg);
    } // setupUi

    void retranslateUi(QDialog *LoginDlg)
    {
        LoginDlg->setWindowTitle(QApplication::translate("LoginDlg", "EHOME\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("LoginDlg", "IP\357\274\232", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LoginDlg", "\347\224\250\346\210\267\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("LoginDlg", "\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        connect_btn->setText(QApplication::translate("LoginDlg", "\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
        cancel_btn->setText(QApplication::translate("LoginDlg", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LoginDlg: public Ui_LoginDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDLG_H
