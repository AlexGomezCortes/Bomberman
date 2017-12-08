#include "Renderer.h"

Renderer::Renderer()
{
	m_window = SDL_CreateWindow("BOMBERMAN", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	const Uint8 imgFlags{ IMG_INIT_PNG | IMG_INIT_JPG };
}

Renderer * Renderer::Instance()
{
	if (renderer == nullptr)
	{
		renderer = new Renderer;
	}

	return renderer;
}


Renderer::~Renderer()
{
	SDL_DestroyRenderer(m_renderer);
	m_renderer = nullptr;
	SDL_DestroyWindow(m_window);
	m_window = nullptr;

	SDL_Quit();
}

void Renderer::Clear()
{
	SDL_RenderClear(m_renderer); 
}

void Renderer::Render() 
{ 
	SDL_RenderPresent(m_renderer); 
}

void Renderer::loadIMG(std::string path, int id)
{
	SDL_Texture* tempTex = IMG_LoadTexture(m_renderer, path.c_str());
	m_images[id] = tempTex;
}

void Renderer::renderText(int e)
{
}

Text* Renderer::editText(int f)
{
	return nullptr;
}


void Renderer::renderIMG(int id, const SDL_Rect &rect)
{
	SDL_RenderCopy(m_renderer, m_images[id], nullptr, &rect);
}

SDL_Texture * Renderer::editIMG(int id)
{
	return nullptr;
}

int Renderer::loadText(Text c)
{
	return 0;
}

std::pair<int, int> Renderer::getTextureDimensions(int id) {
	int w, h;
	SDL_QueryTexture(m_images[id], NULL, NULL, &w, &h);
	return std::make_pair(w, h);
}

Renderer* Renderer::renderer = nullptr;
