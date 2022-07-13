#include "Item.h"

Item::Item(string itemName, int cost)
{
    name = itemName;
    value = cost;
}

int Item::getValue() { return value; }

string Item::getName() { return name; }

string Item::toString()
{
    return (name + " (value: " + to_string(value) + ")");
}
