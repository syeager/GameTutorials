#include "stdafx.h"
#include "Game.h"
#include "SplashScreen.h"
#include "MainMenu.h"

void Game::Start()
{
	if(_gameState != Uninitialized)
		return;

	_mainWindow.Create(sf::VideoMode(1024, 768, 32), "Pang!");
	_gameState = ShowingSplash;

	while(!IsExiting())
	{
		GameLoop();
	}

	_mainWindow.Close();
} // end Start

bool Game::IsExiting()
{
	if(_gameState == Exiting)
		return true;
	else
		return false;
} // end IsExiting

void Game::GameLoop()
{
	std::cout<<_gameState<<std::endl;
	sf::Event currentEvent;
	while(_mainWindow.GetEvent(currentEvent))
	{
		switch(_gameState)
		{
		case ShowingMenu:
			{
				ShowMenu();
				break;
			}
		case ShowingSplash:
			{
				ShowSplashScreen();
				break;
			}
		case Playing:
			{
				sf::Event currentEvent;
				while(_mainWindow.GetEvent(currentEvent))
				{
					_mainWindow.Clear(sf::Color(0, 0, 0));
					_mainWindow.Display();

					if(currentEvent.Type == sf::Event::Closed)
					{
						_gameState = Game::Exiting;
					}
					if(currentEvent.Type == sf::Event::KeyPressed)
					{
						if(currentEvent.Key.Code == sf::Key::Escape)
						{
							ShowMenu();
						}
					}
				}				
				break;
			}
		}
	}
} // end GameLoop

void Game::ShowSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.Show(_mainWindow);
	_gameState = ShowingMenu;
} // end ShowSplashScreen

void Game::ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(_mainWindow);
	switch(result)
	{
	case MainMenu::Exit:
		{
			_gameState = Exiting;
			std::cout<<"Exit\n";
			break;
		}
	case MainMenu::Play:
		{
			_gameState = Playing;
			std::cout<<"Play\n";
			break;
		}
	}
} // end ShowMenu


Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;