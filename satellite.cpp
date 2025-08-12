/***********************************************************************
 * Source File:
 *    SATELLITE
 * Author:
 *    Roger Galan & Jessen Forbush
 * Summary:
 *    base class for every moving and destroyable object
 ************************************************************************/

#pragma once
#include "satellite.h"
#include "acceleration.h"

/******************************************
 * SATELLITE : CONSTRUCTOR WITH SATELLITE AND ANGLE
 * Initialize satellite by copying from another with new direction
 *****************************************/
Satellite::Satellite(Satellite& s, Angle a)
{
   position = s.position;
   velocity = s.velocity;
   direction = s.direction;
   angularVelocity = s.angularVelocity;
   dead = false;        
   radius = 0.0; // feel like this will be specific to each satellite/part
   age = 0;

   double randSpeed = random(1000.0, 3000.0);

#ifndef NDEBUG // testing purposes
   randSpeed = 1000.0;
#endif
   Velocity kickVel;
   kickVel.set(a, randSpeed);
   velocity.addV(kickVel);

   Position kickPos;
   kickPos.setPixelsX(30.0 * sin(a.getRadians())); // adjust the 20 = pixel pos
   kickPos.setPixelsY(30.0 * cos(a.getRadians()));
   position.addMetersX(kickPos.getMetersX());
   position.addMetersY(kickPos.getMetersY());
}

/******************************************
 * SATELLITE : CONSTRUCTOR WITH SATELLITE, ANGLE, AND RADIUS
 * Initialize satellite by copying from another with specified radius
 *****************************************/
Satellite::Satellite(Satellite& s, Angle a, double radius) : Satellite(s, a)
{
   this->radius = radius;
}


/******************************************
 * SATELLITE : MOVE
 * Move satellite according to physics and angular velocity
 *****************************************/
void Satellite::move(double time)
{
   // Calculate gravity effects
   double height = computeHeightAboveEarth(position);
   double aGravity = getGravity(height);
   Angle gravityAngle;
   gravityAngle.setRadians(directionOfGravityPull(position));

   // Create acceleration due to gravity
   Acceleration accel;
   accel.set(gravityAngle, aGravity);

   double diff = 2;
   for (int i = 0; i < diff; i++)
   {
      // Update velocity with acceleration
      velocity.add(accel, time / diff);

      // Update position with velocity and acceleration
      position.add(accel, velocity, time / diff);

      // Update rotation
      direction.rotate(angularVelocity / diff);
      //direction.rotate(angularVelocity * (time / diff));
   }

   age++;
}

/******************************************
 * FRAGMENT : DRAW
 * Draw a fragment on the screen
 *****************************************/
void Fragment::draw(ogstream* pgout)  const
{
   pgout->drawFragment(position, direction.getRadians());
}

/******************************************
 * FRAGMENT : DESTROY
 * Handle fragment destruction
 *****************************************/
void Fragment::destroy(std::vector<std::unique_ptr<Satellite>>* satellites) { }

/******************************************
 * FRAGMENT : MOVE
 * Move fragment and handle expiration
 *****************************************/
void Fragment::move(double time)
{
   Satellite::move(time);
   if (this->age > 100)
      this->dead = true;
}
