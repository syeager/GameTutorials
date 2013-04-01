#include "stdafx.h"
#include "Game.h"

void Game::Start() // (void)
{
	if(_gameState != Uninitialized)
		return;

	_mainWindow.Create(sf::VideoMode(1024, 768, 32), "Pang!");
	_gameState = Game::Playing;

	while(!IsExiting())
	{
		GameLoop();
	}

	_mainWindow.Close();
} // end Start

bool Game::IsExiting()
{
	if(_gameState == Exiting) // Game::
		return true;
	else
		return false;
} // end IsExiting

void Game::GameLoop()
{
	sf::Event currentEvent;
	while(_mainWindow.GetEvent(currentEvent))
	{
		switch(_gameState)
		{
		case Playing: // Game::
			{
				_mainWindow.Clear(sf::Color(255, 0, 0));
				_mainWindow.Display();

				if(currentEvent.Type == sf::Event::Closed)
				{
					_gameState = Game::Exiting;
				}
				break;
			}
		}
	}
} // end GameLoop


Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;