#pragma once
#include "Recursos.h"
#include <iostream>

class Button
{
public:
	Button();
	~Button();

	bool isClicked();
	bool isHovered();
	void eventHandler(SDL_Event evnt);
	void update();
	void draw();

public:
	Text message;

private:
	bool leftClick;
};

