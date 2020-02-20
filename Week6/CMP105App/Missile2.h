#pragma once
#include "Missile.h"
class Missile2 : 
	public Missile
{
public:
	Missile2();
	void update(float dt) override;
protected:
	float acceleration;
};

