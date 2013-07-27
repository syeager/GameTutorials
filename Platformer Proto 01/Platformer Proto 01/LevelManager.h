#pragma once
#include "stdafx.h"


class LevelManager
{
public:
	std::vector<Rigidbody*> gridRigidbodies[10][10];

	LevelManager();
	~LevelManager();

	void Load(std::string map);
	void Draw(sf::RenderWindow &window);

	void DrawBackground(sf::RenderWindow &window);
	void DrawMidground(sf::RenderWindow &window);
	void DrawForeground(sf::RenderWindow &window);


	int GridSpaceSize() const { return _gridSpaceSize; }
	bool TileCollision(int x, int y);
	
	//void RemoveRB(Rigidbody *rb, int x, int y);
	//void AddRB(Rigidbody *rb, int x, int y);

protected:
	int _gridWidth, _gridHeight;
	int _gridSpaceSize;
	std::vector<std::vector<Tile*>> _grid;
	Tile* _background[7][10];
	Tile* _midground[7][10];
	Tile* _foreground[7][10];
}; // end LevelManager class