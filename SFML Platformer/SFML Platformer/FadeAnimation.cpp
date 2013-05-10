#include "StdAfx.h"



FadeAnimation::FadeAnimation(void)
{
}


FadeAnimation::~FadeAnimation(void)
{
}


void FadeAnimation::LoadContent(std::string text, sf::Texture image, sf::Vector2f position)
{
	Animation::LoadContent(text, image, position);
	increase = false;
	fadeSpeed = 100.0f;
} // end LoadContent


void FadeAnimation::UnloadContent()
{

} // end UnloadContent


void FadeAnimation::Update(sf::RenderWindow &Window)
{
	if (active)
	{
		if (!increase)
		{
			alpha -= fadeSpeed * ScreenManager::Instance().deltaTime;
		}
		else
		{
			alpha += fadeSpeed * ScreenManager::Instance().deltaTime;
		}

		if (alpha >= 1.0f)
		{
			alpha = 1.0f;
			increase = false;
		}
		else if (alpha <= 0.0f)
		{
			alpha = 0.0f;
			increase = true;
		}
	}
	else
	{
		alpha = 1.0f;
	}
} // End Update


void FadeAnimation::Draw(sf::RenderWindow &Window)
{
	Animation::Draw(Window);
} // end Draw