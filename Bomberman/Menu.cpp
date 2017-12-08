#include "Menu.h"

Menu::Menu()
{
	BG_id = 1;
	path = "../res/img/bgGame.jpg";
	BG_Rect.x = 0;
	BG_Rect.y = 0;
	BG_Rect.w = SCREEN_WIDTH;
	BG_Rect.h = SCREEN_HEIGHT;

	Renderer::Instance()->loadIMG(path, BG_id);
	Renderer::Instance()->renderIMG(BG_id, BG_Rect);

	play = new Button();
	play->message.placeHolder.x = play->message.placeHolder.y = 0;
	play->message.placeHolder.w = 200; //por probar
	play->message.placeHolder.h = 100;
}


Menu::~Menu()
{
}

void Menu::eventHandler()
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

		play->eventHandler(evnt);
	}
}

void Menu::update()
{
	play->update();
	if (play->isClicked() == true)
	{
		CurrentGameState = GAME_STATE::PLAY;
	}
	Renderer::Instance()->renderIMG(BG_id, BG_Rect);
}

void Menu::draw()
{
}
