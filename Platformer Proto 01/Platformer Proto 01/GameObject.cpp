#include "StdAfx.h"



GameObject::GameObject()
{
	_id = Game::GetGameObjectManager().GetNextID();
} // end GameObject


GameObject::GameObject(std::string name, std::string tag)
{
	_name = name;
	_tag = tag;
	_id = Game::GetGameObjectManager().GetNextID();
} // end GameObject


GameObject::~GameObject()
{
} // end ~GameObject


void GameObject::Draw(sf::RenderWindow &window)
{
} // end Draw


void GameObject::Update(float deltaTime)
{
} // end Update