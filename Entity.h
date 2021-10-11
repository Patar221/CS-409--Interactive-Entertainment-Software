#pragma once

#include "ObjLibrary/Vector3.h"
#include "ObjLibrary/ObjModel.h"
#include "ObjLibrary/DisplayList.h"

#include "CoordinateSystem.h"

class Entity {
public:
//
//  Default Constructor
//
//  Purpose: To create an Enitity without initializing it.
//  Parameter(s): N/A
//  Preconditions: N/A
//  Returns: N/A
//  Side Effect: A new Enitity is created.  It is not
//               initialized.
//
	Entity();

//
//  Constructor
//
//  Purpose: To create an Enitity
//  Parameter(s): N/A
//  Preconditions: N/A
//  Returns: N/A
//  Side Effect: A new Enitity is created.
//
	Entity(const CoordinateSystem& coord);

//
//  getPosition
//
//  Purpose: To determine the original position of this Entity.
//  Parameter(s): N/A
//  Preconditions:
//    <1> isInitialized()
//  Returns: The position of this Enitity's origin.
//  Side Effect: N/A
//
	const ObjLibrary::Vector3& getPosition() const
	{
		return m_coords.getPosition();
	}

//
//  getCoords
//
//  Purpose: To determine the original coords of this Entity.
//  Parameter(s): N/A
//  Preconditions:
//    <1> isInitialized()
//  Returns: The position of this Enitity's origin.
//  Side Effect: N/A
//
	const CoordinateSystem& getCoords() const
	{
		return m_coords;
	}

//
//  updateVelocity
//
//  Purpose: To update the velocity based on acceleration
//  Parameter(s): N/A
//  Preconditions:
//    <1> isInitialized()
//  Returns: N/A
//  Side Effect: N/A
//
	void updateVelocity(const ObjLibrary::Vector3& acceleration, const double deltaTime);

//
//  isInitialized
//
//  Purpose: To determine whether this Enitity has been
//           intialized.
//  Parameter(s): N/A
//  Preconditions: N/A
//  Returns: Whether this Enitity has been initialized.
//  Side Effect: N/A
//
	bool isInitialized() const
	{
		//return m_display_list.isReady();
		return true;
	}

//
//  draw
//
//  Purpose: To display this Enitity.
//  Parameter(s): N/A
//  Preconditions:
//    <1> isInitialized()
//  Returns: N/A
//  Side Effect: This Enitity is displayed at its current
//               position with its current rotation.
//
	virtual void draw() const;

//
//  update
//
//  Purpose: To update this Enitity for one time step.
//  Parameter(s): N/A
//  Preconditions:
//    <1> isInitialized()
//  Returns: N/A
//  Side Effect: This Enitity is updated for one time step.
//                This includes rotation.
//
	virtual void update(const double deltaTime);


//
//  computeAcceleration
//
//  Purpose: To compute the acceleration due to gravity
//  Parameter(s): N/A
//  Preconditions:
//    <1> isInitialized()
//  Returns: N/A
//  Side Effect: N/A
//

	ObjLibrary::Vector3 computeAcceleration();

//
//  computeCircularSpeed
//
//  Purpose: To compute the circular orbit of a radius around an object of a known mass (s = sqrt(G * m / d).)
//  Parameter(s): N/A
//  Preconditions:
//    <1> isInitialized()
//  Returns: N/A
//  Side Effect: N/A
//

	float computeCircularSpeed();

protected:
	CoordinateSystem m_coords;
	ObjLibrary::Vector3 velocity;
	float mass;
};