#pragma once

#include <king/Engine.h>

class Gem
{
public:
	Gem() {}
	Gem(int x, int y);
	~Gem();

	int posX, posY;
	King::Engine::Texture Type;
};
