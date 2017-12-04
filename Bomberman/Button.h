#pragma once
#include "Recursos.h"
class Button
{
public:
	Button();
	~Button();
private:
	Text message;
public:
	bool isClicked();
	bool isHovered();
	void eventHandler();
	void update();
	void draw();
};

