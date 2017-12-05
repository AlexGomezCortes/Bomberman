#pragma once
#include "Scene.h"
#include "Recursos.h"
#include "Scene.h"
#include "Renderer.h"

class Menu : public Scene
{
public:
	Menu();
	~Menu();
private:
	Text titulo;
	int BG_id;
	SDL_Rect BG_Rect;
	std::string path;

	void eventHandler() override;
	void update() override;
	void draw() override;

	Button* play;
};

