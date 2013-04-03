#pragma once
#include "stdafx.h"

class GameScreen
{
public:
	GameScreen(void);
	~GameScreen(void);

	virtual void LoadContent();
	virtual void UnLoadContent();
	virtual void Update();
	virtual void Draw(sf::RenderWindow &window);
};

