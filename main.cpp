#define GLM_FORCE_RADIANS 

#include <king/Engine.h>
#include <king/Updater.h>
#include <iostream>

#include "Grid.h"
#include<stdlib.h>
#include <time.h>
//**********************************************************************

class ExampleGame : public King::Updater {
public:

	ExampleGame()
		: mEngine("./assets")
		, mRotation(0.0f)
		, mYellowDiamondX(100.0f)
		, mYellowDiamondY(100.0f) {
	}

	void Start() {
		srand(time(NULL));
		grid = std::make_shared<Grid>(Grid());
		grid->GenerateGrid(8, 8);

		mEngine.Start(*this);
	}

	void Update() {
		/*mEngine.Render(King::Engine::TEXTURE_GREEN, 650.0f, 100.0f);
		mEngine.Render(King::Engine::TEXTURE_RED, 100.0f, 450.0f);
		mEngine.Render(King::Engine::TEXTURE_BLUE, 650.0f, 450.0f);

		mEngine.Write("Green", 650.0f, 140.0f);
		mEngine.Write("Red", 100.0f, 490.0f);
		mEngine.Write("Blue", 650.0f, 490.0f);

		const char text[] = "This rotates at 5/PI Hz";
		mRotation += mEngine.GetLastFrameSeconds();
		mEngine.Write(text, mEngine.GetWidth() / 2.0f, mEngine.GetHeight() / 2.0f, mRotation * 2.5f);

		
		mEngine.Render(King::Engine::TEXTURE_YELLOW, mYellowDiamondX, mYellowDiamondY);
		mEngine.Write("Click to", mYellowDiamondX, mYellowDiamondY + 40.0f);
		mEngine.Write("move me!", mYellowDiamondX, mYellowDiamondY + 70.0f);
*/
		grid->Update(mEngine);
		grid->DrawField(mEngine);

		if (grid->isMatch(2, 2))
		{
			std::cout << "match found" << std::endl;
		}
		//grid->gemAt(5, 5).get()->Type = King::Engine::Texture(rand() % 6);
	}

private:
	King::Engine mEngine;
	std::shared_ptr<Grid> grid;
	float mRotation;
	float mYellowDiamondX;
	float mYellowDiamondY;
};

//**********************************************************************

int main(int argc, char *argv[]) {
	ExampleGame game;
	game.Start();

	return 0;
}


