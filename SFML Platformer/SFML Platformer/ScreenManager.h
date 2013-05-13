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
	void UnloadContent();
	void Update(sf::RenderWindow &Window, sf::Event event);
	void Draw(sf::RenderWindow &Window);

	void AddScreen(GameScreen *screen);
	float GetAlpha();
	
	float deltaTime;

private:
	ScreenManager();
	ScreenManager(ScreenManager const&);
	void operator=(ScreenManager const&);

	void Transition(sf::RenderWindow &Window);

	sf::Clock frameClock;
	bool transition;
	FadeAnimation fade;
	GameScreen *newScreen;

	FileManager file;
	std::vector<std::vector<std::string>> attributes;
	std::vector<std::vector<std::string>> contents;

	//GameScreen *currentScreen, *newScreen;
};

