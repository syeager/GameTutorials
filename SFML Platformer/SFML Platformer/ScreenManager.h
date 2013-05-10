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
	void Update(sf::RenderWindow &Window, sf::Event event);
	void Draw(sf::RenderWindow &Window);

	void AddScreen(GameScreen *screen);
	
	float deltaTime;

private:
	ScreenManager();
	ScreenManager(ScreenManager const&);
	void operator=(ScreenManager const&);

	sf::Clock frameClock;

	//GameScreen *currentScreen, *newScreen;
};

