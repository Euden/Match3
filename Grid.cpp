#include "Grid.h"

Grid::Grid()
{

}

void Grid::GenerateGrid(int sizeX, int sizeY)
{
	for(int i = 0; i < sizeY; ++i)
		for (int j = 0; j < sizeX; ++j)
		{
			Gems.push_back(std::make_shared<Gem>(Gem(i, j, King::Engine::TEXTURE_RED)));
		}
}

void Grid::DrawField(King::Engine &mEngine)
{
	for (GemIter g  = Gems.begin(); g != Gems.end(); ++g)
	{
		mEngine.Render(g->get()->Type, g->get()->posX, g->get()->posY);
	}
}

Grid::~Grid()
{

}