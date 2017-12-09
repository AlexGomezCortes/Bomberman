#pragma once
#include "Casilla.h"
#include "Renderer.h"
#include "Bomba.h"

class Player : public Casilla
{
public:
	Player() {};
	Player(int num);
	~Player();

	void eventHandler();
	std::pair<int, int>* move();

	void update() override;
	void draw() override;

private:
	Image Sprite;

	Bomba CrearBomba();
	void harm() override;

public:
	int vidas;
	int score;

};

