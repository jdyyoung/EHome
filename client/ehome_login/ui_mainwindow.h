/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Sep 11 22:41:15 2017
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action123;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QFrame *line_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLabel *label_2;
    QPushButton *LEDonBtn;
    QPushButton *LEDoffBtn;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QPushButton *getTempBtn;
    QTextBrowser *temperatureTB;
    QWidget *tab_2;
    QFrame *line;
    QFrame *line_2;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QPushButton *kernelUpdateBtn;
    QPushButton *rootfsUpdateBtn;
    QPushButton *userdataUpdateBtn;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLabel *hwVersionLabel;
    QLabel *label_5;
    QLabel *swVersionLabel;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *systemInfoBtn;
    QLabel *label_7;
    QTextBrowser *CPUfreqTB;
    QLabel *label_8;
    QTextBrowser *memspaceTB;
    QLabel *label_9;
    QTextBrowser *diskspaceTB;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(720, 516);
        action123 = new QAction(MainWindow);
        action123->setObjectName(QString::fromUtf8("action123"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(30, 50, 681, 444));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        line_3 = new QFrame(tab);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(30, 90, 590, 3));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 40, 279, 30));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_5->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_5->addWidget(label_2);

        LEDonBtn = new QPushButton(layoutWidget);
        LEDonBtn->setObjectName(QString::fromUtf8("LEDonBtn"));

        horizontalLayout_5->addWidget(LEDonBtn);

        LEDoffBtn = new QPushButton(layoutWidget);
        LEDoffBtn->setObjectName(QString::fromUtf8("LEDoffBtn"));

        horizontalLayout_5->addWidget(LEDoffBtn);

        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 110, 414, 43));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(59, 18));

        horizontalLayout_4->addWidget(label_3);

        getTempBtn = new QPushButton(layoutWidget1);
        getTempBtn->setObjectName(QString::fromUtf8("getTempBtn"));
        getTempBtn->setMaximumSize(QSize(85, 28));

        horizontalLayout_4->addWidget(getTempBtn);

        temperatureTB = new QTextBrowser(layoutWidget1);
        temperatureTB->setObjectName(QString::fromUtf8("temperatureTB"));
        temperatureTB->setMaximumSize(QSize(256, 41));

        horizontalLayout_4->addWidget(temperatureTB);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        line = new QFrame(tab_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 60, 651, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(tab_2);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(10, 120, 650, 3));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        layoutWidget2 = new QWidget(tab_2);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 80, 349, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout->addWidget(label_6);

        kernelUpdateBtn = new QPushButton(layoutWidget2);
        kernelUpdateBtn->setObjectName(QString::fromUtf8("kernelUpdateBtn"));

        horizontalLayout->addWidget(kernelUpdateBtn);

        rootfsUpdateBtn = new QPushButton(layoutWidget2);
        rootfsUpdateBtn->setObjectName(QString::fromUtf8("rootfsUpdateBtn"));

        horizontalLayout->addWidget(rootfsUpdateBtn);

        userdataUpdateBtn = new QPushButton(layoutWidget2);
        userdataUpdateBtn->setObjectName(QString::fromUtf8("userdataUpdateBtn"));

        horizontalLayout->addWidget(userdataUpdateBtn);

        layoutWidget3 = new QWidget(tab_2);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 130, 571, 41));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        hwVersionLabel = new QLabel(layoutWidget3);
        hwVersionLabel->setObjectName(QString::fromUtf8("hwVersionLabel"));

        horizontalLayout_3->addWidget(hwVersionLabel);

        label_5 = new QLabel(layoutWidget3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        swVersionLabel = new QLabel(layoutWidget3);
        swVersionLabel->setObjectName(QString::fromUtf8("swVersionLabel"));

        horizontalLayout_3->addWidget(swVersionLabel);

        layoutWidget4 = new QWidget(tab_2);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 20, 668, 33));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        systemInfoBtn = new QPushButton(layoutWidget4);
        systemInfoBtn->setObjectName(QString::fromUtf8("systemInfoBtn"));
        systemInfoBtn->setMaximumSize(QSize(71, 27));

        horizontalLayout_2->addWidget(systemInfoBtn);

        label_7 = new QLabel(layoutWidget4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMaximumSize(QSize(66, 21));

        horizontalLayout_2->addWidget(label_7);

        CPUfreqTB = new QTextBrowser(layoutWidget4);
        CPUfreqTB->setObjectName(QString::fromUtf8("CPUfreqTB"));
        CPUfreqTB->setMaximumSize(QSize(115, 31));

        horizontalLayout_2->addWidget(CPUfreqTB);

        label_8 = new QLabel(layoutWidget4);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_2->addWidget(label_8);

        memspaceTB = new QTextBrowser(layoutWidget4);
        memspaceTB->setObjectName(QString::fromUtf8("memspaceTB"));
        memspaceTB->setEnabled(false);
        memspaceTB->setMaximumSize(QSize(115, 31));

        horizontalLayout_2->addWidget(memspaceTB);

        label_9 = new QLabel(layoutWidget4);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_2->addWidget(label_9);

        diskspaceTB = new QTextBrowser(layoutWidget4);
        diskspaceTB->setObjectName(QString::fromUtf8("diskspaceTB"));
        diskspaceTB->setMaximumSize(QSize(115, 31));

        horizontalLayout_2->addWidget(diskspaceTB);

        tabWidget->addTab(tab_2, QString());
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        line->raise();
        line_2->raise();
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        action123->setText(QApplication::translate("MainWindow", "123", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\345\256\242\345\216\205\347\201\257\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
        LEDonBtn->setText(QApplication::translate("MainWindow", "\345\274\200", 0, QApplication::UnicodeUTF8));
        LEDoffBtn->setText(QApplication::translate("MainWindow", "\345\205\263", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "\345\256\244\345\206\205\346\270\251\345\272\246", 0, QApplication::UnicodeUTF8));
        getTempBtn->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\345\275\223\345\211\215\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\345\215\207\347\272\247\357\274\232", 0, QApplication::UnicodeUTF8));
        kernelUpdateBtn->setText(QApplication::translate("MainWindow", "Kernel", 0, QApplication::UnicodeUTF8));
        rootfsUpdateBtn->setText(QApplication::translate("MainWindow", "Rootfs", 0, QApplication::UnicodeUTF8));
        userdataUpdateBtn->setText(QApplication::translate("MainWindow", "Userdata", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "\347\241\254\344\273\266\347\211\210\346\234\254\357\274\232", 0, QApplication::UnicodeUTF8));
        hwVersionLabel->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "\350\275\257\344\273\266\347\211\210\346\234\254\357\274\232", 0, QApplication::UnicodeUTF8));
        swVersionLabel->setText(QString());
        systemInfoBtn->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "CPU\351\242\221\347\216\207\357\274\232", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "\347\251\272\351\227\262\345\206\205\345\255\230\357\274\232", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "\345\211\251\344\275\231\347\243\201\347\233\230\357\274\232", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\347\263\273\347\273\237\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
