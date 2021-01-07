#ifndef USER_H
#define USER_H
#include "sign.h"
#include "function.h"
#include <QMainWindow>
#include <QMessageBox>
namespace Ui {
class user;
}

class user : public QMainWindow
{
  Q_OBJECT

public:
  explicit user(QWidget *parent = nullptr);
  ~user();

private slots:
  void on_backChoose_clicked();
  void on_confirm_Book_clicked();
  void Book();
  void on_confirm_Refund_clicked();
  void Refund();
  void on_confirm_Check_clicked();
  void Check();
  void on_bookT_clicked();

  void on_refundT_clicked();

  void on_checkT_clicked();

private:
  Ui::user *ui;
};

#endif // USER_H
