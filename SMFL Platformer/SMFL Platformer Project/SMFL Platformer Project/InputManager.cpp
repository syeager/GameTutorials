#include "StdAfx.h"



InputManager::InputManager(void)
{
}


InputManager::~InputManager(void)
{
}


void InputManager::Update(sf::Event currentEvent)
{
	this->currentEvent = currentEvent;
}


bool InputManager::KeyPressed(sf::Keyboard::Key key)
{
	if(currentEvent.key.code == key && currentEvent.type == sf::Event::KeyPressed)
		return true;
	return false;
}

bool InputManager::KeyPressed(std::vector<sf::Keyboard::Key> keys)
{
	for(int i = 0; i < keys.size(); i++)
	{
		if(KeyPressed(keys[i]))
			return true;
	}

	return false;
}


bool InputManager::KeyReleased(sf::Keyboard::Key key)
{
	if(currentEvent.key.code == key && currentEvent.type ==	sf::Event::KeyReleased)
		return true;
	return false;
}

bool InputManager::KeyReleased(std::vector<sf::Keyboard::Key> keys)
{
	for(int i = 0; i < keys.size(); i++)
		if(KeyReleased(keys[i]))
			return true;
	return false;
}


bool InputManager::KeyDown(sf::Keyboard::Key key)
{
	if(sf::Keyboard::isKeyPressed(key))
		return true;
	return false;
}

//bool InputManager::KeyDown(sf::RenderWindow &Window,std::vector<int> keys)
//{
//	for(int i = 0; i < keys.size(); i++)
//		if(Window::GetInput().IsKeyDown(keys[i]))
//			return true;
//	return false;
//	return false;
//}