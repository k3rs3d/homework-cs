#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"

class Armor : public Item
{
private:
    int protection;
public:
    Armor(string itemName, int protectionValue, int cost);

    string toString();
    int getProtection();
};


#endif // ARMOR_H
