#include "stdafx.h"
#include "GameBall.h"
#include "Game.h"


GameBall::GameBall() :
	_velocity(230.0f),
	_elapsedTimeSinceStart(0.0f)
{
	Load("images/ball.png");
	assert(IsLoaded());

	GetSprite().SetCenter(15, 15);

	sf::Randomizer::SetSeed(std::clock());
	_angle = (float)sf::Randomizer::Random(0, 360);
}


GameBall::~GameBall()
{
}


void GameBall::Update(float elapsedTime)
{
	_elapsedTimeSinceStart += elapsedTime;

	if(_elapsedTimeSinceStart < 3.0f)
		return;

	float moveAmount = _velocity*elapsedTime;


	float moveByX = LinearVelocityX(_angle) * moveAmount;
	float moveByY = LinearVelocityY(_angle) * moveAmount;


	// ugly
	if(GetPosition().x + moveByX <= 0+GetWidth()/2 ||
		GetPosition().x + GetHeight()/2 + moveByX >= Game::SCREEN_WIDTH)
	{
		_angle = 360.0f - _angle;
		if(_angle > 260.0f && _angle < 280.0f) _angle += 20.0f;
		if(_angle > 80.0f && _angle < 100.0f) _angle += 20.0f;
		moveByX *= -1; // changed
	}



	PlayerPaddle* player1 = dynamic_cast<PlayerPaddle*>(Game::GetGameObjectManager().Get("Paddle1"));
	if(player1 != NULL)
	{
		sf::Rect<float> p1BB = player1->GetBoundingRect();

		if(p1BB.Intersects(GetBoundingRect())
		{
			_angle = 360.0f - (_angle - 180.0f);
			if(_angle > 360.0f) _angle -= 360.0f;


			moveByY *= -1;
		}
	}
}