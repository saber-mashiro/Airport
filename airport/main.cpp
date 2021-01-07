#include "mainwindow.h"
#include "general.h"
#include "mysqlit.h"
#include "function.h"
#include "sign.h"
#include "admin.h"
#include "user.h"
//#include <QTextCodec>
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
  sign s;
  admin ad;
  user us;
  QTextStream cin(stdin, QIODevice::ReadOnly);
  QTextStream cout(stdout, QIODevice::WriteOnly);
//  QTextCodec *codec = QTextCodec::codecForName("UTF-8");
//  QTextCodec::setCodecForLocale(codec);
  function sys;
  mysqlit sql;
//  sql.OpenDb();
//  sql.closeDb();
  w.show();
  return a.exec();
}
