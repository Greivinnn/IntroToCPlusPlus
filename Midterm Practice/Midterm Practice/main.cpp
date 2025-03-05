#include <iostream>
#include "Weapon.h"
#include "Enemy.h"
#include "EnemySpawner.h"

using namespace RPG;

int main()
{
	Weapon weapon1("Sword", 30, 3, "Uncommon");
	Weapon weapon2("Axe", 15, 2, "Common");
	Weapon weapon3("Baton", 30, 4, "Rare");
	Weapon weapon4("Stick", 10, 3, "Common");
	Weapon weapon5("Shield", 20, 5, "Rare");

	EnemySpawner enemySpawner;
	std::vector<Enemy> enemies = enemySpawner.SpawnEnemies(1);

	for (Enemy enemy : enemies)
	{
		enemy.PrintEnemyDetails();
	}
}
