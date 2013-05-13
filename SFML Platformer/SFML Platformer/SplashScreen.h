#pragma once
#include "stdafx.h"

class SplashScreen : public GameScreen
{
public:
	SplashScreen(void);
	~SplashScreen(void);

	void LoadContent();
	void UnloadContent();
	void Update(sf::RenderWindow &Window, sf::Event event);
	void Draw(sf::RenderWindow &Window);

private:
	sf::Text text;
	sf::Font font;
	sf::Texture image;
	std::vector<FadeAnimation*> fade;
	int imageNumber;
};

