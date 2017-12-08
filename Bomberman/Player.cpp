#include "Player.h"



Player::Player()
{
	spriteid = 2;
	spriteSheet.path= "../res/img/player1.png"; //hay que montarse algo para las animaciones

	/*Sprite.placeholder.x = 300;
	Sprite.placeholder.y = 200;
	Sprite.placeholder.w = 70;
	Sprite.placeholder.h = 70;*/

	//Renderer::Instance()->loadIMG(Sprite.path, spriteid);

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
