#pragma once
#include <String>
#include <SDL.h>

enum class GAME_STATE{MENU, RNKING, PLAY}; //asi podemos saber en que estado se encuentra el juego desde cualquier clase

using Color = struct Color { Uint8 r; Uint8 g; Uint8 b; Uint8 a; };

struct Text
{
	std::string path; //path de la fuente
    std::string msg;  //lo que se quiere escribir
	int size;		  //tamaño de la fuente
	SDL_Rect placeHolder; //rectángulo en el que se escribirá
	SDL_Color color;		//color del texto
	int id;
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