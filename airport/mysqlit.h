#ifndef MYSQLIT_H
#define MYSQLIT_H
#include "mainwindow.h"
#include "general.h"
#include <bits/stdc++.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>
#include <QtSql>
#include <QTextStream>
class mysqlit
{
public:
    mysqlit();
    ~mysqlit();
public:
    //创建数据库并建立连接
    bool OpenDb(void);
    //创建数据表（student）
    void createTable(void);
    //在表格中增加新的字段
    void addNewcolumn(QString &columnNameAndproperty);
    //查询和显示结果
    void queryTable(QString tablename);
    void forUp(QString airname);
    void queryTablepa(QString need);
    //判断数据表是否存在
    bool IsTaBexists(QString& Tabname);
    //插入数据
    void passengerinsertdata(passenger &singledb);//插入单条数据
    void planeinsertdata(general &singledb);
    //void Moreinsertdata(QList<passenger> &moredb);//插入多条数据
    //删除数据
    void deletedatapl(QString str);
    void deletedatapa(QString str,QString airnum);
    //修改数据
    void updatedata(int ticket,QString airnum);
    void upDatepl(QString sign,QString value,QString airnum);//admin
    //关闭数据库
    void closeDb(void);
private:
    QSqlDatabase db;//用于建立和数据库的连接
};

#endif // MYSQLIT_H
