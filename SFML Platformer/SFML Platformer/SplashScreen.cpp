#include "StdAfx.h"


SplashScreen::SplashScreen(void)
{
}


SplashScreen::~SplashScreen(void)
{
}


void SplashScreen::LoadContent()
{
	font.loadFromFile("resources/fonts/AdobeHeitiStd-Regular.otf");
	text.setString("Splash Screen");
	text.setFont(font);
	keys.push_back(sf::Keyboard::Return);
	imageNumber = 0;
	
	file.LoadContent("data.txt", attributes, contents);

	for (int i = 0; i < attributes.size(); i++)
	{		
		for (int j = 0; j < attributes[i].size(); j++)
		{
			std::string att = attributes[i][j];
			if (att == "Image")
			{
				image.loadFromFile(contents[i][j]);
				fade.push_back(new FadeAnimation);
				fade[fade.size()-1]->LoadContent("", image, sf::Vector2f(0.0f, 0.0f));
				fade[fade.size()-1]->SetValue(fade[fade.size()-1]->GetActive(), true);
				fade[fade.size()-1]->SetValue(fade[fade.size()-1]->GetScale(), 1.0f);
			}
		}
	}
} // end LoadContent


void SplashScreen::UnloadContent()
{
	GameScreen::UnloadContent();

	for (int i = 0; 9 < fade.size(); i++)
	{
		fade[i]->UnloadContent();
		delete fade[i];
	}
	fade.clear();
} // end UnloadContent


void SplashScreen::Update(sf::RenderWindow &Window, sf::Event event)
{
	input.Update(event);

	if (fade[imageNumber]->GetAlpha() <= 0.0f)
	{
		imageNumber++;
	}

	fade[imageNumber]->Update(Window);

	if (input.KeyPressed(keys) || imageNumber >= (fade.size()-1))
	{
		ScreenManager::Instance().AddScreen(new TitleScreen);
	}
} // end Update


void SplashScreen::Draw(sf::RenderWindow &Window)
{
	//Window.draw(text);
	fade[imageNumber]->Draw(Window);
} // end Draw