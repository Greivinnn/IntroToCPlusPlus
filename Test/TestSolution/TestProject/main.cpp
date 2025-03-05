#include "Character.h"
#include "Weapon.h"
#include "Inventory.h"
#include "Enemy.h"
#include <time.h>

#include <array>

using namespace Practice;

namespace
{
	void IncreaseWeaponDamageBy10Percent(Weapon& weapon)
	{
		weapon.IncreaseDamageByPercent(10);
	}

	std::array<Enemy, 3> SpawnEnemies()
	{
		int typeNum1 = rand() % 2;
		int typeNum2 = rand() % 2;
		int typeNum3 = rand() % 2;

		int health1 = rand() % 100 + 1;
		int health2 = rand() % 100 + 1;
		int health3 = rand() % 100 + 1;

		int damage1 = rand() % 10 + 1;
		int damage2 = rand() % 10 + 1;
		int damage3 = rand() % 10 + 1;
		
		std::array<Enemy, 3> enemies = {
			Enemy(typeNum1 == 0 ? "Zombie" : "Skeleton", health1, damage1),
			Enemy(typeNum2 == 0 ? "Zombie" : "Skeleton", health2, damage2),
			Enemy(typeNum3 == 0 ? "Zombie" : "Skeleton", health3, damage3) };

		return enemies;
	}
}

int main()
{
	srand(time(NULL));

	// 1
	Character player("master chief", 100, 20);
	Character enemy("snake", 30, 5);

	player.TakeDamage(enemy.GetDamage());

	player.PrintStats();
	enemy.PrintStats();

	system("cls");
	// 2
	Weapon sword("sword", 10, "common");
	Weapon pistol("pistol", 20, "rare");
	Weapon axe("axe", 30, "epic");

	IncreaseWeaponDamageBy10Percent(sword);

	sword.PrintWeaponDetails();

	system("cls");
	// 3
	Inventory inventory;
	inventory.AddWeapon(sword);
	inventory.AddWeapon(pistol);
	inventory.AddWeapon(axe);

	inventory.PrintInventory();

	inventory.RemoveWeapon("pistol");

	inventory.PrintInventory();

	Weapon hammer("hammer", 50, "common");
	Weapon dagger("dagger", 70, "rare");
	Weapon rifle("rifle", 100, "epic");
	Weapon shotgun("shotgun", 120, "epic");

	inventory.AddWeapon(hammer);
	inventory.AddWeapon(dagger);
	inventory.AddWeapon(rifle);
	inventory.AddWeapon(shotgun);

	inventory.PrintInventory();

	system("cls");
	// 4
	std::array<Enemy, 3> enemies = SpawnEnemies();
	for (Enemy enemy : enemies)
	{
		enemy.PrintEnemyDetails();
	}

	enemies[0].TakeDamage(player.GetDamage());
	enemies[0].PrintEnemyDetails();

	system("cls");

	return 0;
}