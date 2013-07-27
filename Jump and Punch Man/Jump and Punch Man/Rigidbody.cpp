#include "StdAfx.h"

struct CollisionInfo;

Rigidbody::Rigidbody(void)
{
	_sleeping = false;

	boundingBox.setSize(sf::Vector2f(40, 55));
	boundingBox.setOrigin(boundingBox.getSize().x/2, boundingBox.getSize().y/2);

	boundingBox.setOutlineColor(sf::Color::Green);
	boundingBox.setFillColor(sf::Color(100, 0, 0, 30));
	boundingBox.setOutlineThickness(1);
} // end Rigidbody


Rigidbody::~Rigidbody(void)
{
} // end ~Rigidbody



float Rigidbody::GetHVelocity() const
{
	return _velocity.x;
} // end GetVelocity


void Rigidbody::SetHVelocity(float amount)
{
	_velocity.x = amount;
	if (_velocity.x > _maxVelocity.x)
	{
		_velocity.x = _maxVelocity.x;
	}
	else if (_velocity.x < -_maxVelocity.x)
	{
		_velocity.x = -_maxVelocity.x;
	}
} // end SetVelocity






void Rigidbody::Collision(CollisionInfo info)
{
	std::cout<<"Hit\n";
} // end Collision



void Rigidbody::UpdateGrid()
{
	// remove from grid
	for (auto itr = _gridSpaces.begin(); itr != _gridSpaces.end(); ++itr)
	{
		auto pointer = std::find(Game::GetGameObjectManager()._grid[itr->x][itr->y].begin(), Game::GetGameObjectManager()._grid[itr->x][itr->y].end(), this);
		Game::GetGameObjectManager()._grid[itr->x][itr->y].erase(pointer);
	}
	_gridSpaces.clear();
	
	// calculate spaces
	int gridSize = Game::GetGameObjectManager().gridSpaceSize;
	int y = boundingBox.getPosition().y;
	int x = boundingBox.getPosition().x;
	int width = boundingBox.getGlobalBounds().width;
	int height = boundingBox.getGlobalBounds().height;
	
	// top left
	_gridSpaces.push_back(sf::Vector2i((x-width/2)/gridSize, (y-height/2)/gridSize));
	// top right
	_gridSpaces.push_back(sf::Vector2i((x+width/2)/gridSize, (y-height/2)/gridSize));
	//_gridSpaces.unique();
	// bottom right
	_gridSpaces.push_back(sf::Vector2i((x+width/2)/gridSize, (y+height/2)/gridSize));
	//_gridSpaces.unique();
	// bottom left
	_gridSpaces.push_back(sf::Vector2i((x-width/2)/gridSize, (y+height/2)/gridSize));
	//_gridSpaces.unique();

	// make unique
	//_gridSpaces
	//_gridSpaces.push_back(_gridSpaces.front());
	//_gridSpaces.pop_front();
	//_gridSpaces.unique();

	// add to grid
	for (auto itr = _gridSpaces.begin(); itr != _gridSpaces.end(); ++itr)
	{
		Game::GetGameObjectManager()._grid[itr->x][itr->y].push_back(this);
	}
	//std::cout<<_gridSpaces[0].x << ":" << _gridSpaces[0].y << std::endl;
} // end Move


void Rigidbody::DetectCollisions()
{
	if (_sleeping) return;

	// loop through grid spaces the rigidbody is occupying
	for (int i = 0; i < _gridSpaces.size(); i++)
	{
		// loop through all rigidbodies in this square
		for (auto itr = Game::GetGameObjectManager()._grid[_gridSpaces[i].x][_gridSpaces[i].y].begin(); itr != Game::GetGameObjectManager()._grid[_gridSpaces[i].x][_gridSpaces[i].y].end(); itr++)
		{
			// test for collision
			if ((*itr) != this && boundingBox.getGlobalBounds().intersects((*itr)->boundingBox.getGlobalBounds()))
			{
				std::cout<<"Collision"<<std::endl;
			}
		}

	}
} // end DetectCollisions


void Rigidbody::Update(float deltaTime)
{

} // end Update


void Rigidbody::Draw(sf::RenderWindow &window)
{
	window.draw(boundingBox);
} // end Draw


void Rigidbody::Move(float x, float y)
{
	boundingBox.move(x, y);
	UpdateGrid();
} // end Move