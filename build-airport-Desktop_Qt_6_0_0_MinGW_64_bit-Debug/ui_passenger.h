/********************************************************************************
** Form generated from reading UI file 'passenger.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSENGER_H
#define UI_PASSENGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_passenger
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *passenger)
    {
        if (passenger->objectName().isEmpty())
            passenger->setObjectName(QString::fromUtf8("passenger"));
        passenger->resize(800, 600);
        menubar = new QMenuBar(passenger);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        passenger->setMenuBar(menubar);
        centralwidget = new QWidget(passenger);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        passenger->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(passenger);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        passenger->setStatusBar(statusbar);

        retranslateUi(passenger);

        QMetaObject::connectSlotsByName(passenger);
    } // setupUi

    void retranslateUi(QMainWindow *passenger)
    {
        passenger->setWindowTitle(QCoreApplication::translate("passenger", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class passenger: public Ui_passenger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSENGER_H
