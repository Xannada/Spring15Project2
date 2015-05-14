#include "adminwindow.h"
#include "ui_adminwindow.h"

AdminWindow::AdminWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);

    stadium = merch.stadiumList();


    for (unsigned int index = 0; index < stadium.size(); index++)
    {
        ui->stadiumList->addItem(stadium[index]);
    }



}

AdminWindow::~AdminWindow()
{
    delete ui;
}


void AdminWindow::on_editMerch_clicked()
{

    if(ui->stadiumList->currentItem() != NULL)
    {
        QString temp;
        temp = ui->stadiumList->currentItem()->text();
        newMerch = new newMerchandise(temp);
        newMerch->show();
    }
    else
    {
        QMessageBox::information(this,"Error","Must select a stadium to edit its merchandise list.");
    }
}

void AdminWindow::on_okay_clicked()
{
    this->close();
}
