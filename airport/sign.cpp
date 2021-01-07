#include "sign.h"
#include "ui_sign.h"

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
