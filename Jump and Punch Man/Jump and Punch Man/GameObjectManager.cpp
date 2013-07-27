#include "StdAfx.h"



GameObjectManager::GameObjectManager(void)
{
	gridSpaceSize = 100;
	gridHeight = 25;
	gridWidth = 25;
} // end GameObjectManager


GameObjectManager::~GameObjectManager(void)
{
	std::for_each(_gameObjects.begin(), _gameObjects.end(), GameObjectDeallocator());
} // end ~GameObjectManager


void GameObjectManager::Add(std::string name, VisibleGameObject *gameObject)
{
	_gameObjects.insert(std::pair<std::string, VisibleGameObject*>(name, gameObject));

	if (dynamic_cast<Rigidbody*>(gameObject) != NULL)
	{
		AddRB(dynamic_cast<Rigidbody*>(gameObject));
	}
} // end Add


void GameObjectManager::Remove(std::string name)
{
	std::map<std::string, VisibleGameObject*>::iterator result = _gameObjects.find(name);
	if (result != _gameObjects.end())
	{
		delete result->second;
		_gameObjects.erase(result);
	}
} // end Remove


VisibleGameObject* GameObjectManager::Get(std::string name) const
{
	std::map<std::string, VisibleGameObject*>::const_iterator result = _gameObjects.find(name);
	if (result == _gameObjects.end())
	{
		return NULL;
	}
	return result->second;
} // end Get


int GameObjectManager::GetObjectCount() const
{
	return _gameObjects.size();
} // end GetObjectCount


void GameObjectManager::DrawAll(sf::RenderWindow &window)
{
	// draw collisions
	/*for (int i = 0; i < gridHeight; i++)
	{
		for (int j = 0; j < gridWidth; j++)
		{
			if (_grid[j][i].size() > 1)
			{
				sf::RectangleShape rect(sf::Vector2f(gridSpaceSize, gridSpaceSize));
				rect.setFillColor(sf::Color::Yellow);
				rect.setPosition(j*gridSpaceSize, i*gridSpaceSize);
				window.draw(rect);
			}
		}
	}

	// draw world grid
	for (int i = 0; i < gridHeight; i++)
	{
		sf::RectangleShape rect(sf::Vector2f(2000, 1));
		rect.setPosition(0, i*gridSpaceSize);
		rect.setFillColor(sf::Color::Blue);
		window.draw(rect);

		for (int j = 0; j < gridWidth; j++)
		{
			sf::RectangleShape rect2(sf::Vector2f(1, 2000));
			rect2.setPosition(j*gridSpaceSize, 0);
			rect2.setFillColor(sf::Color::Blue);
			window.draw(rect2);
		}
	}*/

	std::map<std::string, VisibleGameObject*>::const_iterator itr = _gameObjects.begin();
	while (itr != _gameObjects.end())
	{
		itr->second->Draw(window);
		itr++;
	}
} // end DrawAll


void GameObjectManager::UpdateAll()
{
	// check for collisions
	//for (int i = 0; i < gridHeight; i++)
	//{
	//	for (int j = 0; j < gridWidth; j++)
	//	{
	//		if (_grid[j][i].size() > 1)
	//		{
	//			for (int m = 0; m < _grid[j][i].size()-1; m++)
	//			{
	//				for (int n = m+1; n < _grid[j][i].size(); n++)
	//				{
	//					if (_grid[j][i][m]->GetBB().getGlobalBounds().intersects(_grid[j][i][n]->GetBB().getGlobalBounds()))
	//					{
	//						_grid[j][i][m]->Collision(CollisionInfo(CollisionInfo::DOWN, _grid[j][i][n]));
	//						_grid[j][i][n]->Collision(CollisionInfo(CollisionInfo::DOWN, _grid[j][i][m]));

	//						// bottom
	//						if (_grid[j][i][m]->GetBB().getPosition().y+_grid[j][i][m]->GetBB().getGlobalBounds().height/2 > _grid[j][i][n]->GetBB().getPosition().y-_grid[j][i][n]->GetBB().getGlobalBounds().height/2)
	//						{
	//							std::cout<<"Bottom"<<std::endl;
	//						}
	//					}
	//				}
	//			}
	//		}
	//	}
	//}

	// run updates
	std::map<std::string, VisibleGameObject*>::const_iterator itr = _gameObjects.begin();
	float deltaTime = Game::DeltaTime();
	while (itr != _gameObjects.end())
	{
		itr->second->Update(deltaTime);
		itr++;
	}
} // end UpdateAll


void GameObjectManager::AddRB(Rigidbody *rigidbody)
{
	_rigidbodies.push_back(rigidbody);
} // end AddRB


void GameObjectManager::RemoveRB(Rigidbody *rigidbody)
{
	_rigidbodies.remove(rigidbody);
} // end RemoveRB