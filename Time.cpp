#include "Time.h"

float Time::deltaTime = 0;
Uint64 Time::lastFrameTime = 0;

void Time::Initialise()
{
	lastFrameTime = SDL_GetPerformanceCounter();
}

float Time::DeltaTime()
{
	return deltaTime;
}

void Time::UpdateTime()
{
	auto counter = SDL_GetPerformanceCounter();
	deltaTime = (float)(counter - lastFrameTime) / (float)SDL_GetPerformanceFrequency();
	lastFrameTime = counter;
}
