#pragma once
#include "Casilla.h"


class Bomba : public Casilla
{
public:
	Bomba();
	~Bomba();
private:
	float timeToExplode;
	void update() override;
	void draw() override;
};

