#pragma once
#include "StdAfx.h"


class ResourcesManager
{
public:
	ResourcesManager();
	~ResourcesManager();

	sf::Texture &GetTexture(std::string texture);

private:
	std::map<std::string, sf::Texture> _texturePool;
}; // end ResourcesManager