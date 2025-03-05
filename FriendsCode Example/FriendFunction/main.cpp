#include "Weapon.h"
#include <iostream>

// Friend function
void DisplayWeapon(const Weapon& weapon)
{
    cout << "Weapon: " << weapon._weaponName << ", Damage: " << weapon._damage << endl;
}

int main()
{
    Weapon weapon("Sword of Destiny", 50);
    DisplayWeapon(weapon); // Friend function allows access
    return 0;
}