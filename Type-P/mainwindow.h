#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QtWidgets>
#include <QtSql>
#include <QDialog>
#include <vector>
#include <QString>

#include "landingwin.h"
#include "merc.h"
#include "heap.h"
#include "mst.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_TeamInfo_clicked();

    void on_login_clicked();

    void on_Admin_clicked();

    void on_BacktoMain1_clicked();

    void on_add_clicked();

    void on_edit_clicked();

    void on_delete_2_clicked();

    void on_LogOut_clicked();

    void on_BacktoMain2_clicked();

    void on_ToTripPage_clicked();

    void on_EditMercDist_clicked();

    void on_CheckConnection_clicked();

    void on_UpdateDistance_clicked();

    void on_SaveAndBack_clicked();

    void on_ToTripPage2_clicked();

    void on_BacktoMain3_clicked();

    void on_cart_clicked();

    void on_stadiumButton_clicked();

    void on_priceButton_clicked();

    void on_typeButton_clicked();

    void on_PlanTour_clicked();

    void on_newStadium_clicked();


    void on_visitAllBttn_clicked();

    void on_angelsBttn_clicked();

    void on_customBttn_clicked();

    void on_next_clicked();

    void on_buy_clicked();


    void on_go_clicked();

    void on_go2_clicked();

private:
    Ui::MainWindow *ui;
    //sql
    QSqlDatabase db;
    QSqlTableModel *tablemodel;
    QVariant tempvari;
    //merchandies disatance variables
    //map aka merc type variable
    Merc merchandise;
    vector<item> merchVec;
    vector<QString> distTo;
    QString stadiumNametoEditMerc;

    //Shopping cart
    Heap<Item, QString> *defaultHeap;

    //MST
    MST *distmap;

    //private methods
    bool createConnection();
    void initializeModel(QSqlTableModel *model);
    void setMercTableItems();
    void populateTable(Heap<Item, QString> *itemsHeap);
    void populateTable(Heap<Item, float> *itemsHeap);

    void BuyTable();
    void CustomBuy();
    int currentTravelIndex;
    QString startStadium;
    bool onBuy;
    vector<QString> *choices;

};

#endif // MAINWINDOW_H
