#ifndef MERC_H
#define MERC_H

#include <map>
#include <vector>
#include <QString>
#include <QTextStream>
#include <QFile>
#include <QMessageBox>
using namespace std;

struct item
{
  QString name;
  double price;
};

class Merc
{
public:
    Merc();
    ~Merc();
    QString displayItems(QString stadium);
    double getPrice(QString stadium, int number);
    QString getName(QString stadium, int number);
    void changePrice(QString stadium, double newprice, int number);
    void changeName(QString stadium, QString newname, int number);
    void deleteitem(QString stadium, int number);
    void additem(QString stadium, QString newname, double newprice);
    void addstadium(QString stadium);
    vector<QString> stadiumList();
    vector<item> itemlist(QString stadium);
private:
    map<QString,vector<item> > theList;
    map<QString,vector<item> >::iterator itt;
    int numberofstadiums;
};

#endif // MERC_H
