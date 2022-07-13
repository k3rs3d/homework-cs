#include "Weapon.h"


Weapon::Weapon(string itemName, int damageValue, int cost)
    : Item(itemName, cost)
{
    damage = damageValue;
}

int Weapon::getRange() { return 0; }

int Weapon::getDamage() { return damage; }

string Weapon::toString()
{
    return ((this->Item::toString()) + " Damage: " + to_string(damage));
}

int Weapon::use(int rangeToTarget = 0)
{
    return (rangeToTarget <= getRange() ? damage : 0);
}
