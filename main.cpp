#include <iostream>

#include "SDL.h"
#include "Game/Game.h"

int main(int argc, char* argv[])
{
	Game* game = new Game();
	game->Init("Simple SDL Games", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, false);
	game->RunGameLoop();


	return 0;
}