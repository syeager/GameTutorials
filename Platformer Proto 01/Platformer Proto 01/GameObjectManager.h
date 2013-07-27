#pragma once
#include "stdafx.h"


class GameObjectManager
{
public:
	GameObjectManager();
	~GameObjectManager();

	void Add(std::string name, GameObject *gameObject);
	void Remove(std::string name);
	int GetObjectCount() const { return _gameObjects.size(); }
	GameObject *Get(std::string name) const;
	void DrawAll(sf::RenderWindow &window);
	void UpdateAll(float deltaTime);
	unsigned int GetNextID();

private:
	std::map<std::string, GameObject*> _gameObjects;
	unsigned int _gameObjectIDCounter;

	struct GameObjectDeallocator
	{
		void operator()(const std::pair<std::string, GameObject*> &p) const
		{
			delete p.second;
		}
	};
}; // end GameObjectManager class