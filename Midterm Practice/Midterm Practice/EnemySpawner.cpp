#include "EnemySpawner.h"

using namespace RPG;

std::vector<Enemy> EnemySpawner::SpawnEnemies(int count)
{
	std::vector<Enemy> enemies;

	for (int i = 0; i < count; i++)
	{
		int typeNum = rand() % 2;
		int health = rand() % 100 + 1;
		int damage = rand() % 10 + 1;

		enemies.push_back(Enemy(typeNum == 0 ? "Zombie" : "Skeleton", health, damage));
	}

	return enemies;
}