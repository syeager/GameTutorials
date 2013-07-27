#pragma once
#include "stdafx.h"


class Ground : public VisibleGameObject, public Rigidbody
{
public:
	Ground(void);
	~Ground(void);
};