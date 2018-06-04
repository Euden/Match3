#pragma once
#include "Gem.h"
#include <vector>
#include <memory>
#include <king/Engine.h>

typedef std::vector<std::shared_ptr<Gem>> GemVector;
typedef GemVector::iterator GemIter;

#define MAX_ARRAY_SIZE 255

class Grid
{
public:
	Grid();
	~Grid();

	void GenerateGrid(int sizeX, int sizeY);
	void DrawField(King::Engine &mEngine);
	void Update(King::Engine &mEngine);

	bool isMatch(int row, int col);
	bool isHorizontalMatch(int row, int col);
	bool isVerticalMatch(int row, int col);

	
	std::vector<Gem*> lookForMatches();

	void GemSelect();
	void GemDeselect();

	// void showSuggestion

	void TmpSwap(int row1, int col1, int row2, int col2);
	std::shared_ptr<Gem> gemAt(int row, int col);

	void swapGems(Gem &A, Gem &B);

	GemVector Gems;
	Gem* GemsArray[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];
	Gem* SelectedGem = nullptr;
private:
	int fieldSizeX, fieldSizeY;
	bool canPick;
	bool mouseDown;
};