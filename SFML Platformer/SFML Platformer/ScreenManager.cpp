#include "stdafx.h"


GameScreen *currentScreen, *newScreen;


ScreenManager::ScreenManager(void)
{
}


ScreenManager::~ScreenManager(void)
{
}

ScreenManager& ScreenManager::GetInstance()
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

void ScreenManager::Update()
{
	currentScreen->Update();
}

void ScreenManager::Draw(sf::RenderWindow &window)
{
	currentScreen->Draw(window);
}