#pragma once

#include <string>
using namespace std;

class Weapon
{
public:
    Weapon(string name, int dmg);

    // Declare a global function as a friend
    friend void DisplayWeapon(const Weapon& weapon);

private:
    string _weaponName;
    int _damage;
};