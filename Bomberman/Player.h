#pragma once
#include "Casilla.h"
#include "Renderer.h"
#include "Bomba.h"

class Player : public Casilla
{
public:
	Player();
	~Player();

	void eventHandler();
	std::pair<int, int>* move();

	void update() override;
	void draw() override;

private:
	
	int spriteid;
	Image spriteSheet;
	SDL_Rect currentSprite;

	Bomba CrearBomba();
	void harm() override;
};

