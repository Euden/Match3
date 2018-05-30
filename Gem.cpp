#include "Gem.h"

Gem::Gem(int x, int y, King::Engine::Texture type)
	: posX(x), posY(y), Type(type)
{
	posX = posX * 35;
	posY = posY * 35;
}

Gem::~Gem()
{

}