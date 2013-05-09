#include "StdAfx.h"


TitleScreen::TitleScreen(void)
{
}


TitleScreen::~TitleScreen(void)
{
}


void TitleScreen::LoadContent()
{
	font.loadFromFile("resources/fonts/AdobeHeitiStd-Regular.otf");
	text.setString("Title Screen");
	text.setFont(font);
	keys.push_back(sf::Keyboard::Return);
} // end LoadContent


void TitleScreen::UnloadContent()
{
	GameScreen::UnloadContent();
} // end UnloadContent


void TitleScreen::Update(sf::RenderWindow &Window, sf::Event event)
{
	input.Update(event);

	if (input.KeyPressed(keys))
	{
		ScreenManager::Instance().AddScreen(new SplashScreen);
	}
} // end Update


void TitleScreen::Draw(sf::RenderWindow &Window)
{
	Window.draw(text);
} // end Draw