#pragma once
#include "Casilla.h"
#include "Renderer.h"
#include "Bomba.h"
#include <time.h>
#include <stdlib.h>

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
	

public:
	int vidas;
	int score;
	bool canBomb;
	Bomba* myBomb;

private:
	std::pair<int, int> speed;
	bool isPJ1;
	std::pair<int, int> spriteCoordinate;
	float lastTime;
	float counter;
	int local;
};

