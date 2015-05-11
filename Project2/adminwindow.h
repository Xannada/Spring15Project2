#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include "newmerchandise.h"
//#include "adminlogin.h"
namespace Ui {
class AdminWindow;
}

class AdminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = 0);
    ~AdminWindow();

private slots:

    void on_editMerch_clicked();

private:
    Ui::AdminWindow *ui;
    newMerchandise *newMerch;

};

#endif // ADMINWINDOW_H
