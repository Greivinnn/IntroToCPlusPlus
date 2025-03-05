#pragma once
#include <vector>
#include "Enemy.h"

namespace RPG
{
	class EnemySpawner
	{
	public:
		std::vector<Enemy> SpawnEnemies(int count);
	};
}
