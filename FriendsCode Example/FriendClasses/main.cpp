#include "Game.h"
#include "Player.h"

int main()
{
    Game game("Battle Royale");
    Player player("Alice");
    player.DisplayGameName(game); // Friend class allows access
    return 0;
}