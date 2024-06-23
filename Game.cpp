#include "Game.h"
#include <iostream>
#include "Input.h"
#include "Time.h"
#include<string>
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
			isRunning = false;
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
		std::cout << "Key Down" << std::endl;
	/*else
		std::cout << "Key Not Down" << std::endl;*/

	if (Input::GetKeyDownThisFrame(SDLK_s))
	{
		std::cout << "S" << std::endl;
		//SDL_Delay(1000);
	}
	     
	//std::cout << std::to_string(Time::DeltaTime()) << std::endl;
}

void Game::Render()
{
	SDL_RenderClear(renderer);

	//Render Stuff

	SDL_RenderPresent(renderer);
}

void Game::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}
