#include "Enemy.h"
#include <iostream>

using namespace RPG;

Enemy::Enemy(std::string type, int health, int damage)
	:_type(type), _health(health), _damage(damage)
{
}

void Enemy::PrintEnemyDetails()
{
	std::cout << "Type: " << _type << "\n";
	std::cout << "Health: " << _health << "\n";
	std::cout << "Damage: " << _damage << "\n";
}