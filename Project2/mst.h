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
}

class MST
{
public:
    MST();
    ~MST();
    void MSToutput();
    void readFile();
    void writeFile();


private:
    map<QString,vector<node> > stadiumDistances;
    map<QString,vector<node> >::iterator:: itt;
};

#endif // MST_H

