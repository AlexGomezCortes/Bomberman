#include "Game.h"



Game::Game()
{
	currentScene = new Menu();
}


Game::~Game()
{
}

void Game::run()
{
	while (currentScene->isRunning())
	{
		Renderer::Instance()->Clear();
		currentScene->eventHandler();
		currentScene->update();
		Renderer::Instance()->Render();
	}
}




