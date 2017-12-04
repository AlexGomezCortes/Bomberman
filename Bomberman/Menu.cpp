#include "Menu.h"

Menu::Menu()
{
	BG_id = 1;
	path = "../res/img/bgGame.png";
	BG_Rect.x = 0;
	BG_Rect.y = 0;
	BG_Rect.w = 800;
	BG_Rect.h = 500;

	Renderer::Instance()->loadIMG(path, BG_id);
	Renderer::Instance()->renderIMG(BG_id, BG_Rect);
}


Menu::~Menu()
{
}

void Menu::eventHandler()
{
}

void Menu::update()
{
	Renderer::Instance()->renderIMG(BG_id, BG_Rect);
}

void Menu::draw()
{
}
