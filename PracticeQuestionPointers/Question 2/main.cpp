#include <iostream>
#include "Player.h"
#include <iostream>

using namespace Practice;

int main()
{
	// Create teo Player objects
	Player player1("David", 100, 20);
	Player player2("Ron", 140, 30);
	
	// Here we change player's 1 health with a pointer
	Player* ptr = &player1;
	ptr->setHealth(120); 

	// Double pointer use to swap each player's mana 
	Player** doublePtr = &ptr;	// since we already have 
	int tempMana = (*doublePtr)->getMana();	// get the mana of the first player and store it in int tempMana
	(*doublePtr)->setMana(player2.getMana()); //doublePtr has player's 1 mana we will change it to be pointing to the Mana of player2
	ptr = &player2; // now we set ptr to be player 2
	ptr->setMana(tempMana);

	// Print out the results to verify
	std::cout << "Player 1 (" << player1.GetName() << ") has health: " << player1.getHealth() << " has mana: " << player1.getMana() << "\n";
	std::cout << "Player 2 (" << player2.GetName() << ") has health: " << player1.getHealth() << " has mana: " << player2.getMana() << "\n";

	return 0;
}