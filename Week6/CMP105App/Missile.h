#pragma once
#include "Framework/GameObject.h"
class Missile : 
	public GameObject
{
public:
	Missile();
	~Missile();

	void update(float dt) override;
	void handleInput(float dt) override;
	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; };

protected:

	sf::RenderWindow* window;
	float speed;
	sf::Vector2f target;
	sf::Vector2f direction;
};

