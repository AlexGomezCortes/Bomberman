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

	//ACTUALIZAR BOARD CON LOS PUNTEROS A LOS PLAYERS
	board[users.first->getCenter().first / 48][(users.first->getCenter().second - 80) / 48] = users.first;
	board[users.second->getCenter().first / 48][(users.second->getCenter().second - 80) / 48] = users.second;

	//COLISIONES ENTRE PLAYERS
	if(users.first->getSpeed().first!=0 || users.first->getSpeed().second != 0) //tremen cacao vamos a tener para comprobar todas las colisiones
		users.first->correctPosition(users.second);
	if (users.second->getSpeed().first != 0 || users.second->getSpeed().second != 0)
		users.second->correctPosition(users.first);
	
	//COLISIONES ENTRE PLAYER Y ESCENARIO
	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 13; ++j) {
			if (board[i][j] != nullptr) {
				if (board[i][j]->whoIam!=TIPO_CASILLA::PLAYER) {
					users.first->correctPosition(board[i][j]);
					users.second->correctPosition(board[i][j]);
				}
				board[i][j]->update();
				if (!((i == users.first->getCenter().first / 48) && j == (users.first->getCenter().second - 80) / 48) && !((i == users.second->getCenter().first / 48) && j == (users.second->getCenter().second - 80) / 48) && (board[i][j]->whoIam==TIPO_CASILLA::PLAYER)) {
					board[i][j] = nullptr; //CUANDO EL PLAYER SALE DE UNA CASILLA, ESTA DEJA DE APUNTAR A ÉL
				}	
				if (board[i][j]!=nullptr) {
					if (board[i][j]->killMe)
						board[i][j] = nullptr;
				}
			}
		}
	}

	if (users.first->myBomb != nullptr && bombList.first == nullptr) {
		bombList.first = users.first->myBomb;
		bombList.first->photo.placeholder.x = static_cast<int>((users.first->getCenter().first / 48.0f))*48;
		bombList.first->photo.placeholder.y = static_cast<int>(((users.first->getCenter().second - 80) / 48.0f)) * 48 + 80;
	}
	else if (users.first->myBomb == nullptr && bombList.first == nullptr && !users.first->canBomb) {
		users.first->canBomb = true;
	}

	if (users.second->myBomb != nullptr && bombList.second == nullptr) {
		bombList.second = users.second->myBomb;
		bombList.second->photo.placeholder.x = static_cast<int>((users.second->getCenter().first / 48.0f)) * 48;
		bombList.second->photo.placeholder.y = static_cast<int>(((users.second->getCenter().second - 80) / 48.0f)) * 48 + 80;
	}
	else if (users.second->myBomb == nullptr && bombList.second == nullptr && !users.second->canBomb) {
		users.second->canBomb = true;
	}

	std::cout << static_cast<int>(((users.first->getCenter().second-80) / 48.0f))*48 << std::endl;

	if (bombList.first != nullptr) {
		
		bombList.first->update();
		if (bombList.first->collideWithPlayer) {
			users.first->correctPosition(bombList.first);
		}
		else if (!bombList.first->doCollide(*users.first)) {
			bombList.first->collideWithPlayer = true;
		}

		if (bombList.first->isExploding) {
			bool isBlock = false;
			for (int j = 0; j < 3 && !isBlock; ++j) {
				if (board[bombList.first->getCenter().first / 48 + j][(bombList.first->photo.placeholder.y - 80) / 48] != nullptr) {
					switch (board[bombList.first->getCenter().first / 48 + j][(bombList.first->photo.placeholder.y - 80) / 48]->whoIam) {
					case TIPO_CASILLA::BLOQUE:
						isBlock = true;
						break;
					case TIPO_CASILLA::MURO:
						board[bombList.first->photo.placeholder.x / 48 + j][(bombList.first->photo.placeholder.y - 80) / 48]->harm();
						board[bombList.first->photo.placeholder.x / 48 + j][(bombList.first->photo.placeholder.y - 80) / 48] = new Explosion();
						isBlock = true;
						break;
					case TIPO_CASILLA::PLAYER:
						int localX, localY;
						localX = board[bombList.first->photo.placeholder.x / 48 + j][(bombList.first->photo.placeholder.y - 80) / 48]->photo.placeholder.x;
						localY = board[bombList.first->photo.placeholder.x / 48 + j][(bombList.first->photo.placeholder.y - 80) / 48]->photo.placeholder.y;
						board[bombList.first->photo.placeholder.x / 48 + j][(bombList.first->photo.placeholder.y - 80) / 48]->harm();
						board[bombList.first->photo.placeholder.x / 48 + j][(bombList.first->photo.placeholder.y - 80) / 48]->photo.placeholder.x = 48;
						board[bombList.first->photo.placeholder.x / 48 + j][(bombList.first->photo.placeholder.y - 80) / 48]->photo.placeholder.y = 48+80;
						board[bombList.first->photo.placeholder.x / 48 + j][(bombList.first->photo.placeholder.y - 80) / 48] = new Explosion();
						board[bombList.first->photo.placeholder.x / 48 + j][(bombList.first->photo.placeholder.y - 80) / 48]->photo.placeholder.x = localX;
						board[bombList.first->photo.placeholder.x / 48 + j][(bombList.first->photo.placeholder.y - 80) / 48]->photo.placeholder.y = localY;
						break;
					}
				}
				else {
					board[bombList.first->photo.placeholder.x / 48 + j][(bombList.first->photo.placeholder.y - 80) / 48] = new Explosion();
					board[bombList.first->photo.placeholder.x / 48 + j][(bombList.first->photo.placeholder.y - 80) / 48]->photo.placeholder.x = bombList.first->photo.placeholder.x + j*48;
					board[bombList.first->photo.placeholder.x / 48 + j][(bombList.first->photo.placeholder.y - 80) / 48]->photo.placeholder.y = (bombList.first->photo.placeholder.y);
				}
			}
			isBlock = false;
			for (int j = 1; j < 3 && !isBlock; ++j) {
				if (board[bombList.first->getCenter().first / 48 - j][(bombList.first->photo.placeholder.y - 80) / 48] != nullptr) {
					switch (board[bombList.first->photo.placeholder.x / 48 - j][(bombList.first->photo.placeholder.y - 80) / 48]->whoIam) {
					case TIPO_CASILLA::BLOQUE:
						isBlock = true;
						break;
					case TIPO_CASILLA::MURO:
						board[bombList.first->photo.placeholder.x / 48 - j][(bombList.first->photo.placeholder.y - 80) / 48]->harm();
						board[bombList.first->photo.placeholder.x / 48 - j][(bombList.first->photo.placeholder.y - 80) / 48] = new Explosion();
						isBlock = true;
						break;
					case TIPO_CASILLA::PLAYER:
						int localX, localY;
						localX = board[bombList.first->photo.placeholder.x / 48 - j][(bombList.first->photo.placeholder.y - 80) / 48]->photo.placeholder.x;
						localY = board[bombList.first->photo.placeholder.x / 48 - j][(bombList.first->photo.placeholder.y - 80) / 48]->photo.placeholder.y;
						board[bombList.first->photo.placeholder.x / 48 - j][(bombList.first->photo.placeholder.y - 80) / 48]->harm();
						board[bombList.first->photo.placeholder.x / 48 - j][(bombList.first->photo.placeholder.y - 80) / 48]->photo.placeholder.x = 48;
						board[bombList.first->photo.placeholder.x / 48 - j][(bombList.first->photo.placeholder.y - 80) / 48]->photo.placeholder.y = 48 + 80;
						board[bombList.first->photo.placeholder.x / 48 - j][(bombList.first->photo.placeholder.y - 80) / 48] = new Explosion();
						board[bombList.first->photo.placeholder.x / 48 - j][(bombList.first->photo.placeholder.y - 80) / 48]->photo.placeholder.x = localX;
						board[bombList.first->photo.placeholder.x / 48 - j][(bombList.first->photo.placeholder.y - 80) / 48]->photo.placeholder.y = localY;
						break;
					}
				}
				else {
					board[bombList.first->photo.placeholder.x / 48 - j][(bombList.first->photo.placeholder.y - 80) / 48] = new Explosion();
					board[bombList.first->photo.placeholder.x / 48 - j][(bombList.first->photo.placeholder.y - 80) / 48]->photo.placeholder.x = bombList.first->photo.placeholder.x - j*48;
					board[bombList.first->photo.placeholder.x / 48 - j][(bombList.first->photo.placeholder.y - 80) / 48]->photo.placeholder.y = (bombList.first->photo.placeholder.y);
				}
			}
			isBlock = false;
			for (int j = 1; j < 3 && !isBlock; ++j) {
				if (board[bombList.first->getCenter().first / 48][(bombList.first->photo.placeholder.y - 80) / 48 + j] != nullptr) {
					switch (board[bombList.first->photo.placeholder.x / 48][(bombList.first->photo.placeholder.y - 80) / 48 + j]->whoIam) {
					case TIPO_CASILLA::BLOQUE:
						isBlock = true;
						break;
					case TIPO_CASILLA::MURO:
						board[bombList.first->photo.placeholder.x / 48][(bombList.first->photo.placeholder.y - 80) / 48 + j]->harm();
						board[bombList.first->photo.placeholder.x / 48][(bombList.first->photo.placeholder.y - 80) / 48 + j] = new Explosion();
						isBlock = true;
						break;
					case TIPO_CASILLA::PLAYER:
						int localX, localY;
						localX = board[bombList.first->photo.placeholder.x / 48][(bombList.first->photo.placeholder.y - 80) / 48 + j]->photo.placeholder.x;
						localY = board[bombList.first->photo.placeholder.x / 48][(bombList.first->photo.placeholder.y - 80) / 48 + j]->photo.placeholder.y;
						board[bombList.first->photo.placeholder.x / 48][(bombList.first->photo.placeholder.y - 80) / 48 + j]->harm();
						board[bombList.first->photo.placeholder.x / 48][(bombList.first->photo.placeholder.y - 80) / 48 + j]->photo.placeholder.x = 48;
						board[bombList.first->photo.placeholder.x / 48][(bombList.first->photo.placeholder.y - 80) / 48 + j]->photo.placeholder.y = 48 + 80;
						board[bombList.first->photo.placeholder.x / 48][(bombList.first->photo.placeholder.y - 80) / 48 + j] = new Explosion();
						board[bombList.first->photo.placeholder.x / 48][(bombList.first->photo.placeholder.y - 80) / 48 + j]->photo.placeholder.x = localX;
						board[bombList.first->photo.placeholder.x / 48][(bombList.first->photo.placeholder.y - 80) / 48 + j]->photo.placeholder.y = localY;
						break;
					}
				}
				else {
					board[bombList.first->photo.placeholder.x / 48][(bombList.first->photo.placeholder.y - 80) / 48 + j] = new Explosion();
					board[bombList.first->photo.placeholder.x / 48][(bombList.first->photo.placeholder.y - 80) / 48 + j]->photo.placeholder.x = bombList.first->photo.placeholder.x;
					board[bombList.first->photo.placeholder.x / 48][(bombList.first->photo.placeholder.y - 80) / 48 + j]->photo.placeholder.y = (bombList.first->photo.placeholder.y) + j*48;
				}
			}
			isBlock = false;
			for (int j = 1; j < 3 && !isBlock; ++j) {
				if (board[bombList.first->getCenter().first / 48][(bombList.first->photo.placeholder.y - 80) / 48 - j] != nullptr) {
					switch (board[bombList.first->photo.placeholder.x / 48][(bombList.first->photo.placeholder.y - 80) / 48 - j]->whoIam) {
					case TIPO_CASILLA::BLOQUE:
						isBlock = true;
						break;
					case TIPO_CASILLA::MURO:
						board[bombList.first->photo.placeholder.x / 48][(bombList.first->photo.placeholder.y - 80) / 48 - j]->harm();
						board[bombList.first->photo.placeholder.x / 48][(bombList.first->photo.placeholder.y - 80) / 48 - j] = new Explosion();
						isBlock = true;
						break;
					case TIPO_CASILLA::PLAYER:
						int localX, localY;
						localX = board[bombList.first->photo.placeholder.x / 48][(bombList.first->photo.placeholder.y - 80) / 48 - j]->photo.placeholder.x;
						localY = board[bombList.first->photo.placeholder.x / 48][(bombList.first->photo.placeholder.y - 80) / 48 - j]->photo.placeholder.y;
						board[bombList.first->photo.placeholder.x / 48][(bombList.first->photo.placeholder.y - 80) / 48 - j]->harm();
						board[bombList.first->photo.placeholder.x / 48][(bombList.first->photo.placeholder.y - 80) / 48 - j]->photo.placeholder.x = 48;
						board[bombList.first->photo.placeholder.x / 48][(bombList.first->photo.placeholder.y - 80) / 48 - j]->photo.placeholder.y = 48 + 80;
						board[bombList.first->photo.placeholder.x / 48][(bombList.first->photo.placeholder.y - 80) / 48 - j] = new Explosion();
						board[bombList.first->photo.placeholder.x / 48][(bombList.first->photo.placeholder.y - 80) / 48 - j]->photo.placeholder.x = bombList.first->photo.placeholder.x / 48;
						board[bombList.first->photo.placeholder.x / 48][(bombList.first->photo.placeholder.y - 80) / 48 - j]->photo.placeholder.y = localY;
						break;
					}
				}
				else {
					board[bombList.first->photo.placeholder.x / 48][(bombList.first->photo.placeholder.y - 80) / 48 - j] = new Explosion();
					board[bombList.first->photo.placeholder.x / 48][(bombList.first->photo.placeholder.y - 80) / 48 - j]->photo.placeholder.x = bombList.first->photo.placeholder.x;
					board[bombList.first->photo.placeholder.x / 48][(bombList.first->photo.placeholder.y - 80) / 48 - j]->photo.placeholder.y = (bombList.first->photo.placeholder.y ) - j*48;
				}
			}
			bombList.first = nullptr;
			delete users.first->myBomb;
			users.first->myBomb = nullptr;
		}

	}
		/////////////////////////////////////////
	if (bombList.second != nullptr) {

		bombList.second->update();
		if (bombList.second->collideWithPlayer) {
			users.second->correctPosition(bombList.second);
		}
		else if (!bombList.second->doCollide(*users.second)) {
			bombList.second->collideWithPlayer = true;
		}

		if (bombList.second->isExploding) {
			bool isBlock = false;
			for (int j = 0; j < 3 && !isBlock; ++j) {
				if (board[bombList.second->getCenter().first / 48 + j][(bombList.second->photo.placeholder.y - 80) / 48] != nullptr) {
					switch (board[bombList.second->getCenter().first / 48 + j][(bombList.second->photo.placeholder.y - 80) / 48]->whoIam) {
					case TIPO_CASILLA::BLOQUE:
						isBlock = true;
						break;
					case TIPO_CASILLA::MURO:
						board[bombList.second->photo.placeholder.x / 48 + j][(bombList.second->photo.placeholder.y - 80) / 48]->harm();
						board[bombList.second->photo.placeholder.x / 48 + j][(bombList.second->photo.placeholder.y - 80) / 48] = new Explosion();
						isBlock = true;
						break;
					case TIPO_CASILLA::PLAYER:
						int localX, localY;
						localX = board[bombList.second->photo.placeholder.x / 48 + j][(bombList.second->photo.placeholder.y - 80) / 48]->photo.placeholder.x;
						localY = board[bombList.second->photo.placeholder.x / 48 + j][(bombList.second->photo.placeholder.y - 80) / 48]->photo.placeholder.y;
						board[bombList.second->photo.placeholder.x / 48 + j][(bombList.second->photo.placeholder.y - 80) / 48]->harm();
						board[bombList.second->photo.placeholder.x / 48 + j][(bombList.second->photo.placeholder.y - 80) / 48]->photo.placeholder.x = 48;
						board[bombList.second->photo.placeholder.x / 48 + j][(bombList.second->photo.placeholder.y - 80) / 48]->photo.placeholder.y = 48 + 80;
						board[bombList.second->photo.placeholder.x / 48 + j][(bombList.second->photo.placeholder.y - 80) / 48] = new Explosion();
						board[bombList.second->photo.placeholder.x / 48 + j][(bombList.second->photo.placeholder.y - 80) / 48]->photo.placeholder.x = localX;
						board[bombList.second->photo.placeholder.x / 48 + j][(bombList.second->photo.placeholder.y - 80) / 48]->photo.placeholder.y = localY;
						break;
					}
				}
				else {
					board[bombList.second->photo.placeholder.x / 48 + j][(bombList.second->photo.placeholder.y - 80) / 48] = new Explosion();
					board[bombList.second->photo.placeholder.x / 48 + j][(bombList.second->photo.placeholder.y - 80) / 48]->photo.placeholder.x = bombList.second->photo.placeholder.x + j * 48;
					board[bombList.second->photo.placeholder.x / 48 + j][(bombList.second->photo.placeholder.y - 80) / 48]->photo.placeholder.y = (bombList.second->photo.placeholder.y);
				}
			}
			isBlock = false;
			for (int j = 1; j < 3 && !isBlock; ++j) {
				if (board[bombList.second->getCenter().first / 48 - j][(bombList.second->photo.placeholder.y - 80) / 48] != nullptr) {
					switch (board[bombList.second->photo.placeholder.x / 48 - j][(bombList.second->photo.placeholder.y - 80) / 48]->whoIam) {
					case TIPO_CASILLA::BLOQUE:
						isBlock = true;
						break;
					case TIPO_CASILLA::MURO:
						board[bombList.second->photo.placeholder.x / 48 - j][(bombList.second->photo.placeholder.y - 80) / 48]->harm();
						board[bombList.second->photo.placeholder.x / 48 - j][(bombList.second->photo.placeholder.y - 80) / 48] = new Explosion();
						isBlock = true;
						break;
					case TIPO_CASILLA::PLAYER:
						int localX, localY;
						localX = board[bombList.second->photo.placeholder.x / 48 - j][(bombList.second->photo.placeholder.y - 80) / 48]->photo.placeholder.x;
						localY = board[bombList.second->photo.placeholder.x / 48 - j][(bombList.second->photo.placeholder.y - 80) / 48]->photo.placeholder.y;
						board[bombList.second->photo.placeholder.x / 48 - j][(bombList.second->photo.placeholder.y - 80) / 48]->harm();
						board[bombList.second->photo.placeholder.x / 48 - j][(bombList.second->photo.placeholder.y - 80) / 48]->photo.placeholder.x = 48;
						board[bombList.second->photo.placeholder.x / 48 - j][(bombList.second->photo.placeholder.y - 80) / 48]->photo.placeholder.y = 48 + 80;
						board[bombList.second->photo.placeholder.x / 48 - j][(bombList.second->photo.placeholder.y - 80) / 48] = new Explosion();
						board[bombList.second->photo.placeholder.x / 48 - j][(bombList.second->photo.placeholder.y - 80) / 48]->photo.placeholder.x = localX;
						board[bombList.second->photo.placeholder.x / 48 - j][(bombList.second->photo.placeholder.y - 80) / 48]->photo.placeholder.y = localY;
						break;
					}
				}
				else {
					board[bombList.second->photo.placeholder.x / 48 - j][(bombList.second->photo.placeholder.y - 80) / 48] = new Explosion();
					board[bombList.second->photo.placeholder.x / 48 - j][(bombList.second->photo.placeholder.y - 80) / 48]->photo.placeholder.x = bombList.second->photo.placeholder.x - j * 48;
					board[bombList.second->photo.placeholder.x / 48 - j][(bombList.second->photo.placeholder.y - 80) / 48]->photo.placeholder.y = (bombList.second->photo.placeholder.y);
				}
			}
			isBlock = false;
			for (int j = 1; j < 3 && !isBlock; ++j) {
				if (board[bombList.second->getCenter().first / 48][(bombList.second->photo.placeholder.y - 80) / 48 + j] != nullptr) {
					switch (board[bombList.second->photo.placeholder.x / 48][(bombList.second->photo.placeholder.y - 80) / 48 + j]->whoIam) {
					case TIPO_CASILLA::BLOQUE:
						isBlock = true;
						break;
					case TIPO_CASILLA::MURO:
						board[bombList.second->photo.placeholder.x / 48][(bombList.second->photo.placeholder.y - 80) / 48 + j]->harm();
						board[bombList.second->photo.placeholder.x / 48][(bombList.second->photo.placeholder.y - 80) / 48 + j] = new Explosion();
						isBlock = true;
						break;
					case TIPO_CASILLA::PLAYER:
						int localX, localY;
						localX = board[bombList.second->photo.placeholder.x / 48][(bombList.second->photo.placeholder.y - 80) / 48 + j]->photo.placeholder.x;
						localY = board[bombList.second->photo.placeholder.x / 48][(bombList.second->photo.placeholder.y - 80) / 48 + j]->photo.placeholder.y;
						board[bombList.second->photo.placeholder.x / 48][(bombList.second->photo.placeholder.y - 80) / 48 + j]->harm();
						board[bombList.second->photo.placeholder.x / 48][(bombList.second->photo.placeholder.y - 80) / 48 + j]->photo.placeholder.x = 48;
						board[bombList.second->photo.placeholder.x / 48][(bombList.second->photo.placeholder.y - 80) / 48 + j]->photo.placeholder.y = 48 + 80;
						board[bombList.second->photo.placeholder.x / 48][(bombList.second->photo.placeholder.y - 80) / 48 + j] = new Explosion();
						board[bombList.second->photo.placeholder.x / 48][(bombList.second->photo.placeholder.y - 80) / 48 + j]->photo.placeholder.x = localX;
						board[bombList.second->photo.placeholder.x / 48][(bombList.second->photo.placeholder.y - 80) / 48 + j]->photo.placeholder.y = localY;
						break;
					}
				}
				else {
					board[bombList.second->photo.placeholder.x / 48][(bombList.second->photo.placeholder.y - 80) / 48 + j] = new Explosion();
					board[bombList.second->photo.placeholder.x / 48][(bombList.second->photo.placeholder.y - 80) / 48 + j]->photo.placeholder.x = bombList.second->photo.placeholder.x;
					board[bombList.second->photo.placeholder.x / 48][(bombList.second->photo.placeholder.y - 80) / 48 + j]->photo.placeholder.y = (bombList.second->photo.placeholder.y) + j * 48;
				}
			}
			isBlock = false;
			for (int j = 1; j < 3 && !isBlock; ++j) {
				if (board[bombList.second->getCenter().first / 48][(bombList.second->photo.placeholder.y - 80) / 48 - j] != nullptr) {
					switch (board[bombList.second->photo.placeholder.x / 48][(bombList.second->photo.placeholder.y - 80) / 48 - j]->whoIam) {
					case TIPO_CASILLA::BLOQUE:
						isBlock = true;
						break;
					case TIPO_CASILLA::MURO:
						board[bombList.second->photo.placeholder.x / 48][(bombList.second->photo.placeholder.y - 80) / 48 - j]->harm();
						board[bombList.second->photo.placeholder.x / 48][(bombList.second->photo.placeholder.y - 80) / 48 - j] = new Explosion();
						isBlock = true;
						break;
					case TIPO_CASILLA::PLAYER:
						int localX, localY;
						localX = board[bombList.second->photo.placeholder.x / 48][(bombList.second->photo.placeholder.y - 80) / 48 - j]->photo.placeholder.x;
						localY = board[bombList.second->photo.placeholder.x / 48][(bombList.second->photo.placeholder.y - 80) / 48 - j]->photo.placeholder.y;
						board[bombList.second->photo.placeholder.x / 48][(bombList.second->photo.placeholder.y - 80) / 48 - j]->harm();
						board[bombList.second->photo.placeholder.x / 48][(bombList.second->photo.placeholder.y - 80) / 48 - j]->photo.placeholder.x = 48;
						board[bombList.second->photo.placeholder.x / 48][(bombList.second->photo.placeholder.y - 80) / 48 - j]->photo.placeholder.y = 48 + 80;
						board[bombList.second->photo.placeholder.x / 48][(bombList.second->photo.placeholder.y - 80) / 48 - j] = new Explosion();
						board[bombList.second->photo.placeholder.x / 48][(bombList.second->photo.placeholder.y - 80) / 48 - j]->photo.placeholder.x = bombList.second->photo.placeholder.x / 48;
						board[bombList.second->photo.placeholder.x / 48][(bombList.second->photo.placeholder.y - 80) / 48 - j]->photo.placeholder.y = localY;
						break;
					}
				}
				else {
					board[bombList.second->photo.placeholder.x / 48][(bombList.second->photo.placeholder.y - 80) / 48 - j] = new Explosion();
					board[bombList.second->photo.placeholder.x / 48][(bombList.second->photo.placeholder.y - 80) / 48 - j]->photo.placeholder.x = bombList.second->photo.placeholder.x;
					board[bombList.second->photo.placeholder.x / 48][(bombList.second->photo.placeholder.y - 80) / 48 - j]->photo.placeholder.y = (bombList.second->photo.placeholder.y) - j * 48;
				}
			}
			bombList.second = nullptr;
			delete users.second->myBomb;
			users.second->myBomb = nullptr;
		}

	}
}

void Play::draw()
{
	Renderer::Instance()->renderIMG(bg.id, bg.placeholder);
	
		users.first->draw();
		users.second->draw();

	if (bombList.first != nullptr)
		bombList.first->draw();
	if (bombList.second != nullptr)
		bombList.second->draw();

	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 13; ++j) {
			if (board[i][j] != nullptr) {
				board[i][j]->draw();
			}
		}
	}



	interfaz->draw();
}
