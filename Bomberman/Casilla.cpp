#include "Casilla.h"



Casilla::Casilla()
{
	photo.path = PATH_ITEMS;
	photo.id = Renderer::Instance()->loadSpriteSheet(photo.path, 3, 2);

	photo.placeholder.w = photo.placeholder.h= 48;
}


Casilla::~Casilla()
{
}

void Casilla::harm()
{
}

void Casilla::update()
{
}

void Casilla::draw()
{
}

std::pair<int, int> Casilla::getCenter(SDL_Rect other) {
	int one, two;
	one = other.x + other.w / 2;
	two = other.y + other.h / 2;
	return (std::make_pair( one, two ));
}

bool Casilla::doCollide(Casilla other) {
	int xDist = abs(getCenter(photo.placeholder).first - other.getCenter(other.photo.placeholder).first);
	int yDist = abs(getCenter(photo.placeholder).second - other.getCenter(other.photo.placeholder).second);
	return(xDist < (photo.placeholder.w / 2 + other.photo.placeholder.w / 2) && yDist < (photo.placeholder.h / 2 + other.photo.placeholder.h / 2));
}

void Casilla::correctPosition(Casilla* other)
{
	if (doCollide(*other)) {
		int xDist = abs(getCenter(photo.placeholder).first - other->getCenter(other->photo.placeholder).first);
		int yDist = abs(getCenter(photo.placeholder).second - other->getCenter(other->photo.placeholder).second);


		if (xDist - (photo.placeholder.w / 2 + other->photo.placeholder.w / 2) > yDist - (photo.placeholder.h / 2 + other->photo.placeholder.h / 2)) {

			if (getCenter(photo.placeholder).first > getCenter(other->photo.placeholder).first) {
				photo.placeholder.x += abs(xDist - (photo.placeholder.w / 2 + other->photo.placeholder.w / 2));
			}
			else {
				photo.placeholder.x -= abs(xDist - (photo.placeholder.w / 2 + other->photo.placeholder.w / 2));
			}
		}
		else {
			if (getCenter(photo.placeholder).second > getCenter(other->photo.placeholder).second) {
				photo.placeholder.y += abs(yDist - (photo.placeholder.h / 2 + other->photo.placeholder.h / 2));
			}
			else {
				photo.placeholder.y -= abs(yDist - (photo.placeholder.h / 2 + other->photo.placeholder.h / 2));
			}
		}
	}
}

