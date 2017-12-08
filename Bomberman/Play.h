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
	Player* one;
	Player* two;
	HUD* interfaz;

	std::pair <Player, Player> users;

	std::deque <Bomba> bombList;
	Casilla*** board;
	int BG_id;
	std::string path;
	SDL_Rect BG_Rect;

	void eventHandler() override;
	void update() override;
	void draw() override;

};

