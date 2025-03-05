#include "Character.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include "CharacterExceptions.h"

using namespace Practice;

Character::Character(std::string name, int health, int attackPower)
{
	try
	{
		if (health <= 0)
		{
			throw CharacterExceptions("Character cannot have negative or zero health.");
		}
		if (attackPower >= 100)
		{
			throw CharacterExceptions("Character cannot have more than 99 attack damage.");
		}

		_characterName = name;
		_characterHealth = health;
		_attackPower = attackPower;
	}
	catch (CharacterExceptions ex)
	{
		std::cout << "Caught an exception: " << ex.what() << "\n";
	}
	
}

void Character::TakeDamage(int damage)
{
	_characterHealth -= damage;
}

void Character::Fight(Character char1, Character char2)
{
	try
	{
		while (char1._characterHealth != 0 || char2._characterHealth != 0 || char1._characterHealth < 0 || char2._characterHealth < 0)
		{
			if (char1._characterHealth <= 0)
			{
				throw CharacterExceptions("Character 1 is dead, Character 2 wins");
				return;
			}
			if (char2._characterHealth <= 0)
			{
				throw CharacterExceptions("Character 2 is dead, Character 1 wins");
				return;
			}

			std::cout << char2._characterName << " attacking...\n\n";
			char1.TakeDamage(char2._attackPower);

			std::cout << char1._characterName << " attacking...\n\n";
			char2.TakeDamage(char1._attackPower);
		}
		
	}
	catch (CharacterExceptions ex)
	{
		std::cout << "Caught an exception: " << ex.what() << "\n";
	}
}