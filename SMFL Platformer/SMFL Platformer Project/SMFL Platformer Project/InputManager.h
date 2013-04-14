#pragma once
#include "stdafx.h"

class InputManager
{
public:
	InputManager(void);
	~InputManager(void);

	void Update(sf:: Event currentEvent);

	bool KeyPressed(sf::Keyboard::Key key);
	bool KeyPressed(std::vector<sf::Keyboard::Key> keys);
	bool KeyReleased(sf::Keyboard::Key key);
	bool KeyReleased(std::vector<sf::Keyboard::Key> keys);
	bool KeyDown(sf::Keyboard::Key key);
	//bool KeyDown(sf::RenderWindow &Window,std::vector<int> keys);

//private:
	sf::Event currentEvent;
};

