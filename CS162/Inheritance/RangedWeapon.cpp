#include "RangedWeapon.h"

RangedWeapon::RangedWeapon(string itemName, int damageValue, int rangeValue, int ammoValue, int cost)
        : Weapon(itemName, damageValue, cost)
    {
        range = rangeValue;
        ammo = ammoValue;
    }

int RangedWeapon::getRange() { return range; }

int RangedWeapon::getAmmo() { return ammo; }

string RangedWeapon::toString()
{
    return ((this->Weapon::toString()) + " Ammo: " + to_string(ammo) + " Range: " + to_string(range));
}

int RangedWeapon::use(int rangeToTarget = 0)
{
    // No ammo?
    if (ammo <= 0) { return 0; }

    // Use ammo
    ammo--;

    // Return damage value depending on range
    return (rangeToTarget <= getRange() ? Weapon::use(rangeToTarget) : 0);
}
