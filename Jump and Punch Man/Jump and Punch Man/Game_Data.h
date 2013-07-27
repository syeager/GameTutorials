#pragma once
#include "StdAfx.h"


class Game_Data
{
public:
	~Game_Data();
	static Game_Data &main();

	void CreateGame(int x, int y);

	// Getters Setters
	sf::Vector2i GetScreenSize() { return screenSize; }
private:
	Game_Data();
	Game_Data(Game_Data const&);
	void operator=(Game_Data const&);
	
	sf::Vector2i screenSize;
};