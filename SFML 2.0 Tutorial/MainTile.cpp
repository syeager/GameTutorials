// Video: 37
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::vector<sf::Vector2i>> map;
std::vector<std::vector<int>> colMap;
sf::Texture tileTexture;
sf::Sprite tiles;

class Player
{
public:
	sf::RectangleShape rect;
	float bottom, left, right, top;

	Player(sf::Vector2f position, sf::Vector2f size, sf::Color color)
	{
		rect.setPosition(position);
		rect.setSize(size);
		rect.setFillColor(color);
	}

	void Update()
	{
		bottom = rect.getPosition().y + rect.getSize().y;
		left = rect.getPosition().x;
		right = rect.getPosition().x + rect.getSize().x;
		top = rect.getPosition().y;
	}


};

void LoadMap(const char *filename)
{
	std::ifstream openfile(filename);
	std::vector<sf::Vector2i> tempMap;
	map.clear();

	if (openfile.is_open())
	{
		std::string tileLocation;
		openfile >> tileLocation;
		tileTexture.loadFromFile(tileLocation);
		tiles.setTexture(tileTexture);

		while (!openfile.eof())
		{
			std::string str, value;
			std::getline(openfile, str);
			std::stringstream stream(str);

			while (std::getline(stream, value, ' '))
			{
				if (value.length() > 0)
				{

				}
			}
		}
	}
}

void LoadColMap(const char *filename)
{
	std::ifstream openfile(filename);
	std::vector<int> tempMap;
	colMap.clear();

	if (openfile.is_open())
	{
		while (!openfile.eof())
		{
			std::string str, value;
			std::getline(openfile, str);
			std::stringstream stream(str);

			while (std::getline(stream, value, ' '))
			{
				if (value.length() > 0)
				{
					int a = atoi(value.c_str());
					tempMap.push_back(a);
				}
			}

			colMap.push_back(tempMap);
			tempMap.clear();
		}
	}
}



int main()
{
	sf::RenderWindow Window(sf::VideoMode(640, 480), "Box Collisions");


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
			}
		}

		

		Window.clear(sf::Color::Cyan);
		Window.display();
	}

	return 0;
} // end main