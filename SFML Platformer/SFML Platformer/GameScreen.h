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
};

