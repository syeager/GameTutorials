#pragma once
#include "stdafx.h"
#include "InputManager.h"

class GameScreen
{
public:
	GameScreen();
	~GameScreen();

	virtual void LoadContent();
	virtual void UnloadContent();
	virtual void Update(sf::Event curEvent);
	virtual void Draw(sf::RenderWindow &Window);

protected:
	InputManager input;
	std::vector<sf::Keyboard::Key> keys;
};

