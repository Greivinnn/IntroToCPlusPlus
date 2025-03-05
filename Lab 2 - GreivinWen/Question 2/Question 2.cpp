#include <iostream>
#include "Weapon.h"
#include <array>

using namespace WeaponInfo;

int main()
{
    std::array<Weapon, 3> weapons =
    {
        Weapon("Sword", 40, 10),
        Weapon("Lance", 50, 15),
        Weapon("Gun", 100, 7),
    };

    for (Weapon list : weapons)
    {
        list.DisplayAllWeapons();
    }

    for (Weapon list : weapons)
    {
        list.DecreaseDurability();
    }
}