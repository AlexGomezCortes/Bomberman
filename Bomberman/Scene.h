#pragma once
#include "Button.h"
#include <SDL.h>
#include <deque>

class Scene
{
public:
	Scene();
	~Scene();

	virtual void eventHandler();
	virtual void update();
	virtual void draw();
protected:
	SDL_Texture* BG;
	std::deque <Button> buttonList;
};

