#ifndef MST_H
#define MST_H

#include <map>
#include <vector>
#include <QString>
#include <QTextStream>
#include <QFile>
#include <QMessageBox>
#include <QDebug>
using namespace std;

struct node
{
    QString name;
    int distance;
};

struct treenode
{
    QString name;
    bool mstSet;
};

struct dijknode
{
    QString name;
    int distanceFromStart;
};

class MST
{
public:
    MST();
    ~MST();

    int getSize();
    void readFile();
    void writeFile();
    void addNewStadium(QString n);
    void changeDistance(QString current, QString n, int d);
    int distanceOfTwo(QString current, QString dest);
    vector<node> distToOthers(QString n);
    vector<QString> MSToutput();
    int totaldist();
    vector<dijknode> singledijk(QString start);
    vector<dijknode> doubleDijking(vector<QString> toVisit);

private:
    int mstSize;
    int totaldistance;
    int minKey();
    vector<treenode> Key;
    vector<QString> parentVector;
    map<QString,vector<node> > stadiumDistances;
    map<QString,vector<node> >::iterator itt;
    vector<dijknode> TravelList;
    void tree();
};

#endif // MST_H

