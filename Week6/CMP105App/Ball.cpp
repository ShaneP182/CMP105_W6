#include "Ball.h"

Ball::Ball()
{
	scale = 100.f;
	gravity = sf::Vector2f(0.f, 9.8f) * scale;
	pos = getPosition();
	jumpSpeed = sf::Vector2f(0.f, -10.f) * scale;
	horizontalSpeed = sf::Vector2f(2.f, 0) * scale;
	jumping = true;
}

Ball::~Ball()
{

}

void Ball::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		if (!jumping)
		{
			velocity = jumpSpeed;
			jumping = true;
		}
	}
	if (input->isKeyDown(sf::Keyboard::D))
	{
		//velocity += horizontalSpeed * dt;
		move(horizontalSpeed.x * dt, 0);
	}
	else if (input->isKeyDown(sf::Keyboard::A))
	{
		//velocity += -horizontalSpeed * dt;
		move(-horizontalSpeed.x * dt, 0);
	}


	if (input->isMouseLDown())
	{
		setPosition(input->getMouseX() - 50, input->getMouseY() - 50);
		velocity = sf::Vector2f(0, 0);
	}
}

void Ball::update(float dt)
{
	pos = getVelocity() * dt + 0.5f * gravity * dt * dt;
	velocity += gravity * dt;
	setPosition(getPosition() + pos);

	if (getPosition().y > window->getSize().y - 100)
	{
		setPosition(getPosition().x, window->getSize().y - 100);
		//velocity = sf::Vector2f(velocity.x, 0);
		velocity = sf::Vector2f(velocity.x, -velocity.y) * 0.8f;
		jumping = false;
	}
}