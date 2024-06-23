#include "Input.h"
#include <iostream>

Input::InputMap Input::inputMap;
SDL_Event Input::event;

bool Input::GetKeyDownThisFrame(SDL_KeyCode key)
{
	auto it = inputMap.find(key);
	if (it == inputMap.end())
		return false;

	if (it->second == KeyState::PRESSED_THIS_FRAME)
		return true;
	return false;
}

bool Input::GetKeyUpThisFrame(SDL_KeyCode key)
{
	auto it = inputMap.find(key);
	if (it == inputMap.end())
		return false;

	if (it->second == KeyState::RELEASED_THIS_FRAME)
		return true;
	return false;
}

bool Input::GetKeyDown(SDL_KeyCode key)
{
	auto it = inputMap.find(key);
	if (it == inputMap.end())
		return false;

	if (it->second == KeyState::PRESSED || it->second == KeyState::PRESSED_THIS_FRAME)
		return true;

	return false;
}

void Input::UpdateInput()
{
	if (inputMap.empty()) return;

	for (auto it = inputMap.begin(); it != inputMap.end(); it++)
	{
		if (it->second == KeyState::RELEASED_THIS_FRAME)
			it->second = KeyState::RELEASED;
		else if (it->second == KeyState::PRESSED_THIS_FRAME)
			it->second = KeyState::PRESSED;
	}

	//for (auto kvp : inputMap)
	//{
	//	if (kvp.second == KeyState::RELEASED_THIS_FRAME)
	//		kvp.second = KeyState::RELEASED;
	//	else if (kvp.second == KeyState::PRESSED_THIS_FRAME)
	//		kvp.second = KeyState::PRESSED;
	//}
}

void Input::HandleEvent(SDL_Event event)
{
	if (event.key.repeat) return;

	if (event.type == SDL_KEYDOWN)
		HandleKeyDownEvent(event);
	else if (event.type == SDL_KEYUP)
		HandleKeyUpEvent(event);
}

void Input::HandleKeyDownEvent(SDL_Event event)
{
	auto key = event.key.keysym.sym;
	inputMap[key] = KeyState::PRESSED_THIS_FRAME;
}
void Input::HandleKeyUpEvent(SDL_Event event)
{
	auto key = event.key.keysym.sym;
	inputMap[key] = KeyState::RELEASED_THIS_FRAME;
}

