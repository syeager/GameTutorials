#include "StdAfx.h"



InputManager::InputManager(void)
{
}


InputManager::~InputManager(void)
{
}


void InputManager::Update(sf::Event event)
{
	this->event = event;
} // end Update


bool InputManager::KeyPressed(sf::Keyboard::Key key)
{
	if (event.key.code == key)
		return true;
	return false;
} // End KeyPressed

bool InputManager::KeyPressed(std::vector<sf::Keyboard::Key> keys)
{
	for (int i = 0; i < keys.size(); i++)
	{
		if (KeyPressed(keys[i]))
			return true;
	}
	return false;
} // end KeyPressed


bool InputManager::KeyReleased(sf::Keyboard::Key key)
{
	if (event.key.code == key && event.KeyReleased)
		return true;
	return false;
} // end KeyReleased

bool InputManager::KeyReleased(std::vector<sf::Keyboard::Key> keys)
{
	for (int i = 0; i < keys.size(); i++)
	{
		if (KeyReleased(keys[i]))
			return true;
	}
	return false;
} // end KeyReleased


bool InputManager::KeyDown(sf::Keyboard::Key key)
{
	if (sf::Keyboard::isKeyPressed(key))
		return true;
	return false;
} // end KeyDown

bool InputManager::KeyDown(std::vector<sf::Keyboard::Key> keys)
{
	for (int i = 0; i < keys.size(); i++)
	{
		if (KeyDown(keys[i]))
			return true;
	}
	return false;
} // end KeyDown