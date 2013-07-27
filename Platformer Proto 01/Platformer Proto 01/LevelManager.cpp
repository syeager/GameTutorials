#include "StdAfx.h"



LevelManager::LevelManager()
{
} // end LevelManager


LevelManager::~LevelManager()
{
} // end ~LevelManager


void LevelManager::Load(std::string map)
{
	std::ifstream openFile(map);

	if (openFile.is_open())
	{
		while (!openFile.eof())
		{
			std::string str, value;
			std::getline(openFile, str);
			std::stringstream stream(str);

			// new empty column
			_grid.push_back(std::vector<Tile*>());
			_gridWidth = 0;

			while (std::getline(stream, value, ' '))
			{
				int adlkj = str.length();

				// fill column
				if (value == "0")
				{
					_grid[_gridHeight].push_back(new Tile("Resources/Textures/green.jpg", (_gridWidth)*32, (_gridHeight)*32, true));
				}
				else if (value == "1")
				{
					_grid[_gridHeight].push_back(new Tile("Resources/Textures/blue.jpg", (_gridWidth)*32, (_gridHeight)*32, true));
				}

				_gridWidth++;
			}
			_gridHeight++;
		}
		
		openFile.close();
	}
} // end Load


void LevelManager::Draw(sf::RenderWindow &window)
{
	for (int i = 0; i < _gridHeight; i++)
	{
		for (int j = 0; j < _gridWidth; j++)
		{
			_grid[i][j]->Draw(window);
		}
	}
} // end Draw


void LevelManager::DrawBackground(sf::RenderWindow &window)
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (_background[i][j] != NULL) _background[i][j]->Draw(window);
		}
	}
} // end DrawBackground


void LevelManager::DrawMidground(sf::RenderWindow &window)
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (_midground[i][j] != NULL) _midground[i][j]->Draw(window);
		}
	}
} // end DrawMidground


void LevelManager::DrawForeground(sf::RenderWindow &window)
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (_foreground[i][j] != NULL) _foreground[i][j]->Draw(window);
		}
	}
} // end DrawForeground


bool LevelManager::TileCollision(int x, int y)
{
	if (_grid[y][x] != NULL && _grid[y][x]->IsSolid())
	{
		return true;
	}
	else
	{
		return false;
	}
} // end TileCollision