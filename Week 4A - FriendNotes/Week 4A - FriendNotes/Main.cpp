#include "Player.h"
#include "Game.h"
#include <iostream>

using namespace FriendExample;

int main()
{
	Game game("Halo");
	Player player("bobby");
	player.DisplayGameName(game);
}