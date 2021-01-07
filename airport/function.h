#ifndef FUNCTION_H
#define FUNCTION_H
#include <QTextStream>
#include "general.h"
#include "mysqlit.h"
#include "user.h"
#include "mainwindow.h"
#include <bits/stdc++.h>
class function
{
public:
    function();
    //passenger
    void bookTicket(QString name,QString id,QString airnum,int ticket,int level);//订票
    void refundTicket(QString id,QString airnum,int ticket,int level);//退票
    void checkTicket(QString id);//查询自己的订票
    //void checkFinalstation();//订票查询目的地
    //planes
    void showPlanes();//显示所有航班信息
    void upData(QString sign,QString value,QString airnum);//修改某航班信息
    void showPassenger();//显示所有乘客信息
    void insertPl(QString airnum,QString planenum,QString startsta,QString finalsta,QString day,int people,int reticket);//admin 插入飞机信息
    void deletePl(QString airnum);
};

#endif // FUNCTION_H
