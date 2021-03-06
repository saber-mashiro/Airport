#ifndef ADMIN_H
#define ADMIN_H
#include "sign.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QSqlQueryModel>
namespace Ui {
class admin;
}

class admin : public QMainWindow
{
  Q_OBJECT

public:
  explicit admin(QWidget *parent = nullptr);
  ~admin();

private slots:
  void on_back_Choose_clicked();

  void on_confirm_Plus_clicked();
  void Plus();
  void on_confirm_Up_clicked();
  void upDate();
  void on_confirm_Del_clicked();
  void Delete();
  void on_plShow_clicked();

  void on_paShow_clicked();

private:
  Ui::admin *ui;
  QSqlQueryModel *qmodel;
};

#endif // ADMIN_H
