#include "Game.h"
#include <iostream>
#include "Utilities/Input.h"
#include "Utilities/Time.h"
#include <string>
#include "SDL_image.h"

bool Game::isRunning;

Game::Game()
{
	isRunning = true;
}

Game::~Game()
{
}

void Game::Init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)//Try Initialise SDL
	{
		std::cout << "Subsystems Not Initialised" << std::endl;
		isRunning = false;
		return;
	}
	std::cout << "Subsystems Initialised" << std::endl;
	
	int flags = 0;
	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;

	window = SDL_CreateWindow(title, xPos, yPos, width, height, flags); //Try Create Window
	if (!window)
	{
		std::cout << "Window Could Not Be Created" << std::endl;
		isRunning = false;
		return;
	}
	std::cout << "Window Created" << std::endl;

	renderer = SDL_CreateRenderer(window, -1, 0); //Create Renderer

	if (!renderer)
	{
		std::cout << "Renderer Could Not Be Created" << std::endl;
		isRunning = false;
		return;
	}
	std::cout << "Renderer Created" << std::endl;

	SDL_Surface* surface = IMG_Load("Assets/Sprites/01_mining.png");
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	Time::Initialise();
}

void Game::RunGameLoop()
{
	while (Running())
	{
		Time::UpdateTime();

		HandleEvents();
		Update();
		Render();

		Input::UpdateInput();

		Time::CapFramerate();
	}

	Clean();
}

void Game::HandleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			QuitGame();
			break;
		case SDL_KEYDOWN:
			Input::HandleEvent(event);
			break;
		case SDL_KEYUP:
			Input::HandleEvent(event);
		default:
			break;
		}
	}
}
void Game::Update()
{
	if (Input::GetKeyDown(SDLK_w))
	{
		std::cout << "Remove Framerate Cap" << std::endl;
		Time::LimitFramerate(false);
	}
	/*else
		std::cout << "Key Not Down" << std::endl;*/

	if (Input::GetKeyDownThisFrame(SDLK_s))
	{
		std::cout << "LimitFramerate" << std::endl;
		Time::LimitFramerate(true, 60);
	}
	     
	if (Input::GetKeyDownThisFrame(SDLK_ESCAPE))
		QuitGame();

	std::cout << std::to_string(Time::DeltaTime()) << std::endl;

	destinationRect.h = 128;
	destinationRect.w = 128;
	destinationRect.x = 136;
	destinationRect.y = 99;

}

void Game::Render()
{
	SDL_RenderClear(renderer);

	//Render Stuff

	SDL_RenderCopy(renderer, texture, NULL, &destinationRect);

	SDL_RenderPresent(renderer);
}

void Game::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}

void Game::QuitGame()
{
	isRunning = false;
}
