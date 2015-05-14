#include "merc.h"

Merc::Merc()
{
    numberofstadiums = 0;
    QString key;
    QString reader;
    item temp;
    QFile mercfile("MercList.txt");

    if(!mercfile.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(0,"Cannot Open to Read", mercfile.errorString());
    }
    else
    {
        QTextStream in(&mercfile);

        while(!in.atEnd())
        {
            reader = in.readLine();

            if(reader != "0" && reader != "")
            {
                key = reader;
                numberofstadiums++;
                reader = in.readLine();
            }

            while(reader != "0" && reader != "")
            {
                temp.name = reader;
                reader = in.readLine();
                temp.price = reader.toDouble();
                theList[key].push_back(temp);
                reader = in.readLine();
            }
        }
    }
    mercfile.close();
}

Merc::~Merc()
{

}

void Merc::SavetoFile()
{
    vector<item> temp;
    QFile mercfile("MercList.txt");

    if(!mercfile.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(0,"Cannot Open to Write", mercfile.errorString());
    }
    else
    {
        QTextStream out(&mercfile);

        itt = theList.begin();
        for(;itt != theList.end(); itt++)
        {
            if(itt != theList.begin())
                out << endl;
            out << itt->first << endl;  //output key
            temp = itt->second;

            for(int i=0; i < temp.size() ; i++)
            {
                out << temp[i].name << endl << temp[i].price << endl;
            }
            out << 0;
        }

    }
    mercfile.flush();
    mercfile.close();
}

QString Merc::displayItems(QString stadium)
{
    QString retString;
    QTextStream out;
    vector<item> stadiumMerc;
    int vectorsize;

    stadiumMerc = theList[stadium];
    vectorsize = stadiumMerc.size();

    for(int i=0; i < vectorsize; i++)
    {
        out << i+1 << ") " << stadiumMerc[i].name;
        retString.setNum(stadiumMerc[i].price);
        out << "/t/t" << retString << "/n/n";
    }


    return retString;
}

double Merc::getPrice(QString stadium, int number)
{
    return theList[stadium][number-1].price;
}

QString Merc::getName(QString stadium, int number)
{
    return theList[stadium][number-1].name;
}

void Merc::changePrice(QString stadium, double newprice, int number)
{
    theList[stadium][number].price = newprice;
}

void Merc::changeName(QString stadium, QString newname, int number)
{
    theList[stadium][number].name = newname;
}

void Merc::deleteitem(QString stadium, int number)
{
    vector<item>::iterator itremove;
    itremove = theList[stadium].begin();
    itremove += number;
    theList[stadium].erase(itremove);
}

void Merc::additem(QString stadium, item newitem)
{
    theList[stadium].push_back(newitem);
}

void Merc::addstadium(QString stadium)
{
    theList[stadium];
}

vector<QString> Merc::stadiumList()
{
    vector<QString> temp;
    itt = theList.begin();

    for(;itt != theList.end(); itt++)
    {
        temp.push_back(itt->first);
    }
    return temp;
}

//returns a vector of merch items according to which stadium
vector<item> Merc::itemlist(QString stadium)
{
    vector<item> stadiumMerc;
    itt = theList.find(stadium);
    if(itt != theList.end())
        return itt->second;
    else
        return stadiumMerc;
}
