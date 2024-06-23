#pragma once
#include "SDL.h"
class Time
{
public:
	static void Initialise();
	static float DeltaTime();
	static void UpdateTime();

private:
	static Uint64 lastFrameTime;
	static float deltaTime;
};

