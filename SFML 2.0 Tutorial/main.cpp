// Video: 7
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

int main()
{
	sf::RenderWindow Window(sf::VideoMode(800, 600, 32), "SFML Sample Application");

	std::string message = "Hello my name is Steve";
	std::string display = "";
	int index = 0;

	Window.setKeyRepeatEnabled(false);

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
			// key
			case sf::Event::KeyPressed:
				if (Event.key.code == sf::Keyboard::Return && Event.key.control)
				{
					display += message[index];
					index++;
					system("cls");
					std::cout<<display;
				}
				break;
			// mouse
			case sf::Event::MouseEntered:
				std::cout<<"Entered\n";
				break;
			case sf::Event::MouseLeft:
				std::cout<<"Left\n";
				break;
			case sf::Event::MouseMoved:
				std::cout<<"X: "<<Event.mouseMove.x<<" Y: "<<Event.mouseMove.y<<std::endl;
				break;
			case sf::Event::MouseButtonPressed:
				if (Event.mouseButton.button == sf::Mouse::Right)
				{
					std::cout<<"Right pressed\n";
				}
				break;
			default:
				break;
			}


			Window.clear(sf::Color(0, 255, 255));
			Window.display();
		}
	}

	return 0;
} // end main