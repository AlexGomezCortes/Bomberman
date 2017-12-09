#include "Player.h"



Player::Player(int num) //añadir switch que gestione si se crea un player 1 o un player 2
{
	Sprite.path= "../res/img/test.png";
	Sprite.placeholder.x = 300;
	Sprite.placeholder.y = 200;
	Sprite.placeholder.w = 70;
	Sprite.placeholder.h = 70;

	Sprite.id=Renderer::Instance()->loadIMG(Sprite.path);

	vidas = 3;
	score = 0;
}


Player::~Player()
{
}

void Player::eventHandler()
{
}

std::pair<int, int>* Player::move()
{
	return nullptr;
}

Bomba Player::CrearBomba()
{
	return Bomba();
}

void Player::harm()
{
}

void Player::update()
{
	draw();
}

void Player::draw()
{
	Renderer::Instance()->renderIMG(Sprite.id, Sprite.placeholder);
}
