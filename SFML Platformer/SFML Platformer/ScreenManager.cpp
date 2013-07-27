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
	transition = false;

	file.LoadContent("data.txt", attributes, contents);
} // end Initialize


void ScreenManager::LoadContent()
{
	currentScreen->LoadContent();
	fade.LoadContent("", sf::Texture(), sf::Vector2f());
	fade.SetAlpha(0.0f);
} // end LoadContent


void ScreenManager::UnloadContent()
{

} // end UnloadContent


void ScreenManager::Update(sf::RenderWindow &Window, sf::Event event)
{
	deltaTime = frameClock.restart().asMilliseconds();
	if (!transition)
	{
		currentScreen->Update(Window, event);
	}
	Transition(Window);
} // end Update


void ScreenManager::Draw(sf::RenderWindow &Window)
{
	currentScreen->Draw(Window);
} // end Draw


void ScreenManager::AddScreen(GameScreen *screen)
{
	transition = true;
	newScreen = screen;
	fade.SetValue(fade.GetActive(), true);
	fade.SetAlpha(0.0f);
} // end AddScreen


void ScreenManager::Transition(sf::RenderWindow &Window)
{
	if (transition)
	{
		fade.Update(Window);
		if (fade.GetAlpha() >= 1.0f)
		{
			currentScreen->UnloadContent();
			delete currentScreen;
			currentScreen = newScreen;
			currentScreen->LoadContent();
			newScreen = NULL;
		}
		else if (fade.GetAlpha() <= 0.0f)
		{
			transition = false;
			fade.SetValue(fade.GetActive(), false);
		}
	}
} // end Transition


float ScreenManager::GetAlpha()
{
	return fade.GetAlpha();
} // end GetAlpha