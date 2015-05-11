#ifndef NEWMERCHANDISE_H
#define NEWMERCHANDISE_H

#include <QWidget>
namespace Ui {
class newMerchandise;
}

class newMerchandise : public QWidget
{
    Q_OBJECT

public:
    explicit newMerchandise(QWidget *parent = 0);
    ~newMerchandise();

private slots:
    void on_add_clicked();

    void on_edit_clicked();

    void on_delete_2_clicked();

private:
    Ui::newMerchandise *ui;
    //declare map of merch
    //index
};

#endif // NEWMERCHANDISE_H
