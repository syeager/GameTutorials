#pragma once
class GameScreen
{
public:
	GameScreen(void);
	~GameScreen(void);

	virtual void LoadContent();
	virtual void UnloadContent();
	virtual void Update();
	virtual void Draw(sf::RenderWindow &Window);
};

