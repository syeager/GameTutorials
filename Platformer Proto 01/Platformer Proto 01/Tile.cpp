#include "StdAfx.h"



Tile::Tile(std::string texture, int x, int y, bool solid)
{
	_texture = &Game::GetResourcesManager().GetTexture(texture);
	_sprite.setTexture(*_texture);
	_sprite.setPosition(x, y);

	//_boundingBox.setSize(sf::Vector2f(32, 32));
	//_sleeping = true;
} // end Tile


Tile::~Tile()
{
} // end ~Tile