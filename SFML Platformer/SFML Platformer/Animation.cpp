#include "StdAfx.h"


Animation::Animation(void)
{
}


Animation::~Animation(void)
{
}


void Animation::LoadContent(std::string text, sf::Texture image, sf::Vector2f position)
{
	this->preText = text;
	this->image = image;
	this->position = position;

	alpha = 1.0f;
	textColor = sf::Color(sf::Color::Green);
	sprite.setTexture(image);
	this->text.setString(text);

	active = false;
} // end LoadContent


void Animation::UnloadContent()
{

} // end UnloadContent


void Animation::Update(sf::RenderWindow &Window)
{

} // end Update


void Animation::Draw(sf::RenderWindow &Window)
{
	std::string str = text.getString();
	if (str != "")
	{
		Window.draw(text);
	}

	if (sprite.getTexture() != NULL)
	{
		Window.draw(sprite);
	}
} // end Draw