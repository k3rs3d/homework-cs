#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

using namespace std;

class Weapon : public Item
{
private:
    int damage;
public:
    Weapon(string itemName, int damageValue, int cost);

    string toString();
    virtual int use(int rangeToTarget);
    virtual int getRange();
    int getDamage();
};

#endif // WEAPON_H
