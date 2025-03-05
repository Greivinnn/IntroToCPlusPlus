#include <iostream>
#include <string>
#include "Character.h"
#include "Inventory.h"

using namespace Midterm;

Character::Character(std::string name, int health, int attackPower, int defence)
	:_characterName(name), _characterHealth(health), _characterAttackPower(attackPower), _characterDefence(defence)
{
}

void Character::takeDamage(int amount)
{
	_characterHealth -= amount;
}

void Character::AttackFunction(Character* target)
{
	_characterHealth -= target->_characterAttackPower;
}

void Character::DisplayStats()
{
	std::cout << "Character name: " << _characterName << "\nCharacter health: " << _characterHealth << "\nCharacter Attack Power: " << _characterAttackPower << "\nCharacter defense: " << _characterDefence << "\n\n";
}

void Character::UseMedkit()
{
	_characterHealth += 50;
}

int Character::GetDamage()
{
	return _characterAttackPower;
}

int Character::GetHealth()
{
	return _characterHealth;
}

std::string Character::GetName()
{
	return _characterName;
}

void Character::BattleFunction(Character* player1, Character* player2)
{
	while (1)
	{
		std::cout << player1->_characterName << " is attacking\n";
		std::cout << "SLASH! " << player1->_characterName << " attacked " << player2->_characterName << "\n";
		std::cout << player2->_characterName << " takes " << player1->_characterAttackPower << " damage\n\n";
		player2->_characterHealth -= player1->_characterAttackPower;

		std::cout << player2->_characterName << " is gonna attack now\n";
		std::cout << "BOOM! " << player2->_characterName << " attacked " << player1->_characterName << "\n";
		std::cout << player1->_characterName << " takes " << player2->_characterAttackPower << " damage\n\n";
		player1->_characterHealth -= player2->_characterAttackPower;

		if (player1->_characterHealth <= 0)
		{
			std::cout << player2->_characterName << " wins!\n\n";
			break;
		}
		else if (player2->_characterHealth <= 0)
		{
			std::cout << player1->_characterName << " wins!\n\n";
			break;
		}
	}
}

void Character::AddItemToInvetory(Weapon weapon)
{
	_inventory.AddItem(weapon);
}

void Character::UseItemFromInventory(std::string item)
{
	_inventory.UseItem(item);
}

void Character::PrintInvetory()
{
	_inventory.displayInventory();
}



