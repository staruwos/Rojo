#include "physics.h"

PhysBody::PhysBody()
{

}

PhysBody::~PhysBody()
{

}

void PhysBody::Acelerate()
{
	if (sgn(speed.x) == 1)
	{
		if(speed.x + aceleration.x < max_speed.x)
			speed.x += aceleration.x;
	}

	else if (sgn(speed.x) == -1)
	{
		if(speed.x - aceleration.x < (-1 * (max_speed.x)))
			speed.x -= aceleration.x;
	}

	if (sgn(speed.y) == 1)
	{
		if(speed.y + aceleration.y < max_speed.y)
			speed.y += aceleration.y;
	}

	else if (sgn(speed.y) == -1)
	{
		if(speed.y - aceleration.y < (-1*max_speed.y))
			speed.y -= aceleration.y;
	}
}

Vector2D PhysBody::Move(Vector2D position, Vector2D dir)
{
	if(sgn(dir.x) == 1 && sgn(speed.x) == -1)
	{
		speed.x *= -1;
	}

	if(sgn(dir.y) == 1 && sgn(speed.y) == -1)
	{
		speed.y *= -1;
	}

	Acelerate();
	return position + speed;
}

