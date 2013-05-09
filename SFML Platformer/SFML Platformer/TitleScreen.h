#pragma once
#include "stdafx.h"
class TitleScreen : public GameScreen
{
public:
	TitleScreen(void);
	~TitleScreen(void);

	void LoadContent();
	void UnloadContent();
	void Update(sf::RenderWindow &Window, sf::Event event);
	void Draw(sf::RenderWindow &Window);

private:
	sf::Text text;
	sf::Font font;
};

