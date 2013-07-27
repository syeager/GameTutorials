#include "StdAfx.h"



LevelManager::LevelManager(void)
{
	gridSpaceSize = 50;
	gridHeight = 100;
	gridWidth = 100;
	grid.resize(gridHeight);
	for (int i = 0; i < gridHeight; i++)
	{
		grid[i].resize(gridWidth);
	}
} // end LevelManager


LevelManager::~LevelManager(void)
{
} // end ~LevelManager