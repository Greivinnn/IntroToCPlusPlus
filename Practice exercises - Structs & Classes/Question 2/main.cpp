#include <iostream>
#include <string>
#include <vector>
#include "Weapon.h"

using namespace WeaponInfo;

int main()
{
    std::cout << "Original Weapon List:\n";
    std::vector<Weapon> weaponsList =
    {
        Weapon("Sword", 40, "Rare"),
        Weapon("Axe", 20, "Common"),
        Weapon("RayGun", 40, "Epic"),
    };

    for (Weapon print : weaponsList)
    {
        print.printWeaponDetails();
    }

    weaponsList[1].IncreaseDamage();

    std::cout << "\nUpgrading Axe...\n\n";

    std::cout << "New Weapon List:\n";

    for (Weapon print : weaponsList)
    {
        print.printWeaponDetails();
    }
}