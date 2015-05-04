#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->hide();
    LandingWin lander;
    lander.setModal(true);
    lander.exec();

    ui->menubar->show();

    this->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAdmin_Login_triggered()
{
    adminLogin = new AdminLogin;
    adminLogin->show();
}
