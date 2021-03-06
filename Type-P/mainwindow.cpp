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

    distmap = new MST;
    distmap->readFile();


    ui->MainStack->setCurrentIndex(0);

    ui->navigateTrip->setCurrentIndex(0);

    defaultHeap = new Heap<Item, QString>;
    choices = new vector<QString>;

    //initialize cart table
    ui->CartDisplay->setShowGrid(true);
    ui->CartDisplay->setColumnCount(5);
    ui->CartDisplay->setRowCount(0);
    ui->CartDisplay->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->CartDisplay->setHorizontalHeaderLabels(QStringList() << "Item" << "Stadium" << "Unit Price" << "Quantity" << "Total");
    //initialize merchandise table for trip
    ui->merchTable->setShowGrid(true);
    ui->merchTable->setColumnCount(2);
    ui->merchTable->setRowCount(0);
    ui->merchTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->merchTable->setHorizontalHeaderLabels(QStringList() << "Name" << "Price");
    //initialize merchList table for admin
    ui->merchList->setShowGrid(true);
    ui->merchList->setColumnCount(2);
    ui->merchList->setRowCount(0);
    ui->merchList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->merchList->setHorizontalHeaderLabels(QStringList() << "Name" << "Price");
    //initialize angelstable
    ui->angelsTable->setShowGrid(true);
    ui->angelsTable->setColumnCount(2);
    ui->angelsTable->setRowCount(0);
    ui->angelsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->angelsTable->setHorizontalHeaderLabels(QStringList() << "Name" << "Dist");

//    Item q;
//    q.set(1,25.99,"Test item","Test Park");
//    defaultHeap->insert(q, q.type);



    LandingWin lander;
    lander.setModal(true);
    lander.exec();

    //used to keep track of indexes in the buy tables
    currentTravelIndex = 0;
    callRegularBuyTable = false;

    this->show();
}

MainWindow::~MainWindow()
{
    delete distmap;
    delete tablemodel;
    delete defaultHeap;
    choices->clear();
    delete choices;
    delete ui;
}

void MainWindow::toDoReminder()
{
    vector<QString>::iterator outit;
    outit = ToDoList.begin();
    qDebug() << "To Do List:\n";
    for(;outit != ToDoList.end();outit++)
    {
        qDebug() << *outit << endl;
    }
    qDebug() << "Find and remove debug messages.\nEnd to Do List\n";
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

    query.exec("insert into stadium values('Angel Stadium', 'Los Angeles Angels of Anaheim', '2000 E Gene Autry Way\nAnaheim, CA 92806', '(714) 940-2000', '1966 April 19', '45,483', 'Grass', 'American')");
    query.exec("insert into stadium values('Comerica Park','Detroit Tigers','2100 Woodward Ave\nDetroit, MI 48201','(313) 962-4000','2000 April 11','41,681','Grass','American')");
    query.exec("insert into stadium values('Fenway Park','Boston Red Sox','4 Yawkey Way\nBoston, MA 02215','(877) 733-7699','1912 April 20','37,499 (night) & 37,071 (day)','Grass','American')");
    query.exec("insert into stadium values('Rangers BallPark','Texas Rangers','1000 Ballpark Way\nArlington, TX 76011','(817) 273-5222','1994 April 1','48,114','Grass','American')");
    query.exec("insert into stadium values('Kauffman Stadium','Kansas City Royals','1 Royal Way\nKansas City, MO 64129','(816) 921-8000','1973 April 10','37,903','Grass','American')");
    query.exec("insert into stadium values('Minute Maid Park','Houston Astros','501 Crawford St\nHouston, TX 77002','(713) 259-8000','2000 May 30','42,060','Grass','American')");
    query.exec("insert into stadium values('O.co Coliseum','Oakland Athletics','7000 Coliseum Way\nOakland, CA 94621','(510) 569-2121','1966 September 18','37,090 (April - August) & 55,945 (Sept - Jan)','Grass','American')");
    query.exec("insert into stadium values('Camden Yards','Baltimore Orioles','333 West Camden Street\nBaltimore, MD 21201','(410) 685-9800','1992 April 6','48,187','Grass','American')");
    query.exec("insert into stadium values('Progressive Field','Cleveland Indians','2401 Ontario Street\nCleveland, OH 44115','(216) 420-4487','1994 April 2','42,404','Grass','American')");
    query.exec("insert into stadium values('Rogers Center','Toronto Blue Jays','1 Blue Jays Way\nToronto, Ontario, Canada M5V1J3','(416) 341-1000','1989 June 3','49,282','Turf','American')");
    query.exec("insert into stadium values('Safeco Field','Seattle Mariners','1516 First Avenue South\nSeattle, WA 98134','(206) 346-4000','1999 July 15','47,476','Grass','American')");
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
    query.exec("insert into stadium values('PETCO Park','San Diego Padres','19 Tony Gwynn Drive\nSan Diego, CA 92101','(619) 795-5000','2004 April 8','42,524','Grass','National')");
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
        QMessageBox::warning(this,"Invalid","Wrong password, try Again");
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
    tempvari = ui->TeamEdit->currentIndex().data();

    stadiumNametoEditMerc = tempvari.toString();

    ui->MainStack->setCurrentIndex(ui->MainStack->indexOf(ui->MerchandiseEdit));
    ui->editinglabel->setText(stadiumNametoEditMerc);

    this->setMercTableItems();

//for distance editing
    ui->distList->clear();
    distTo.clear();
    distTo = merchandise.stadiumList();
    ui->ConNoCon->setChecked(false);
    ui->DirectDist->setText("select stadium");

    for (unsigned int index = 0; index < distTo.size(); index++)
    {
        ui->distList->addItem(distTo[index]);
    }
}

