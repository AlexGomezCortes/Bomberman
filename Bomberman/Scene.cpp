#include "Scene.h"

Scene::Scene()
{
	active = true;
}


Scene::~Scene()
{
}

void Scene::eventHandler()
{
}

void Scene::update()
{
}

void Scene::draw()
{
}

bool Scene::isRunning() { return active; }