#pragma once
#include "stdafx.h"


class MenuManager
{
public:
	MenuManager(void);
	~MenuManager(void);

	void LoadContent(std::string menuID);
	void UnloadContent();
	void Update(sf::RenderWindow &Window, InputManager input);
	void Draw(sf::RenderWindow &Window);

private:
	std::vector<std::vector<std::string>> attributes;
	std::vector<std::vector<std::string>> contents;
	FileManager file;
	std::vector<std::vector<Animation*>> animation;
	std::vector<Animation*> tempAnimation;
	sf::Texture image;
	sf::Sprite sprite;
	std::vector<sf::Texture> images;
	std::vector<sf::Sprite> menuImages;
	std::vector<std::string> menuItems;
	sf::Vector2f position;
	int axis;
	std::string align;
	std::vector<std::string> animationTypes;

	void SetAnimations();
	void SetPositions();
	void EqualizeMenuItems();
};

