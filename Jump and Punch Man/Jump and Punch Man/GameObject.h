#pragma once
#include "stdafx.h"


class GameObject
{
public:
	GameObject(std::string name);
	GameObject();
	~GameObject(void);

	std::string GetName() { return _name; }
	void SetName(std::string name) { _name = name; }
	std::string GetTag() { return _tag; }
	void SetTag(std::string tag) { _tag = tag; }
protected:
	std::string _name;
	std::string _tag;
}; // end GameObject class