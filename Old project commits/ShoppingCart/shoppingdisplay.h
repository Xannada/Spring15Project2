#ifndef SHOPPINGDISPLAY_H
#define SHOPPINGDISPLAY_H
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include "heap.h"
#include "item.h"
namespace Ui {
class ShoppingDisplay;
}



class ShoppingDisplay : public QDialog
{
    Q_OBJECT

public:
    explicit ShoppingDisplay(QWidget *parent = 0, int numItems = 0, Heap<Item, QString> *heap = 0);
    ~ShoppingDisplay();
    void populateTable(Heap<Item, QString> *itemsHeap);
    void populateTable(Heap<Item, float> *itemsHeap);
    void setHeap(Heap<Item, QString> &itemsHeap);
    void setHeap(Heap<Item, float>   &itemsHeap);

private slots:
    void on_stadiumButton_clicked();
    void on_typeButton_clicked();
    void on_priceButton_clicked();

private:
    Ui::ShoppingDisplay *ui;
    Heap<Item, QString> *defaultHeap;
    QTableWidget *tableWidget;
    QPushButton  *typeButton;
    QPushButton  *stadiumButton;
    QPushButton  *priceButton;
    QVBoxLayout  *box;
};

#endif // SHOPPINGDISPLAY_H
