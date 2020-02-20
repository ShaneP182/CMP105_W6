#include "AngryBird.h"
#include "Framework/Vector.h"

AngryBird::AngryBird()
{
	scale = 100.f;
	gravity = sf::Vector2f(0.f, 9.8f) * scale;
	pos = getPosition();
	shotPower = 10;
}

AngryBird::~AngryBird()
{

}

void AngryBird::update(float dt)
{
	pos = getVelocity() * dt + 0.5f * gravity * dt * dt;
	velocity += gravity * dt;
	setPosition(getPosition() + pos);

	if (getPosition().y > window->getSize().y - 50)
	{
		setPosition(getPosition().x, window->getSize().y - 50);
		//velocity = sf::Vector2f(velocity.x, 0);
		velocity = sf::Vector2f(velocity.x, -velocity.y) * 0.5f;
	}

	if (getPosition().x > window->getSize().x - 50)
	{
		setPosition(window->getSize().x - 50, getPosition().y);
		velocity = sf::Vector2f(-velocity.x, velocity.y);
	}

	if (getPosition().x < 0)
	{
		setPosition(0, getPosition().y);
		velocity = sf::Vector2f(-velocity.x, velocity.y);
	}

	if (getPosition().y < 0)
	{
		setPosition(getPosition().x, 0);
		velocity = sf::Vector2f(velocity.x, -velocity.y);
	}
}

void AngryBird::handleInput(float dt)
{
	// For calculating difference between mouse click and release
	if (input->isMouseLDown())
	{
		// When mouse is first clicked it will get the initial position, and set mouse clicked variable to true
		if (!mouseClicked)
		{
			initialClick.x = input->getMouseX();
			initialClick.y = input->getMouseY();
			mouseClicked = true;
		}
		if (mouseClicked) // when mouse is being clicked it will repeatedly get the current position until the mouse is no longer clicked - the final position.
		{
			finalClick.x = input->getMouseX();
			finalClick.y = input->getMouseY();
		}
	}

	// Resets mouse clicked variable when the mouse is not being clicked, calculates and displays length of drag
	if (!input->isMouseLDown() && mouseClicked)
	{
		mouseClicked = false;
		direction = Vector::normalise(initialClick - finalClick);
		speed = Vector::magnitude(initialClick - finalClick);
		velocity = direction * speed * shotPower;
		move(velocity * dt);
	}
}
