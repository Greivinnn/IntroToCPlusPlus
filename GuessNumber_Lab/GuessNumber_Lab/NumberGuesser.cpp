#include <iostream>
#include <stdexcept>
#include "NumberGuesser.h"
#include "GameException.h"
#include <time.h>

using namespace Lab;

NumberGuesser::NumberGuesser()
{
	srand(time(NULL));
	targetNumber = rand() % 50 + 1;
	hasWon = false;
}

void NumberGuesser::GuessTheNumber()
{
	int num;
	std::cout << "Guess the number 1-50: ";
	std::cin >> num;

	if (num == targetNumber)
	{
		std::cout << "You have won the game!\n";
		hasWon = true;
		return;
	}
	else if (num <= 0 || num > 50)
	{
		throw GameException("Out of range 1-50 inclusive only.\n");
	}
	else if (num > targetNumber)
	{
		std::cout << "Number is too high\n";
	}
	else if (num < targetNumber)
	{
		std::cout << "Number is too low\n";
	}
}

void NumberGuesser::PlayGame()
{
	while (!hasWon)
	{
		try
		{
			GuessTheNumber();
		}
		catch (GameException ex)
		{
			std::cout << "Caught an exception: " << ex.what() << "\n";
		}
	}

	std::cout << "Game Over! Thanks for playing.\n";
}