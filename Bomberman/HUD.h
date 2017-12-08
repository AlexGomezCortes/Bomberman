#pragma once
#include "Player.h"

class HUD
{
public:
	HUD(Player* &uno, Player* &dos);
	~HUD();
private:
	float countDown;
	std::pair <int, int> vidas;
	std::pair <int, int> score;
	Player* JugadorUno;
	Player* JugadorDos;

	Text score1;
	Text score2;
	Text vida1;
	Text vida2;
};

