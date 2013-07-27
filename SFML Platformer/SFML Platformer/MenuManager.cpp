#include "StdAfx.h"


MenuManager::MenuManager(void)
{
}


MenuManager::~MenuManager(void)
{
}


void MenuManager::SetAnimations()
{
	for (int i = 0; i < menuItems.size(); i++)
	{
		for (int j = 0; j < animationTypes.size(); j++)
		{
			if (animationTypes[j] == "Fade")
			{
				tempAnimation.push_back(new FadeAnimation);
				tempAnimation[tempAnimation.size()-1]->LoadContent(menuItems[i], menuImages[i].getTexture(), position);
			}
		}
	}
}


void MenuManager::SetPositions()
{

}


void MenuManager::EqualizeMenuItems()
{
	for (int i = 0; i < menuItems.size(); i++)
	{
		if (menuImages.size() == i)
		{
			menuImages.push_back(sprite);
		}
	}

	for (int i = 0; i < menuImages.size(); i++)
	{
		if (menuItems.size() == i)
		{
			menuItems.push_back("");
		}
	}
}


void MenuManager::LoadContent(std::string menuID)
{
	file.LoadContent("menu.txt", attributes, contents, menuID);

	for (int i = 0; i < attributes.size(); i++)
	{
		for (int j = 0; j < attributes[i].size(); j++)
		{
			std::string att = attributes[i][j];
			std::string con = contents[i][j];

			if (att == "Item")
			{
				menuItems.push_back(con);
			}
			else if (att == "Image")
			{
				image.loadFromFile(con);
				images.push_back(image);
				sprite.setTexture(image);
				menuImages.push_back(sprite);
			}
			else if (att == "Position")
			{
				std::string pos[2];
				pos[0] = con.substr(0, con.find(','));
				pos[1] = con.substr(con.find(','+1));
				
				position.x = atof(pos[0].c_str());
				position.y = atof(pos[1].c_str());

				std::cout << position.x << " " << position.y << std::endl;
			}
			else if (att == "Align")
			{
				align = con;
			}
			else if (att == "Axis")
			{
				axis = atoi(con.c_str());
			}
			else if (att == "Animation")
			{
				animationTypes.push_back(con);
			}
		}
	}

	EqualizeMenuItems();
	SetAnimations();
	SetPositions();
} // end LoadContent
