#ifndef ADMIN_H
#define ADMIN_H
#include "sign.h"
#include <QMainWindow>

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

private:
  Ui::admin *ui;
};

#endif // ADMIN_H
