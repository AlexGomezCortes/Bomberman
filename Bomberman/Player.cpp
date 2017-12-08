#include "Player.h"



Player::Player()
{
	spriteid = 2;
	Sprite.path= "../res/img/player1.png";
	Sprite.placeholder.x = 300;
	Sprite.placeholder.y = 200;
	Sprite.placeholder.w = 70;
	Sprite.placeholder.h = 70;

	Renderer::Instance()->loadIMG(Sprite.path, spriteid);

	spriteid2 = 2;
	Sprite2.path = "../res/img/player2.png";
	Sprite2.placeholder.x = 500;
	Sprite2.placeholder.y = 100;
	Sprite2.placeholder.w = 70;
	Sprite2.placeholder.h = 70;	

	Renderer::Instance()->loadIMG(Sprite2.path, spriteid2);
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
	Renderer::Instance()->renderIMG(spriteid, Sprite.placeholder);
	Renderer::Instance()->renderIMG(spriteid2, Sprite2.placeholder);
}
