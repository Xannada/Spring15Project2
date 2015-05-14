#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "adminlogin.h"
//#include "adminwindow.h"
#include "landingwin.h"
#include "teaminfo.h"

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

    void on_TeamInfo_clicked();

private:
    Ui::MainWindow *ui;
    AdminLogin *adminLogin;
    TeamInfo *teamInfo;

};

#endif // MAINWINDOW_H
