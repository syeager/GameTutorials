#pragma once
#include "stdafx.h"


class Rigidbody
{
public:
	Rigidbody();
	~Rigidbody();

	virtual void Update(float deltaTime);
	virtual void Draw(sf::RenderWindow &window);

	virtual void Collision(CollisionInfo info);
	virtual void Move(float x, float y);
	virtual void SetPosition(float x, float y);

protected:
	sf::RectangleShape _boundingBox;
	bool _sleeping;

	void DetectCollisions();

private:
	std::vector<sf::Vector2i> _gridSpaces;

	void UpdateGrid();
}; // end Rigidbody