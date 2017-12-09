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
	void update() override;
	void draw() override;
	void harm() override;
	
	void moveX(int delta);
	void moveY(int delta);
	std::pair<int, int> getPos();
	std::pair<int, int> getSpeed() { return speed; }

private:
	Bomba CrearBomba();

public:
	int vidas;
	int score;

private:
	std::pair<int, int> speed;
	bool isPJ1;
};

