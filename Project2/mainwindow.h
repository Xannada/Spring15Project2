#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "MainHeader.h"
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

private:
    Ui::MainWindow *ui;
    LandingWin *lander;
};

#endif // MAINWINDOW_H
