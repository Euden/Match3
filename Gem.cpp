#include "Gem.h"
#include <math.h>

Gem::Gem(int x, int y)
	: posX(x), posY(y)
{
	posX = posX * 35;
	posY = posY * 35;

	Type = King::Engine::Texture(rand() % 5 + 1);
}

Gem::~Gem()
{

}