//
//  Spaceship.cpp
//

#include "Spaceship.h"

#include <cassert>

#include "GetGlut.h"
#include "ObjLibrary/Vector3.h"
#include "ObjLibrary/ObjModel.h"
#include "ObjLibrary/DisplayList.h"

using namespace ObjLibrary;
namespace
{
	const double ACCELERATION = 10.0;

}  // end of anonymous namespace

Spaceship::Spaceship()
{
	mass = 1000;
	m_coords = CoordinateSystem(Vector3(-1000, 0, 0),  // position
								Vector3(1, 0, 0),  // forward vector
								Vector3(0, 1, 0)); // up vector
}

void Spaceship::setModel(ObjModel m)
{
	model = m;
}

void Spaceship::rotateAroundForward(float radian)
{
	m_coords.rotateAroundForward(radian);
}

void Spaceship::rotateAroundRight(float radian)
{
	m_coords.rotateAroundRight(radian);
}

void Spaceship::rotateAroundUp(float radian)
{
	m_coords.rotateAroundUp(radian);
}

void Spaceship::accelerateForward(int sign, const double deltaTime)
{
	updateVelocity(m_coords.getForward() * (ACCELERATION * sign), deltaTime);
}

void Spaceship::accelerateForwardQuick(int sign, const double deltaTime)
{
	updateVelocity(m_coords.getForward() * (ACCELERATION * 10 * sign), deltaTime);
}

void Spaceship::accelerateRight(int sign, const double deltaTime)
{
	updateVelocity(m_coords.getRight() * (ACCELERATION * sign), deltaTime);
}

void Spaceship::accelerateUp(int sign, const double deltaTime)
{
	updateVelocity(m_coords.getUp() * (ACCELERATION * sign), deltaTime);
}

void Spaceship::draw() const
{
	assert(isInitialized());

	glPushMatrix();
		m_coords.applyDrawTransformations();
		glScaled(4, 4, 4);
		model.draw();
	glPopMatrix();
}

Vector3 Spaceship::updateCameraPosition()
{
	Vector3 newPosition = m_coords.getPosition();

	newPosition += (m_coords.getForward() * -20.0);
	newPosition += (m_coords.getUp() * 5.0);

	return newPosition;
}


CoordinateSystem Spaceship::updateCamera()
{
	return CoordinateSystem(updateCameraPosition(), // position
							m_coords.getForward(),  // forward vector
							m_coords.getUp());	// up vector
}
