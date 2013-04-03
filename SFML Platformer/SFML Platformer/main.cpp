// video: 
#include "stdafx.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

//using namespace std;

int main()
{
	sf::RenderWindow Window(sf::VideoMode(ScreenWidth, ScreenHeight, 32), "SFML Platformer");

	while(Window.IsOpened())
	{
		sf::Event curEvent;
		if(Window.GetEvent(curEvent))
		{
			if(curEvent.Type == sf::Event::Closed || curEvent.Key.Code == sf::Key::Escape)
				Window.Close();
		}

		Window.Display();
	}

	return 0;
}