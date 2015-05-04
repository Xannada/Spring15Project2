#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "MainHeader.h"
#include "adminlogin.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionAdmin_Login_triggered();

private:
    Ui::MainWindow *ui;
    AdminLogin *adminLogin;

};

#endif // MAINWINDOW_H
