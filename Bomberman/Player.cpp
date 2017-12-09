#include "Player.h"



Player::Player(int num) //añadir switch que gestione si se crea un player 1 o un player 2
{
	if (num == 1) {
		isPJ1 = true;

		photo.path = PATH_PJ1;
		photo.placeholder.x = 48;
		photo.placeholder.y = 48+80;
	}
	else {
		isPJ1 = false;

		photo.path = PATH_PJ2;
		photo.placeholder.x = SCREEN_WIDTH-48*2;
		photo.placeholder.y = SCREEN_HEIGHT-48*2;
	}
	photo.placeholder.w = 48;
	photo.placeholder.h = 48;

	photo.id=Renderer::Instance()->loadSpriteSheet(photo.path, 3, 4);

	vidas = 3;
	score = 0;
}


Player::~Player()
{
}

void Player::eventHandler()
{
	const Uint8* keyboardState = SDL_GetKeyboardState(NULL);

	if (isPJ1) {
		if (keyboardState[SDL_SCANCODE_W])
			speed.second = -1;
		else if (keyboardState[SDL_SCANCODE_S])
			speed.second = 1;
		else
			speed.second = 0;
		if (keyboardState[SDL_SCANCODE_D])
			speed.first = 1;
		else if (keyboardState[SDL_SCANCODE_A])
			speed.first = -1;
		else
			speed.first = 0;
	}
	else {
		if (keyboardState[SDL_SCANCODE_UP])
			speed.second = -1;
		else if (keyboardState[SDL_SCANCODE_DOWN])
			speed.second = 1;
		else
			speed.second = 0;
		if (keyboardState[SDL_SCANCODE_LEFT])
			speed.first = -1;
		else if (keyboardState[SDL_SCANCODE_RIGHT])
			speed.first = 1;
		else
			speed.first = 0;
	}

}

void Player::update()
{
	moveX(speed.first);
	moveY(speed.second);
}

void Player::draw()
{
	std::pair<int, int> spriteCoordinate;
	switch (speed.first) {
	case -1: spriteCoordinate.second = 1;
		break;
	case 0:
		break;
	case 1: spriteCoordinate.second = 3;
		break;
	}

	switch (speed.second) {
	case -1: spriteCoordinate.second = 0;
		break;
	case 0:
		break;
	case 1: spriteCoordinate.second = 2;
		break;
	}

	Renderer::Instance()->renderSprite(photo.id, photo.placeholder, spriteCoordinate);
}

void Player::moveX(int delta)
{
	photo.placeholder.x += delta;
}

void Player::moveY(int delta) 
{
	photo.placeholder.y += delta;
}

std::pair<int, int> Player::getPos() {
	return std::make_pair(photo.placeholder.x, photo.placeholder.y);
}

Bomba Player::CrearBomba()
{
	return Bomba();
}

void Player::harm()
{
}


