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
} // end LoadContent


void TitleScreen::UnloadContent()
{

} // end UnloadContent


void TitleScreen::Update()
{

} // end Update


void TitleScreen::Draw(sf::RenderWindow &Window)
{
	Window.draw(text);
} // end Draw