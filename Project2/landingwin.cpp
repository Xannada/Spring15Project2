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

void LandingWin::on_EnterLink_linkActivated(const QString &link)
{
    MainWindow main;
    main.show();
    this->hide();

}
