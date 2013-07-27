#include "StdAfx.h"



Rigidbody::Rigidbody(void)
{
} // end Rigidbody


Rigidbody::~Rigidbody(void)
{
} // end ~Rigidbody


void Rigidbody::Update(float deltaTime)
{
	if (!_sleeping)
	{
		DetectCollisions();
	}
} // end Update


void Rigidbody::Draw(sf::RenderWindow &window)
{
	window.draw(_boundingBox);
} // end Draw


void Rigidbody::Collision(CollisionInfo info)
{
	std::cout<<"Hit"<<std::endl;
} // end Collision


void Rigidbody::Move(float x, float y)
{
	_boundingBox.move(x, y);
	UpdateGrid();
} // end Move


void Rigidbody::SetPosition(float x, float y)
{
	_boundingBox.setPosition(x, y);
} // end SetPosition


void Rigidbody::DetectCollisions()
{
	// loop through grid spaces the rigidbody is occupying
	for (int i = 0; i < _gridSpaces.size(); i++)
	{
		// loop through all rigidbodies in this square
		for (auto itr = Game::GetLevelManager().gridRigidbodies[_gridSpaces[i].x][_gridSpaces[i].y].begin(); itr != Game::GetLevelManager().gridRigidbodies[_gridSpaces[i].x][_gridSpaces[i].y].end(); itr++)
		{
			// test for collision
			if ((*itr) != this && _boundingBox.getGlobalBounds().intersects((*itr)->_boundingBox.getGlobalBounds()))
			{
				std::cout<<"Collision"<<std::endl;
			}
		}
	}

	// test for tile collisions
	int left = _boundingBox.getGlobalBounds().left;
	int right = left + _boundingBox.getGlobalBounds().width;
	int top = _boundingBox.getGlobalBounds().top;
	int bottom = top + _boundingBox.getGlobalBounds().height;

	Game::GetLevelManager().TileCollision(left, top);
	Game::GetLevelManager().TileCollision(right, top);
	Game::GetLevelManager().TileCollision(left, bottom);
	Game::GetLevelManager().TileCollision(right, bottom);
} // end DetectCollisions


void Rigidbody::UpdateGrid()
{
	// remove from grid
	for (auto itr = _gridSpaces.begin(); itr != _gridSpaces.end(); ++itr)
	{
		auto pointer = std::find(Game::GetLevelManager().gridRigidbodies[itr->x][itr->y].begin(), Game::GetLevelManager().gridRigidbodies[itr->x][itr->y].end(), this);
		Game::GetLevelManager().gridRigidbodies[itr->x][itr->y].erase(pointer);
	}
	_gridSpaces.clear();

	// calculate spaces
	int gridSize = Game::GetLevelManager().GridSpaceSize();
	int y = _boundingBox.getPosition().y;
	int x = _boundingBox.getPosition().x;
	int width = _boundingBox.getGlobalBounds().width;
	int height = _boundingBox.getGlobalBounds().height;

	// top left
	_gridSpaces.push_back(sf::Vector2i((x-width/2)%gridSize, (y-height/2)%gridSize));
	// top right
	_gridSpaces.push_back(sf::Vector2i((x+width/2)%gridSize, (y-height/2)%gridSize));
	// bottom right
	_gridSpaces.push_back(sf::Vector2i((x+width/2)%gridSize, (y+height/2)%gridSize));
	// bottom left
	_gridSpaces.push_back(sf::Vector2i((x-width/2)%gridSize, (y+height/2)%gridSize));

	// add to grid
	for (auto itr = _gridSpaces.begin(); itr != _gridSpaces.end(); ++itr)
	{
		Game::GetLevelManager().gridRigidbodies[itr->x][itr->y].push_back(this);
	}
} // end UpdateGrid