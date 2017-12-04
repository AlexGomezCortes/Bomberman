#pragma once
#include "Casilla.h"
#include "Bomba.h"

class Player : public Casilla
{
public:
	Player();
	~Player();

	void eventHandler();
	std::pair<int, int>* move();
private:
	
	int spriteid;
	Bomba CrearBomba();
	void harm() override;
	void update() override;
	void draw() override;

};

