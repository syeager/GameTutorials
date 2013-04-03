#pragma once
#include "stdafx.h"

#define ScreenWidth 800
#define ScreenHeight 600

using namespace std;

class ScreenManager
{
public:
	~ScreenManager(void);
	static ScreenManager &GetInstance();

	void Initialize();
	void LoadContent();
	void Update();
	void Draw(sf::RenderWindow &window);

private:
	//GameScreen *currentScreen, *newScreen;
	ScreenManager();
	ScreenManager(ScreenManager const&);
	void operator=(ScreenManager const&);
};

