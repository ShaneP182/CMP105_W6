#pragma once
#include "Framework/GameObject.h"
class Ball : 
	public GameObject
{
public:
	Ball();
	~Ball();

	void update(float dt) override;
	void handleInput(float dt) override;
	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; };

protected:

	sf::RenderWindow* window;
	float scale;
	sf::Vector2f gravity;
	sf::Vector2f pos;
	sf::Vector2f jumpSpeed;
	sf::Vector2f horizontalSpeed;
	bool jumping;

};

