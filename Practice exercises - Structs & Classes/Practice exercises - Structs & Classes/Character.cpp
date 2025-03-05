#include "Character.h"
#include <iostream>
#include <string>
#include <vector>

using namespace CharacterInfo;

Character::Character(std::string name, int health, int damage)
	:M_characterName(name), M_health(health), M_damage(damage)
{
}

void Character::TakeDamage(int damageAmount)
{
	M_health -= damageAmount;
}

void Character::PrintStats()
{
	std::cout << "Name: " << M_characterName << "\nHealth: " << M_health << "hp\nAttack Damage: " << M_damage << "\n\n";
}

int Character::GetDamage()
{
	return M_damage;
}

