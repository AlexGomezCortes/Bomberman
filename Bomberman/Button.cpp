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
    if (isHovered())
	{
		std::cout << "hovered" << std::endl;
	}	
}

void Button::draw(Text& a) //le pasamos una variable de tipo Text porque los botones tienen Text, que contiene el color, el rectangulo, el path, el tamaño, el texto etc
{
	SDL_Surface* surfaceMessage = TTF_RenderText_Blended(Renderer::Instance()->m_fonts[a.id], a.msg, a.color);
	SDL_Texture* Message = SDL_CreateTextureFromSurface(Renderer::Instance()->getRenderer(), surfaceMessage);
	
	Renderer::Instance()->renderTXT(a, Message);
	SDL_FreeSurface(surfaceMessage);
    //SDL_RenderCopy(Renderer::Instance()->getRenderer(), Message, NULL, &a.placeHolder);
}
