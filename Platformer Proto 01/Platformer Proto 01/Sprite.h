#pragma once
#include "stdafx.h"


class Sprite :	public GameObject
{
public:
	Sprite(void);
	~Sprite(void);

	virtual void Load(std::string filename);
	virtual void Draw(sf::RenderWindow &window);
	virtual void Update(float deltaTime);

	virtual void SetPosition(float x, float y);
	virtual sf::Vector2f GetPosition() const;
	float GetWidth() const;
	float GetHeight() const;
	sf::Rect<float> GetBoundingRect() const; 

protected:
	sf::Sprite _sprite;
	sf::Texture *_texture;
}; // end Sprite class