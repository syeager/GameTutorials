#include "StdAfx.h"
#include "VisibleRB.h"



VisibleRB::VisibleRB(void)
{
	boundingBox.setOutlineColor(sf::Color::Green);
	boundingBox.setFillColor(sf::Color(100, 0, 0, 30));
	boundingBox.setOutlineThickness(1);
} // end VisibleRB


VisibleRB::~VisibleRB(void)
{
} // end ~VisibleRB


void VisibleRB::UpdateGrid(float x, float y)
{
	boundingBox.move(x, y);
	//Rigidbody::UpdateGrid();

	GetSprite().move(x, y);
} // end Move


void VisibleRB::SetPosition(float x, float y)
{
	boundingBox.setPosition(x, y);
	//Rigidbody::UpdateGrid();

	GetSprite().setPosition(x, y);
} // end SetPosition


void VisibleRB::Draw(sf::RenderWindow &window)
{
	VisibleGameObject::Draw(window);
	window.draw(boundingBox);
} // end Draw