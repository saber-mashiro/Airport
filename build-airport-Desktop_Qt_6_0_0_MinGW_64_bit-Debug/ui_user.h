/********************************************************************************
** Form generated from reading UI file 'user.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_H
#define UI_USER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_user
{
public:
    QWidget *centralwidget;
    QPushButton *bookT;
    QPushButton *refundT;
    QPushButton *checkT;
    QPushButton *backChoose;
    QTabWidget *tabWidget;
    QWidget *bookTicket;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *nameLine;
    QLineEdit *idLine;
    QLineEdit *airnumLine;
    QLineEdit *ticketLine;
    QLineEdit *levelLine;
    QPushButton *confirm_Book;
    QWidget *refundTicket;
    QLabel *label_10;
    QLineEdit *idLine2;
    QLineEdit *airnumLine2;
    QLineEdit *ticketLine2;
    QPushButton *confirm_Refund;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_11;
    QLineEdit *levelLine2;
    QWidget *checkTicket;
    QLabel *label_8;
    QLineEdit *idLine3;
    QPushButton *confirm_Check;
    QTableView *checkAll;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *user)
    {
        if (user->objectName().isEmpty())
            user->setObjectName(QString::fromUtf8("user"));
        user->resize(800, 600);
        centralwidget = new QWidget(user);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        bookT = new QPushButton(centralwidget);
        bookT->setObjectName(QString::fromUtf8("bookT"));
        bookT->setGeometry(QRect(0, 0, 151, 111));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\345\255\227\350\277\271-\345\205\260\346\242\223\350\223\221\347\254\240\347\277\201\344\275\223 \347\256\200"));
        font.setPointSize(16);
        bookT->setFont(font);
        refundT = new QPushButton(centralwidget);
        refundT->setObjectName(QString::fromUtf8("refundT"));
        refundT->setGeometry(QRect(320, 0, 151, 111));
        refundT->setFont(font);
        checkT = new QPushButton(centralwidget);
        checkT->setObjectName(QString::fromUtf8("checkT"));
        checkT->setGeometry(QRect(640, 0, 151, 111));
        checkT->setFont(font);
        backChoose = new QPushButton(centralwidget);
        backChoose->setObjectName(QString::fromUtf8("backChoose"));
        backChoose->setGeometry(QRect(0, 120, 791, 31));
        backChoose->setFont(font);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 160, 791, 381));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\271\346\255\243\345\255\227\350\277\271-\345\205\260\346\242\223\350\223\221\347\254\240\347\277\201\344\275\223 \347\256\200"));
        tabWidget->setFont(font1);
        bookTicket = new QWidget();
        bookTicket->setObjectName(QString::fromUtf8("bookTicket"));
        label = new QLabel(bookTicket);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(230, 60, 59, 33));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\226\271\346\255\243\345\255\227\350\277\271-\345\205\260\346\242\223\350\223\221\347\254\240\347\277\201\344\275\223 \347\256\200"));
        font2.setPointSize(10);
        label->setFont(font2);
        label_2 = new QLabel(bookTicket);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(230, 100, 76, 33));
        label_2->setFont(font2);
        label_3 = new QLabel(bookTicket);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 140, 59, 33));
        label_3->setFont(font2);
        label_4 = new QLabel(bookTicket);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(230, 180, 71, 33));
        label_4->setFont(font2);
        label_5 = new QLabel(bookTicket);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(230, 220, 71, 33));
        label_5->setFont(font2);
        nameLine = new QLineEdit(bookTicket);
        nameLine->setObjectName(QString::fromUtf8("nameLine"));
        nameLine->setGeometry(QRect(320, 70, 211, 21));
        nameLine->setClearButtonEnabled(true);
        idLine = new QLineEdit(bookTicket);
        idLine->setObjectName(QString::fromUtf8("idLine"));
        idLine->setGeometry(QRect(320, 110, 211, 21));
        idLine->setClearButtonEnabled(true);
        airnumLine = new QLineEdit(bookTicket);
        airnumLine->setObjectName(QString::fromUtf8("airnumLine"));
        airnumLine->setGeometry(QRect(320, 150, 211, 21));
        airnumLine->setClearButtonEnabled(true);
        ticketLine = new QLineEdit(bookTicket);
        ticketLine->setObjectName(QString::fromUtf8("ticketLine"));
        ticketLine->setGeometry(QRect(320, 190, 211, 21));
        ticketLine->setClearButtonEnabled(true);
        levelLine = new QLineEdit(bookTicket);
        levelLine->setObjectName(QString::fromUtf8("levelLine"));
        levelLine->setGeometry(QRect(320, 230, 211, 21));
        levelLine->setClearButtonEnabled(true);
        confirm_Book = new QPushButton(bookTicket);
        confirm_Book->setObjectName(QString::fromUtf8("confirm_Book"));
        confirm_Book->setGeometry(QRect(640, 280, 121, 51));
        tabWidget->addTab(bookTicket, QString());
        refundTicket = new QWidget();
        refundTicket->setObjectName(QString::fromUtf8("refundTicket"));
        label_10 = new QLabel(refundTicket);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(150, 170, 110, 33));
        label_10->setFont(font2);
        idLine2 = new QLineEdit(refundTicket);
        idLine2->setObjectName(QString::fromUtf8("idLine2"));
        idLine2->setGeometry(QRect(280, 50, 261, 41));
        idLine2->setClearButtonEnabled(true);
        airnumLine2 = new QLineEdit(refundTicket);
        airnumLine2->setObjectName(QString::fromUtf8("airnumLine2"));
        airnumLine2->setGeometry(QRect(280, 110, 261, 41));
        airnumLine2->setClearButtonEnabled(true);
        ticketLine2 = new QLineEdit(refundTicket);
        ticketLine2->setObjectName(QString::fromUtf8("ticketLine2"));
        ticketLine2->setGeometry(QRect(280, 170, 261, 41));
        ticketLine2->setClearButtonEnabled(true);
        confirm_Refund = new QPushButton(refundTicket);
        confirm_Refund->setObjectName(QString::fromUtf8("confirm_Refund"));
        confirm_Refund->setGeometry(QRect(640, 280, 121, 51));
        label_6 = new QLabel(refundTicket);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(150, 50, 76, 33));
        label_6->setFont(font2);
        label_7 = new QLabel(refundTicket);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(150, 110, 59, 33));
        label_7->setFont(font2);
        label_11 = new QLabel(refundTicket);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(150, 230, 110, 33));
        label_11->setFont(font2);
        levelLine2 = new QLineEdit(refundTicket);
        levelLine2->setObjectName(QString::fromUtf8("levelLine2"));
        levelLine2->setGeometry(QRect(280, 230, 261, 41));
        levelLine2->setClearButtonEnabled(true);
        tabWidget->addTab(refundTicket, QString());
        checkTicket = new QWidget();
        checkTicket->setObjectName(QString::fromUtf8("checkTicket"));
        label_8 = new QLabel(checkTicket);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 20, 76, 33));
        label_8->setFont(font2);
        idLine3 = new QLineEdit(checkTicket);
        idLine3->setObjectName(QString::fromUtf8("idLine3"));
        idLine3->setGeometry(QRect(50, 20, 261, 31));
        idLine3->setClearButtonEnabled(true);
        confirm_Check = new QPushButton(checkTicket);
        confirm_Check->setObjectName(QString::fromUtf8("confirm_Check"));
        confirm_Check->setGeometry(QRect(610, 10, 121, 51));
        checkAll = new QTableView(checkTicket);
        checkAll->setObjectName(QString::fromUtf8("checkAll"));
        checkAll->setGeometry(QRect(0, 70, 781, 281));
        tabWidget->addTab(checkTicket, QString());
        user->setCentralWidget(centralwidget);
        menubar = new QMenuBar(user);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        user->setMenuBar(menubar);
        statusbar = new QStatusBar(user);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        user->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());

        retranslateUi(user);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(user);
    } // setupUi

    void retranslateUi(QMainWindow *user)
    {
        user->setWindowTitle(QCoreApplication::translate("user", "\351\243\236\346\234\272\347\245\250\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        bookT->setText(QCoreApplication::translate("user", "\350\256\242\347\245\250", nullptr));
        refundT->setText(QCoreApplication::translate("user", "\351\200\200\347\245\250", nullptr));
        checkT->setText(QCoreApplication::translate("user", "\346\237\245\350\257\242", nullptr));
        backChoose->setText(QCoreApplication::translate("user", "\350\277\224\345\233\236", nullptr));
        label->setText(QCoreApplication::translate("user", "\345\247\223\345\220\215 :", nullptr));
        label_2->setText(QCoreApplication::translate("user", "ID :", nullptr));
        label_3->setText(QCoreApplication::translate("user", "\350\210\252\347\217\255\345\217\267 :", nullptr));
        label_4->setText(QCoreApplication::translate("user", "\345\256\232\347\245\250\351\207\217 :", nullptr));
        label_5->setText(QCoreApplication::translate("user", "\347\245\250\347\255\211\347\272\247:", nullptr));
        nameLine->setPlaceholderText(QCoreApplication::translate("user", "\350\257\267\350\276\223\345\205\245\345\247\223\345\220\215[NAME]", nullptr));
        idLine->setPlaceholderText(QCoreApplication::translate("user", "\350\257\267\350\276\223\345\205\245\350\272\253\344\273\275ID[ID]", nullptr));
        airnumLine->setPlaceholderText(QCoreApplication::translate("user", "\350\257\267\350\276\223\345\205\245\350\210\252\347\217\255\345\217\267[AIRNUM]", nullptr));
        ticketLine->setPlaceholderText(QCoreApplication::translate("user", "\350\257\267\350\276\223\345\205\245\350\256\242\347\245\250\351\207\217[TICKETNUM]", nullptr));
        levelLine->setPlaceholderText(QCoreApplication::translate("user", "\350\257\267\350\276\223\345\205\245\350\256\242\347\245\250\347\255\211\347\272\247[level]", nullptr));
        confirm_Book->setText(QCoreApplication::translate("user", "\347\241\256\350\256\244", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(bookTicket), QCoreApplication::translate("user", "\350\256\242\347\245\250", nullptr));
        label_10->setText(QCoreApplication::translate("user", "\351\200\200\347\245\250\351\207\217 :", nullptr));
        idLine2->setPlaceholderText(QCoreApplication::translate("user", "\350\257\267\350\276\223\345\205\245\350\272\253\344\273\275ID[ID]", nullptr));
        airnumLine2->setPlaceholderText(QCoreApplication::translate("user", "\350\257\267\350\276\223\345\205\245\350\210\252\347\217\255\345\217\267[AIRNUM]", nullptr));
        ticketLine2->setPlaceholderText(QCoreApplication::translate("user", "\350\257\267\350\276\223\345\205\245\351\200\200\347\245\250\351\207\217[TICKETNUM]", nullptr));
        confirm_Refund->setText(QCoreApplication::translate("user", "\347\241\256\350\256\244", nullptr));
        label_6->setText(QCoreApplication::translate("user", "ID :", nullptr));
        label_7->setText(QCoreApplication::translate("user", "\350\210\252\347\217\255\345\217\267 :", nullptr));
        label_11->setText(QCoreApplication::translate("user", "\351\200\200\347\245\250\347\255\211\347\272\247 :", nullptr));
        levelLine2->setPlaceholderText(QCoreApplication::translate("user", "\350\257\267\350\276\223\345\205\245\351\200\200\347\245\250\347\255\211\347\272\247[level]", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(refundTicket), QCoreApplication::translate("user", "\351\200\200\347\245\250", nullptr));
        label_8->setText(QCoreApplication::translate("user", "ID :", nullptr));
        idLine3->setPlaceholderText(QCoreApplication::translate("user", "\350\257\267\350\276\223\345\205\245\350\272\253\344\273\275ID[ID]", nullptr));
        confirm_Check->setText(QCoreApplication::translate("user", "\347\241\256\350\256\244", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(checkTicket), QCoreApplication::translate("user", "\346\237\245\350\257\242\346\230\276\347\244\272", nullptr));
        menu->setTitle(QCoreApplication::translate("user", "\347\263\273\347\273\237", nullptr));
        menu_2->setTitle(QCoreApplication::translate("user", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class user: public Ui_user {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_H
