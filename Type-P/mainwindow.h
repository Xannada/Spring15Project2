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
#include <QDebug>

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

    //slots for buttons
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

    void on_cartBttn_clicked();

    void on_ToTeamInfo_clicked();

    void on_BacktoMain_clicked();

private:
    Ui::MainWindow *ui;

    //sql
    QSqlDatabase db;
    QSqlTableModel *tablemodel;
    QVariant tempvari;

    //merchandies disatance variables
    //map aka merc type variable
    Merc merchandise;

    //of type item represents each merchandise item, vector is relative to current stadium
    //and will output all merchandise for that stadium
    vector<item> merchVec;

    //is a stadium list used in admin window, and in some of the tours
    vector<QString> distTo;

    //used in admin window, specifies which stadium we are editing
    QString stadiumNametoEditMerc;

    //Shopping cart
    Heap<Item, QString> *defaultHeap;

    //MST
    MST *distmap;
    int traveldist;
    vector<dijknode> dikstras;

    //trip varies
    //specifies which stadium you are in the vectors,
    //used to traverse trip windows
    unsigned int currentTravelIndex;


    //used when user specifies where they want to start the custom trip at
    QString startStadium;

    //on buy will turn on or off the know when next button should be calling
    //buy table or custom buy relative to each seperate tour
    bool callRegularBuyTable;


    //choices is a subset of all the stadiums, might have to change parameter
    //to some kind of node object, to acceess distances once theyre up
    vector<QString> *choices;

    //private methods
    bool createConnection();

    //will create a table relative to sql database, will be able to show in
    //logical order
    void initializeModel(QSqlTableModel *model);

    //called through admin window, sets table for merchandise
    //according to stadium you want to edit
    void setMercTableItems();

    //populates table for heap aka shopping cart ordere by name
    void populateTable(Heap<Item, QString> *itemsHeap);

    //popuates table for heap aka shopping cart ordered by price
    void populateTable(Heap<Item, float> *itemsHeap);

    //buy table show merchandise while in trip to visit all stadiums
    //allows user to click what they want to buy, is created dynamically
    //to current Stadium
    void BuyTable();


    //custom buy shows merchandise tables for when you are in custom tours
    //allows user to chose merch and add to cart, and it relative to
    //current Stadium you are at
    void CustomBuy();


    //extra
    vector<QString> ToDoList;
    void toDoReminder();

};

#endif // MAINWINDOW_H
