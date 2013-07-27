#pragma once
#include "stdafx.h"

class LevelManager;

class Game
{
public:
	Game();
	~Game();

	const static int SCREEN_WIDTH = 1024;
	const static int SCREEN_HEIGHT = 768;

	static sf::RenderWindow &GetWindow() { return _mainWindow; }
	static GameObjectManager &GetGameObjectManager() { return _gameObjectManager; }
	static ResourcesManager &GetResourcesManager() { return _resourcesManager; }
	static LevelManager &GetLevelManager() { return _levelManager; }
	static void Start();
	static float DeltaTime() { return _frameSpeed; }

private:
	static sf::Clock _frameClock;
	static float _deltaTime;
	enum GameStates { UNITIALIZED, SPLASH, MAINMENU, PLAYING, PAUSED, EXITING, LOADING };
	static GameStates _gameState;
	static sf::RenderWindow _mainWindow;
	static GameObjectManager _gameObjectManager;
	static ResourcesManager _resourcesManager;
	static LevelManager _levelManager;
	static float _frameSpeed;

	static bool IsExiting();
	static void GameLoop();
}; // end Game class