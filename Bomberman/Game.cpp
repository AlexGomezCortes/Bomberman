#include "Game.h"



Game::Game()
{
	currentScene = new Menu();
	running = true;
}


Game::~Game()
{
}

void Game::run()
{
	while (running)
	{
		Renderer::Instance()->Clear();
		currentScene->update();
		Renderer::Instance()->Render();
	}
}


