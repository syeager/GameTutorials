// Video: 17
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

int main()
{
	sf::Vector2i screenDimensions(800, 600);
	sf::Vector2i blockDimensions(10, 10);

	sf::RenderWindow Window(sf::VideoMode(screenDimensions.x, screenDimensions.y, 32), "SFML Sample Application");
	sf::Clock clock;

	Window.setKeyRepeatEnabled(false);
	srand(time(0));

	float frameCounter = 0, switchFrame = 100, frameSpeed = 500;
	bool updateFrame = true;

	sf::Texture pTexture;
	sf::Sprite player;
	if (!pTexture.loadFromFile("resources/images/Player_SS.png")) std::cout<<"error\n";
	player.setTexture(pTexture);
	float speed = 2;
	

	enum Directions {Down, Left, Right, Up};
	sf::Vector2i source(1, Down);

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

			default:
				break;
			}
		}



		Window.clear();

		for (int i = 0; i < screenDimensions.x/blockDimensions.x; i++)
		{
			for (int j = 0; j < screenDimensions.y/blockDimensions.y; j++)
			{
				sf::VertexArray vArray(sf::PrimitiveType::LinesStrip, 4);
				vArray[0].position = sf::Vector2f(i*blockDimensions.x, j*blockDimensions.y);
				vArray[1].position = sf::Vector2f(i*blockDimensions.x+ blockDimensions.x, j*blockDimensions.y);
				vArray[2].position = sf::Vector2f(i*blockDimensions.x + blockDimensions.x, j*blockDimensions.y + blockDimensions.y);
				vArray[3].position = sf::Vector2f(i*blockDimensions.x, j*blockDimensions.y+blockDimensions.y);

				for(int k = 0; k < 4; k++)
				{
					int red = rand() % 255;
					int blue = rand() % 255;
					int green = rand() % 255;

					vArray[k].color = sf::Color(red, green, blue);
				}

				Window.draw(vArray);
			}
		}

			sf::Vector2f moveSpeed(sf::Joystick::getAxisPosition(1, sf::Joystick::X), sf::Joystick::getAxisPosition(1, sf::Joystick::Y));

			if (moveSpeed.x > 10)
			{
				source.y = Right;
			}
			else if (moveSpeed.x < -10)
			{
				source.y = Left;
			}
			else if (moveSpeed.y < -10)
			{
				source.y = Up;
			}
			else if (moveSpeed.y > 10)
			{
				source.y = Down;
			}
			player.move(moveSpeed.x * clock.getElapsedTime().asSeconds(), moveSpeed.y * clock.getElapsedTime().asSeconds());



			// frame management		
			frameCounter = (updateFrame) ? frameCounter + frameSpeed * clock.restart().asSeconds() : 0;

			if (frameCounter >= switchFrame) 
			{
				frameCounter = 0;
			
				source.x++;
				if (source.x*32 >= pTexture.getSize().x) source.x = 1;
			}

			
			
			player.setTextureRect(sf::IntRect(source.x*32, source.y*32, 32, 32));

			Window.draw(player);
			Window.display();
		
	}

	return 0;
} // end main