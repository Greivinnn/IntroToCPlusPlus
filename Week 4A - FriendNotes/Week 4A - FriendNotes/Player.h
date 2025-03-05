#pragma once
#include <string>

namespace FriendExample
{
	class Game;

	class Player
	{
	public:
		Player(std::string name);
		void DisplayGameName(Game game);
	private:
		std::string _playerName;
	};
}
