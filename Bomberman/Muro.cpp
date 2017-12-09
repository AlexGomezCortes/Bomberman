#include "Muro.h"



Muro::Muro()
{}


Muro::~Muro()
{
}

void Muro::draw() {
	Renderer::Instance()->renderSprite(photo.id, photo.placeholder, std::make_pair(0, 0));
}

void Muro::update() {

}