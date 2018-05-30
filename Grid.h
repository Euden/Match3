#pragma once
#include "Gem.h"
#include <vector>
#include <memory>
#include <king/Engine.h>

typedef std::vector<std::shared_ptr<Gem>> GemVector;
typedef GemVector::iterator GemIter;

class Grid
{
public:
	Grid();
	~Grid();

	void GenerateGrid(int sizeX, int sizeY);
	void DrawField(King::Engine &mEngine);

	GemVector Gems;
};