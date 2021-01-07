/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_admin
{
public:
    QWidget *centralwidget;
    QPushButton *plShow;
    QPushButton *paShow;
    QPushButton *plPlus;
    QPushButton *plUpdate;
    QPushButton *plDelete;
    QPushButton *back_Choose;
    QTabWidget *tabWidget;
    QWidget *plMess;
    QPlainTextEdit *plainTextEdit;
    QWidget *paMess;
    QPlainTextEdit *plainTextEdit_2;
    QWidget *plPlus_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *airnumLine;
    QLineEdit *planeLine;
    QLineEdit *startLine;
    QLineEdit *finalLine;
    QLineEdit *dayLine;
    QLineEdit *reticketLine;
    QLineEdit *peoLine;
    QPushButton *confirm_Plus;
    QWidget *plUpd;
    QLabel *label_8;
    QLabel *label_11;
    QLabel *label_9;
    QLineEdit *idoLine;
    QLineEdit *valueLine;
    QLineEdit *airnumLine2;
    QPushButton *confirm_Up;
    QWidget *plDel;
    QLabel *label_10;
    QLineEdit *airnumLine3;
    QPushButton *confirm_Del;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *admin)
    {
        if (admin->objectName().isEmpty())
            admin->setObjectName(QString::fromUtf8("admin"));
        admin->resize(800, 600);
        centralwidget = new QWidget(admin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        plShow = new QPushButton(centralwidget);
        plShow->setObjectName(QString::fromUtf8("plShow"));
        plShow->setGeometry(QRect(0, 0, 151, 111));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\345\255\227\350\277\271-\345\205\260\346\242\223\350\223\221\347\254\240\347\277\201\344\275\223 \347\256\200"));
        font.setPointSize(16);
        plShow->setFont(font);
        paShow = new QPushButton(centralwidget);
        paShow->setObjectName(QString::fromUtf8("paShow"));
        paShow->setGeometry(QRect(160, 0, 151, 111));
        paShow->setFont(font);
        plPlus = new QPushButton(centralwidget);
        plPlus->setObjectName(QString::fromUtf8("plPlus"));
        plPlus->setGeometry(QRect(320, 0, 151, 111));
        plPlus->setFont(font);
        plUpdate = new QPushButton(centralwidget);
        plUpdate->setObjectName(QString::fromUtf8("plUpdate"));
        plUpdate->setGeometry(QRect(480, 0, 151, 111));
        plUpdate->setFont(font);
        plDelete = new QPushButton(centralwidget);
        plDelete->setObjectName(QString::fromUtf8("plDelete"));
        plDelete->setGeometry(QRect(640, 0, 151, 111));
        plDelete->setFont(font);
        back_Choose = new QPushButton(centralwidget);
        back_Choose->setObjectName(QString::fromUtf8("back_Choose"));
        back_Choose->setGeometry(QRect(0, 120, 791, 31));
        back_Choose->setFont(font);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 160, 791, 381));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\271\346\255\243\345\255\227\350\277\271-\345\205\260\346\242\223\350\223\221\347\254\240\347\277\201\344\275\223 \347\256\200"));
        tabWidget->setFont(font1);
        plMess = new QWidget();
        plMess->setObjectName(QString::fromUtf8("plMess"));
        plainTextEdit = new QPlainTextEdit(plMess);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(0, 0, 791, 361));
        tabWidget->addTab(plMess, QString());
        paMess = new QWidget();
        paMess->setObjectName(QString::fromUtf8("paMess"));
        plainTextEdit_2 = new QPlainTextEdit(paMess);
        plainTextEdit_2->setObjectName(QString::fromUtf8("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(0, 0, 791, 361));
        tabWidget->addTab(paMess, QString());
        plPlus_2 = new QWidget();
        plPlus_2->setObjectName(QString::fromUtf8("plPlus_2"));
        label = new QLabel(plPlus_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 40, 59, 33));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\226\271\346\255\243\345\255\227\350\277\271-\345\205\260\346\242\223\350\223\221\347\254\240\347\277\201\344\275\223 \347\256\200"));
        font2.setPointSize(10);
        label->setFont(font2);
        label_2 = new QLabel(plPlus_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(160, 80, 76, 33));
        label_2->setFont(font2);
        label_3 = new QLabel(plPlus_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(160, 120, 59, 33));
        label_3->setFont(font2);
        label_4 = new QLabel(plPlus_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(160, 160, 59, 33));
        label_4->setFont(font2);
        label_5 = new QLabel(plPlus_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(160, 200, 38, 33));
        label_5->setFont(font2);
        label_6 = new QLabel(plPlus_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(160, 280, 55, 33));
        label_6->setFont(font2);
        label_7 = new QLabel(plPlus_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(160, 240, 61, 33));
        label_7->setFont(font2);
        airnumLine = new QLineEdit(plPlus_2);
        airnumLine->setObjectName(QString::fromUtf8("airnumLine"));
        airnumLine->setGeometry(QRect(250, 50, 211, 21));
        airnumLine->setClearButtonEnabled(true);
        planeLine = new QLineEdit(plPlus_2);
        planeLine->setObjectName(QString::fromUtf8("planeLine"));
        planeLine->setGeometry(QRect(250, 90, 211, 21));
        planeLine->setClearButtonEnabled(true);
        startLine = new QLineEdit(plPlus_2);
        startLine->setObjectName(QString::fromUtf8("startLine"));
        startLine->setGeometry(QRect(250, 130, 211, 21));
        startLine->setClearButtonEnabled(true);
        finalLine = new QLineEdit(plPlus_2);
        finalLine->setObjectName(QString::fromUtf8("finalLine"));
        finalLine->setGeometry(QRect(250, 170, 211, 21));
        finalLine->setClearButtonEnabled(true);
        dayLine = new QLineEdit(plPlus_2);
        dayLine->setObjectName(QString::fromUtf8("dayLine"));
        dayLine->setGeometry(QRect(250, 210, 211, 21));
        dayLine->setClearButtonEnabled(true);
        reticketLine = new QLineEdit(plPlus_2);
        reticketLine->setObjectName(QString::fromUtf8("reticketLine"));
        reticketLine->setGeometry(QRect(250, 250, 211, 21));
        reticketLine->setClearButtonEnabled(true);
        peoLine = new QLineEdit(plPlus_2);
        peoLine->setObjectName(QString::fromUtf8("peoLine"));
        peoLine->setGeometry(QRect(250, 290, 211, 21));
        peoLine->setClearButtonEnabled(true);
        confirm_Plus = new QPushButton(plPlus_2);
        confirm_Plus->setObjectName(QString::fromUtf8("confirm_Plus"));
        confirm_Plus->setGeometry(QRect(640, 280, 121, 51));
        tabWidget->addTab(plPlus_2, QString());
        plUpd = new QWidget();
        plUpd->setObjectName(QString::fromUtf8("plUpd"));
        label_8 = new QLabel(plUpd);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(150, 50, 76, 33));
        label_8->setFont(font2);
        label_11 = new QLabel(plUpd);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(150, 130, 59, 33));
        label_11->setFont(font2);
        label_9 = new QLabel(plUpd);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(150, 220, 110, 33));
        label_9->setFont(font2);
        idoLine = new QLineEdit(plUpd);
        idoLine->setObjectName(QString::fromUtf8("idoLine"));
        idoLine->setGeometry(QRect(280, 50, 261, 41));
        idoLine->setClearButtonEnabled(true);
        valueLine = new QLineEdit(plUpd);
        valueLine->setObjectName(QString::fromUtf8("valueLine"));
        valueLine->setGeometry(QRect(280, 130, 261, 41));
        valueLine->setClearButtonEnabled(true);
        airnumLine2 = new QLineEdit(plUpd);
        airnumLine2->setObjectName(QString::fromUtf8("airnumLine2"));
        airnumLine2->setGeometry(QRect(280, 220, 261, 41));
        airnumLine2->setClearButtonEnabled(true);
        confirm_Up = new QPushButton(plUpd);
        confirm_Up->setObjectName(QString::fromUtf8("confirm_Up"));
        confirm_Up->setGeometry(QRect(640, 280, 121, 51));
        tabWidget->addTab(plUpd, QString());
        plDel = new QWidget();
        plDel->setObjectName(QString::fromUtf8("plDel"));
        label_10 = new QLabel(plDel);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(220, 130, 121, 41));
        label_10->setFont(font2);
        airnumLine3 = new QLineEdit(plDel);
        airnumLine3->setObjectName(QString::fromUtf8("airnumLine3"));
        airnumLine3->setGeometry(QRect(340, 130, 151, 41));
        airnumLine3->setClearButtonEnabled(true);
        confirm_Del = new QPushButton(plDel);
        confirm_Del->setObjectName(QString::fromUtf8("confirm_Del"));
        confirm_Del->setGeometry(QRect(640, 280, 121, 51));
        tabWidget->addTab(plDel, QString());
        admin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(admin);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        admin->setMenuBar(menubar);
        statusbar = new QStatusBar(admin);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        admin->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());

        retranslateUi(admin);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(admin);
    } // setupUi

    void retranslateUi(QMainWindow *admin)
    {
        admin->setWindowTitle(QCoreApplication::translate("admin", "\351\243\236\346\234\272\347\245\250\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        plShow->setText(QCoreApplication::translate("admin", "\350\210\252\347\217\255\344\277\241\346\201\257", nullptr));
        paShow->setText(QCoreApplication::translate("admin", "\344\271\230\345\256\242\344\277\241\346\201\257", nullptr));
        plPlus->setText(QCoreApplication::translate("admin", "\345\242\236\345\212\240\350\210\252\347\217\255", nullptr));
        plUpdate->setText(QCoreApplication::translate("admin", "\344\277\256\346\224\271\350\210\252\347\217\255", nullptr));
        plDelete->setText(QCoreApplication::translate("admin", "\345\210\240\351\231\244\350\210\252\347\217\255", nullptr));
        back_Choose->setText(QCoreApplication::translate("admin", "\350\277\224\345\233\236", nullptr));
        plainTextEdit->setPlainText(QString());
        tabWidget->setTabText(tabWidget->indexOf(plMess), QCoreApplication::translate("admin", "\350\210\252\347\217\255\344\277\241\346\201\257", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(paMess), QCoreApplication::translate("admin", "\344\271\230\345\256\242\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("admin", "\350\210\252\347\217\255\345\217\267 :", nullptr));
        label_2->setText(QCoreApplication::translate("admin", "\351\243\236\346\234\272\347\274\226\345\217\267 :", nullptr));
        label_3->setText(QCoreApplication::translate("admin", "\350\265\267\345\247\213\347\253\231 :", nullptr));
        label_4->setText(QCoreApplication::translate("admin", "\347\273\210\347\202\271\347\253\231 :", nullptr));
        label_5->setText(QCoreApplication::translate("admin", "\346\230\237\346\234\237:", nullptr));
        label_6->setText(QCoreApplication::translate("admin", "\350\275\275\345\256\242\351\207\217:", nullptr));
        label_7->setText(QCoreApplication::translate("admin", "\344\275\231\347\245\250\351\207\217:", nullptr));
        confirm_Plus->setText(QCoreApplication::translate("admin", "\347\241\256\350\256\244", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(plPlus_2), QCoreApplication::translate("admin", "\345\242\236\345\212\240\350\210\252\347\217\255", nullptr));
        label_8->setText(QCoreApplication::translate("admin", "\344\277\256\346\224\271\351\241\271\347\233\256 :", nullptr));
        label_11->setText(QCoreApplication::translate("admin", "\345\200\274\346\224\271\344\270\272 :", nullptr));
        label_9->setText(QCoreApplication::translate("admin", "\351\234\200\344\277\256\346\224\271\350\210\252\347\217\255\345\217\267 :", nullptr));
        confirm_Up->setText(QCoreApplication::translate("admin", "\347\241\256\350\256\244", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(plUpd), QCoreApplication::translate("admin", "\344\277\256\346\224\271\350\210\252\347\217\255", nullptr));
        label_10->setText(QCoreApplication::translate("admin", "\351\234\200\345\210\240\351\231\244\350\210\252\347\217\255\345\217\267 :", nullptr));
        confirm_Del->setText(QCoreApplication::translate("admin", "\347\241\256\350\256\244", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(plDel), QCoreApplication::translate("admin", "\345\210\240\351\231\244\350\210\252\347\217\255", nullptr));
        menu->setTitle(QCoreApplication::translate("admin", "\347\263\273\347\273\237", nullptr));
        menu_2->setTitle(QCoreApplication::translate("admin", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admin: public Ui_admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
