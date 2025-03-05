#pragma once
#include <string>

namespace FriendExample
{
	class Game
	{
	public:
		Game(std::string name);
		friend class Player;
	private:
		std::string _gameName;
	};
}
