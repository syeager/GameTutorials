#include "StdAfx.h"


Game::GameStates Game::_gameState = UNITIALIZED;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;
sf::Clock Game::gameClock;
float Game::_deltaTime;
float Game::_frameSpeed;
LevelManager Game::levelManager;

void Game::Start()
{
	if (_gameState != UNITIALIZED) return;

	_mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Jump and Punch Man");

	//_mainWindow.setFramerateLimit(60); // causes lag
	_mainWindow.setKeyRepeatEnabled(false);
	_frameSpeed = 30.0f;

	_gameState = PLAYING;

	// create player for testing
	Rex *RexPlayer = new Rex();
	RexPlayer->SetPosition(100, 100);
	RexPlayer->SetName("Rex");
	_gameObjectManager.Add("Rex", RexPlayer);
	Rex *target = new Rex();
	target->SetPosition(0, 0);
	target->SetName("Target");
	_gameObjectManager.Add("target", target);

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


sf::RenderWindow& Game::GetWindow()
{
	return _mainWindow;
} // end GetWindow


GameObjectManager &Game::GetGameObjectManager()
{
	return _gameObjectManager;
} // end GetGameObjectManager


void Game::GameLoop()
{
	_deltaTime = _frameSpeed*gameClock.restart().asSeconds();

	sf::Event currentEvent;

	//while (_mainWindow.pollEvent(currentEvent))
	_mainWindow.pollEvent(currentEvent);
	{
		switch (_gameState)
		{
		case SPLASH:

			break;
			
		case MAINMENU:

			break;

		case PLAYING:
			// update
			_gameObjectManager.UpdateAll();

			// draw
			_mainWindow.clear();
			_gameObjectManager.DrawAll(_mainWindow);
			_mainWindow.display();

			// close
			if (currentEvent.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				std::cout<<"EXITING\n";
				_gameState = EXITING;
			}
			
			// restart
			if (currentEvent.key.code == sf::Keyboard::Return && currentEvent.type == sf::Event::KeyPressed)
			{
				std::cout<<"RESTARTING\n";
				// restarting code here
			}
			break;

		default:
			break;
		}
	}
} // end GameLoop