#pragma once
#include "stdafx.h"

struct CollisionInfo
{
	enum Sides { NONE, LEFT, UP, RIGHT, DOWN };
	Sides side;
	Rigidbody other;

	CollisionInfo(Sides side, Rigidbody &other)
	{
		this->side = side;
		this->other = other;
	}
}; // end CollisionInfo struct