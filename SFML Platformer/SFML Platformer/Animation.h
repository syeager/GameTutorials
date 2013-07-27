#pragma once
#include "stdafx.h"

class Animation
{
public:
	Animation(void);
	~Animation(void);

	virtual void LoadContent(std::string text, sf::Texture &image, sf::Vector2f position);
	virtual void UnloadContent();
	virtual void Update(sf::RenderWindow &Window);
	virtual void Draw(sf::RenderWindow &Window);

	virtual void SetAlpha(float value);
	
	float &GetAlpha();
	bool &GetActive();
	float &GetScale();
	
	template<typename T>
	void SetValue(T &variable, T value)
	{
		variable = value;
	}
	

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
	float scale;
};

