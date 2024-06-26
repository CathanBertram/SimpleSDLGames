#include "Time.h"

float Time::deltaTime;
Uint64 Time::frameStartTime;
bool Time::limitFramerate;
float Time::targetFrameTime;

void Time::Initialise()
{
	frameStartTime = SDL_GetPerformanceCounter();
}

float Time::DeltaTime()
{
	return deltaTime;
}
void Time::LimitFramerate(bool limit, int maxFrameRate)
{
	limitFramerate = limit;
	targetFrameTime = 1000.0f / (float)maxFrameRate;
}

void Time::UpdateTime()
{
	auto counter = SDL_GetPerformanceCounter();
	deltaTime = (float)(counter - frameStartTime) / (float)SDL_GetPerformanceFrequency();
	frameStartTime = counter;
}

void Time::CapFramerate()
{
	if (!limitFramerate) return;
	auto endFrameTime = SDL_GetPerformanceCounter();
	auto totalFrameTime = (float)(endFrameTime - frameStartTime) / (float)SDL_GetPerformanceFrequency();

	if (totalFrameTime >= targetFrameTime) return;

	SDL_Delay(targetFrameTime - totalFrameTime);
}
