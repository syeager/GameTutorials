#pragma once
#include "StdAfx.h"


class LevelManager
{
public:
	LevelManager(void);
	~LevelManager(void);


	int gridSpaceSize;
	int gridHeight;
	int gridWidth;
	std::vector<std::vector<std::map<std::string, Rigidbody*>>> grid;
}; // end LevelManager class