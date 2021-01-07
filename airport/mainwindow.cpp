#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
      , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  // connect(ui->pushButton,SIGNAL(on_pushButton_clicked()),this,SLOT(on_pushButton_clicked()));
}

MainWindow::~MainWindow()
{
  delete ui;
}


//void MainWindow::closeEvent( QCloseEvent * event )
//{
//  switch( QMessageBox::information( this, tr("退出系统"), tr("确认退出?"), tr("是"), tr("否"), 0, 1 ) )
//   {
//  case 0:
//    event->accept();
//    break;
//  case 1:
//  default:
//    event->ignore();
//    break;
//   }
//}

void MainWindow::on_enterSys_clicked()
{
  this->close();
  sign *siscreen = new sign();
  siscreen->show();
}

void MainWindow::on_exitsys_clicked()
{
  QApplication* ex = nullptr;
  ex->quit();
}
