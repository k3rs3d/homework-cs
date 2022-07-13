#ifndef ITEM_H
#define ITEM_H

#include <iostream>

using namespace std;

class Item
{
private:
    string name;
    int value;

public:
    Item(string itemName, int cost);

    virtual string toString();
    virtual string getName();
    int getValue();
};


#endif // ITEM_H
