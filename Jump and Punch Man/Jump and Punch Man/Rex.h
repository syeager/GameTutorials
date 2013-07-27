#pragma once
#include "stdafx.h"


class Rex : public Character
{
public:
	Rex(void);
	~Rex(void);

	void Update(float deltaTime);
	void Draw(sf::RenderWindow &window);

	void SetPosition(float x, float y);

private:
	float _jumpStrength;

	void Jump();
	bool IsGrounded();
};

