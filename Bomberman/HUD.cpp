#include "HUD.h"



HUD::HUD(Player* &uno, Player* &dos) : JugadorUno{uno}, JugadorDos{dos}
{
	countDown = GAMETIME;

	vidas.first = JugadorUno->vidas;
	vidas.second = JugadorDos->vidas;
	score.first = JugadorUno->score;
	score.second = JugadorDos->score;
}


HUD::~HUD()
{
}
