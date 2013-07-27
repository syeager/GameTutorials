#include "StdAfx.h"



VisibleGameObject::VisibleGameObject(void)
{
	_isLoaded = false;
} // end VisisbleGameObject


VisibleGameObject::~VisibleGameObject(void)
{
} // end ~VisibleGameObject


void VisibleGameObject::Load(std::string filename)
{
	if (_texture.loadFromFile(filename) == false)
	{
		_filename = "";
		_isLoaded = false;
	}
	else
	{
		_filename = filename;
		_sprite.setTexture(_texture);
		_isLoaded = true;
	}
} // end Load


void VisibleGameObject::Draw(sf::RenderWindow &window)
{
	//if (_isLoaded)
	{
		window.draw(_sprite);
	}
} // end Draw


void VisibleGameObject::Update(float deltaTime)
{
} // end Update


void VisibleGameObject::SetPosition(float x, float y)
{
	if (_isLoaded)
	{
		_sprite.setPosition(x, y);
	}
} // end SetPosition


sf::Vector2f VisibleGameObject::GetPosition() const
{
	if (_isLoaded)
	{
		return _sprite.getPosition();
	}
} // end GetPosition


float VisibleGameObject::GetWidth() const
{
	return _sprite.getGlobalBounds().width;
} // end GetWidth


float VisibleGameObject::GetHeight() const
{
	return _sprite.getGlobalBounds().height;
} // end GetHeight


sf::Rect<float> VisibleGameObject::GetBoundingRect() const
{
	return sf::Rect<float> (
							_sprite.getGlobalBounds().left,
							_sprite.getGlobalBounds().top,
							_sprite.getGlobalBounds().left+_sprite.getGlobalBounds().width,
							_sprite.getGlobalBounds().top+_sprite.getGlobalBounds().height
							);
} // end GetBoundingRect


sf::Sprite &VisibleGameObject::GetSprite()
{
	return _sprite;
} // end GetSprite


bool VisibleGameObject::IsLoaded() const
{
	return _isLoaded;
} // end IsLoaded