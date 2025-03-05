#include "Inventory.h"
#include <iostream>

using namespace Practice;

Inventory::Inventory()
{
	// Reserve only reserves space for the number of elements specified
	// It does not add to the size
	_weapons.reserve(5);
}

void Inventory::AddWeapon(Weapon newWeapon)
{
	if (_weapons.capacity() != _weapons.size())
	{
		_weapons.push_back(newWeapon);
	}
}

void Inventory::RemoveWeapon(std::string weaponName)
{
	// Do this
	/*for (int i = 0; i < _weapons.size(); i++)
	{
		if (_weapons[i].GetName().compare(weaponName) == 0)
		{
			_weapons.erase(_weapons.begin() + i);
			break;
		}
	}*/

	// Or this
	for (std::vector<Weapon>::iterator it = _weapons.begin(); it != _weapons.end(); it++)
	{
		if (it->GetName().compare(weaponName) == 0)
		{
			_weapons.erase(it);
			return;
		}
	}
}

void Inventory::PrintInventory()
{
	for (Weapon weapon : _weapons)
	{
		std::cout << weapon.GetName() << "\n";
	}
	std::cout << "\n";
}