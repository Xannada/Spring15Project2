#include "newmerchandise.h"
#include "ui_newmerchandise.h"

newMerchandise::newMerchandise(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newMerchandise)
{
    ui->setupUi(this);
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
