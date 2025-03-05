#include <iostream>
#include <string>
#include <vector>
#include "Weapon.h"
#include "Inventory.h"
#include "Character.h"


using namespace Practice;

int main()
{
    std::vector<Weapon> weaponList =
    {
        Weapon("Sword",50, 40, "Rare"),
        Weapon("Axe",50, 20, "Rare"),
        Weapon("RayGun",30, 40, "Epic"),
        Weapon("Stick",10, 5, "Common"),
    };

    Character Player1("Alfredo", 100, 10);

    std::cout << "\nPlayer 1, this are your current stats\n";
    Player1.PrintStats();

    std::cout << "Your inventory:\n";
    for (Weapon print : weaponList)
    {
        print.printWeaponDetails();
    }

    std::cout << "\nWhich weapon would you like to use (1, 2, 3, 4)";
    int choice;
    std::cin >> choice;

    if (choice == 1)
    {
        weaponList[0].useWeapon();
    }
    else if (choice == 2)
    {
        weaponList[1].useWeapon();
    }
    else if (choice == 3)
    {
        weaponList[2].useWeapon();
    }
    else if (choice == 4)
    {
        weaponList[3].useWeapon();
    }

    std::cout << "\nUpdated weapon stats:\n";
    for (Weapon print : weaponList)
    {
        print.printWeaponDetails();
    }

}
