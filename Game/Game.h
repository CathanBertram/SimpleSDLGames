#pragma once

#include "SDL.h"

class Game
{
public:
	Game();
	~Game();

	void Init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);
	void RunGameLoop();
	static void QuitGame();
	
private:
	static bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;

	void HandleEvents();
	void Update();
	void Render();
	void Clean();
	bool Running() { return Game::isRunning; }
	
	SDL_Texture* texture;
	SDL_Rect sourceRect;
	SDL_Rect destinationRect;
};

