#include "Missile.h"
#include "Framework/Vector.h"

Missile::Missile()
{
	speed = 100.f;
	
}

Missile::~Missile()
{

}

void Missile::update(float dt)
{
	target = sf::Vector2f(window->getSize().x - 50, window->getSize().y - 50);
	direction = Vector::normalise(target - getPosition());
	velocity = direction * speed;
	setPosition(getPosition() + (velocity * dt));

	if (Vector::magnitude(target - getPosition()) < 10.f) 
	{ 
		setPosition(target); 
	}
}

void Missile::handleInput(float dt)
{

}