 // Steve Yeager


#include "stdafx.h"
#include <Box2D/Box2D.h>
#include <cstdio>
using namespace std;

#define SCALE 30.0f

void CreateGround(b2World &World, float X, float Y)
{
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(X/30.0f, Y/30.0f);
	BodyDef.type = b2_staticBody;
	b2Body *Body = World.CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox((800.0f/2)/SCALE, (16.0f/2)/SCALE);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 0.0f;
	FixtureDef.shape = &Shape;
	Body->CreateFixture(&FixtureDef);
}


void CreateBox(b2World &World, int MouseX, int MouseY)
{
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(MouseX/SCALE, MouseY/SCALE);
	BodyDef.type = b2_dynamicBody;
	b2Body* Body = World.CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox((32.f/2)/SCALE, (32.f/2)/SCALE);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.f;
	FixtureDef.friction = 0.7f;
	FixtureDef.shape = &Shape;
	Body->CreateFixture(&FixtureDef);
}




int mainBox()
{
	sf::RenderWindow Window(sf::VideoMode(800, 600, 32), "Test");
	Window.setFramerateLimit(60);

	/** Prepare the world */
	b2Vec2 Gravity(0.f, 9.8f);
	b2World World(Gravity);
	CreateGround(World, 400.0f, 500.0f);

	sf::Texture GroundTexture;
	sf::Texture BoxTexture;
	GroundTexture.loadFromFile("resources/test/ground.png");
	BoxTexture.loadFromFile("resources/test/box.png");

	while (Window.isOpen())
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			CreateBox(World, sf::Mouse::getPosition(Window).x, sf::Mouse::getPosition(Window).y);
			cout<<"box\n";
		}

		World.Step(1/60.0f, 8, 3);

		Window.clear(sf::Color::White);
		for (b2Body *BodyIterator = World.GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
		{
			if (BodyIterator->GetType() == b2_dynamicBody)
			{
				cout<<"drawing\n";
				sf::Sprite Sprite;
				Sprite.setTexture(BoxTexture);
				Sprite.setOrigin(16, 16);
				Sprite.setPosition(SCALE * BodyIterator->GetPosition().x, SCALE * BodyIterator->GetPosition().y);
				Sprite.setRotation(BodyIterator->GetAngle() * 180/b2_pi);
				Window.draw(Sprite);
			}
			else
			{
				sf::Sprite GroundSprite;
				GroundSprite.setTexture(GroundTexture);
				GroundSprite.setOrigin(400, 8);
				GroundSprite.setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);
				GroundSprite.setRotation(180/b2_pi * BodyIterator->GetAngle());
				Window.draw(GroundSprite);
			}
		}
		Window.display();
	}



	system("pause");
	return 0;
}