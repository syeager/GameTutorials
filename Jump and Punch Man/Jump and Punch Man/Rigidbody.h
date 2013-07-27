#pragma once
#include "stdafx.h"
#include "CollisionInfo.h"


class Rigidbody
{
public:
	Rigidbody(void);
	~Rigidbody(void);
	
	const sf::RectangleShape &GetBB() {return boundingBox;}
	float GetHVelocity() const;
	void SetHVelocity(float amount);
	bool IsSleeping() { return _sleeping; }

	virtual void Collision(CollisionInfo info);

	virtual void Update(float deltaTime);
	virtual void Draw(sf::RenderWindow &window);

	virtual void Move(float x, float y);


protected:
	sf::RectangleShape boundingBox;
	float _gravity;
	sf::Vector2f _velocity;
	sf::Vector2f _maxVelocity;
	bool _sleeping;
	CollisionInfo CheckCollision(Rigidbody *other);

	// Check for collisions against all rigidbodies in the squares currently being occupied. Only run if not sleeping.
	void DetectCollisions();



	std::vector<sf::Vector2i> _gridSpaces;
	void UpdateGrid();
}; // end Rigidbody class