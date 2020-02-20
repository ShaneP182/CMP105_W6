#pragma once
#include "Framework/GameObject.h"

class AngryBird :
	public GameObject
{
public:
	AngryBird();
	~AngryBird();

	void update(float dt) override;
	void handleInput(float dt) override;
	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; };

protected:

	sf::RenderWindow* window;
	float scale;
	sf::Vector2f gravity;
	sf::Vector2f pos;
	float speed;
	float shotPower;

	sf::Vector2f direction;

	sf::Vector2f initialClick;
	sf::Vector2f finalClick;
	bool mouseClicked;
};

