#include "Renderer.h"

Renderer::Renderer()
{
	m_window = SDL_CreateWindow("BOMBERMAN", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	const Uint8 imgFlags{ IMG_INIT_PNG | IMG_INIT_JPG };

	SaiyanText.id = 1;
	SaiyanText.size = 5;
	SaiyanText.path = "../res/ttf/saiyan.ttf";

	GameoverText.id = 2;
	GameoverText.size = 40;
	GameoverText.path = "../res/ttf/game_over.ttf";
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

Text* Renderer::editText(int f)
{
	return nullptr;
}

void Renderer::loadFont(Text text)
{
	TTF_Font *ttfFont = TTF_OpenFont(text.path.c_str(), text.size);
	m_fonts[text.id] = ttfFont;
	std::cout << m_fonts[text.id] << std::endl;
}


void Renderer::renderIMG(int id, const SDL_Rect &rect)
{
	SDL_RenderCopy(m_renderer, m_images[id], nullptr, &rect);
}

void Renderer::renderTXT(Text a, SDL_Texture * b)
{
	/*std::cout<<*/SDL_RenderCopy(m_renderer, b, nullptr, &a.placeHolder);
}

SDL_Texture * Renderer::editIMG(int id)
{
	return nullptr;
}

Renderer* Renderer::renderer = nullptr;
