// Video: 20
#include "stdafx.h"


int main()
{
	// set up
	sf::RenderWindow Window(sf::VideoMode(ScreenWidth, ScreenHeight, 32), "Platformer");
	Window.setKeyRepeatEnabled(false);

	ScreenManager::Instance().Initialize();
	ScreenManager::Instance().LoadContent();

	sf::RectangleShape Fade(sf::Vector2f(ScreenWidth, ScreenHeight));
	Fade.setFillColor(sf::Color::White);


	// main loop
	while (Window.isOpen())
	{
		sf::Event Event;
		while (Window.pollEvent(Event))
		{
			switch (Event.type)
			{
			// close
			case sf::Event::Closed:
				Window.close();
				break;
			}

			// update
			ScreenManager::Instance().Update(Window, Event);
		}

		// draw
		Window.clear();		
		ScreenManager::Instance().Draw(Window);
		Fade.setFillColor(sf::Color(0, 0, 0, 255*ScreenManager::Instance().GetAlpha()));
		Window.draw(Fade);
		Window.display();
	}

	return 0;
} // end main

