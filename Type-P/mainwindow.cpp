#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->hide();
    setCentralWidget(ui->MainStack);

    if(createConnection())
    {
        tablemodel = new QSqlTableModel(0,db);
        initializeModel(tablemodel);
    }
    ui->MainStack->setCurrentIndex(0);

    defaultHeap = 0;

    ui->CartDisplay->setShowGrid(true);
    ui->CartDisplay->setColumnCount(5);
    ui->CartDisplay->setRowCount(0);
    ui->CartDisplay->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->CartDisplay->setHorizontalHeaderLabels(QStringList() << "Item"
                                                             << "Stadium"
                                                             << "Unit Price"
                                                             << "Quantity"
                                                             << "Total");

//    //cart is breaking, for testing...causes crash
//    Item q;
//    q.set(5,25.99,"Baseball cap","Fenway Park");
//    Item b;
//    b.set(1,35.35,"Baseball bat","Dodger Stadium");
//    Item c;
//    c.set(2,12.99,"Team pennant","Rogers Centre");
//    Item d;
//    d.set(7,19.99,"Autographed baseball","Rogers Centre");
//    Item e;
//    e.set(7,19.99,"Autographed baseball","Rogers Centre");
//    Item f;
//    f.set(7,19.99,"Autographed baseball","Rogers Centre");

//    defaultHeap->insert(q, q.type);
//    defaultHeap->insert(b, b.type);
//    defaultHeap->insert(c, c.type);
//    defaultHeap->insert(d, d.type);
//    defaultHeap->insert(e, e.type);
//    defaultHeap->insert(f, f.type);



    LandingWin lander;
    lander.setModal(true);
    lander.exec();

    this->show();
}

MainWindow::~MainWindow()
{
    merchandise.SavetoFile();
    delete ui;
    delete tablemodel;
}

void MainWindow::on_TeamInfo_clicked()
{
    ui->MainStack->setCurrentIndex(ui->MainStack->indexOf(ui->TeamInfoPage));
    ui->TeamInfoTable->setModel(tablemodel);
    ui->TeamInfoTable->show();
}


