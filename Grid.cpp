#include "Grid.h"

Grid::Grid()
{

}

void Grid::GenerateGrid(int sizeX, int sizeY)
{
	for(int i = 0; i < sizeY; ++i)
		for (int j = 0; j < sizeX; ++j)
		{
			Gems.push_back(std::make_shared<Gem>(Gem(i, j)));
		}

	fieldSizeX = sizeX;
	fieldSizeY = sizeY;
}

void Grid::DrawField(King::Engine &mEngine)
{
	for (GemIter g  = Gems.begin(); g != Gems.end(); ++g)
	{
		mEngine.Render(g->get()->Type, g->get()->posX, g->get()->posY);
	}
}

std::shared_ptr<Gem> Grid::gemAt(int row, int col)
{
	if (row < 0 || row >= fieldSizeX || col < 0 || col >= fieldSizeY)
	{
		return nullptr;
	}

	int gemNum = 0;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
		{
			gemNum++;
		}
	return Gems[gemNum];
}

bool Grid::isHorizontalMatch(int row, int col)
{
	return gemAt(row, col).get()->Type == gemAt(row, col -1).get()->Type  && gemAt(row, col).get()->Type == gemAt(row, col - 2).get()->Type;
}

bool Grid::isVerticalMatch(int row, int col)
{
	return gemAt(row, col).get()->Type == gemAt(row - 1, col).get()->Type && gemAt(row, col).get()->Type == gemAt(row - 2, col).get()->Type;
}

bool Grid::isMatch(int row, int col)
{
	return isHorizontalMatch(row, col) || isVerticalMatch(row, col);
}
Grid::~Grid()
{

}