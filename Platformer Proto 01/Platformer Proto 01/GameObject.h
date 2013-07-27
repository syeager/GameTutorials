#pragma once


class GameObject
{
public:
	GameObject();
	GameObject(std::string name, std::string tag);
	~GameObject();

	unsigned int GetID() { return _id; }
	std::string GetName() { return _name; }
	std::string GetTag() { return _tag; }

	virtual void Draw(sf::RenderWindow &window);
	virtual void Update(float deltaTime);

protected:
	unsigned int _id;
	std::string _name;
	std::string _tag;
}; // end GameObject class