void MainWindow::setMercTableItems()
{
    ui->merchList->clearContents();

    merchVec = merchandise.itemlist(stadiumNametoEditMerc);

    ui->merchList->setRowCount(merchVec.size());

    //index used synonymously for row
    for(unsigned int index = 0; index < merchVec.size(); index++)
    {
        QStringList merchFields;
        QString merchPrice = QString::number(merchVec[index].price);
        merchFields << merchVec[index].name << merchPrice;

        for (int column = 0; column < 2; column++)
        {
            QTableWidgetItem *newItem = new QTableWidgetItem(merchFields.at(column));
            ui->merchList->setItem(index, column, newItem);
        }
    }
}

void MainWindow::BuyTable()
{
    ui->merchTable->clearContents();
    QString currentStadium = "Eror Fix Me!!";

    currentStadium = choices->at(currentTravelIndex);
    ui->currentS->setText(currentStadium);

    merchVec = merchandise.itemlist(currentStadium);

    ui->merchTable->setRowCount(merchVec.size());

    //index used synonymously for row
    for(unsigned int index = 0; index < merchVec.size(); index++)
    {
        QStringList merchFields;
        QString merchPrice = QString::number(merchVec[index].price);
        merchFields << merchVec[index].name << merchPrice;

        for (int column = 0; column < 2; column++)
        {
            QTableWidgetItem *newItem = new QTableWidgetItem(merchFields.at(column));
            ui->merchTable->setItem(index, column, newItem);
        }
    }
}



