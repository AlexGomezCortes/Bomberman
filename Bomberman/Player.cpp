#include "Player.h"



Player::Player()
{
	spriteid = 2;
	spriteSheet.path= "../res/img/player1.png"; //hay que montarse algo para las animaciones

	score = 0;
	vidas = 3;
	position.first = position.second = 0;

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
	/*Renderer::Instance()->renderIMG(spriteid, Sprite.placeholder);
	Renderer::Instance()->renderIMG(spriteid2, Sprite2.placeholder);*/
}
