#include "newmerchandise.h"
#include "ui_newmerchandise.h"

newMerchandise::newMerchandise(QString stadiumName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newMerchandise)
{
    ui->setupUi(this);
    stad = stadiumName;

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

        //ui->merchList->setItem(index+1,1,merchVec[index].name);
        //ui->merchList->setItem(index+1,2,merchVec[index].price);
    }






}

newMerchandise::~newMerchandise()
{
    delete ui;
}

void newMerchandise::on_add_clicked()
{

}

void newMerchandise::on_edit_clicked()
{

}

void newMerchandise::on_delete_2_clicked()
{

}
