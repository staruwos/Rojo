#ifndef PHYSICS_H
#define PHYSICS_H

#include "math.h"

class PhysBody {

	PhysBody();
	~PhysBody();

protected:
	Vector2D max_speed;
	Vector2D speed;
	Vector2D aceleration;

public:

	Vector2D Move(Vector2D position, Vector2D dir);

	void Acelerate();

};

#endif