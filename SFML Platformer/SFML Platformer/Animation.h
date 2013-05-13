#pragma once
#include "stdafx.h"

class Animation
{
public:
	Animation(void);
	~Animation(void);

	virtual void LoadContent(std::string text, sf::Texture image, sf::Vector2f position);
	virtual void UnloadContent();
	virtual void Update(sf::RenderWindow &Window);
	virtual void Draw(sf::RenderWindow &Window);
	virtual void SetAlpha(float value);
	float GetAlpha();

	void SetActive(bool value);

protected:
	float alpha;
	std::string preText;
	sf::Text text;
	sf::Texture image;
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Color textColor;
	sf::IntRect sourceRect;
	bool active;
};

