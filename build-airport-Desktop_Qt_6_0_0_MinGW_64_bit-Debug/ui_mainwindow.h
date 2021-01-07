/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *enterSys;
    QLabel *label;
    QPushButton *exitsys;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setToolButtonStyle(Qt::ToolButtonFollowStyle);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        enterSys = new QPushButton(centralwidget);
        enterSys->setObjectName(QString::fromUtf8("enterSys"));
        enterSys->setGeometry(QRect(300, 270, 171, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\345\255\227\350\277\271-\345\205\260\346\242\223\350\223\221\347\254\240\347\277\201\344\275\223 \347\256\200"));
        font.setPointSize(20);
        enterSys->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 130, 481, 91));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\271\346\255\243\345\255\227\350\277\271-\345\205\260\346\242\223\350\223\221\347\254\240\347\277\201\344\275\223 \347\256\200"));
        font1.setPointSize(28);
        label->setFont(font1);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setFrameShadow(QFrame::Plain);
        label->setTextFormat(Qt::AutoText);
        label->setOpenExternalLinks(false);
        exitsys = new QPushButton(centralwidget);
        exitsys->setObjectName(QString::fromUtf8("exitsys"));
        exitsys->setGeometry(QRect(300, 360, 171, 71));
        exitsys->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\351\243\236\346\234\272\347\245\250\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        enterSys->setText(QCoreApplication::translate("MainWindow", "\350\277\233\345\205\245\347\263\273\347\273\237", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\254\242\350\277\216\344\275\277\347\224\250\351\243\236\346\234\272\350\256\242\347\245\250\347\263\273\347\273\237", nullptr));
        exitsys->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\347\263\273\347\273\237", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
