#pragma once
#include "stdafx.h"

class FadeAnimation :
	public Animation
{
public:
	FadeAnimation(void);
	~FadeAnimation(void);

	virtual void LoadContent(std::string text, sf::Texture &image, sf::Vector2f position);
	virtual void UnloadContent();
	virtual void Update(sf::RenderWindow &Window);
	void Draw(sf::RenderWindow &Window);

	void SetAlpha(float value);

private:
	bool increase;
	float fadeSpeed;
};

