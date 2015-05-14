#include "teaminfo.h"
#include "ui_teaminfo.h"

TeamInfo::TeamInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeamInfo)
{
    ui->setupUi(this);
}

TeamInfo::~TeamInfo()
{
    delete ui;
}

void TeamInfo::on_teamS_clicked()
{

}

void TeamInfo::on_stadiumS_clicked()
{

}

void TeamInfo::on_leagueS_clicked()
{

}

void TeamInfo::on_seatingS_clicked()
{

}

void TeamInfo::on_dateS_clicked()
{

}
