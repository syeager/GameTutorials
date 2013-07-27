#include "StdAfx.h"



Sprite::Sprite(void)
{
} // end Sprite


Sprite::~Sprite(void)
{
} // end Sprite


void Sprite::Load(std::string filename)
{
	//_texture.loadFromFile(filename);
	//_sprite.setTexture(_texture);
} // end Load


void Sprite::Draw(sf::RenderWindow &window)
{
	window.draw(_sprite);
} // end Draw


void Sprite::Update(float deltaTime)
{
} // end Update


void Sprite::SetPosition(float x, float y)
{
	_sprite.setPosition(x, y);
} // end SetPosition


sf::Vector2f Sprite::GetPosition() const
{
	return _sprite.getPosition();
} // end GetPosition


float Sprite::GetWidth() const
{
	return _sprite.getGlobalBounds().width;
} // end GetWidth


float Sprite::GetHeight() const
{
	return _sprite.getGlobalBounds().height;
} // end GetHeight


sf::Rect<float> Sprite::GetBoundingRect() const
{
	return sf::Rect<float> (
		_sprite.getGlobalBounds().left,
		_sprite.getGlobalBounds().top,
		_sprite.getGlobalBounds().left+_sprite.getGlobalBounds().width,
		_sprite.getGlobalBounds().top+_sprite.getGlobalBounds().height
		);
} // end GetBoundingRect