#pragma once
#include "stdafx.h"


class VisibleRB : public VisibleGameObject, public Rigidbody
{
public:
	VisibleRB(void);
	~VisibleRB(void);

	void UpdateGrid(float x, float y);
	void SetPosition(float x, float y);
	virtual void Draw(sf::RenderWindow &window);
}; // end VisibleRB class