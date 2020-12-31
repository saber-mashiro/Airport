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
  QString str1 = QString("create table passenger(NAME TEXT,ID TEXT,BOOKAIR TEXT,TICKETNUM INTEGER,LEVEL INTEGER)");
  QString str2 = QString("create table planes(AIRNUM TEXT,PLANENUM TEXT,STARTSTATION TEXT,FINALSTATION TEXT,DAY TEXT,PEOPLE INTEGER,RETICKET INTEGER)");
  //执行sql语句
  query.exec(str1);
  query.exec(str2);
  qDebug() << "数据库创建成功";
}

void mysqlit::queryTable(QString tablename)//输出所有飞机信息
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
      qDebug()<<QString("name:%1    id:%2    bookair:%3   ticket:%4    level:%5").arg(name).arg(ID).arg(bookair).arg(TICKET).arg(LEVEL);
    }
  }
  else if(tablename == "planes")
  {
    while(query.next())
    {
      QString startstation = query.value(0).toString();
      QString finalstation = query.value(1).toString();
      QString airnum = query.value(2).toString();
      QString planenum = query.value(3).toString();
      QString day = query.value(4).toString();
      int people = query.value(5).toInt();
      int retickt = query.value(6).toInt();
      qDebug()<<QString("startstation:%1    finalstation:%2    airnum:%3   planenum:%4    day:%5    people:%6    retickt:%7").arg(startstation).arg(finalstation).arg(airnum).arg(planenum).arg(day).arg(people).arg(retickt);
    }
  }
  qDebug() << "数据库查询成功";
}

void mysqlit::forUp(QString airname)//输出所有飞机信息
{
  QSqlQuery query;
  //构建创建数据库的sql语句字符串
  QString str = QString("select ")+airname+(" from planes");
  ticketransfer = query.value(6).toInt();

  //执行sql语句,并将结果集保存到model
  query.exec(str);

}

void mysqlit::queryTablepa(QString need)//字段匹配出对应乘客信息
{
  QSqlQuery query;
  QString st = QString("select ")+need+QString("from passenger");
  query.exec(st);
}

void mysqlit::passengerinsertdata(passenger &singledb)//乘客单插
{
  QSqlQuery query;
  query.prepare("INSERT INTO passenger VALUES (:NAME,:ID,:BOOKAIR,:TICKETNUM,:LEVEL)");
  query.bindValue(":NAME", singledb.name);
  query.bindValue(":ID", singledb.ID);
  query.bindValue(":BOOKAIR", singledb.bookair);
  query.bindValue(":TICKETNUM", singledb.ticket);
  query.bindValue(":LEVEL",singledb.level);
  query.exec();
}

void mysqlit::planeinsertdata(general &singledb)//飞机单插
{
  QSqlQuery query;
  query.prepare("INSERT INTO planes VALUES (:AIRNUM,:PLANENUM,:STARTSTATION,:FINALSTATION,:DAY:PEOPLE:RETICKET)");
  query.bindValue(":AIRNUM", singledb.airnum);
  query.bindValue(":PLANENUM", singledb.planenum);
  query.bindValue(":STARTSTATION", singledb.startstation);
  query.bindValue(":FINALSTATION",singledb.finalstation);
  query.bindValue(":DAY",singledb.day);
  query.bindValue(":PEOPLE",singledb.people);
  query.bindValue(":RETICKET",singledb.retickt);
  query.exec();
}

//update
//void mysqlit::Moreinsertdata(QList<passenger>& moredb)//乘客多插，挂了
//{
//    QSqlQuery query;
//    query.prepare("insert into passenger values (?,?,?,?,?,?,?,?)");
//    QVariantList idlist,snlist,typelist,MACAddrlsit,produceTimelist,Pieceslist,Operatorlist,OperateStatlist;
//    for(int i=0; i< moredb.size(); i++)
//    {
//        typelist << moredb.at(i).name;
//        typelist << moredb.at(i).ID;
//        idlist << moredb.at(i).ticket;
//        idlist << moredb.at(i).level;
//    }
//    query.addBindValue(idlist);
//    query.addBindValue(MACAddrlsit);
//    query.addBindValue(produceTimelist);

//    if (!query.execBatch())
//    {
//        qDebug() << query.lastError();
//    }
//}


void mysqlit::deletedatapl(QString str)
{
  QSqlQuery query;
  QString location =  QString("delete from planes where AIRNUM = ")+str;
  //    query.prepare("delete from planes where ID = 1");
  query.exec(location);
}

void mysqlit::deletedatapa(QString str)
{
  QSqlQuery query;
  QString location =  QString("delete from passenger where ID = ")+str;
  //    query.prepare("delete from planes where ID = 1");
  query.exec(location);
}
//修改
void mysqlit::updatedata(int newsen)
{
  QSqlQuery query;
  int tmp = ticketransfer - newsen;
  QString s = QString::number(tmp,10);
  QString ud = QString("set retickt = ")+s;
  //    query.prepare("update planes set name = \"QT\" where id = 1");
  query.exec(ud);
}

void mysqlit::closeDb(void)
{
  db.close();
}
