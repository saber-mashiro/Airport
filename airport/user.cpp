#include "user.h"
#include "ui_user.h"

user::user(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::user)
{
  ui->setupUi(this);
//  connect(ui->confirm_Book,SIGNAL(clicked()),this,SLOT(on_confirm_Book_clicked()));
}

user::~user()
{
  delete ui;
}

void user::on_backChoose_clicked()
{
  this->close();
  sign *ba = new sign();
  ba->show();
}

void user::on_confirm_Book_clicked()
{
  Book();
  ui->nameLine->clear();
  ui->idLine->clear();
  ui->airnumLine->clear();
  ui->ticketLine->clear();
  ui->levelLine->clear();
  QMessageBox::information(this, "提示", "订票成功");
//  connect(ui->confirm_Book,SIGNAL(clicked()),this,SLOT(Book()));
}

void user::Book()
{
  function book;
  QString name = ui->nameLine->text();
  QString id = ui->idLine->text();
  QString airnum = ui->airnumLine->text();
  QString ticketnum = ui->ticketLine->text();
  QString level = ui->levelLine->text();
  int tctnum = ticketnum.toInt();
  int lvl = level.toInt();
  book.bookTicket(name,id,airnum,tctnum,lvl);
//  QMessageBox::information(this, "提示", "订票成功");
}

void user::on_confirm_Refund_clicked()
{
  Refund();
  ui->idLine2->clear();
  ui->airnumLine2->clear();
  ui->ticketLine2->clear();
  ui->levelLine2->clear();
  QMessageBox::information(this, "提示", "退票成功");
//    connect(ui->pushButton_8,SIGNAL(clicked()), this,SLOT(Refund()));
}

void user::Refund()
{
  function refund;
  QString id = ui->idLine2->text();
  QString airnum = ui->airnumLine2->text();
  QString ticketnum = ui->ticketLine2->text();
  QString level = ui->levelLine2->text();
  int tctnum = ticketnum.toInt();
  int lvl = level.toInt();
  refund.refundTicket(id,airnum,tctnum,lvl);
//    QMessageBox::information(this, "提示", "退票成功");
}

void user::on_confirm_Check_clicked()
{
  QString id = ui->idLine3->text();
  qmodel = new QSqlQueryModel();
  QString mes =QString("select * from passenger where ID = ")+id;
  qmodel->setQuery(mes);
  ui->checkAll->setModel(qmodel);
  ui->idLine3->clear();
  QMessageBox::information(this, "提示", "查询成功");
}

void user::on_bookT_clicked()
{
//  ui->tabWidget->clear();
  ui->refundTicket->close();
  ui->checkTicket->close();
  ui->bookTicket->show();
}

void user::on_refundT_clicked()
{
//    ui->tabWidget->clear();
  ui->bookTicket->close();
  ui->checkTicket->close();
  ui->refundTicket->show();
}

void user::on_checkT_clicked()
{
//    ui->tabWidget->clear();
  ui->bookTicket->close();
  ui->refundTicket->close();
  ui->checkTicket->show();
}
