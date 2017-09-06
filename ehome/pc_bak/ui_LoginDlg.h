/********************************************************************************
** Form generated from reading UI file 'LoginDlg.ui'
**
** Created: Sun Jul 30 01:02:13 2017
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
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginDlg
{
public:
    QVBoxLayout *m_layVer;
    QSpacerItem *m_spcUp;
    QGridLayout *m_layGrid;
    QLabel *m_labUsername;
    QLineEdit *m_editUserame;
    QLabel *m_labPassword;
    QLineEdit *m_editPassword;
    QLabel *m_labelIPaddress;
    QLineEdit *m_editIPaddress;
    QDialogButtonBox *m_btnBox;
    QSpacerItem *m_spcDown;

    void setupUi(QDialog *LoginDlg)
    {
        if (LoginDlg->objectName().isEmpty())
            LoginDlg->setObjectName(QString::fromUtf8("LoginDlg"));
        LoginDlg->resize(214, 159);
        LoginDlg->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);\n"
"background-color: rgb(208, 213, 213);"));
        m_layVer = new QVBoxLayout(LoginDlg);
        m_layVer->setObjectName(QString::fromUtf8("m_layVer"));
        m_spcUp = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        m_layVer->addItem(m_spcUp);

        m_layGrid = new QGridLayout();
        m_layGrid->setObjectName(QString::fromUtf8("m_layGrid"));
        m_labUsername = new QLabel(LoginDlg);
        m_labUsername->setObjectName(QString::fromUtf8("m_labUsername"));
        m_labUsername->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_layGrid->addWidget(m_labUsername, 0, 0, 1, 1);

        m_editUserame = new QLineEdit(LoginDlg);
        m_editUserame->setObjectName(QString::fromUtf8("m_editUserame"));

        m_layGrid->addWidget(m_editUserame, 0, 1, 1, 1);

        m_labPassword = new QLabel(LoginDlg);
        m_labPassword->setObjectName(QString::fromUtf8("m_labPassword"));
        m_labPassword->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_layGrid->addWidget(m_labPassword, 1, 0, 1, 1);

        m_editPassword = new QLineEdit(LoginDlg);
        m_editPassword->setObjectName(QString::fromUtf8("m_editPassword"));
        m_editPassword->setEchoMode(QLineEdit::Password);

        m_layGrid->addWidget(m_editPassword, 1, 1, 1, 1);

        m_labelIPaddress = new QLabel(LoginDlg);
        m_labelIPaddress->setObjectName(QString::fromUtf8("m_labelIPaddress"));
        m_labelIPaddress->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_layGrid->addWidget(m_labelIPaddress, 2, 0, 1, 1);

        m_editIPaddress = new QLineEdit(LoginDlg);
        m_editIPaddress->setObjectName(QString::fromUtf8("m_editIPaddress"));

        m_layGrid->addWidget(m_editIPaddress, 2, 1, 1, 1);


        m_layVer->addLayout(m_layGrid);

        m_btnBox = new QDialogButtonBox(LoginDlg);
        m_btnBox->setObjectName(QString::fromUtf8("m_btnBox"));
        m_btnBox->setLayoutDirection(Qt::RightToLeft);
        m_btnBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        m_btnBox->setCenterButtons(true);

        m_layVer->addWidget(m_btnBox);

        m_spcDown = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        m_layVer->addItem(m_spcDown);


        retranslateUi(LoginDlg);

        QMetaObject::connectSlotsByName(LoginDlg);
    } // setupUi

    void retranslateUi(QDialog *LoginDlg)
    {
        LoginDlg->setWindowTitle(QApplication::translate("LoginDlg", "EHOME\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        m_labUsername->setText(QApplication::translate("LoginDlg", "\347\224\250\346\210\267\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        m_labPassword->setText(QApplication::translate("LoginDlg", "\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        m_labelIPaddress->setText(QApplication::translate("LoginDlg", "IP\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LoginDlg: public Ui_LoginDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDLG_H
