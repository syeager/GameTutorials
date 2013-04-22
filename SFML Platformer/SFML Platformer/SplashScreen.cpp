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
} // end LoadContent


void SplashScreen::UnloadContent()
{

} // end UnloadContent


void SplashScreen::Update()
{

} // end Update


void SplashScreen::Draw(sf::RenderWindow &Window)
{
	Window.draw(text);
} // end Draw