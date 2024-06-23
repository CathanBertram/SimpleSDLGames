#pragma once
#include <SDL.h>
#include <map>

enum KeyState
{
	PRESSED,
	PRESSED_THIS_FRAME,
	RELEASED,
	RELEASED_THIS_FRAME
};

class Input
{
public:
	static bool GetKeyDownThisFrame(SDL_KeyCode key);
	static bool GetKeyUpThisFrame(SDL_KeyCode key);
	static bool GetKeyDown(SDL_KeyCode key);
	static void HandleEvent(SDL_Event event);
	static void UpdateInput();
private:
	typedef std::map<SDL_Keycode, KeyState> InputMap;
	static InputMap inputMap;
	static SDL_Event event;

	static void HandleKeyDownEvent(SDL_Event event);
	static void HandleKeyUpEvent(SDL_Event event);

};

