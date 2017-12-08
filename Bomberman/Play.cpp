#include "Play.h"



Play::Play()
{
	ReferenceToPlayer = new Player();

	BG.id = 1;
	BG.placeholder.x = 0;
	BG.placeholder.y = 0;
	BG.placeholder.w = SCREEN_WIDTH;
	BG.placeholder.h = SCREEN_HEIGHT;
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
	Renderer::Instance()->renderIMG(BG.id, BG.placeholder);
	ReferenceToPlayer->draw();	
}

void Play::draw()
{
}
