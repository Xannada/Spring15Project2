#include "newmerchandise.h"
#include "ui_newmerchandise.h"

newMerchandise::newMerchandise(QString stadiumName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newMerchandise)
{
    ui->setupUi(this);
    stad = stadiumName;

    this->setWindowTitle("Merchandise Viewer");


    ui->merchList->setShowGrid(true);
    ui->merchList->setColumnCount(2);
    ui->merchList->setRowCount(0);
    ui->merchList->setEditTriggers(QAbstractItemView::NoEditTriggers);

    this->setTableItems();
}

void newMerchandise::setTableItems()
{
    ui->merchList->clear();
    QStringList headers;
    headers << "Name" << "Price";

    ui->merchList->setHorizontalHeaderLabels(headers);
    merchVec = merchandise.itemlist(stad);

    int size = merchVec.size();

    ui->merchList->setRowCount(size);


    for(unsigned int index = 0; index < merchVec.size(); index++)
    {
        QStringList merchFields;
        QString merchName = merchVec[index].name;
        QString merchPrice = QString::number(merchVec[index].price);
        merchFields << merchName << merchPrice;

        for (int column = 0; column < 2; column++)
        {
            QTableWidgetItem *newItem = new QTableWidgetItem(merchFields.at(column));
            ui->merchList->setItem(index, column, newItem);
        }
    }
}

newMerchandise::~newMerchandise()
{
    delete ui;
}

void newMerchandise::on_add_clicked()
{
    item temp;
    bool ok;
    temp.name = ui->newName->text();
    temp.price = ui->newPrice->text().toDouble(&ok);
    if(temp.name != "" && ok)
    {
        merchandise.additem(stad, temp);
    }
    else
    {
        QMessageBox::warning(this,"Error", "Error, item not added. Please check fields.");
    }
    ui->newName->clear();
    ui->newPrice->clear();
    this->setTableItems();
}

void newMerchandise::on_edit_clicked()
{
    QString temp;
    bool ok;
    double price;
    if(ui->merchList->currentItem() != NULL && ui->merchList->currentRow() >= 0)
    {
        int index = ui->merchList->currentRow();
        temp = ui->newName->text();
        if(temp != "")
            merchandise.changeName(stad,temp,index);

        temp = ui->newPrice->text();
        if(temp != "")
        {
            price = temp.toDouble(&ok);
            if(ok)
            {
                merchandise.changePrice(stad,price,index);

            }
        }
        ui->newName->clear();
        ui->newPrice->clear();
        this->setTableItems();
    }
}

void newMerchandise::on_delete_2_clicked()
{
    if(ui->merchList->currentItem() != NULL && ui->merchList->currentRow() >= 0)
    {
        int index = ui->merchList->currentRow();
        merchandise.deleteitem(stad,index);

        this->setTableItems();
    }
}
