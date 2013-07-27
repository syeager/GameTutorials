#pragma once
#include "stdafx.h"
#include "Rigidbody.h"


class VisibleGameObject : public GameObject
{
public:
	VisibleGameObject(void);
	virtual ~VisibleGameObject(void);

	virtual void Load(std::string filename);
	virtual void Draw(sf::RenderWindow &window);
	virtual void Update(float deltaTime);

	virtual void SetPosition(float x, float y);
	virtual sf::Vector2f GetPosition() const;
	virtual float GetWidth() const;
	virtual float GetHeight() const;

	virtual bool IsLoaded() const;
	virtual sf::Rect<float> GetBoundingRect() const;

protected:
	sf::Sprite &GetSprite();

private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	std::string _filename;
	bool _isLoaded;
};

