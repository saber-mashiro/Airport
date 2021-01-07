#include "admin.h"
#include "ui_admin.h"

admin::admin(QWidget *parent) :
                                QMainWindow(parent),
                                ui(new Ui::admin)
{
  ui->setupUi(this);
}

admin::~admin()
{
  delete ui;
}

void admin::on_back_Choose_clicked()
{
  this->close();
  sign *ba = new sign();
  ba->show();
}

void admin::on_confirm_Plus_clicked()
{
  Plus();
  ui->airnumLine->clear();
  ui->planeLine->clear();
  ui->startLine->clear();
  ui->finalLine->clear();
  ui->dayLine->clear();
  ui->reticketLine->clear();
  ui->peoLine->clear();
  QMessageBox::information(this, "提示", "增加成功");
}

void admin::Plus()
{
  function plus;
  QString airnum = ui->airnumLine->text();
  QString planenum =  ui->planeLine->text();
  QString startsta =  ui->startLine->text();
  QString finalsta =  ui->finalLine->text();
  QString day =  ui->dayLine->text();
  QString reticket =  ui->reticketLine->text();
  QString people =  ui->peoLine->text();
  int ret = reticket.toInt();
  int peop = people.toInt();
  plus.insertPl(airnum,planenum,startsta,finalsta,day,peop,ret);
}

void admin::on_confirm_Up_clicked()
{
  upDate();
  ui->idoLine->clear();
  ui->airnumLine2->clear();
  ui->valueLine->clear();
  QMessageBox::information(this, "提示", "更新成功");
}

void admin::upDate()
{
  function upd;
  QString ido = ui->idoLine->text();
  QString airnum = ui->airnumLine2->text();
  QString value = ui->valueLine->text();
  upd.upData(ido,value,airnum);
}

void admin::on_confirm_Del_clicked()
{
  Delete();
  ui->airnumLine3->clear();
  QMessageBox::information(this, "提示", "删除成功");
}

void admin::Delete()
{
  function del;
  QString airnum = ui->airnumLine3->text();
  del.deletePl(airnum);
}

void admin::on_plShow_clicked()
{
  qmodel = new QSqlQueryModel();
  qmodel->setQuery("select * from planes");
  ui->plAll->setModel(qmodel);
}

void admin::on_paShow_clicked()
{
  qmodel = new QSqlQueryModel();
  qmodel->setQuery("select * from passenger");
  ui->paall->setModel(qmodel);
}
