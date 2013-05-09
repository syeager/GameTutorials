// Video: 7
#include "stdafx.h"


int main()
{
	// set up
	sf::RenderWindow Window(sf::VideoMode(ScreenWidth, ScreenHeight, 32), "Platformer");

	ScreenManager::Instance().Initialize();
	ScreenManager::Instance().LoadContent();

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

			case sf::Event::KeyPressed:
				if (Event.key.code == sf::Keyboard::S)
					ScreenManager::Instance().AddScreen(new SplashScreen);
				if (Event.key.code == sf::Keyboard::T)
					ScreenManager::Instance().AddScreen(new TitleScreen);
				break;
			}
		}

		Window.clear();

		// update
		ScreenManager::Instance().Update();
		ScreenManager::Instance().Draw(Window);

		// draw
		Window.display();
	}


	return 0;
}

