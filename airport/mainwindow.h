#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "sign.h"
#include <QMainWindow>
#include <QTextStream>
#include <QMessageBox>
#include <QCloseEvent>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  private slots:
    //void closeEvent( QCloseEvent * event );

    void on_enterSys_clicked();

    void on_exitsys_clicked();

  private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
