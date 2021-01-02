#include "mysqlit.h"
int ticketransfer;
mysqlit::mysqlit()
{
  QSqlDatabase database;
  if(QSqlDatabase::contains("qt_sql_default_connection"))
  {
    database = QSqlDatabase::database("qt_sql_default_connection");
  }
  else
  {
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbname = QString("./")+QString("plane.db");
    db.setDatabaseName(dbname);
  }
}
mysqlit::~mysqlit()
{
  db.close();
}

bool mysqlit::OpenDb(void)
{
  //打开数据库
  if(!db.open()){
    qDebug() << "连接数据失败！";
    return false;
  }
  qDebug() << "连接数据库成功";
  return true;
}

//判断数据库中某个数据表是否存在
bool mysqlit::IsTaBexists(QString& Tabname)
{
  QSqlDatabase db = QSqlDatabase::database();
  if(db.tables().contains(Tabname))
  {
    return true;
  }
  return false;
}

void mysqlit::createTable(void)
{
  //用于执行sql语句的对象
  QSqlQuery query;
  //构建创建数据库的sql语句字符串
  QString str1 = QString("create table passenger(NAME TEXT,ID TEXT,AIRNUM TEXT,TICKETNUM INTEGER,LEVEL INTEGER)");
  QString str2 = QString("create table planes(AIRNUM TEXT,PLANENUM TEXT,STARTSTATION TEXT,FINALSTATION TEXT,DAY TEXT,PEOPLE INTEGER,RETICKET INTEGER)");
  //执行sql语句
  query.exec(str1);
  query.exec(str2);
  qDebug() << "数据库创建成功";
}

void mysqlit::queryTable(QString tablename)//输出所有飞机信息乘客信息 管理员操作
{
  QSqlQuery query;
  //构建创建数据库的sql语句字符串
  QString str = QString("select * from ")+tablename;
  //执行sql语句,并将结果集保存到model
  query.exec(str);
  if(tablename == "passenger")
  {
    while(query.next())
    {
      QString name = query.value(0).toString();
      QString ID = query.value(1).toString();
      QString bookair = query.value(2).toString();
      int TICKET = query.value(3).toInt();
      int LEVEL = query.value(4).toInt();
      qDebug()<<QString("name:%1    id:%2    airnum:%3   ticket:%4    level:%5").arg(name).arg(ID).arg(bookair).arg(TICKET).arg(LEVEL);
    }
  }
  else if(tablename == "planes")
  {
    while(query.next())
    {
      QString startstation = query.value(2).toString();
      QString finalstation = query.value(3).toString();
      QString airnum = query.value(0).toString();
      QString planenum = query.value(1).toString();
      QString day = query.value(4).toString();
      int people = query.value(5).toInt();
      int retickt = query.value(6).toInt();
      qDebug()<<QString("airnum:%1    planenum:%2    startstation:%3   finalstation:%4    day:%5    people:%6    retickt:%7").arg(airnum).arg(planenum).arg(startstation).arg(finalstation).arg(day).arg(people).arg(retickt);
    }
  }
  qDebug() << "数据库查询成功";
}

void mysqlit::forUp(QString airname)//update ticket
{
  QSqlQuery query;
  //构建创建数据库的sql语句字符串
  query.prepare("select RETICKET from planes where AIRNUM = :AIRNUM");
  query.bindValue(":AIRNUM",airname);
  query.exec();
  query.next();
  ticketransfer = query.value(0).toInt();
  std::cout<<ticketransfer<<std::endl;
}

void mysqlit::queryTablepa(QString need)//查询某个乘客信息
{
  QSqlQuery query;
  QString st = QString("select * from passenger where ID = ")+need;
  query.exec(st);
  while(query.next())
  {
    QString name = query.value(0).toString();
    QString ID = query.value(1).toString();
    QString bookair = query.value(2).toString();
    int TICKET = query.value(3).toInt();
    int LEVEL = query.value(4).toInt();
    qDebug()<<QString("name:%1    id:%2    airnum:%3   ticket:%4    level:%5").arg(name).arg(ID).arg(bookair).arg(TICKET).arg(LEVEL);
  }
  qDebug()<<"check complete";
}

