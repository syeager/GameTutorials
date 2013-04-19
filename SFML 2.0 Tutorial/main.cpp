// Video: 22
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

int main()
{
	sf::Vector2i screenDimensions(800, 600);

	sf::RenderWindow Window(sf::VideoMode(screenDimensions.x, screenDimensions.y, 32), "SFML Sample Application");
	sf::Clock clock;

	sf::Texture bTexture;
	sf::Sprite bImage;

	if (!bTexture.loadFromFile("resources/images/Background.jpg")) std::cout<<"Can't load image.\n";
	bImage.setTexture(bTexture);
	bImage.setScale(1.0f, (float)screenDimensions.y/bTexture.getSize().y);

	sf::RectangleShape rect(sf::Vector2f(20, 20));
	rect.setFillColor(sf::Color::Red);
	sf::RectangleShape rect2(sf::Vector2f(20, 20));
	rect2.setFillColor(sf::Color::Blue);

	float moveSpeed = 100000;

	sf::View view1, view2;
	view1.setViewport(sf::FloatRect(0, 0, 0.5f, 1.0f));
	view1.setSize(screenDimensions.x/2, screenDimensions.y);
	view2.setViewport(sf::FloatRect(0.5f, 0, 0.5f, 1.0f));
	view2.setSize(screenDimensions.x/2, screenDimensions.y);

	sf::Vector2f position(screenDimensions.x/2, screenDimensions.y/2);
	sf::Vector2f position2(position);

	sf::SoundBuffer soundBuffer;
	sf::Sound sound;

	sf::Music music;
	if (!music.openFromFile("resources/audio/jump.wav")) std::cout<<"Can't load music.\n";
	music.play();
	music.setLoop(true);

	if (!soundBuffer.loadFromFile("resources/audio/jump.wav")) std::cout<<"Can't load audio.\n";
	sound.setBuffer(soundBuffer);

	while (Window.isOpen())
	{
		clock.restart();
		sf::Event Event;
		while (Window.pollEvent(Event))
		{
			switch (Event.type)
			{
			// close
			case sf::Event::Closed:
				Window.close();
				break;

			// keyboard
			case sf::Event::KeyPressed:
				if (Event.key.code == sf::Keyboard::Escape)
					Window.close();
				else if (Event.key.code == sf::Keyboard::P)
				{
					sound.play();
				}
				break;

			default:
				break;
			}

			// input
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				rect.move(moveSpeed * clock.getElapsedTime().asSeconds(), 0);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				rect.move(-moveSpeed * clock.getElapsedTime().asSeconds(), 0);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				rect2.move(moveSpeed * clock.getElapsedTime().asSeconds(), 0);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				rect2.move(-moveSpeed * clock.getElapsedTime().asSeconds(), 0);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			{
				view1.zoom(1.001f);
				view2.zoom(0.999f);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
			{
				view1.rotate(0.1f);
				view2.rotate(-0.1f);
			}


			if (rect.getPosition().x+10 >= view1.getSize().x/2)
				position.x = rect.getPosition().x+10;
			else
				position.x = view1.getSize().x/2;

			if (rect2.getPosition().x+10 >= view2.getSize().x/2)
				position2.x = rect2.getPosition().x+10;
			else
				position2.x = view2.getSize().x/2;

			view1.setCenter(position);
			view2.setCenter(position2);

			// draw
			Window.clear();

			Window.setView(view1);
			Window.draw(bImage);
			Window.draw(rect);
			Window.draw(rect2);

			Window.setView(view2);
			Window.draw(bImage);
			Window.draw(rect2);
			Window.draw(rect);

			Window.display();
		}
	}

	return 0;
} // end main