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
		update();
		Renderer::Instance()->Render();
	}
}

void Game::update()
{
	std::cout << int(currentScene->CurrentGameState) << std::endl;

	if (currentScene->CurrentGameState == GAME_STATE::PLAY)
	{
		std::cout << "entro play" << std::endl;
		currentScene = new Play();
	}
	currentScene->update();
}




