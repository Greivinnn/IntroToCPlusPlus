#include "Inventory.h"
#include <iostream>

using namespace Practice;

Inventory::Inventory()
{
	_weapons.reserve(5);
}

void Inventory::AddWeapon(Weapon newWeapon)
{
	if (_weapons.capacity() != _weapons.size())
	{
		_weapons.push_back(newWeapon);
	}
	else
	{
		std::cout << "\nInventory full! Drop an item to add a new item.\n\n";
	}
}

void Inventory::RemoveWeapon(std::string weaponName)
{
	for (std::vector<Weapon>::iterator it = _weapons.begin(); it != _weapons.end(); it++)
	{
		if (it->GetName().compare(weaponName) == 0)
		{
			_weapons.erase(it);
			return;
		}
	}
}