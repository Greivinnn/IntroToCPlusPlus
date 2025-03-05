#pragma once
#include <time.h>
#include <iostream>

namespace Lab
{
	class NumberGuesser
	{
	public:
		NumberGuesser();
		void GuessTheNumber();
		bool hasWon;
		void PlayGame();
		int targetNumber;
	};
}