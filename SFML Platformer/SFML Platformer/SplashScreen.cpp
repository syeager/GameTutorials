#include "StdAfx.h"


SplashScreen::SplashScreen(void)
{
}


SplashScreen::~SplashScreen(void)
{
}


void SplashScreen::LoadContent()
{
	font.loadFromFile("resources/fonts/AdobeHeitiStd-Regular.otf");
	text.setString("Splash Screen");
	text.setFont(font);
	keys.push_back(sf::Keyboard::Return);
} // end LoadContent


void SplashScreen::UnloadContent()
{
	GameScreen::UnloadContent();
} // end UnloadContent


void SplashScreen::Update(sf::RenderWindow &Window, sf::Event event)
{
	input.Update(event);

	if (input.KeyPressed(keys))
	{
		ScreenManager::Instance().AddScreen(new TitleScreen);
	}
} // end Update


void SplashScreen::Draw(sf::RenderWindow &Window)
{
	Window.draw(text);
} // end Draw