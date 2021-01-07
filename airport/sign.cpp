#include "sign.h"
#include "ui_sign.h"
//#include "mainwindow.h"
sign::sign(QWidget *parent)
    :QMainWindow(parent)
    ,ui(new Ui::sign)
{
  ui->setupUi(this);
}

sign::~sign()
{
  delete ui;
}

void sign::on_backMain_clicked()
{
  this->close();
  MainWindow *backfirst = new MainWindow();
  backfirst->show();
}

void sign::on_paEnter_clicked()
{
  this->close();
  user *pa = new user();
  pa->show();
}

void sign::on_adEnter_clicked()
{
  this->close();
  admin *pl = new admin();
  pl->show();
}
