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

	bool isMatch(int row, int col);
	bool isHorizontalMatch(int row, int col);
	bool isVerticalMatch(int row, int col);

	std::shared_ptr<Gem> gemAt(int row, int col);

	GemVector Gems;

private:
	int fieldSizeX, fieldSizeY;
};