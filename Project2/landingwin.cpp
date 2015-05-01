#include "landingwin.h"
#include "ui_landingwin.h"

LandingWin::LandingWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LandingWin)
{
    ui->setupUi(this);
    parnt = parent;
}

LandingWin::~LandingWin()
{
    delete ui;
    parnt->show();
}

void LandingWin::on_Enter_clicked()
{
//    main->show();
//    this->hide();
}
