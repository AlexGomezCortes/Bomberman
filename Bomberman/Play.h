#pragma once
#include "HUD.h"
#include "Scene.h"
#include "Casilla.h"
#include "Player.h"
#include "Bomba.h"
#include <deque>
#include "Button.h"
#include "Renderer.h"

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
	Player* ReferenceToPlayer;

	void eventHandler() override;
	void update() override;
	void draw() override;

};

