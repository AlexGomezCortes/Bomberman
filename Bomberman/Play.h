#pragma once
#include "HUD.h"
#include "Scene.h"
#include "Casilla.h"
#include "Player.h"
#include "Bomba.h"
#include <deque>

class Play : public Scene
{
public:
	Play();
	~Play();
private:
	HUD interfaz;
	std::pair <Player, Player> users;
	std::deque <Bomba> bombList;
	Casilla*** board;
	int playBG_id;

	void eventHandler() override;
	void update() override;
	void draw() override;

};

