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

	board = new Casilla**[15];
	for (int i = 0; i < 15; ++i) {
		board[i] = new Casilla*[13];
	}

	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 13; ++j) {
			if (i == 0 || i == 14 || j == 0 || j == 12) {
				board[i][j] = new Bloque();
				board[i][j]->photo.placeholder.x = i * 48;
				board[i][j]->photo.placeholder.y = j * 48 + 80;
			}
			else if ((j == 2 || j == 4 || j == 6 || j == 8 || j == 10) && (i == 2 || i == 4 || i == 6 || i == 8 || i == 10 || i == 12)) {
				board[i][j] = new Bloque();
				board[i][j]->photo.placeholder.x = i * 48;
				board[i][j]->photo.placeholder.y = j * 48 + 80;
			}
			else {
				board[i][j] = nullptr;
			}
			
		}
	}
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
		users.first->eventHandler();
		users.second->eventHandler();
	}
}

void Play::update()
{
	interfaz->update();
	users.first->update();
	users.second->update();

	if(users.first->getSpeed().first!=0 || users.first->getSpeed().second != 0) //tremen cacao vamos a tener para comprobar todas las colisiones
		users.first->correctPosition(users.second);
	if (users.second->getSpeed().first != 0 || users.second->getSpeed().second != 0)
		users.second->correctPosition(users.first);
	
	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 13; ++j) {
			if (board[i][j] != nullptr) {
					users.first->correctPosition(board[i][j]);
					users.second->correctPosition(board[i][j]);
			}
		}
	}
}

void Play::draw()
{
	Renderer::Instance()->renderIMG(bg.id, bg.placeholder);
	
	users.first->draw();
	users.second->draw();

	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 13; ++j) {
			if(board[i][j]!=nullptr)
				board[i][j]->draw();
		}
	}

	interfaz->draw();
}
