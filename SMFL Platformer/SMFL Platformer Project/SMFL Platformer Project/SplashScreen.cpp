#include "StdAfx.h"



SplashScreen::SplashScreen(void)
{
}


SplashScreen::~SplashScreen(void)
{
}

void SplashScreen::LoadContent()
{
	if(!font.loadFromFile("slkscr.ttf")) std::cout<<"Couldn't find font\n";

	text.setString("SplashScreen");
	text.setFont(font);

	keys.push_back(sf::Keyboard::Return);
	keys.push_back(sf::Keyboard::Z);
}

void SplashScreen::UnloadContent()
{
	GameScreen::UnloadContent();
}

void SplashScreen::Update(sf::Event event)
{
	input.Update(event);

	if(input.currentEvent.type == sf::Event::KeyPressed) std::cout<<"Key pressed.\n";
	if(input.KeyPressed(keys))
	{
		ScreenManager::GetInstance().AddScreen(new TitleScreen);
	}
}

void SplashScreen::Draw(sf::RenderWindow &Window)
{
	Window.draw(text);
}