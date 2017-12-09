#include "Play.h"



Play::Play()
{
	bg.placeholder.x = 0;
	bg.placeholder.y = 0;
	bg.placeholder.w = SCREEN_WIDTH;
	bg.placeholder.h = SCREEN_HEIGHT;
	bg.path = PATH_BG;

	users.first = new Player(1);
	users.second = new Player(2);

	interfaz = new HUD(users);
}


Play::~Play()
{
}

void Play::eventHandler()
{
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt)) {
		switch (evnt.type) {
		case SDL_QUIT:
			active = false;
			break;
		case SDL_WINDOWEVENT_MOVED:
			break;
		}
	}
}

void Play::update()
{
	interfaz->update();
}

void Play::draw()
{
	Renderer::Instance()->renderIMG(bg.id, bg.placeholder);
	
	users.first->draw();
	users.second->draw();

	interfaz->draw();
}
