#include "StdAfx.h"


Game::GameStates Game::_gameState = UNITIALIZED;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;
ResourcesManager Game::_resourcesManager;
LevelManager Game::_levelManager;
sf::Clock Game::_frameClock;
float Game::_deltaTime;
float Game::_frameSpeed;


Game::Game()
{
} // end Game


Game::~Game()
{
} // end ~Game


void Game::Start()
{
	if (_gameState != UNITIALIZED) return;

	_mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Platformer Proto 01");
	_mainWindow.setKeyRepeatEnabled(false);
	_frameSpeed = 30.0f;
	_gameState = PLAYING;

	// set up test tiles
	//Tile *newTile = new Tile("Resources/Textures/green.jpg", true);
	//newTile->Load("Resources/Textures/green.jpg");
	//_gameObjectManager.Add("Green Tile", newTile);
	_levelManager.Load("Resources/Maps/Level_Map_1.txt");




	// main loop
	while (!IsExiting())
	{
		GameLoop();
	}
	_mainWindow.close();
} // end Start


bool Game::IsExiting()
{
	if (_gameState == EXITING)
	{
		return true;
	}
	else
	{
		return false;
	}
} // end IsExiting


void Game::GameLoop()
{
	_deltaTime = _frameSpeed*_frameClock.restart().asSeconds();

	sf::Event currentEvent;
	_mainWindow.pollEvent(currentEvent);

	switch(_gameState)
	{
	case PLAYING:
		// update
		_gameObjectManager.UpdateAll(_deltaTime);

		// draw
		_mainWindow.clear();
		//_levelManager.Draw(_mainWindow);
		_levelManager.DrawBackground(_mainWindow);
		_levelManager.DrawMidground(_mainWindow);
		_gameObjectManager.DrawAll(_mainWindow);
		_levelManager.DrawForeground(_mainWindow);
		_mainWindow.display();

		// close
		if (currentEvent.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			std::cout<<"EXITING\n";
			_gameState = EXITING;
		}
		break;

	default:
		break;
	}
} // end GameLoop