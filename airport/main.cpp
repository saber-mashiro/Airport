#include "mainwindow.h"
#include "general.h"
#include "mysqlit.h"
#include "function.h"
#include "sign.h"
#include "admin.h"
#include "user.h"
#include <QApplication>
#include <qdebug.h>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <bits/stdc++.h>
#include <QtSql>
//#include <QTextCodec>
int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  mysqlit sql;
  sql.OpenDb();
  w.show();
  return a.exec();
}
