#include "Explosion.h"



Explosion::Explosion()
{
	photo.path = PATH_EXPLOSION;
	photo.id = Renderer::Instance()->loadSpriteSheet(photo.path, 4, 7);
	
	lastTime = clock();
	lifeSpan = 1500;
}


Explosion::~Explosion()
{
}

void Explosion::draw()
{
	Renderer::Instance()->renderSprite(photo.id, photo.placeholder, std::make_pair(0, 0));
}

void Explosion::update()
{
	float deltaTime = clock() - lastTime;

	lifeSpan -= deltaTime;
	if (lifeSpan <= 0)
		delete this;

	lastTime = clock();
}

