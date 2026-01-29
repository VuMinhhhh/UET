#include <iostream>
#include "Game.h"

using namespace std;

int main(int argc, char* argv[])
{
    Game game;
    if(game.Init("Sokoban"))
        game.GameLoop();
    game.clean();
    return 0;
}

