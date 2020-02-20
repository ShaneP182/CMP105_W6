#include "Missile2.h"
#include "Framework/Vector.h"

Missile2::Missile2()
{
	speed = 100.f;
	acceleration = 50.f;
}

void Missile2::update(float dt)
{
	target = sf::Vector2f(input->getMouseX(), input->getMouseY());
	direction = Vector::normalise(target - getPosition());
	velocity = direction * speed;
	speed = speed + acceleration * dt;
	setPosition(getPosition() + (velocity * dt));

	if (Vector::magnitude(target - getPosition()) < 10.f)
	{
		speed = 100.f;
	}
}
