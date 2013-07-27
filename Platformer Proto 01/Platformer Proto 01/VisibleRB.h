#pragma once
#include "stdafx.h"


class VisibleRB : public Sprite, public Rigidbody
{
public:
	VisibleRB();
	~VisibleRB();

	virtual void Draw(sf::RenderWindow &window);
	virtual void Update(float deltaTime);

	void SetPosition(float x, float y);
	void Move(float x, float y);
}; // end VisibleRB class