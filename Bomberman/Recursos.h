#pragma once
#include <String>
#include <SDL.h>

struct Text
{
	std::string path;
	std::string msg;
	int size;
	SDL_Rect placeHolder;
};