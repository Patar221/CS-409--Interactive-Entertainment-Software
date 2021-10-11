//
//  Entity.cpp
//

#include "Entity.h"

#include <cassert>
#include <cmath>
#include <algorithm>  // for min/max

#include "GetGlut.h"
#include "ObjLibrary/Vector3.h"
#include "ObjLibrary/ObjModel.h"
#include "ObjLibrary/DisplayList.h"

#include "CoordinateSystem.h"

using namespace ObjLibrary;
namespace
{
	const double PI = 3.1415926535897932384626433832795;
	const double TWO_PI = PI * 2.0;
	const double ROTATION_RATE_MAX = 0.25;  // radians / second
	const double GRAVITATIONAL_CONSTANT = 6.67408e-11;
	const double BLACK_HOLE_MASS = 5.0e16;
}  // end of anonymous namespace


Entity::Entity()
	: m_coords(Vector3(0.0, 0.0, 0.0))
	, velocity(Vector3(0.0, 0.0, 0.0))
	, mass(0.0)
{
	//assert(invariant());
}

Entity::Entity(const CoordinateSystem& coord)
{
	m_coords = coord;
}

void Entity::updateVelocity(const Vector3& acceleration, const double deltaTime)
{
	velocity += (acceleration * deltaTime);
}

void Entity::draw() const
{
}

void Entity::update(const double deltaTime)
{
	updateVelocity(computeAcceleration(), deltaTime);

	m_coords.setPosition(m_coords.getPosition() + (velocity * deltaTime));
}

Vector3 Entity::computeAcceleration()
{
	double distanceToOrigin = m_coords.getPosition().getDistance(Vector3(0.0, 0.0, 0.0));
	float magnitude = (GRAVITATIONAL_CONSTANT * BLACK_HOLE_MASS) / (distanceToOrigin * distanceToOrigin);
	Vector3 directionOfGravity = (Vector3(0.0, 0.0, 0.0) - m_coords.getPosition());
	directionOfGravity = directionOfGravity.getNormalizedSafe();
	return magnitude * directionOfGravity;
}

float Entity::computeCircularSpeed()
{
	double distanceToOrigin = m_coords.getPosition().getDistance(Vector3(0.0, 0.0, 0.0));
	return sqrt(GRAVITATIONAL_CONSTANT * BLACK_HOLE_MASS / distanceToOrigin);	//s = sqrt(G * m / d).
}
