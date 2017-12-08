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
		updateScene();

		Renderer::Instance()->Clear();
		currentScene->eventHandler();	
		currentScene->update();
		currentScene->draw();
		Renderer::Instance()->Render();
	}
}

void Game::updateScene()
{
	switch (currentScene->CurrentGameState)
	{
	/*case GAME_STATE::MENU:   si pongo esto no funciona nada del sistema de escenas, y no se porque, si lo pongo dentro de un if dentro del case ranking, funcionan todas las escenas menos la del ranking, enytra en esta y sale automaticamente, sin esperar a que le des al boton de back
		currentScene = new Menu();
		break;*/
	case GAME_STATE::RNKING:
		currentScene = new Ranking();
		break;
	case GAME_STATE::PLAY:
		currentScene = new Play();
		break;
	default:
		break;
	}
}




