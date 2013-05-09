#pragma once
#include "stdafx.h"

#define ScreenWidth 800
#define ScreenHeight 600

class ScreenManager
{
public:
	~ScreenManager();
	static ScreenManager &Instance();

	void Initialize();
	void LoadContent();
	void Update(sf::Event event);
	void Draw(sf::RenderWindow &Window);

	void AddScreen(GameScreen *screen);

private:
	ScreenManager();
	ScreenManager(ScreenManager const&);
	void operator=(ScreenManager const&);

	//GameScreen *currentScreen, *newScreen;
};

