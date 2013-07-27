#include "StdAfx.h"


Animation::Animation(void)
{
}


Animation::~Animation(void)
{
}


void Animation::LoadContent(std::string text, sf::Texture &image, sf::Vector2f position)
{
	this->preText = text;
	this->image = image;
	this->position = position;

	alpha = 1.0f;
	textColor = sf::Color(sf::Color::Green);

	if (image.getSize().y > 0)
	{
		sprite.setTexture(this->image);
	}
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
		text.setColor(sf::Color(255, 255, 255, 255*alpha));
		text.setPosition(position);
		text.setScale(scale, scale);

		Window.draw(text);
	}

	if (sprite.getTexture() != NULL)
	{
		sprite.setColor(sf::Color(255, 255, 255, 255 * alpha));
		sprite.setPosition(position);
		sprite.setScale(scale, scale);

		Window.draw(sprite);
	}
} // end Draw


void Animation::SetAlpha(float value)
{
	alpha = value;
} // end SetAlpha


float &Animation::GetAlpha()
{
	return alpha;
}


bool &Animation::GetActive()
{
	return active;
}


float &Animation::GetScale()
{
	return scale;
}