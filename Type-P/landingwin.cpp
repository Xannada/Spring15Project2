#include "landingwin.h"
#include "ui_landingwin.h"

LandingWin::LandingWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LandingWin)
{
    ui->setupUi(this);
}

LandingWin::~LandingWin()
{
    delete ui;
}

void LandingWin::on_Enter_clicked()
{
    this->close();
}
