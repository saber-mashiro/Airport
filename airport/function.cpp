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
    book.updatedata(ticket,st3);
    qDebug()  <<"book complete";
}

void function::refundTicket()
{
  mysqlit refund;
  int ticket;
  std::string tmp;
  std::cout<<"please enter your ID:"<<std::endl;
  std::cin>>tmp;
  QString id = QString::fromStdString(tmp);
  std::cout<<"please enter the airnum to refund:"<<std::endl;
  std::cin>>tmp;
  QString bookair = QString::fromStdString(tmp);
  std::cout<<"please enter the ticket to refund:"<<std::endl;
  std::cin>>ticket;

  qDebug()  <<"delete complete";
}

void function::checkTicket()
{
  mysqlit check;
  std::string tmp;
  std::cout<<"please enter your ID:"<<std::endl;
  std::cin>>tmp;
  QString id = QString::fromStdString(tmp);
  check.queryTablepa(id);
}

void function::showPlanes()
{
  mysqlit showpl;
  showpl.queryTable("planes");
}

void function::showPassenger()
{
  mysqlit showpa;
  showpa.queryTable("passenger");
}

void function::upData()
{
  mysqlit up;
  std::string tmp;
  std::cout<<"please enter the sign:"<<std::endl;
  std::cin>>tmp;
  QString sign = QString::fromStdString(tmp);
  std::cout<<"please enter the value:"<<std::endl;
  std::cin>>tmp;
  QString value = QString::fromStdString(tmp);
  std::cout<<"please enter the airnum:"<<std::endl;
  std::cin>>tmp;
  QString air = QString::fromStdString(tmp);
  up.upDatepl(sign,value,air);
}

void function::insertPl()
{
  mysqlit pl;
  general gl;
  std::string tmp;
  int persenal = 1000;
  int rest = 1000;
  //QTextStream cin(stdin, QIODevice::ReadOnly);
  //QTextStream cout(stdout, QIODevice::WriteOnly);
  std::cout<<"please enter airnum:"<<std::endl;
  std::cin>>tmp;
  QString arnum = QString::fromStdString(tmp);
  gl.airnum = arnum;

  std::cout<<"please enter planenum:"<<std::endl;
  std::cin>>tmp;
  QString plnum = QString::fromStdString(tmp);
  gl.planenum = plnum;

  std::cout<<"please enter startstation:"<<std::endl;
  std::cin>>tmp;
  QString ststation = QString::fromStdString(tmp);
  gl.startstation = ststation;

  std::cout<<"please enter finalstation:"<<std::endl;
  std::cin>>tmp;
  QString flstation = QString::fromStdString(tmp);
  gl.finalstation = flstation;

  std::cout<<"please enter day:"<<std::endl;
  std::cin>>tmp;
  QString days = QString::fromStdString(tmp);
  gl.day = days;

  std::cout<<"please enter people:"<<std::endl;
  std::cin>>persenal;
  gl.people = persenal;

  std::cout<<"please enter reticket:"<<std::endl;
  std::cin>>rest;
//  QString days = QString::fromStdString(tmp);
  gl.retickt = rest;
  pl.planeinsertdata(gl);
}

void function::deletePl()
{
  mysqlit dlt;
  std::string tmp;
  std::cout<<"please enter airnum:"<<std::endl;
  std::cin>>tmp;
  QString airnum = QString::fromStdString(tmp);
  dlt.deletedatapl(airnum);
}
