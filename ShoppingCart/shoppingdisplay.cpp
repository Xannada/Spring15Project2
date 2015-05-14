#include "shoppingdisplay.h"
#include "ui_shoppingdisplay.h"


ShoppingDisplay::ShoppingDisplay(QWidget *parent, int numItems, Heap<Item, QString> *heap) :
    QDialog(parent),
    ui(new Ui::ShoppingDisplay)
{
    defaultHeap = heap;
    ui->setupUi(this);
    tableWidget = new QTableWidget(numItems, 5, this);
    tableWidget->resize(600,300);
    tableWidget->setHorizontalHeaderLabels(QStringList() << "Item"
                                                         << "Stadium"
                                                         << "Unit Price"
                                                         << "Quantity"
                                                         << "Total");
    typeButton    = new QPushButton("Sort by Item Type");
    stadiumButton = new QPushButton("Sort by Stadium");
    priceButton   = new QPushButton("Sort by Price");
    box = new QVBoxLayout;
    box->addWidget(typeButton);
    box->addWidget(stadiumButton);
    box->addWidget(priceButton);
    box->addWidget(tableWidget);
    this->setLayout(box);
    on_typeButton_clicked();
    QObject::connect(typeButton, SIGNAL(clicked()),this, SLOT(on_typeButton_clicked()));
    QObject::connect(stadiumButton, SIGNAL(clicked()),this, SLOT(on_stadiumButton_clicked()));
    QObject::connect(priceButton, SIGNAL(clicked()),this, SLOT(on_priceButton_clicked()));
}

ShoppingDisplay::~ShoppingDisplay()
{
    delete ui;
}

void ShoppingDisplay::populateTable(Heap<Item, QString> *itemsHeap){
    int row = 0;
    int col = 0;
    int itemQuantity = 1;
    float itemTotal;
    bool duplicate;
    while(itemsHeap->size() > 0){
        QTableWidgetItem *type     = new QTableWidgetItem(itemsHeap->min().type);
        QTableWidgetItem *stadium  = new QTableWidgetItem(itemsHeap->min().stadium);
        QTableWidgetItem *price    = new QTableWidgetItem(QString::number(itemsHeap->min().price));
        itemsHeap->removeMin();
        do{
            if(itemsHeap->size() > 0){
                if(itemsHeap->min().type == type->text() && itemsHeap->min().stadium == stadium->text()){
                    ++itemQuantity;
                    itemsHeap->removeMin();
                    duplicate = true;
                }
                else{
                    duplicate = false;
                }
            }
        }while(itemsHeap->size() > 0 && duplicate);
        itemTotal = float(itemQuantity) * price->text().toFloat();
        QTableWidgetItem *quantity = new QTableWidgetItem(QString::number(itemQuantity));
        QTableWidgetItem *total    = new QTableWidgetItem(QString::number(itemTotal));
        tableWidget->setItem(row, col, type);
        tableWidget->setItem(row, ++col, stadium);
        tableWidget->setItem(row, ++col, price);
        tableWidget->setItem(row, ++col, quantity);
        tableWidget->setItem(row, ++col, total);
        col = 0;
        row++;
        itemQuantity = 1;
    }
}

void ShoppingDisplay::populateTable(Heap<Item, float> *itemsHeap){
    int row = 0;
    int col = 0;
    int itemQuantity = 1;
    float itemTotal;
    bool duplicate;
    while(itemsHeap->size() > 0){
        QTableWidgetItem *type     = new QTableWidgetItem(itemsHeap->min().type);
        QTableWidgetItem *stadium  = new QTableWidgetItem(itemsHeap->min().stadium);
        QTableWidgetItem *price    = new QTableWidgetItem(QString::number(itemsHeap->min().price));
        itemsHeap->removeMin();
        do{
            if(itemsHeap->size() > 0){
                if(itemsHeap->min().type == type->text() && itemsHeap->min().stadium == stadium->text()){
                    ++itemQuantity;
                    itemsHeap->removeMin();
                    duplicate = true;
                }
                else{
                    duplicate = false;
                }
            }
        }while(itemsHeap->size() > 0 && duplicate);
        itemTotal = float(itemQuantity) * price->text().toFloat();
        QTableWidgetItem *quantity = new QTableWidgetItem(QString::number(itemQuantity));
        QTableWidgetItem *total    = new QTableWidgetItem(QString::number(itemTotal));
        tableWidget->setItem(row, col, type);
        tableWidget->setItem(row, ++col, stadium);
        tableWidget->setItem(row, ++col, price);
        tableWidget->setItem(row, ++col, quantity);
        tableWidget->setItem(row, ++col, total);
        col = 0;
        row++;
        itemQuantity = 1;
    }
}

void ShoppingDisplay::on_stadiumButton_clicked(){
    Heap<Item, QString> *copyHeap = new Heap<Item, QString>;
    Heap<Item, QString> *newHeap  = new Heap<Item, QString>;
    copyHeap->populate(*defaultHeap);
    while(copyHeap->size() > 0){
        newHeap->insert(copyHeap->min(), copyHeap->min().stadium);
        copyHeap->removeMin();
    }
    populateTable(newHeap);

}

void ShoppingDisplay::on_typeButton_clicked(){
   Heap<Item, QString> *copyHeap = new Heap<Item, QString>;
   copyHeap->populate(*defaultHeap);
   populateTable(copyHeap);
}

void ShoppingDisplay::on_priceButton_clicked(){
    Heap<Item, QString> *copyHeap = new Heap<Item, QString>;
    Heap<Item, float> *newHeap  = new Heap<Item, float>;
    copyHeap->populate(*defaultHeap);
    while(copyHeap->size() > 0){
        newHeap->insert(copyHeap->min(), copyHeap->min().price);
        copyHeap->removeMin();
    }
    populateTable(newHeap);

}
