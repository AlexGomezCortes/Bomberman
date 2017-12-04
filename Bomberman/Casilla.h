#pragma once
#include <deque>
#include <SDL.h>
class Casilla
{
public:
	Casilla();
	~Casilla();
protected:
	int spriteID;
	std::deque <SDL_Texture*> sprites;
private:
	SDL_Rect placeHolder;
	virtual void harm();
	virtual void update();
	virtual void draw();

};

