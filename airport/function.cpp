#include "function.h"

function::function(){}

void function::bookTicket(QString name,QString id,QString airnum,int ticket,int level)
{
    passenger pa;
    mysqlit book;
    pa.name = name;
    pa.ID = id;
    pa.bookair = airnum;
    pa.ticket = ticket;
    pa.level = level;
    int cmp = 0;
    cmp = book.forUppa(id,airnum,level);
    if(cmp == 0)
    {book.passengerinsertdata(pa);}
    else
    {
      book.upPaplus(ticket,airnum,id,level);
    }
    book.forUp(airnum);
    book.updatedata(ticket,airnum);
    qDebug()  <<"book complete";
}

void function::refundTicket(QString id,QString airnum,int ticket,int level)//退票做同步
{
  mysqlit refund;
  int cmp = refund.forUppa(id,airnum,level);
  refund.upPa(ticket,airnum,id,level);
  if(cmp == ticket)
  {
    refund.deletedatapa(id,airnum);
  }
  refund.forUp(airnum);
  refund.updatedataplus(ticket,airnum);
  qDebug()  <<"delete complete";
}

void function::checkTicket(QString id)
{
  mysqlit check;
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

void function::upData(QString sign,QString value,QString airnum)
{
  mysqlit up;
  up.upDatepl(sign,value,airnum);
}

void function::insertPl(QString airnum,QString planenum,QString startsta,QString finalsta,QString day,int people,int reticket)
{
  mysqlit pl;
  general gl;
  gl.airnum = airnum;
  gl.planenum = planenum;
  gl.startstation = startsta;
  gl.finalstation = finalsta;
  gl.day = day;
  gl.people = people;
  gl.retickt = reticket;
  pl.planeinsertdata(gl);
}

void function::deletePl(QString airnum)//航班删除做同步
{
  mysqlit dlt;
  dlt.deletedatapl(airnum);
}
