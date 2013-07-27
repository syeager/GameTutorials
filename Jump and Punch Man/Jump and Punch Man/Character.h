// Steve Yeager
#pragma once
#include "Character.h"


class Character : public VisibleGameObject, public Rigidbody
{
public:
	Character(void);
	~Character(void);

	virtual void Draw(sf::RenderWindow &window);
	//virtual void Update(float deltaTime);

protected:
	int _health;
	enum States { SPAWNING, IDLE, MOVING, HIT, DYING, DEAD };
	States _state;
}; // end Character class