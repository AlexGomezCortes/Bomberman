#include "Bloque.h"



Bloque::Bloque()
{
}


Bloque::~Bloque()
{
}

void Bloque::draw() {
	Renderer::Instance()->renderSprite(photo.id, photo.placeholder, std::make_pair(0, 0));
}

void Bloque::update() {

}