#pragma once
#include <SDL.h>
#include "Recursos.h"
#include <map>
#include <string>
#include <SDL_image.h>

class Renderer
{

private:
	SDL_Window* m_window=nullptr;
	SDL_Renderer* m_renderer=nullptr;
	std::map <int, SDL_Texture*> m_images;
	std::map <int, Text> m_messages;
	static Renderer *renderer;

public:
	
	static Renderer* Instance();

	Renderer();
	~Renderer();
	void renderIMG(int id, const SDL_Rect &rect);
	SDL_Texture* editIMG(int id);
	int loadText(Text c);
	void loadIMG(std::string path, int id); //supongo que devuelve un int porque los maps tienen un int como key
	void renderText(int e);
	Text* editText(int f);

	void Clear();
	void Render();

	SDL_Renderer* getRenderer() { return m_renderer; }
	SDL_Window* getWindow() { return m_window; }



};

