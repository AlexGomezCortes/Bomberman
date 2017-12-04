#pragma once
#include "Player.h"

class HUD
{
public:
	HUD();
	~HUD();
private:
	float countDown;
	std::pair <int, int> vidas;
	std::pair <int, int> score;
	Player* JugadorUno;
	Player* JugadorDos;
};