void MainWindow::CustomBuy()
{
    ui->merchTable->clearContents();
    QString currentStadium = "Eror Fix Me!!";

    currentStadium = dikstras[currentTravelIndex].name;
    ui->currentS->setText(currentStadium);

    merchVec = merchandise.itemlist(currentStadium);

    ui->merchTable->setRowCount(merchVec.size());

    //index used synonymously for row
    for(unsigned int index = 0; index < merchVec.size(); index++)
    {
        QStringList merchFields;
        QString merchPrice = QString::number(merchVec[index].price);
        merchFields << merchVec[index].name << merchPrice;

        for (int column = 0; column < 2; column++)
        {
            QTableWidgetItem *newItem = new QTableWidgetItem(merchFields.at(column));
            ui->merchTable->setItem(index, column, newItem);
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
    if(ui->distList->currentItem() != NULL)
    {
        QString temp = ui->distList->currentItem()->text();
        int d = distmap->distanceOfTwo(stadiumNametoEditMerc, temp);

        if(d == -1)
        {
            ui->ConNoCon->setChecked(false);
            ui->DirectDist->setText("Not Connected");
        }
        else
        {
            ui->ConNoCon->setChecked(true);
            ui->DirectDist->setText(QString::number(d));
        }
    }
}

void MainWindow::on_UpdateDistance_clicked()
{
    bool ok = false;
    QString temp = ui->DirectDist->text();
    int d = temp.toInt(&ok);
    if(ui->ConNoCon->isChecked() && ok && ui->distList->currentItem() != NULL && d >= 0)
    {
        distmap->changeDistance(stadiumNametoEditMerc,ui->distList->currentItem()->text(), d);
        distmap->changeDistance(ui->distList->currentItem()->text(), stadiumNametoEditMerc, d);
    }
    else if (ui->ConNoCon->isChecked() && !ok)
    {
        QMessageBox::warning(this,"Invalid Input","Please enter an integer number.");
    }
    else if(ui->ConNoCon->isChecked() && ok && d < 0)
    {
        QMessageBox::warning(this,"Invalid Input","Please enter a positive distance.");
    }

    if(!ui->ConNoCon->isChecked() && distmap->distanceOfTwo(stadiumNametoEditMerc, ui->distList->currentItem()->text()) >= 0)
    {
        temp = "Are you sure you would like to remove the connection between:\n";
        temp += stadiumNametoEditMerc;
        temp += " and ";
        temp += ui->distList->currentItem()->text();
        temp += "?";
        if(QMessageBox::Yes == QMessageBox::question(this,"Remove Connection?",temp,QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
        {
            distmap->changeDistance(stadiumNametoEditMerc,ui->distList->currentItem()->text(), -1);
            distmap->changeDistance(ui->distList->currentItem()->text(), stadiumNametoEditMerc, -1);
        }
    }
}

void MainWindow::on_SaveAndBack_clicked()
{
    distmap->writeFile();
    merchandise.SavetoFile();
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
    this->populateTable(newHeap);
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
    ui->CartDisplay->setRowCount(0);
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
        ui->CartDisplay->setRowCount(ui->CartDisplay->rowCount() + 1);
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
    ui->CartDisplay->setRowCount(0);
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
        ui->CartDisplay->setRowCount(ui->CartDisplay->rowCount() + 1);
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
    ui->MainStack->setCurrentIndex(ui->MainStack->indexOf(ui->TripPage));
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
        distmap->addNewStadium(ui->newStadiumName->text());

        ui->TeamEdit->show();
        ui->newStadiumName->clear();
    }
}


void MainWindow::on_visitAllBttn_clicked()
{
    ui->next->setEnabled(true);
    ui->navigateTrip->setCurrentIndex(ui->navigateTrip->indexOf(ui->all));

    //get MST from mst class. will be returned as a vector.
    choices->clear();
    *choices = distmap->MSToutput();

    currentTravelIndex = 0;
    traveldist = 0;
    ui->traveledDist->clear();
    callRegularBuyTable = true;
    this->BuyTable();
}

void MainWindow::on_angelsBttn_clicked()
{
    ui->navigateTrip->setCurrentIndex(ui->navigateTrip->indexOf(ui->angelsStart));
    ui->angelsTable->clearContents();

    //get dijkstras will be returned as vector
    dikstras.clear();
    dikstras = distmap->singledijk("Angel Stadium");


    ui->angelsTable->setRowCount(dikstras.size());

    //index used synonymously for row
    for(unsigned int index = 0; index < dikstras.size(); index++)
    {
        QStringList stadiumFields;
        QString stadiumdist = QString::number(dikstras[index].distanceFromStart);
        stadiumFields << dikstras[index].name << stadiumdist;

        for (int column = 0; column < 2; column++)
        {
            QTableWidgetItem *newItem = new QTableWidgetItem(stadiumFields.at(column));
            ui->angelsTable->setItem(index, column, newItem);
        }

    }
}

void MainWindow::on_customBttn_clicked()
{
    ui->navigateTrip->setCurrentIndex(ui->navigateTrip->indexOf(ui->custom));
    ui->customTrip->setCurrentIndex(ui->customTrip->indexOf(ui->starting));

    ui->startList->clear();
    ui->otherList->clear();
    choices->clear();
    distTo.clear();

    distTo = merchandise.stadiumList();

    for(unsigned int index = 0; index < distTo.size(); index ++)
    {
        ui->startList->addItem(distTo[index]);
        ui->otherList->addItem(distTo[index]);
    }
}

void MainWindow::on_next_clicked()
{
    currentTravelIndex++;

    if(callRegularBuyTable)
    {
        if(currentTravelIndex == choices->size())
        {
            ui->next->setEnabled(false);
            QMessageBox *end = new QMessageBox;
            end->setText("You have reached the end of your trip !\n Come back Soon!");
            end->exec();
            ui->next->setEnabled(false);
        }
        else
        {
            this->BuyTable();
            int d = distmap->distanceOfTwo(choices->at(currentTravelIndex),choices->at(currentTravelIndex - 1));
            traveldist += d;
            ui->traveledDist->setText(QString::number(traveldist));
        }
    }
    else
    {
        if(currentTravelIndex == dikstras.size())
        {
            ui->next->setEnabled(false);
            QMessageBox *end = new QMessageBox;
            end->setText("You have reached the end of your trip !\n Come back Soon!");
            end->exec();
            ui->next->setEnabled(false);
        }
        else
        {
            this->CustomBuy();
            int d = dikstras[currentTravelIndex].distanceFromStart;
            traveldist += d;
            ui->traveledDist->setText(QString::number(traveldist));
        }
    }
}

void MainWindow::on_buy_clicked()
{
    if(ui->merchTable->currentItem() != NULL)
    {
    item currentMerch = merchVec.at(ui->merchTable->currentRow());
    Item i;
    i.set(1,currentMerch.price,currentMerch.name, ui->currentS->text());
    defaultHeap->insert(i,i.type);
    }
    else
    {
        QMessageBox *error = new QMessageBox;
        error->setText("Please select something to buy!");
        error->exec();
    }
}

void MainWindow::on_go_clicked()
{
    ui->customTrip->setCurrentIndex(ui->customTrip->indexOf(ui->others));
    callRegularBuyTable = false;

    int currentIndex = ui->startList->currentRow();
    choices->push_back(distTo[currentIndex]);

    ui->otherList->setRowHidden(currentIndex, true);
}

void MainWindow::on_go2_clicked()
{
    QListWidgetItem *item = new QListWidgetItem;
    int row = 0;

    item = ui->otherList->item(row);

    while(item != NULL)
    {
        if(ui->otherList->isItemSelected(item))
        {
            choices->push_back(distTo[row]);
        }
        row++;

        item = ui->otherList->item(row);
    }

    //at end of this take vector that was built and do dijkstas to it
    dikstras = distmap->doubleDijking(*choices);

    //then re-route ui to visit all using the dijkstra's instead of MST
    ui->next->setEnabled(true);
    ui->navigateTrip->setCurrentIndex(ui->navigateTrip->indexOf(ui->all));
    currentTravelIndex = 0;
    traveldist = 0;
    ui->traveledDist->clear();
    this->CustomBuy();
}

void MainWindow::on_cartBttn_clicked()
{
    ui->MainStack->setCurrentIndex(ui->MainStack->indexOf(ui->CartPage));
}

void MainWindow::on_ToTeamInfo_clicked()
{
    ui->MainStack->setCurrentIndex(ui->MainStack->indexOf(ui->TeamInfoPage));
    ui->TeamInfoTable->setModel(tablemodel);
    ui->TeamInfoTable->show();
}

void MainWindow::on_BacktoMain_clicked()
{
    ui->MainStack->setCurrentIndex(ui->MainStack->indexOf(ui->mainpage));
}