void mysqlit::passengerinsertdata(passenger &singledb)//乘客单插
{
  QSqlQuery query;
  query.prepare("INSERT INTO passenger VALUES (:NAME,:ID,:AIRNUM,:TICKETNUM,:LEVEL)");
  query.bindValue(":NAME", singledb.name);
  query.bindValue(":ID", singledb.ID);
  query.bindValue(":AIRNUM", singledb.bookair);
  query.bindValue(":TICKETNUM", singledb.ticket);
  query.bindValue(":LEVEL",singledb.level);
  query.exec();
}

void mysqlit::planeinsertdata(general &singledb)//飞机单插
{
  QSqlQuery query;
  query.prepare("INSERT INTO planes VALUES (:AIRNUM,:PLANENUM,:STARTSTATION,:FINALSTATION,:DAY,:PEOPLE,:RETICKET)");
  query.bindValue(":AIRNUM", singledb.airnum);
  query.bindValue(":PLANENUM", singledb.planenum);
  query.bindValue(":STARTSTATION", singledb.startstation);
  query.bindValue(":FINALSTATION",singledb.finalstation);
  query.bindValue(":DAY",singledb.day);
  query.bindValue(":PEOPLE",singledb.people);
  query.bindValue(":RETICKET",singledb.retickt);
  query.exec();
  qDebug() << "insert complete";
}

void mysqlit::deletedatapl(QString str)//删除航班
{
  QSqlQuery query;
  query.prepare("delete from planes where AIRNUM = :AIRNUM ");
  query.bindValue(":AIRNUM",str);
  query.exec();
  qDebug() << "delete complete";
}

void mysqlit::deletedatapa(QString id,QString airnum)//退票调用
{
  QSqlQuery query;
  query.prepare("delete from passenger where ID = :ID and AIRNUM = :AIRNUM");
  query.bindValue(":ID",id);
  query.bindValue(":AIRNUM",airnum);
  query.exec();
}
//修改
void mysqlit::updatedata(int ticket,QString airnum)//更新飞机数据加法
{
  QSqlQuery query;
  int reticket = ticketransfer - ticket;
  query.prepare("update planes set RETICKET = :RETICKET where AIRNUM = :AIRNUM");
  query.bindValue(":RETICKET",reticket);
  query.bindValue(":AIRNUM",airnum);
  query.exec();
}

void mysqlit::upDatepl(QString sign,QString value,QString airnum)
{
  QSqlQuery query;
  if(sign == "PLANENUM")
  {query.prepare("update planes set PLANENUM = :value where AIRNUM = :AIRNUM");
    query.bindValue(":value",value);
    query.bindValue(":AIRNUM",airnum);}
  else if(sign == "STARTSTATION")
  {query.prepare("update planes set STARTSTATION = :value where AIRNUM = :AIRNUM");
    query.bindValue(":value",value);
    query.bindValue(":AIRNUM",airnum);}
  else if(sign == "FINALSTATION")
  {query.prepare("update planes set FINALSTATION = :value where AIRNUM = :AIRNUM");
    query.bindValue(":value",value);
    query.bindValue(":AIRNUM",airnum);}
  else if(sign == "DAY")
  {query.prepare("update planes set DAY = :value where AIRNUM = :AIRNUM");
    query.bindValue(":value",value);
    query.bindValue(":AIRNUM",airnum);}
  else if(sign == "PEOPLE")
  {query.prepare("update planes set PEOPLE = :value where AIRNUM = :AIRNUM");
    query.bindValue(":value",value);
    query.bindValue(":AIRNUM",airnum);}
  else if(sign == "RETICKET")
  {query.prepare("update planes set RETICKET = :value where AIRNUM = :AIRNUM");
    query.bindValue(":value",value);
    query.bindValue(":AIRNUM",airnum);}
  query.exec();
  qDebug()<<"updata complete";
}

void mysqlit::closeDb(void)
{
  db.close();
}
