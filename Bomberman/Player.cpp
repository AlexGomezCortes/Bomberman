#include "Player.h"



Player::Player(int num) //añadir switch que gestione si se crea un player 1 o un player 2
{
	if (num == 1)
		isPJ1 = true;
	else
		isPJ1 = false;
	photo.path= "../res/img/test.png";
	photo.placeholder.x = 300;
	photo.placeholder.y = 200;
	photo.placeholder.w = 70;
	photo.placeholder.h = 70;

	photo.id=Renderer::Instance()->loadIMG(photo.path);

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
	Renderer::Instance()->renderIMG(photo.id, photo.placeholder);
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


