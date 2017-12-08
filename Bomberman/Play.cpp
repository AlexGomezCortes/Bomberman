#include "Play.h"



Play::Play()
{
	path = "../res/img/bgGame.jpg";
	BG_id = 2;
	BG_Rect.x = BG_Rect.y = 0;
	BG_Rect.w = SCREEN_WIDTH;
	BG_Rect.h = SCREEN_HEIGHT;

	Renderer::Instance()->loadIMG(path, BG_id);

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

	Renderer::Instance()->renderIMG(BG_id, BG_Rect);
}

void Play::draw()
{
}
