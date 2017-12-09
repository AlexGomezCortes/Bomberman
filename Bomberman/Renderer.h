#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include "Recursos.h"
#include <map>
#include <string>
#include <SDL_image.h>
#include <iostream>

class Renderer
{

private:
	SDL_Window* m_window=nullptr;
	SDL_Renderer* m_renderer=nullptr;
	static Renderer *renderer;

	unsigned int nextKey;

public:

	std::map <int, SDL_Texture*> m_images;

	std::map <int, Text> m_messages;
	std::map <int, TTF_Font*> m_fonts;
	
	static Renderer* Instance();

	Renderer();
	~Renderer();

	int loadIMG(std::string path);
	int loadText(Text text);
	void loadText(Text text, int id);
	void renderIMG(int id, const SDL_Rect &rect);

	void Clear();
	void Render();

	SDL_Renderer* getRenderer() { return m_renderer; }
	SDL_Window* getWindow() { return m_window; }



};

