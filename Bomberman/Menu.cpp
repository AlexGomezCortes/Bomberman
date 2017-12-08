#include "Menu.h"

Menu::Menu()
{
	BG.path = "../res/img/bgGame.jpg";
	BG.placeholder.x = 0;
	BG.placeholder.y = 0;
	BG.placeholder.w = SCREEN_WIDTH;
	BG.placeholder.h = SCREEN_HEIGHT;

	BG.id=Renderer::Instance()->loadIMG(BG.path);

	play = new Button();                                            //declaramos todos los botones
	play->message.placeHolder.w = 100; 
	play->message.placeHolder.h = 50;
	play->message.placeHolder.x = SCREEN_WIDTH/2-play->message.placeHolder.w/2;
	play->message.placeHolder.y = SCREEN_HEIGHT*0.25;
	play->message.size = 20;
	play->message.color = { 0,0,0,255 };
	play->message.msg = "PLAY";

	ranking = new Button();
	ranking->message.placeHolder.w = 100;
	ranking->message.placeHolder.h = 50;
	ranking->message.placeHolder.x = SCREEN_WIDTH / 2 - ranking->message.placeHolder.w / 2;
	ranking->message.placeHolder.y = SCREEN_HEIGHT*0.5;
	ranking->message.size = 20;
	ranking->message.color = { 0,0,0,1 };
	ranking->message.msg = "RANKING";

	exit = new Button();
	exit->message.placeHolder.w = 100;
	exit->message.placeHolder.h = 50;
	exit->message.placeHolder.x = SCREEN_WIDTH / 2 - exit->message.placeHolder.w / 2;
	exit->message.placeHolder.y = SCREEN_HEIGHT*0.75;
	exit->message.size = 20;
	exit->message.color = { 0,0,0, 1};
	exit->message.msg = "EXIT";
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

		if (play->isClicked() == true)
		{
			CurrentGameState = GAME_STATE::PLAY;
		}
		if (ranking->isClicked() == true)
		{
			CurrentGameState = GAME_STATE::RNKING;
			std::cout << "entro ranking" << std::endl;
		}
		if (exit->isClicked() == true)
		{
			Renderer::Instance()->~Renderer();
		}

		play->eventHandler(evnt);
		ranking->eventHandler(evnt);
		exit->eventHandler(evnt);
	}
}

void Menu::update()
{
	play->update();
	ranking->update();
	exit->update();

	

	
}

void Menu::draw()
{
	

	Renderer::Instance()->renderIMG(BG.id, BG.placeholder);

	play->draw();
	ranking->draw();
	exit->draw();
}
