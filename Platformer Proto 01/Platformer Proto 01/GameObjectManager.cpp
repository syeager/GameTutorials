#include "StdAfx.h"



GameObjectManager::GameObjectManager()
{
} // end GameObjectManager


GameObjectManager::~GameObjectManager()
{
	std::for_each(_gameObjects.begin(), _gameObjects.end(), GameObjectDeallocator());
} // end ~GameObjectManager


void GameObjectManager::Add(std::string name, GameObject *gameObject)
{
	_gameObjects.insert(std::pair<std::string, GameObject*>(name, gameObject));
} // end Add


void GameObjectManager::Remove(std::string name)
{
	std::map<std::string, GameObject*>::iterator gameObject = _gameObjects.find(name);
	if (gameObject != _gameObjects.end())
	{
		delete gameObject->second;
		_gameObjects.erase(gameObject);
	}
} // end Remove


void GameObjectManager::DrawAll(sf::RenderWindow &window)
{
	std::map<std::string, GameObject*>::const_iterator itr = _gameObjects.begin();
	while (itr != _gameObjects.end())
	{
		itr->second->Draw(window);
		itr++;
	}
} // end DrawAll


void GameObjectManager::UpdateAll(float deltaTime)
{
	std::map<std::string, GameObject*>::const_iterator itr = _gameObjects.begin();
	while (itr != _gameObjects.end())
	{
		itr->second->Update(deltaTime);
		itr++;
	}
} // end UpdateAll


unsigned int GameObjectManager::GetNextID()
{
	_gameObjectIDCounter++;
	return _gameObjectIDCounter-1;
} // end GetNextID