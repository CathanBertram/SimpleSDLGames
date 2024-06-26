#pragma once
#include "SDL.h"
class Time
{
public:
	static void Initialise();
	static float DeltaTime();
	static void UpdateTime();
	static void CapFramerate();


	static void LimitFramerate(bool limit, int maxFrameRate = 144);
private:
	static Uint64 frameStartTime;
	static float deltaTime;

	static bool limitFramerate;
	static float targetFrameTime;
};

