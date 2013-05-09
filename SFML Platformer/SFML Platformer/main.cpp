// Video: 9
#include "stdafx.h"


int main()
{
	// set up
	sf::RenderWindow Window(sf::VideoMode(ScreenWidth, ScreenHeight, 32), "Platformer");
	Window.setKeyRepeatEnabled(false);

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
			}

			ScreenManager::Instance().Update(Window, Event);
		}

		Window.clear();

		// update
		
		ScreenManager::Instance().Draw(Window);

		// draw
		Window.display();
	}


	return 0;
}

