#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->hide();
    lander = new LandingWin(this);
    lander->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
