#pragma once

#include <king/Engine.h>

class Gem
{
public:
	Gem() {}
	Gem(int x, int y, King::Engine::Texture type);
	~Gem();

	int posX, posY;
	King::Engine::Texture Type;
};
