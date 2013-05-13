#pragma once
#include "stdafx.h"

class GameScreen
{
public:
	GameScreen(void);
	~GameScreen(void);

	virtual void LoadContent();
	virtual void UnloadContent();
	virtual void Update(sf::RenderWindow &Window, sf::Event event);
	virtual void Draw(sf::RenderWindow &Window);

protected:
	InputManager input;
	std::vector<sf::Keyboard::Key> keys;

	FileManager file;
	std::vector<std::vector<std::string>> attributes;
	std::vector<std::vector<std::string>> contents;
};

