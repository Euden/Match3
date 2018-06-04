#pragma once

#include <king/Engine.h>

struct Bounds {
	int x, y, width, height;
};

class Gem
{
public:
	Gem() {}
	Gem(int x, int y);

	void Reset();

	~Gem();

	int posX, posY;
	int prevX, prevY;
	int row, col;
	King::Engine::Texture Type;
	bool selected = false;
};
