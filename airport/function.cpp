#include "function.h"
#include "general.h"
#include "mysqlit.h"
#include "mainwindow.h"
#include <bits/stdc++.h>

function::function(){}

void function::bookTicket()
{
    passenger pa;
    mysqlit book;
    std::string tmp;
    //QTextStream cin(stdin, QIODevice::ReadOnly);
    //QTextStream cout(stdout, QIODevice::WriteOnly);
    int ticket = 0;
    int level = 0;
    std::cout<<"please enter your name:"<<std::endl;
    std::cin>>tmp;
    QString st1 = QString::fromStdString(tmp);
    pa.name = st1;

    std::cout<<"please enter your ID:"<<std::endl;
    std::cin>>tmp;
    QString st2 = QString::fromStdString(tmp);
    pa.ID = st2;

    std::cout<<"please enter the airnum:"<<std::endl;
    std::cin>>tmp;
    QString st3 = QString::fromStdString(tmp);
    pa.bookair = st3;

    std::cout<<"please enter the ticketnum:"<<std::endl;
    std::cin>>ticket;
    pa.ticket = ticket;

    std::cout<<"please enter the level of plane:"<<std::endl;
    std::cin>>level;
    pa.level = level;

    book.passengerinsertdata(pa);
    book.forUp(st3);
    book.updatedata(ticket);
}
