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
