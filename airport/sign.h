#ifndef SIGN_H
#define SIGN_H
#include "admin.h"
#include "user.h"
#include "mainwindow.h"
#include <QMainWindow>

namespace Ui {
class sign;
}

class sign : public QMainWindow
{
  Q_OBJECT

public:
  explicit sign(QWidget *parent = nullptr);
  ~sign();

private slots:
  void on_backMain_clicked();

  void on_paEnter_clicked();

  void on_adEnter_clicked();

private:
  Ui::sign *ui;
};

#endif // SIGN_H
