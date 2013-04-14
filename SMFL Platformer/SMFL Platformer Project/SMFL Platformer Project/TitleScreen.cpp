#include "StdAfx.h"



TitleScreen::TitleScreen(void)
{
}


TitleScreen::~TitleScreen(void)
{
}

void TitleScreen::LoadContent()
{
	if(!font.loadFromFile("slkscr.ttf")) std::cout<<"Couldn't find font\n";

	text.setString("TitleScreen");
	text.setFont(font);

	keys.push_back(sf::Keyboard::Key::Return);
	keys.push_back(sf::Keyboard::Key::Z);
}

void TitleScreen::UnloadContent()
{
	GameScreen::UnloadContent();
}

void TitleScreen::Update(sf::Event event)
{
	input.Update(event);

	if(input.KeyPressed(keys))
	{
		ScreenManager::GetInstance().AddScreen(new SplashScreen);
	}
}

void TitleScreen::Draw(sf::RenderWindow &Window)
{
	Window.draw(text);
}