#include "user.h"
#include "ui_user.h"

user::user(QWidget *parent) :
                              QMainWindow(parent),
                              ui(new Ui::user)
{
  ui->setupUi(this);
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
