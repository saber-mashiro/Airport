/********************************************************************************
** Form generated from reading UI file 'sign.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGN_H
#define UI_SIGN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sign
{
public:
    QWidget *centralwidget;
    QPushButton *paEnter;
    QPushButton *adEnter;
    QPushButton *backMain;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *sign)
    {
        if (sign->objectName().isEmpty())
            sign->setObjectName(QString::fromUtf8("sign"));
        sign->resize(800, 600);
        centralwidget = new QWidget(sign);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        paEnter = new QPushButton(centralwidget);
        paEnter->setObjectName(QString::fromUtf8("paEnter"));
        paEnter->setGeometry(QRect(250, 140, 271, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\345\255\227\350\277\271-\345\205\260\346\242\223\350\223\221\347\254\240\347\277\201\344\275\223 \347\256\200"));
        font.setPointSize(26);
        paEnter->setFont(font);
        adEnter = new QPushButton(centralwidget);
        adEnter->setObjectName(QString::fromUtf8("adEnter"));
        adEnter->setGeometry(QRect(250, 340, 271, 71));
        adEnter->setFont(font);
        backMain = new QPushButton(centralwidget);
        backMain->setObjectName(QString::fromUtf8("backMain"));
        backMain->setGeometry(QRect(0, 510, 791, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\271\346\255\243\345\255\227\350\277\271-\345\205\260\346\242\223\350\223\221\347\254\240\347\277\201\344\275\223 \347\256\200"));
        font1.setPointSize(16);
        backMain->setFont(font1);
        sign->setCentralWidget(centralwidget);
        menubar = new QMenuBar(sign);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        sign->setMenuBar(menubar);
        statusbar = new QStatusBar(sign);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        sign->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());

        retranslateUi(sign);

        QMetaObject::connectSlotsByName(sign);
    } // setupUi

    void retranslateUi(QMainWindow *sign)
    {
        sign->setWindowTitle(QCoreApplication::translate("sign", "\351\243\236\346\234\272\347\245\250\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        paEnter->setText(QCoreApplication::translate("sign", "\344\271\230\345\256\242\347\231\273\345\275\225", nullptr));
        adEnter->setText(QCoreApplication::translate("sign", "\347\256\241\347\220\206\345\221\230\347\231\273\345\275\225", nullptr));
        backMain->setText(QCoreApplication::translate("sign", "\350\277\224\345\233\236", nullptr));
        menu->setTitle(QCoreApplication::translate("sign", "\347\263\273\347\273\237", nullptr));
        menu_2->setTitle(QCoreApplication::translate("sign", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sign: public Ui_sign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGN_H
