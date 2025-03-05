#include <iostream>
#include <string>
#include "Character.h"
#include "Weapon.h"
#include "Inventory.h"

using namespace Midterm;

int main()
{
	/*

	// Task 1
	Character player1("Alfredo", 50, 10, 20);
	Character player2("Santi", 70, 5, 15);

	std::cout << "Character Details Test:\n\n";

	player1.DisplayStats();
	player2.DisplayStats();

	player1.takeDamage(player2.GetDamage());
	player2.AttackFunction(&player1);

	std::cout << "Players attacked each other, new stats:\n\n";

	player1.DisplayStats();
	player2.DisplayStats();
	// everything works

	// Task 2
	player1.BattleFunction(&player1, &player2);

	player1.DisplayStats();
	player2.DisplayStats();
	//Battle function works

	// Task 3
	Weapon weapon1("Sword", 20, "Uncommon");
	Weapon weapon2("Axe", 15, "Common");
	Weapon weapon3("Baton", 30, "Rare");
	Weapon weapon4("Shoe", 10, "Rare");
	Weapon weapon5("Snowball", 5, "Common");

	Inventory Inventory1;

	Inventory1.AddItem(weapon1);
	Inventory1.AddItem(weapon2);
	Inventory1.AddItem(weapon3);
	Inventory1.displayInventory();

	Inventory1.UseItem("Sword");
	Inventory1.UseItem("Sword");
	// this works as well 

	// Task 4
	player1.AddItemToInvetory(weapon1);
	player1.AddItemToInvetory(weapon2);
	player1.AddItemToInvetory(weapon3);
	std::cout << player1.GetName() << " inventory:\n\n";
	player1.UseItemFromInventory("Sword");
	player1.PrintInvetory();

	player2.AddItemToInvetory(weapon4);
	player2.AddItemToInvetory(weapon5);
	std::cout << player2.GetName() << " inventory:\n\n";
	player2.UseItemFromInventory("Shoe");
	player2.PrintInvetory();
	// everything works perfectly

	*/

	// By the way I ran task 5 specifically by itself like this. Because I did not want to scroll all the way down all the time. When I ran my code
	// i would reccomend doing the same, since the players and weapons are repeated in task 5
	//	Task 5
	Character player1("Alfredo", 50, 10, 20);
	Character player2("Santi", 70, 5, 15);

	Weapon weapon1("Sword", 20, "Uncommon");
	Weapon weapon2("Axe", 15, "Common");
	Weapon weapon3("Baton", 30, "Rare");

	player1.AddItemToInvetory(weapon1);
	player1.AddItemToInvetory(weapon2);
	player1.AddItemToInvetory(weapon3);

	player2.AddItemToInvetory(weapon1);
	player2.AddItemToInvetory(weapon2);
	player2.AddItemToInvetory(weapon3);

	Inventory inventory2;

	std::cout << "Prepare for battle!\n\n";

	inventory2.CharacterBattleFunction(&player1, &player2);
	// this does run but it does not meet the some requirements, it is lacking the fighting implementation, the medkit function works well
	// maybe next time I should try making the battle function in another CPP instead of Inventory CPP, maybe create a new class called "Battle" 
	// I honestly forgot why I started using the inventory CPP but we are too deep in the rabbit hole now and I do not want to mess my code up haha
}

