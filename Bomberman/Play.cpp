#include "Play.h"



Play::Play()
{
	ReferenceToPlayer = new Player();
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
	ReferenceToPlayer->draw();
}

void Play::draw()
{
}
