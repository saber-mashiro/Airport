#ifndef GENERAL_H
#define GENERAL_H
#include "mainwindow.h"
#include <QTextStream>
struct passenger
{
    QString name;//成员姓名
    QString ID;//身份id
    QString bookair;//订票航班号
    int ticket;//订票量
    int level;//订票舱等级
//    passenger(qstring a, long long b, int c) : name(a), ticket(b), level(c){}
};

class general
{
public:
    general();
    QString startstation;//起点站名
    QString finalstation;//终点站名
    QString airnum;//航班号
    QString planenum;//飞机号
    QString day;//飞机周日
    int people;//乘员定额
    int retickt;//余票量
};
#endif // GENERAL_H
