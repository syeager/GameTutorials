#include "StdAfx.h"



VisibleRB::VisibleRB()
{
} // end VisibleRB


VisibleRB::~VisibleRB()
{
} // end ~VisibleRB


void VisibleRB::Draw(sf::RenderWindow &window)
{
	Sprite::Draw(window);
} // end Draw


void VisibleRB::Update(float deltaTime)
{
	Sprite::Update(deltaTime);
	Rigidbody::Update(deltaTime);
} // end Update


void VisibleRB::SetPosition(float x, float y)
{
	_sprite.setPosition(x, y);
	_boundingBox.setPosition(x, y);
} // end SetPosition


void VisibleRB::Move(float x, float y)
{
	_sprite.move(x, y);
	_boundingBox.move(x, y);
} // end Move