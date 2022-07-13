#include "Armor.h"

Armor::Armor(string itemName, int protectionValue, int cost)
        : Item(itemName, cost)
    {
        protection = protectionValue;
    }

int Armor::getProtection() { return protection; }

string Armor::toString()
{
    return ((this->Item::toString()) + " Protection: " + to_string(protection));
}
