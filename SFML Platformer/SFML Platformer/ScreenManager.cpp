#include "StdAfx.h"

GameScreen *currentScreen, *newScreen;


ScreenManager &ScreenManager::Instance()
{
	static ScreenManager instance;
	return instance;
} // end Instance


ScreenManager::~ScreenManager()
{
}

ScreenManager::ScreenManager()
{

}


void ScreenManager::Initialize()
{
	currentScreen = new SplashScreen();
} // end Initialize


void ScreenManager::LoadContent()
{
	currentScreen->LoadContent();
} // end LoadContent


void ScreenManager::Update(sf::RenderWindow &Window, sf::Event event)
{
	deltaTime = frameClock.restart().asMilliseconds();
	currentScreen->Update(Window, event);
} // end Update


void ScreenManager::Draw(sf::RenderWindow &Window)
{
	currentScreen->Draw(Window);
} // end Draw


void ScreenManager::AddScreen(GameScreen *screen)
{
	currentScreen->UnloadContent();
	delete currentScreen;
	currentScreen = screen;
	currentScreen->LoadContent();
} // end AddScreen