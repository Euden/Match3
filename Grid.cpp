#include "Grid.h"
#include <iostream>
Grid::Grid()
{

}

void Grid::GenerateGrid(int sizeX, int sizeY)
{
	bool settingUp = true;
	while (settingUp)
	{
		for (int i = 0; i < sizeY; ++i)
			for (int j = 0; j < sizeX; ++j)
			{
				GemsArray[i][j] = new Gem(i, j);
			}

		if (lookForMatches().size() != 0) continue;

		// no matches, break.
		settingUp = false;
	}
	


	fieldSizeX = sizeX;
	fieldSizeY = sizeY;
}

void Grid::DrawField(King::Engine &mEngine)
{
	for (int i = 0; i < fieldSizeX; ++i)
		for (int j = 0; j < fieldSizeY; ++j)
		{
			if (GemsArray[i][j]->selected)
			{
				mEngine.Render(GemsArray[i][j]->Type, GemsArray[i][j]->posX + 1, GemsArray[i][j]->posY + 1);
			}
			else
			{
				mEngine.Render(GemsArray[i][j]->Type, GemsArray[i][j]->posX, GemsArray[i][j]->posY);
			}
		}
}

void Grid::Update(King::Engine &mEngine)
{
	int mouseX = mEngine.GetMouseX();
	int mouseY = mEngine.GetMouseY();

	if (mEngine.GetMouseButtonDown())
	{
		if (mouseDown)
			return;
		std::cout << "mouse Down again.." << std::endl;
		mouseDown = true;
		for (int i = 0; i < fieldSizeX; ++i)
			for (int j = 0; j < fieldSizeY; ++j)
			{
				// Calculate bounds of gem.
				int width = mEngine.GetTextureHeight(GemsArray[i][j]->Type);
				int height = mEngine.GetTextureWidth(GemsArray[i][j]->Type);
				
				int Left = GemsArray[i][j]->posX;
				int right = Left + width;
				int top = GemsArray[i][j]->posY;
				int bottom = top + height;
				if (((mouseX > Left) && (mouseX < right)) && ((mouseY > top) && (mouseY < bottom)))
				{ 
					if(GemsArray[i][j]->selected)
						return;

					if (SelectedGem != nullptr)
					{
						SelectedGem->selected = false;
						swapGems(*SelectedGem, *GemsArray[i][j]);
						SelectedGem = nullptr;
						return;
					}
					else
					{
						std::cout << "New Gem.." << std::endl;
						SelectedGem = GemsArray[i][j];
						std::cout << "row: " << SelectedGem->row << " col: " << SelectedGem->col << std::endl;
						SelectedGem->selected = true;
					}
				}
			}
	}
	else
	{	
		mouseDown = false;
	}
}

void Grid::swapGems(Gem &A, Gem &B)
{
	bool canSwap = false;
	if (A.row == B.row)
	{
		if( (A.col == B.col+1)  || (A.col == B.col - 1))
		{
			canSwap = true;
		}
	}

	if ((A.row == B.row - 1) || (A.row == B.row + 1))
	{
		if (A.col == B.col)
		{
			canSwap = true;
		}
	}

	if (canSwap)
	{	
		Gem temp = A;
		A.Type = B.Type;
		B.Type = temp.Type;
		//std::swap(A, B);

	}
	else {
		std::cout << "GEMS CAN'T BE SWAPPED" << std::endl;
	}
}

std::vector<Gem*> Grid::lookForMatches()
{

	std::vector<Gem*> matches;

	for (int i = 0; i < fieldSizeX; ++i)
		for (int j = 0; j < fieldSizeY; ++j)
		{
			if (isMatch(GemsArray[i][j]->row, GemsArray[i][j]->col))
			{
				matches.push_back(GemsArray[i][j]);
			}
		}
	
	return matches;
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

bool Grid::isVerticalMatch(int row, int col)
{
	bool matchFound = false;
	if (col > 1)
	{
		if (GemsArray[row][col]->Type == GemsArray[row][col - 1]->Type  && GemsArray[row][col]->Type == GemsArray[row][col - 2]->Type)
		{
			matchFound = true;
		}
		else
		{
			if (GemsArray[row][col]->Type == GemsArray[row][col + 1]->Type  && GemsArray[row][col]->Type == GemsArray[row][col + 2]->Type)
			{
				matchFound = true;
			}
		}
	}

	return matchFound;
}

bool Grid::isHorizontalMatch(int row, int col)
{
	bool matchFound = false;
	if (row > 1)
	{
		if (GemsArray[row][col]->Type == GemsArray[row - 1][col]->Type  && GemsArray[row][col]->Type == GemsArray[row - 2][col]->Type)
		{
			matchFound = true;
		}
		else
		{
			if (GemsArray[row][col]->Type == GemsArray[row + 1][col]->Type  && GemsArray[row][col]->Type == GemsArray[row + 2][col]->Type)
			{
				matchFound = true;
			}
		}
	}

	return matchFound;
}

bool Grid::isMatch(int row, int col)
{
	return isHorizontalMatch(row, col) || isVerticalMatch(row, col);
}

void Grid::TmpSwap(int row1, int col1, int row2, int col2)
{
	Gem temp = *gemAt(row1, col1).get();
	gemAt(row1, col1) = gemAt(row2, col2);
	gemAt(row2, col2) = std::make_shared<Gem>(temp);
}
Grid::~Grid()
{

}