bool MainWindow::createConnection()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("databaseNameFile");
    if (!db.open()) {
        QMessageBox::critical(0, qApp->tr("Cannot open database"),
            qApp->tr("Unable to establish a database connection.\n"
                     "This example needs SQLite support."
                     "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }

    QSqlQuery query;

    query.exec("create table stadium (stadiumName varchar(40) primary key, "
                   "teamName varchar(40), address varchar(80), phone varchar(20), "
                   "dateopened varchar(30), seatingCap varchar(50), Grass varchar(10), "
                   "League varchar(15))");

    query.exec("insert into stadium values('Angels Stadium of Anaheim', 'Los Angeles Angels of Anaheim', '2000 E Gene Autry Way\nAnaheim, CA 92806', '(714) 940-2000', '1966 April 19', '45,483', 'Grass', 'American')");
    query.exec("insert into stadium values('Comerica Park','Detroit Tigers','2100 Woodward Ave\nDetroit, MI 48201','(313) 962-4000','2000 April 11','41,681','Grass','American')");
    query.exec("insert into stadium values('Fenway Park','Boston Red Sox','4 Yawkey Way\nBoston, MA 02215','(877) 733-7699','1912 April 20','37,499 (night) & 37,071 (day)','Grass','American')");
    query.exec("insert into stadium values('Globe Life Park in Arlington','Texas Rangers','1000 Ballpark Way\nArlington, TX 76011','(817) 273-5222','1994 April 1','48,114','Grass','American')");
    query.exec("insert into stadium values('Kauffman Stadium','Kansas City Royals','1 Royal Way\nKansas City, MO 64129','(816) 921-8000','1973 April 10','37,903','Grass','American')");
    query.exec("insert into stadium values('Minute Maid Park','Houston Astros','501 Crawford St\nHouston, TX 77002','(713) 259-8000','2000 May 30','42,060','Grass','American')");
    query.exec("insert into stadium values('O.co Coliseum','Oakland Athletics','7000 Coliseum Way\nOakland, CA 94621','(510) 569-2121','1966 September 18','37,090 (April - August) & 55,945 (Sept - Jan)','Grass','American')");
    query.exec("insert into stadium values('Oriole Park at Camden Yards','Baltimore Orioles','333 West Camden Street\nBaltimore, MD 21201','(410) 685-9800','1992 April 6','48,187','Grass','American')");
    query.exec("insert into stadium values('Progressive Field','Cleveland Indians','2401 Ontario Street\nCleveland, OH 44115','(216) 420-4487','1994 April 2','42,404','Grass','American')");
    query.exec("insert into stadium values('Rogers Centre','Toronto Blue Jays','1 Blue Jays Way\nToronto, Ontario, Canada M5V1J3','+1 416-341-1000','1989 June 3','49,282','Turf','American')");
    query.exec("insert into stadium values('SafeCo Field','Seattle Mariners','1516 First Avenue South\nSeattle, WA 98134','(206) 346-4000','1999 July 15','47,476','Grass','American')");
    query.exec("insert into stadium values('Target Field','Minnesota Twins','353 N 5th St\nMinneapolis, MN 55403','(800) 338-9467','2010 April 12','39,021','Grass','American')");
    query.exec("insert into stadium values('Tropicana Field','Tampa Bay Rays','1 Tropicana Dr\nSt. Petersburg, FL 33705','(727) 825-3137','1990 March 3','31,042 (Regular Season) 42,735 (Postseason)','Turf','American')");
    query.exec("insert into stadium values('US Cellular Field','Chicago White Sox','333 West 35th Street\nChicago, IL 60616','(312) 674-1000','1991 April 18','40,615','Grass','American')");
    query.exec("insert into stadium values('Yankee Stadium','New York Yankees','1 E 161st St\nSouth Bronx, NY 10451','(718) 293-4300','2009 April 16','50,291','Grass','American')");
    query.exec("insert into stadium values('AT&T Park','San Francisco Giants','24 Willie Mays Plaza\nSan Francisco, CA 94107','(415) 972-2000','2000 April 11','41,915','Grass','National')");
    query.exec("insert into stadium values('Busch Stadium','St. Louis Cardinals','700 Clark Street\nSt. Louis, MO 63102','(314) 345-9600','2006 April 10','46,861','Grass','National')");
    query.exec("insert into stadium values('Chase Field','Arizona Diamondbacks','401 East Jefferson Street\nPhoenix, AZ 85004','(602) 462-6500','1998 March 31','48,633','Grass','National')");
    query.exec("insert into stadium values('Citi Field','New York Mets','126th St. & Roosevelt Ave.\nQueens, NY 11368','(718) 507-6387','2009 April 13','41,922','Grass','National')");
    query.exec("insert into stadium values('Citizens Bank Park','Philadelphia Phillies','1 Citizens Bank Way\nPhiladelphia, PA 19148','(215) 463-1000','2004 April 3','43,651','Grass','National')");
    query.exec("insert into stadium values('Coors Field','Colorado Rockies','2001 Blake St\nDenver, CO 80205','(303) 292-0200','1995 April 26','50,480','Grass','National')");
    query.exec("insert into stadium values('Dodger Stadium','Los Angeles Dodgers','1000 Elysian Park Avenue\nLos Angeles, CA 90090','(323) 224-1507','1962 April 10','56,000','Grass','National')");
    query.exec("insert into stadium values('Great America Ball Park','Cincinnati Reds','100 Joe Nuxhall Way\nCincinnati, OH 45202','(513) 381-7337','2003 March 31','42,319','Grass','National')");
    query.exec("insert into stadium values('Marlins Park','Miami Marlins','501 Marlins Way\nMiami, FL 33125','(305)480-1300','2012 April 4','37,442','Grass','National')");
    query.exec("insert into stadium values('Miller Park','Milwaukee Brewers','1 Brewers Way\nMilwaukee, WI 53214','(414) 902-4400','2001 April 6','41,900','Grass','National')");
    query.exec("insert into stadium values('Nationals Park','Washington Nationals','1500 S Capitol St SE\nWashington, DC 20003','(202) 675-6287','2008 March 30','41,418','Grass','National')");
    query.exec("insert into stadium values('Petco Park','San Diego Padres','19 Tony Gwynn Drive\nSan Diego, CA 92101','(619) 795-5000','2004 April 8','42,524','Grass','National')");
    query.exec("insert into stadium values('PNC Park','Pittsburgh Pirates','115 Federal St\nPittsburgh, PA 15212','(412) 321-2827','2002 March 31','38,362','Grass','National')");
    query.exec("insert into stadium values('Turner Field ','Atlanta Braves','755 Hank Aaron Drive\nAtlanta, GA 30315','(404) 522-7630','1997 March 29','49,586','Grass','National')");
    query.exec("insert into stadium values('Wrigley Field','Chicago Cubs','1060 West Addison Street\nChicago, IL 60613','(773) 404-2827','1914 April 23','42,374','Grass','National')");


    return true;
}

void MainWindow::initializeModel(QSqlTableModel *model)
{
    model->setTable("stadium");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Stadium Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Team name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Address"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Phone"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date Opened"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Seating Capacity"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Grass"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("League"));
}

void MainWindow::on_login_clicked()
{
    QString password = ui->password->text();
    QString username = ui->username->text();

    if(username == "admin" && password == "meowistheword")
    {
        ui->password->clear();
        ui->username->clear();
        ui->TeamEdit->setModel(tablemodel);
        ui->TeamEdit->show();
        ui->MainStack->setCurrentIndex(ui->MainStack->indexOf(ui->AdminPage));
    }
    else
    {
       QMessageBox *denied = new QMessageBox;
       denied->setText("Wrong password, try Again");
       denied->exec();
    }
}

void MainWindow::on_Admin_clicked()
{

    ui->MainStack->setCurrentIndex(ui->MainStack->indexOf(ui->AdminLoginPage));
}

void MainWindow::on_BacktoMain1_clicked()
{
    ui->MainStack->setCurrentIndex(0);
}

void MainWindow::on_LogOut_clicked()
{
    ui->MainStack->setCurrentIndex(0);
}

void MainWindow::on_BacktoMain2_clicked()
{
    ui->MainStack->setCurrentIndex(0);
}

void MainWindow::on_ToTripPage_clicked()
{
    ui->MainStack->setCurrentIndex(ui->MainStack->indexOf(ui->TripPage));
}

void MainWindow::on_EditMercDist_clicked()
{
    QSqlQuery query;
    QModelIndex ind = ui->TeamEdit->currentIndex();

    //need to get the index and then query for stadium name
//    tempvari = query.value(ind);
//    tempvari.convert()
//    stadiumNametoEditMerc =

    ui->MainStack->setCurrentIndex(ui->MainStack->indexOf(ui->MerchandiseEdit));
    ui->editinglabel->setText(stadiumNametoEditMerc);

//for merchandise table
    ui->merchList->setShowGrid(true);
    ui->merchList->setColumnCount(2);
    ui->merchList->setRowCount(0);
    ui->merchList->setEditTriggers(QAbstractItemView::NoEditTriggers);

    this->setMercTableItems();

//for distance editing
    ui->distList->clear();
    distTo = merchandise.stadiumList();

    for (unsigned int index = 0; index < distTo.size(); index++)
    {
        ui->distList->addItem(distTo[index]);
    }
}

void MainWindow::setMercTableItems()
{
    ui->merchList->clear();
    QStringList headers;
    headers << "Name" << "Price";

    ui->merchList->setHorizontalHeaderLabels(headers);
    merchVec = merchandise.itemlist(stadiumNametoEditMerc);

    ui->merchList->setRowCount(merchVec.size());

    //index used synonymously for row
    for(unsigned int index = 0; index < merchVec.size(); index++)
    {
        QStringList merchFields;
//        QString merchName = ;
        QString merchPrice = QString::number(merchVec[index].price);
        merchFields << merchVec[index].name << merchPrice;

        for (int column = 0; column < 2; column++)
        {
            QTableWidgetItem *newItem = new QTableWidgetItem(merchFields.at(column));
            ui->merchList->setItem(index, column, newItem);
        }
    }
}

void MainWindow::on_add_clicked()
{
    item temp;
    bool ok;
    temp.name = ui->newName->text();
    temp.price = ui->newPrice->text().toDouble(&ok);
    if(temp.name != "" && ok)
    {
        merchandise.additem(stadiumNametoEditMerc, temp);
    }
    else
    {
        QMessageBox::warning(this,"Error", "Error, item not added. Please check fields.");
    }
    ui->newName->clear();
    ui->newPrice->clear();
    this->setMercTableItems();
}

void MainWindow::on_edit_clicked()
{
    item temp;
    bool ok;
    if(ui->merchList->currentItem() != NULL)
    {
        int index = ui->merchList->currentRow();

        temp.name = ui->newName->text();
        if(temp.name != "")
        {
            merchandise.changeName(stadiumNametoEditMerc,temp.name,index);
        }

        temp.name = ui->newPrice->text();
        temp.price = temp.name.toDouble(&ok);
        if(ok && temp.name != "")
        {
            merchandise.changePrice(stadiumNametoEditMerc,temp.price,index);
        }

        ui->newName->clear();
        ui->newPrice->clear();
        this->setMercTableItems();
    }
}

void MainWindow::on_delete_2_clicked()
{
    if(ui->merchList->currentItem() != NULL)
    {
        int index = ui->merchList->currentRow();
        merchandise.deleteitem(stadiumNametoEditMerc,index);

        this->setMercTableItems();
    }
}

void MainWindow::on_CheckConnection_clicked()
{
    //check if stadiumNametoEditMerc and the selected stadium are connected
    //if yes check the check box if no uncheck it
    //if yes display dist otherwise 0
}

void MainWindow::on_UpdateDistance_clicked()
{
    //take in check box and distance and update the distances / matrix accordingly
}

void MainWindow::on_SaveAndBack_clicked()
{
    ui->MainStack->setCurrentIndex(ui->MainStack->indexOf(ui->AdminPage));
}

void MainWindow::on_ToTripPage2_clicked()
{
    ui->MainStack->setCurrentIndex(ui->MainStack->indexOf(ui->TripPage));
}

void MainWindow::on_BacktoMain3_clicked()
{
    ui->MainStack->setCurrentIndex(ui->MainStack->indexOf(ui->mainpage));
}

void MainWindow::on_cart_clicked()
{
    ui->CartDisplay->show();
    ui->MainStack->setCurrentIndex(ui->MainStack->indexOf(ui->CartPage));
}

void MainWindow::on_stadiumButton_clicked()
{
    Heap<Item, QString> *copyHeap = new Heap<Item, QString>;
    Heap<Item, QString> *newHeap  = new Heap<Item, QString>;
    copyHeap->populate(*defaultHeap);
    while(copyHeap->size() > 0){
        newHeap->insert(copyHeap->min(), copyHeap->min().stadium);
        copyHeap->removeMin();
    }
    populateTable(newHeap);
}

void MainWindow::on_priceButton_clicked()
{
    Heap<Item, QString> *copyHeap = new Heap<Item, QString>;
    Heap<Item, float> *newHeap  = new Heap<Item, float>;
    copyHeap->populate(*defaultHeap);
    while(copyHeap->size() > 0){
        newHeap->insert(copyHeap->min(), copyHeap->min().price);
        copyHeap->removeMin();
    }
    populateTable(newHeap);
}

void MainWindow::on_typeButton_clicked()
{
    Heap<Item, QString> *copyHeap = new Heap<Item, QString>;
    copyHeap->populate(*defaultHeap);
    populateTable(copyHeap);
}

void MainWindow::populateTable(Heap<Item, QString> *itemsHeap){
    int row = 0;
    int col = 0;
    int itemQuantity = 1;
    float itemTotal;
    bool duplicate;
    while(itemsHeap->size() > 0){
        QTableWidgetItem *type     = new QTableWidgetItem(itemsHeap->min().type);
        QTableWidgetItem *stadium  = new QTableWidgetItem(itemsHeap->min().stadium);
        QTableWidgetItem *price    = new QTableWidgetItem(QString::number(itemsHeap->min().price));
        itemsHeap->removeMin();
        do{
            if(itemsHeap->size() > 0){
                if(itemsHeap->min().type == type->text() && itemsHeap->min().stadium == stadium->text()){
                    ++itemQuantity;
                    itemsHeap->removeMin();
                    duplicate = true;
                }
                else{
                    duplicate = false;
                }
            }
        }while(itemsHeap->size() > 0 && duplicate);
        itemTotal = float(itemQuantity) * price->text().toFloat();
        QTableWidgetItem *quantity = new QTableWidgetItem(QString::number(itemQuantity));
        QTableWidgetItem *total    = new QTableWidgetItem(QString::number(itemTotal));
        ui->CartDisplay->setItem(row, col, type);
        ui->CartDisplay->setItem(row, ++col, stadium);
        ui->CartDisplay->setItem(row, ++col, price);
        ui->CartDisplay->setItem(row, ++col, quantity);
        ui->CartDisplay->setItem(row, ++col, total);
        col = 0;
        row++;
        itemQuantity = 1;
    }
}

void MainWindow::populateTable(Heap<Item, float> *itemsHeap){
    int row = 0;
    int col = 0;
    int itemQuantity = 1;
    float itemTotal;
    bool duplicate;
    while(itemsHeap->size() > 0){
        QTableWidgetItem *type     = new QTableWidgetItem(itemsHeap->min().type);
        QTableWidgetItem *stadium  = new QTableWidgetItem(itemsHeap->min().stadium);
        QTableWidgetItem *price    = new QTableWidgetItem(QString::number(itemsHeap->min().price));
        itemsHeap->removeMin();
        do{
            if(itemsHeap->size() > 0){
                if(itemsHeap->min().type == type->text() && itemsHeap->min().stadium == stadium->text()){
                    ++itemQuantity;
                    itemsHeap->removeMin();
                    duplicate = true;
                }
                else{
                    duplicate = false;
                }
            }
        }while(itemsHeap->size() > 0 && duplicate);
        itemTotal = float(itemQuantity) * price->text().toFloat();
        QTableWidgetItem *quantity = new QTableWidgetItem(QString::number(itemQuantity));
        QTableWidgetItem *total    = new QTableWidgetItem(QString::number(itemTotal));
        ui->CartDisplay->setItem(row, col, type);
        ui->CartDisplay->setItem(row, ++col, stadium);
        ui->CartDisplay->setItem(row, ++col, price);
        ui->CartDisplay->setItem(row, ++col, quantity);
        ui->CartDisplay->setItem(row, ++col, total);
        col = 0;
        row++;
        itemQuantity = 1;
    }
}

void MainWindow::on_PlanTour_clicked()
{

}

void MainWindow::on_newStadium_clicked()
{
    if(QMessageBox::Yes == QMessageBox::question(this,"Are you sure?","Add a new stadium to the database?",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
    {
        QString temp;
        QSqlQuery query;
        QTextStream addstad(&temp);

        addstad << "insert into stadium values(\'" << ui->newStadiumName->text() << "\',\'\',\'\',\'\',\'\',\'\',\'\',\'\')";
        temp = *addstad.string();
        query.exec(temp);

        merchandise.addstadium(ui->newStadiumName->text());
        //add to distance list

        ui->TeamEdit->show();
        ui->newStadiumName->clear();
    }
}
