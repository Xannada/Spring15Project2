#include "adminlogin.h"
#include "ui_adminlogin.h"

AdminLogin::AdminLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminLogin)
{
    ui->setupUi(this);
}

AdminLogin::~AdminLogin()
{
    delete ui;
}

void AdminLogin::on_login_clicked()
{
     QString password = ui->password->text();
     QString username = ui->username->text();

     if(username == "admin" && password == "meowistheword")
     {
         AdminWindow *w = new AdminWindow;
         w->show();
         this->close();
     }
     else
     {
        QMessageBox *denied = new QMessageBox;
        denied->setText("Wrong password, try Again");
        denied->exec();
     }

}
