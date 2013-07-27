#include "StdAfx.h"



Character::Character(void)
{
}


Character::~Character(void)
{
}


void Character::Draw(sf::RenderWindow &window)
{
	VisibleGameObject::Draw(window);
	Rigidbody::Draw(window);
} // end Draw