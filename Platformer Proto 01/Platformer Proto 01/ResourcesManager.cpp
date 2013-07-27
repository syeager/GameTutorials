#include "StdAfx.h"



ResourcesManager::ResourcesManager()
{
} // end ResourcesManager


ResourcesManager::~ResourcesManager()
{
} // end ~ResourcesManager


sf::Texture &ResourcesManager::GetTexture(std::string texture)
{
	std::map<std::string, sf::Texture>::iterator itr = _texturePool.find(texture);
	if (itr == _texturePool.end())
	{
		sf::Texture newTexture;
		if (!newTexture.loadFromFile(texture)) std::cout<<"Can't find texture: "<<texture<<std::endl;
		_texturePool.insert(std::pair<std::string, sf::Texture>(texture, newTexture));

		itr = _texturePool.find(texture);

		return itr->second;
	}
	else
	{
		return itr->second;
	}
} // end GetTexture