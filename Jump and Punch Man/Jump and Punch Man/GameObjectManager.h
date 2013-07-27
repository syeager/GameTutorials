#pragma once
#include "stdafx.h"
#include "VisibleGameObject.h"
#include "Rigidbody.h"


class GameObjectManager
{
public:
	GameObjectManager(void);
	~GameObjectManager(void);

	void Add(std::string name, VisibleGameObject *gameOject);
	void Remove(std::string name);
	int GetObjectCount() const;
	VisibleGameObject *Get(std::string name) const;

	void AddRB(Rigidbody *rigidbody);
	void RemoveRB(Rigidbody *rigidbody);
	std::list<Rigidbody*> _rigidbodies;

	void DrawAll(sf::RenderWindow &window);
	void UpdateAll();



	int gridSpaceSize;
	int gridHeight;
	int gridWidth;


	std::vector<Rigidbody*> _grid[25][25];



private:
	std::map<std::string, VisibleGameObject*> _gameObjects;

	struct GameObjectDeallocator
	{
		void operator()(const std::pair<std::string, VisibleGameObject*> &p) const
		{
			delete p.second;
		}
	};
};

