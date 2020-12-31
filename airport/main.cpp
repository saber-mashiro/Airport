#include "mainwindow.h"
#include "general.h"
#include "mysqlit.h"
#include "function.h"
#include <QApplication>
#include <qdebug.h>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <bits/stdc++.h>
#include <QtSql>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QTextStream cin(stdin, QIODevice::ReadOnly);
    QTextStream cout(stdout, QIODevice::WriteOnly);
    function sys;
    mysqlit sql;
    sql.OpenDb();
    sys.bookTicket();
    sql.queryTable("passenger");
    sql.queryTable("planes");
    //sql.deletedatapa("122201");
    sql.closeDb();
    //w.show();
    return a.exec();
}