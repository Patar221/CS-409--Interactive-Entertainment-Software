#pragma once

#include "Entity.h"

#include "ObjLibrary/Vector3.h"
#include "ObjLibrary/ObjModel.h"
#include "ObjLibrary/DisplayList.h"

#include "CoordinateSystem.h"


class Spaceship : public Entity
{
public:

//
//  Default Constructor
//
//  Purpose: To create an Enitity without initializing it.
//  Parameter(s): N/A
//  Preconditions: N/A
//  Returns: N/A
//  Side Effect: A new Spaceship is created.  It is not
//               initialized.
//
	Spaceship();

	void setModel(ObjLibrary::ObjModel m);

//
//  rotateAroundForward
//
//  Purpose: To rotate ship around forward vector
//  Parameter(s): N/A
//  Preconditions:
//    <1> isInitialized()
//  Returns: N/A
//  Side Effect: Rotates Camera and Ship
	void rotateAroundForward(float radian);

//
//  rotateAroundRight
//
//  Purpose: To rotate ship around right vector
//  Parameter(s): N/A
//  Preconditions:
//    <1> isInitialized()
//  Returns: N/A
//  Side Effect: Rotates Camera and Ship
	void rotateAroundRight(float radian);

//
//  rotateAroundUp
//
//  Purpose: To rotate ship around up vector
//  Parameter(s): N/A
//  Preconditions:
//    <1> isInitialized()
//  Returns: N/A
//  Side Effect: Rotates Camera and Ship
	void rotateAroundUp(float radian);

//
//  accelerateForward
//
//  Purpose: To accelerate the ship forward
//  Parameter(s): N/A
//  Preconditions:
//    <1> isInitialized()
//  Returns: N/A
//  Side Effect: Increase velocity in forward direction
	void accelerateForward(int sign, const double deltaTime);

//
//  accelerateForward
//
//  Purpose: To accelerate the ship forward quickly
//  Parameter(s): N/A
//  Preconditions:
//    <1> isInitialized()
//  Returns: N/A
//  Side Effect: Increase velocity in forward direction quickly
	void accelerateForwardQuick(int sign, const double deltaTime);


//
//  accelerateRight
//
//  Purpose: To accelerate the ship right
//  Parameter(s): N/A
//  Preconditions:
//    <1> isInitialized()
//  Returns: N/A
//  Side Effect: Increase velocity in right direction
	void accelerateRight(int sign, const double deltaTime);

//
//  accelerateUp
//
//  Purpose: To accelerate the ship up
//  Parameter(s): N/A
//  Preconditions:
//    <1> isInitialized()
//  Returns: N/A
//  Side Effect: Increase velocity in up direction
	void accelerateUp(int sign, const double deltaTime);

//
//  draw
//
//  Purpose: To display this Asteroid.
//  Parameter(s): N/A
//  Preconditions:
//    <1> isInitialized()
//  Returns: N/A
//  Side Effect: This Asteroid is displayed at its current
//               position with its current rotation.
//
	void draw() const;

//
//  updateCameraPosition
//
//  Purpose: Updates the cameras position relative to ship
//  Parameter(s): N/A
//  Preconditions:
//    <1> isInitialized()
//  Returns: N/A
//  Side Effect: Returns new camera postion
	ObjLibrary::Vector3 updateCameraPosition();

//
//  updateCameraForward
//
//  Purpose: Updates the cameras position relative to ship
//  Parameter(s): N/A
//  Preconditions:
//    <1> isInitialized()
//  Returns: N/A
//  Side Effect: Returns new forward vector for camera
	CoordinateSystem updateCamera();

private:
	ObjLibrary::ObjModel model;
};