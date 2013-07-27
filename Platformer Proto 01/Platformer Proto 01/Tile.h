#pragma once
#include "StdAfx.h"


class Tile : public Sprite
{
public:
	Tile(std::string texture, int x, int y, bool solid);
	~Tile();

	bool IsSolid() { return _solid; }

private:
	bool _solid;
}; // end Tile class