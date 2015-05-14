#ifndef ITEM_H
#define ITEM_H

#include <QString>

struct Item
{
    int quantity;
    float price;
    QString type;
    QString stadium;
    set(int q, float p, QString t, QString s){
        quantity = q;
        price    = p;
        type     = t;
        stadium  = s;
    }
};

#endif // ITEM_H
