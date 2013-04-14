#include "StdAfx.h"

GameScreen *currentScreen, *newScreen;


ScreenManager::ScreenManager(void)
{
}


ScreenManager::~ScreenManager(void)
{
}

ScreenManager &ScreenManager::GetInstance()
{
	static ScreenManager instance;
	return instance;
}

void ScreenManager::Initialize()
{
	currentScreen = new SplashScreen();
}

void ScreenManager::LoadContent()
{
	currentScreen->LoadContent();
}

void ScreenManager::Update(sf::Event curEvent)
{
	currentScreen->Update(curEvent);
}

void ScreenManager::Draw(sf::RenderWindow &Window)
{
	currentScreen->Draw(Window);
}

void ScreenManager::AddScreen(GameScreen *screen)
{
	currentScreen->UnloadContent();
	delete currentScreen;
	currentScreen = screen;
	currentScreen->LoadContent();
}