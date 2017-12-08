#pragma once
#include <String>
#include <SDL.h>

enum class GAME_STATE{MENU, RNKING, PLAY}; //asi podemos saber en que estado se encuentra el juego desde cualquier clase

using Color = struct Color { Uint8 r; Uint8 g; Uint8 b; Uint8 a; };

struct Text
{
	std::string path;
    const char* msg;
	int size;
	int id;
	SDL_Rect placeHolder;
	SDL_Color color;
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
	SDL_Texture* Tex;
	int id;
};

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 500;