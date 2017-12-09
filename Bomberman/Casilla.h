#pragma once
#include <deque>
#include <SDL.h>
#include "Recursos.h"

class Casilla
{
public:
	Casilla();
	~Casilla();
protected:
	Image photo;
	virtual void harm();
	virtual void update();
	virtual void draw();

};

