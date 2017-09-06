/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Oct 17 17:41:10 2016
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *getVerPtn;
    QLabel *sversionLabel;
    QLabel *hversionLabel;
    QLabel *sversioninfo;
    QLabel *hversioninfo;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(556, 405);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        getVerPtn = new QPushButton(centralWidget);
        getVerPtn->setObjectName(QString::fromUtf8("getVerPtn"));
        getVerPtn->setGeometry(QRect(170, 260, 111, 51));
        sversionLabel = new QLabel(centralWidget);
        sversionLabel->setObjectName(QString::fromUtf8("sversionLabel"));
        sversionLabel->setGeometry(QRect(90, 120, 81, 31));
        hversionLabel = new QLabel(centralWidget);
        hversionLabel->setObjectName(QString::fromUtf8("hversionLabel"));
        hversionLabel->setGeometry(QRect(90, 190, 81, 31));
        sversioninfo = new QLabel(centralWidget);
        sversioninfo->setObjectName(QString::fromUtf8("sversioninfo"));
        sversioninfo->setGeometry(QRect(170, 110, 161, 51));
        hversioninfo = new QLabel(centralWidget);
        hversioninfo->setObjectName(QString::fromUtf8("hversioninfo"));
        hversioninfo->setGeometry(QRect(170, 180, 161, 51));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 556, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        getVerPtn->setText(QApplication::translate("MainWindow", "get version", 0, QApplication::UnicodeUTF8));
        sversionLabel->setText(QApplication::translate("MainWindow", "sversion:", 0, QApplication::UnicodeUTF8));
        hversionLabel->setText(QApplication::translate("MainWindow", "hversion:", 0, QApplication::UnicodeUTF8));
        sversioninfo->setText(QApplication::translate("MainWindow", "SYYMMDDXY", 0, QApplication::UnicodeUTF8));
        hversioninfo->setText(QApplication::translate("MainWindow", "HYYMMDDXY", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
