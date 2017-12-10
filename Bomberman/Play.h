#pragma once
#include "HUD.h"
#include "Scene.h"
#include "Casilla.h"
#include "Player.h"
#include "Bomba.h"
#include "Muro.h"
#include "Bloque.h"
#include "Explosion.h"
#include <deque>
#include "Button.h"
#include "Renderer.h"
#include "string"


class Play : public Scene
{
public:
	Play();
	~Play();

private:

	Image bg;
	HUD *interfaz;
	std::pair <Player*, Player*> users;
	std::pair <Bomba*, Bomba*> bombList;
	Casilla*** board;

	void eventHandler() override;
	void update() override;
	void draw() override;

	float auxTime;

};

