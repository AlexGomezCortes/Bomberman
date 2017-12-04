#pragma once
#include <SDL.h>
#include <string>
class Text
{
public:
	Text();
	~Text();

	std::string path;
	std::string msg;
	int size;
	SDL_Rect placeHolder;
};

