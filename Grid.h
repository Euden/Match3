#pragma once
#include "Gem.h"
#include <vector>
#include <memory>
#include <king/Engine.h>

typedef std::vector<std::shared_ptr<Gem>> GemVector;
typedef GemVector::iterator GemIter;
typedef std::vector<GemVector> DoubleGemVector;

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


	void GemSelect();
	void GemDeselect();

	// void showSuggestion

	void TmpSwap(int row1, int col1, int row2, int col2);
	std::shared_ptr<Gem> gemAt(int row, int col);

	void swapGems(Gem& g1, Gem& g2, bool swapBack)
	{
		canPick = false;
		King::Engine::Texture fromColor = g1.Type;
		King::Engine::Texture toColor = g2.Type;

		gameArray[getOrbRow(orb1)][getOrbCol(orb1)].orbColor = toColor;
		gameArray[getOrbRow(orb1)][getOrbCol(orb1)].orbSprite = toSprite;
		gameArray[getOrbRow(orb2)][getOrbCol(orb2)].orbColor = fromColor;
		gameArray[getOrbRow(orb2)][getOrbCol(orb2)].orbSprite = fromSprite;
		
		
		var orb1Tween = game.add.tween(gameArray[getOrbRow(orb1)][getOrbCol(orb1)].orbSprite).to({
		x: getOrbCol(orb1) * orbSize + orbSize / 2,
		   y : getOrbRow(orb1) * orbSize + orbSize / 2
		}, swapSpeed, Phaser.Easing.Linear.None, true);
		var orb2Tween = game.add.tween(gameArray[getOrbRow(orb2)][getOrbCol(orb2)].orbSprite).to({
		x: getOrbCol(orb2) * orbSize + orbSize / 2,
		   y : getOrbRow(orb2) * orbSize + orbSize / 2
		}, swapSpeed, Phaser.Easing.Linear.None, true);
		orb2Tween.onComplete.add(function() {
			if (!matchInBoard() && swapBack) {
				swapOrbs(orb1, orb2, false);
			}
			else {
				if (matchInBoard()) {
					handleMatches();
				}
				else {
					canPick = true;
					selectedOrb = null;
				}
			}
		});
	}

	GemVector Gems;
	DoubleGemVector Gems2;

private:
	int fieldSizeX, fieldSizeY;
	bool canPick;
};