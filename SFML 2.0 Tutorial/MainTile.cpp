// Video: 37
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>


int main()
{
	sf::RenderWindow Window(sf::VideoMode(640, 480), "Box Collisions");

	if (!sf::SoundBufferRecorder::isAvailable()) std::cout<<"No mic\n";

	sf::SoundBufferRecorder recorder;
	sf::SoundBuffer buffer;
	sf::Sound sound;

	while (Window.isOpen())
	{
		sf::Event Event;
		while (Window.pollEvent(Event))
		{
			switch (Event.type)
			{
			case sf::Event::Closed:
				Window.close();
				break;

			case sf::Event::KeyPressed:
				if (Event.key.code == sf::Keyboard::R)
				{
					recorder.start();
					std::cout<<"Recording\n";
				}
				else if(Event.key.code == sf::Keyboard::S)
				{
					recorder.stop();
					buffer = recorder.getBuffer();
					sound.setBuffer(buffer);
					sound.play();
					std::cout<<"Saved\n";
				}
				break;
			}
		}

		

		Window.clear(sf::Color::Cyan);
		Window.display();
	}

	return 0;
} // end main