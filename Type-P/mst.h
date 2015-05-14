#ifndef MST_H
#define MST_H

#include <map>
#include <vector>
#include <QString>
#include <QTextStream>
#include <QFile>
#include <QMessageBox>
using namespace std;

struct node
{
    QString name;
    int distance;
};

class MST
{
public:
    MST();
    ~MST();


    void readFile();
    void writeFile();
    void addNewStadium(QString n);
    void changeDistance(QString current, QString n, int d);
    int distanceOfTwo(QString current, QString dest);
    vector<node> distToOthers(QString n);
    vector<QString> MSToutput(int& totalDist);


private:
    map<QString,vector<node> > stadiumDistances;
    map<QString,vector<node> >::iterator itt;
};

#endif // MST_H

