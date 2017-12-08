#include "Menu.h"

Menu::Menu()
{
	BG.id = 1;
	BG.path = "../res/img/bgGame.jpg";
	BG.placeholder.x = 0;
	BG.placeholder.y = 0;
	BG.placeholder.w = SCREEN_WIDTH;
	BG.placeholder.h = SCREEN_HEIGHT;

	Renderer::Instance()->loadIMG(BG.path, BG.id);
	Renderer::Instance()->renderIMG(BG.id, BG.placeholder);
	Renderer::Instance()->loadFont(Renderer::Instance()->SaiyanText);
	Renderer::Instance()->loadFont(Renderer::Instance()->GameoverText);

	play = new Button();                                            //declaramos todos los botones
	play->message.placeHolder.x = 100;
	play->message.placeHolder.y = 100;
	play->message.placeHolder.w = 100; //por probar
	play->message.placeHolder.h = 50;
	play->message.size = 20;
	play->message.color = { 0,0,0,1 };
	play->message.msg = "PLAY";

	ranking = new Button();
	ranking->message.placeHolder.x = 100;  
	ranking->message.placeHolder.y = 250;
	ranking->message.placeHolder.w = 100; 
	ranking->message.placeHolder.h = 50;
	ranking->message.size = 20;
	ranking->message.color = { 0,0,0,1 };
	ranking->message.msg = "RANKING";

	exit = new Button();
	exit->message.placeHolder.x = 100;
	exit->message.placeHolder.y = 400;
	exit->message.placeHolder.w = 100;
	exit->message.placeHolder.h = 50;
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

	play->draw(play->message);
	ranking->draw(ranking->message);
	exit->draw(exit->message);

	Renderer::Instance()->renderIMG(BG.id, BG.placeholder);
}

void Menu::draw()
{
}
