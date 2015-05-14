#ifndef STADIUM_H
#define STADIUM_H

//#include "MainHeader.h"

#include <QString>

using namespace std;


struct stadiumNode
{
    string stadiumName;
    string teamName;
    string address1;
    string address2;
    string phone;
    string opening;
    string capacity;
    bool fieldType; // 0 for grass
    bool league;    // 0 for American

    stadiumNode *next;
    stadiumNode *prev;
};

class stadium
{


    public:
    stadium();

    void addStadium(string sName,
                    string tName,
                    string a1,
                    string a2,
                    string tele,
                    string date,
                    string seats,
                    bool astroTurf,
                    bool national);

    void getList();

    void alphaLeague();
    void alphaStadium();
    void alphaTeam();
    void Opening();
    void seating();

    void setStadiumName(string compare, string sName);
    void setTeamName(string compare, string tName);
    void setAddress1(string compare, string a1);
    void setAddress2(string compare, string a2);
    void setPhone(string compare, string tele);
    void setOpening(string compare, string date);
    void setCapacity(string compare, string seats);
    void setFieldType(string compare, bool astroTurf);
    void setLeague(string compare, bool national);

    string getStadiumName(string compare);
    string getTeamName(string compare);
    string getAddress1(string compare);
    string getAddress2(string compare);
    string getPhone(string compare);
    string getOpening(string compare);
    string getCapacity(string compare);
    bool getFieldType(string compare);
    bool getLeague(string compare);

    private:


        stadiumNode *comparison(string compare)
        {
            stadiumNode *tempNode;

            tempNode = stadiumList;

            while(tempNode->stadiumName != compare)
            {
                tempNode = tempNode->next;
            }

            return tempNode;
        }

        stadiumNode *copy(stadiumNode *list)
        {
            if(list == NULL)
            {
                return NULL;
            }

            stadiumNode *outputList = new stadiumNode;
            outputList->stadiumName = list->stadiumName;
            outputList->teamName = list->teamName;
            outputList->address1 = list->address1;
            outputList->address2 = list->address2;
            outputList->phone = list->phone;
            outputList->opening = list->opening;
            outputList->capacity = list->capacity;
            outputList->fieldType = list->fieldType;
            outputList->league = list->league;
            outputList->prev = list->prev;
            outputList->next = copy(list->next);

            return outputList;

        }

        stadiumNode *stadiumList;
};

#endif // STADIUM_H
