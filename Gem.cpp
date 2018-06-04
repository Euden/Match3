#include "Gem.h"
#include <math.h>
Gem::Gem(int x, int y)
	: posX(x), posY(y), prevX(x), prevY(y), row(y), col(x)
{
	posX = posX * 35;
	posY = posY * 35;
	prevX = posX;
	prevY = posY;

	Type = King::Engine::Texture(rand() % 4 + 1);
}

void Gem::Reset()
{
	posX = prevX;
	posY = prevY;
	selected = false;
}

Gem::~Gem()
{

}