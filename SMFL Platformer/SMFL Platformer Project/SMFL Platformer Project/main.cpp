// video: 7

#include "stdafx.h"


int main()
{
	bool quickQuit = false;
	
	sf::VideoMode VMode(ScreenWidth, ScreenHeight, 32);
	sf::RenderWindow Window(VMode, "Platformer");

	ScreenManager::GetInstance().Initialize();
	ScreenManager::GetInstance().LoadContent();

	while(Window.isOpen())
	{
		sf::Event curEvent;
		while(Window.pollEvent(curEvent))
		{
			switch(curEvent.type)
			{
			case sf::Event::Closed:
				quickQuit = true;
				Window.close();
				break;
			case sf::Event::KeyReleased:
				// close
				if(curEvent.key.code == sf::Keyboard::Escape)
				{
					Window.close();
				}
				break;
			default:
				break;
			}
		}

		Window.clear();

		ScreenManager::GetInstance().Update(curEvent);
		ScreenManager::GetInstance().Draw(Window);

		Window.display();
	}

	if(!quickQuit) std::cin.get();
	return 0;
}