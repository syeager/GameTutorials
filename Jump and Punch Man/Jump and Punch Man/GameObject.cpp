#include "StdAfx.h"


GameObject::GameObject(std::string name)
{
	_name = name;
} // end GameObject

GameObject::GameObject()
{
	_name = "";
} // end GameObject


GameObject::~GameObject(void)
{

} // end ~GameObject