#include <iostream>
#include <cassert>


#include "Character.h"

using namespace std;


Character::Character(const std::string& nameVal)
{
    name = nameVal;
    healthPoints = 100;

    //point to our built in armor/weapon
    weapon = &hands;
    armor = &skin;
}

void Character::print() const
{
    cout << name << endl;
    cout << "Health: " << healthPoints << endl;
    cout << "Armor: " << armor->toString() << endl;
    cout << "Weapon: " << weapon->toString() << endl;
    cout << "Inventory: " << endl;
    cout << "-----------------------------------" << endl;
    for(int i = 0; i < INVENTORY_SIZE; i++) {
        if(inventory[i] != nullptr) {
            cout << "[" << i << "] " << inventory[i]->toString() << endl;
        }
    }
    cout << "-----------------------------------" << endl;
}


int Character::getHealthPoints() const
{
    return healthPoints;
}

void Character::takeDamage(int amount)
{
    int damageAmount = amount - armor->getProtection();

    if(damageAmount < 0)
        damageAmount = 0;

    healthPoints -= damageAmount;
    if(healthPoints < 0)
        healthPoints = 0;
}


void Character::attack(Character& target, int range)
{
    target.takeDamage( weapon->use(range) );
}

bool Character::aquire(Item* item)
{
    for(int i = 0; i < INVENTORY_SIZE; i++) {
        if(inventory[i] == nullptr) {
            inventory[i] = item;
            return true;
        }
    }
    return false;
}

void Character::equip(int itemNumber)
{
    // First, check whether the index is even valid
    if (itemNumber >= INVENTORY_SIZE)
        return;

    // Secondly, check whether there's anything at that index
    if (inventory[itemNumber] == nullptr)
        return;

    // At this point, there must be an item at this index

    // Determine whether this is a weapon:
    Weapon* isWeapon = dynamic_cast<Weapon*>(inventory[itemNumber]);

    if (isWeapon)
    {
        weapon = isWeapon;
        return;
    }

    // If the last 'return' wasn't hit, then let's check if this is armor:
    Armor* isArmor = dynamic_cast<Armor*>(inventory[itemNumber]);

    if (isArmor)
    {
        armor = isArmor;
        return;
    }
}

Weapon* Character::getWeapon()
{
    return weapon;
}

Armor* Character::getArmor()
{
    return armor;
}
