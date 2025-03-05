#include "Character.h"
#include <iostream>

using namespace Practice;

Character::Character(std::string name, int health, int damage)
	: _name(name), _health(health), _damage(damage)
{
}

void Character::TakeDamage(int amount)
{
	_health -= amount;
}

void Character::PrintStats()
{
	std::cout << "Name: " << _name << "\n";
	std::cout << "Health: " << _health << "\n";
	std::cout << "Damage: " << _damage << "\n";
}

int Character::GetDamage()
{
	return _damage;
}