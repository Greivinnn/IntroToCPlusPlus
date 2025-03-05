#include <iostream>
#include <string>
#include <vector>
#include "Inventory.h"
#include "Character.h"
#include "Weapon.h"

using namespace Midterm;

Inventory::Inventory()
{
	_weapons.reserve(5);
}

void Inventory::AddItem(Weapon newWeapon)
{
	if (_weapons.capacity() != _weapons.size())
	{
		_weapons.push_back(newWeapon);
	}
}

void Inventory::displayInventory()
{
	for (Weapon weapons : _weapons)
	{
		std::cout << weapons.GetWeaponName() << "\nDamage: " << weapons.GetWeaponDamage() << "\nRarity: " << weapons.GetWeaponRarity() << "\n\n";
	}
	std::cout << "\n";
}

void Inventory::UseItem(std::string name)
{
	for (int i = 0; i < _weapons.size(); i++)
	{
		if (_weapons[i].GetWeaponName().compare(name) == 0)
		{
			_weapons.erase(_weapons.begin() + i);
			std::cout << "You have used " << name << "!\n\n";
			break;
		}
		else
		{
			std::cout << "Sorry you have already used this item, or it does not match anything in your inventory.\n\n";
			break;
		}
	}
}

void Inventory::CharacterBattleFunction(Character* player1, Character* player2)
{
	int numChoice;
	std::string choice;
	bool player1MedkitUse = false;
	bool player2MedkitUse = false;

	while (1)
	{
		std::cout << "BATTLE IN PROGRESS...\n\n";

		std::cout << "Player 1 and their stats:\n";
		player1->DisplayStats();

		std::cout << "\nPlayer 2 and their stats:\n";
		player2->DisplayStats();

		//Player 1 turn
		std::cout << player1->GetName() << " inventory:\n";
		player1->PrintInvetory();
		std::cout << "\n\n";

		std::cout << "Is " << player1->GetName() << " turn.\n\n";

		std::cout << "What would you like to do?\n";
		std::cout << "1. Normal attack\n2. Use something from the inventory\n3. Use medkit to heal yourself\n";
		std::cin >> numChoice;

		if (numChoice == 1)
		{
			player1->AttackFunction(player2); 
			std::cout << player2->GetName() << " just got attack by you and suffered. His current stats are:\n";
			player2->DisplayStats();

		}
		else if (numChoice == 2)
		{
			std::string weapon;

			player1->PrintInvetory();
			std::cout << "\n";

			std::cout << "What would you like to use? ";
			std::cin >> weapon;

			player1->UseItemFromInventory(weapon);

			player1->AttackFunction(player2);
			std::cout << player2->GetName() << " just got attack by you and suffered. His current stats are:\n";
			player2->DisplayStats();
		}
		else if (numChoice == 3)
		{
			if (player1MedkitUse == true)
			{
				std::cout << "You already used the medkit\n";
			}
			else
			{
				player1->UseMedkit();
				player1MedkitUse = true;
				std::cout << "Using medkit...\n";
				player1->DisplayStats();
			}	
		}
		else
		{
			std::cout << "Invalid input, skipping your turn :/\n";
		}

		std::cout << "\n\n";

		//Player 2 turn
		std::cout << player2->GetName() << " inventory:\n";
		player2->PrintInvetory();
		std::cout << "\n\n";

		std::cout << "Is " << player2->GetName() << " turn.\n\n";

		std::cout << "What would you like to do?\n";
		std::cout << "1. Normal attack\n2. Use something from the inventory\n3. Use medkit to heal yourself\n";
		std::cin >> numChoice;

		if (numChoice == 1)
		{
			player2->AttackFunction(player1);
			std::cout << player1->GetName() << " just got attack by you and suffered. His current stats are:\n";
			player1->DisplayStats();
		}
		else if (numChoice == 2)
		{
			std::string weapon;

			player1->PrintInvetory();
			std::cout << "\n";

			std::cout << "What would you like to use? ";
			std::cin >> weapon;

			player2->UseItemFromInventory(weapon);

			player2->AttackFunction(player1);
			std::cout << player1->GetName() << " just got attack by you and suffered. His current stats are:\n";
			player1->DisplayStats();
		}
		else if (numChoice == 3)
		{
			if (player1MedkitUse == true)
			{
				std::cout << "You already used the medkit\n";
			}
			else
			{
				player1->UseMedkit();
				player1MedkitUse = true;
				std::cout << "Using medkit...\n";
				player2->DisplayStats();
			}
		}
		else
		{
			std::cout << "Invalid input, skipping your turn :/\n";
		}

		if (player1->GetHealth() <= 0)
		{
			std::cout << "Congratulations! " << player2->GetName() << " won.";
			break;
		}
		if (player2->GetHealth() <= 0)
		{
			std::cout << "Congratulations! " << player1->GetName() << " won.";
			break;
		}
	}
}