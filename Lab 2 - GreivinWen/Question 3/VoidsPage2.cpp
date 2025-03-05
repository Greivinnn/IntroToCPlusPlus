#include <iostream>
#include "Weapon.h"
#include <array>
#include <string>

using namespace WeaponInfo;

Weapon::Weapon(std::string name, int dmg, int dur)
    : M_weaponName(name), M_weaponDamage(dmg), M_weaponDurability(dur)
{

}

void Weapon::DisplayAllWeapons()
{
    std::cout << "Weapon Name: " << M_weaponName << "\n";
    std::cout << "Weapon Damage Capability: " << M_weaponDamage << "\n";
    std::cout << "Weapon Durability: " << M_weaponDurability << "\n\n";
}

void Weapon::DecreaseDurability()
{
    std::cout << "\n\nUsing " << M_weaponName << "...\n";

    int index = 0;
    int newWeaponDurability;
    for (int i = 0; i < 6; i++)
    {
        std::cout << "-1 SHANK!\n";
        index = i;
    }
    newWeaponDurability = M_weaponDurability - index;

    std::cout << "\nYour weapon was used and it decrese its durability by: " << index << ". Now your weapons durability is: " << newWeaponDurability << "\n\n";
}

int Weapon::GetDamage()
{
    return M_weaponDamage;
}