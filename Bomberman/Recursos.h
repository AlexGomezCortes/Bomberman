#pragma once
#include <String>
#include <SDL.h>

enum class GAME_STATE{MENU, RNKING, PLAY}; //asi podemos saber en que estado se encuentra el juego desde cualquier clase


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
	SDL_Rect placeholder; //esto tiene que ser un sdl rect  en vez de tipo struct rect porque sino no podemos pasarlo como argumento a las funciones del renderer
};

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 500;