#pragma once
#include "stdafx.h"
#include "GameScreen.h"

#define ScreenWidth 800
#define ScreenHeight 600

class ScreenManager
{
public:
	~ScreenManager();
	static ScreenManager &GetInstance();

	void Initialize();
	void LoadContent();
	//void UnloadContent();
	void Update(sf::Event curEvent);
	void Draw(sf::RenderWindow &Window);

	void AddScreen(GameScreen *screen);

private:
	//GameScreen *currentScreen, *newScreen;

	ScreenManager();
	ScreenManager(ScreenManager const&);
	void operator=(ScreenManager const&);
};