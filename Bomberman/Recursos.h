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

struct Rect {
	int x;
	int y;
	int w;
	int h;
};

struct Image {
	std::string path;
	Rect placeholder;
};

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 500;