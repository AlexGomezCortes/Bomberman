#pragma once
#include <deque>
#include <SDL.h>
#include "Recursos.h"
#include "Renderer.h"

class Casilla
{
public:
	Casilla();
	~Casilla();

	std::pair<int, int> getCenter(SDL_Rect other);
	bool doCollide(Casilla other);
	void correctPosition(Casilla* other);

	virtual void harm();
	virtual void update();
	virtual void draw();

	Image photo;
	
};

