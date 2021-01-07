#ifndef USER_H
#define USER_H
#include "sign.h"
#include <QMainWindow>

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

private:
  Ui::user *ui;
};

#endif // USER_H
