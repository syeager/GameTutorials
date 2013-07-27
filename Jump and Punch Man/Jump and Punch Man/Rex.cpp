#include "StdAfx.h"



Rex::Rex(void)
{
	_maxVelocity = sf::Vector2f(10, 20);
	_gravity = 1.0f;

	Load("resources/sprites/Rex/mario.png");
	assert(IsLoaded());

	GetSprite().setScale(0.1f, 0.1f);
	GetSprite().setOrigin(GetSprite().getLocalBounds().width/2, GetSprite().getLocalBounds().height/2);
} // end Rex


Rex::~Rex(void)
{
} // end ~Rex


void Rex::Draw(sf::RenderWindow &window)
{
	Character::Draw(window);
} // end Draw


void Rex::Update(float deltaTime)
{
	// check for collisions
	DetectCollisions();


	_velocity.x = 0;
	_velocity.y = 0;

	// move
	if (_name == "Rex")
	{
		if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -1.0f || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			SetHVelocity(-_maxVelocity.x);
		}
		else if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 1.0f || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			SetHVelocity(_maxVelocity.x);
		}

		if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -1.0f || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			_velocity.y = -_maxVelocity.y;
		}
		else if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 1.0f || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			_velocity.y = _maxVelocity.y;
		}
	}
	else
	{
		if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -1.0f || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			SetHVelocity(-_maxVelocity.x);
		}
		else if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 1.0f || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			SetHVelocity(_maxVelocity.x);
		}

		if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -1.0f || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			_velocity.y = -_maxVelocity.y;
		}
		else if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 1.0f || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			_velocity.y = _maxVelocity.y;
		}
	}

	
	// jump
	if (sf::Joystick::isButtonPressed(0, 0) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		std::cout<<"Pressed\n";
	}

	if (!IsGrounded())
	{
		//_velocity.y += _gravity*deltaTime;
	}

	Move(_velocity.x*deltaTime, _velocity.y*deltaTime);
	GetSprite().move(_velocity.x*deltaTime, _velocity.y*deltaTime);

	//VisibleRB::Update(deltaTime);
} // end Update


void Rex::Jump()
{

} // end Jump


bool Rex::IsGrounded()
{
	return false;
} // end IsGrounded


void Rex::SetPosition(float x, float y)
{
	boundingBox.setPosition(x, y);
	GetSprite().setPosition(x, y);
} // end SetPosition