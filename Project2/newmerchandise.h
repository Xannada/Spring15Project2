#ifndef NEWMERCHANDISE_H
#define NEWMERCHANDISE_H

#include <QWidget>
#include "merc.h"
namespace Ui {
class newMerchandise;
}

class newMerchandise : public QWidget
{
    Q_OBJECT

public:
    void setTableItems();
    explicit newMerchandise(QString stadiumName, QWidget *parent = 0);
    ~newMerchandise();

private slots:
    void on_add_clicked();

    void on_edit_clicked();

    void on_delete_2_clicked();

private:
    Ui::newMerchandise *ui;
    Merc merchandise;
    vector<item> merchVec;
    QString stad;
};

#endif // NEWMERCHANDISE_H
