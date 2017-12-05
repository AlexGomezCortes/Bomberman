#include "Button.h"



Button::Button()
{
	leftClick = false;
}


Button::~Button()
{
}

bool Button::isClicked()
{
	if (isHovered()) {
		if (leftClick) {
			return true;
		}
	}
	return false;
}

bool Button::isHovered()
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (x < (message.placeHolder.x + message.placeHolder.w) && x > (message.placeHolder.x)) {
		if (y < (message.placeHolder.y + message.placeHolder.h) && y > (message.placeHolder.y)) {
			return true;
		}
	}
	return false;
}

void Button::eventHandler( SDL_Event evnt)
{
	int a = 0;
		switch (evnt.type) {
			case SDL_MOUSEBUTTONDOWN:
				switch (evnt.button.button) {
				case SDL_BUTTON_LEFT:
					leftClick = true;
					break;
				}
				break;
			default:
				leftClick = false;
		}
	
}

void Button::update()
{

	if (isClicked())
		std::cout << "click" << std::endl;
	else if (isHovered())
		std::cout << "hover" << std::endl;
	
}

void Button::draw()
{
}
