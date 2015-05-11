#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include <vector>
#include <QString>
#include "newmerchandise.h"
#include "merc.h"
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

    void on_okay_clicked();

private:
    Ui::AdminWindow *ui;
    newMerchandise *newMerch;
    Merc merch;
    vector<QString> stadium;

};

#endif // ADMINWINDOW_H
