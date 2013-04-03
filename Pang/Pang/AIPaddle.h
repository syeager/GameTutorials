#pragma once
#include "VisibleGameObject.h"

class AIPaddle : public VisibleGameObject
{
public:
	AIPaddle(void);
	~AIPaddle(void);

	void Update(float elapsedTime);
	void Draw(sf::RenderWindow& rw);

	float GetVelocity() const;

	private:
		float _velocity;
		float _maxVelocity;
};