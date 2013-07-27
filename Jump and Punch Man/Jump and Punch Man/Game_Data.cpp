#include "StdAfx.h"



Game_Data::Game_Data(void)
{
	
} // end Game_Data


Game_Data::~Game_Data(void)
{

} // end ~Game_Data


//
Game_Data &Game_Data::main()
{
	static Game_Data instance;
	return instance;
}


// Stand in constructor.
void Game_Data::CreateGame(int x, int y)
{
	screenSize = sf::Vector2i(x, y);
} // end CreateGame
