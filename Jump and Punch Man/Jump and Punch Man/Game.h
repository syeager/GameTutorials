#pragma once
#include "stdafx.h"


class Game
{
public:
	static sf::RenderWindow& GetWindow();
	const static int SCREEN_WIDTH = 1024;
	const static int SCREEN_HEIGHT = 768;
	static GameObjectManager &GetGameObjectManager();

	static void Start();
	static float DeltaTime() {return _deltaTime;}

	static LevelManager levelManager;
private:
	//b2World  _world;

	static sf::Clock gameClock;
	static float _deltaTime;
	enum GameStates {UNITIALIZED, SPLASH, MAINMENU, PLAYING, PAUSED, EXITING, LOADING};
	static GameStates _gameState;
	static sf::RenderWindow _mainWindow;
	static GameObjectManager _gameObjectManager;
	static float _frameSpeed;

	static bool IsExiting();
	static void GameLoop();
};