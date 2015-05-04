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

    this->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
