/***********************************************************************
 * Source File:
 *    DREAMCHASER
 * Author:
 *    Roger Galan & Jessen Forbush
 * Summary:
 *    The DreamChaser (user-controlled ship) class
 ************************************************************************/

#include "dreamchaser.h"
#include "acceleration.h"
#include "projectile.h"
#include "uiDraw.h"

 /***************************************************
  * DREAMCHASER
  * Default constructor for DreamChaser
  * Initially, the spaceplane is in the upper left corner
  * of the screen (-450px, 450px) moving down slowly
  * (0.0 m/s, -2,000 m/s). It has a radius of 10 pixels.
  ***************************************************/
Dreamchaser::Dreamchaser() : thrusting(false)
{
   radius = 10.0;
   angularVelocity = 0.0;                     // Ship doesn't auto-rotate

   // Convert screen coordinates to meters
   // Use individual setPixelsX and setPixelsY methods
   position.setPixelsX(-450.0);              // Upper left corner X
   position.setPixelsY(450.0);               // Upper left corner Y
   velocity.setDxDy(0.0, -2000.0);           // Moving down slowly
   direction.setDown();                 // Pointing down initially
}

/***************************************************
 * INPUT
 * Handle user input for ship controls
 * Left/Right arrows: rotate ship ±0.1 radians
 * Down arrow: thrust with 2.0 m/s² acceleration
 * Space bar: fire projectile
 ***************************************************/
void Dreamchaser::input(const Interface* pUI)
{
   // Reset thrusting flag
   thrusting = false;

   // Handle rotation - Left arrow rotates left (counterclockwise)
   if (pUI->isLeft())
   {
      rotate(-0.1);  // Rotate left by 0.1 radians
   }

   // Handle rotation - Right arrow rotates right (clockwise)
   if (pUI->isRight())
   {
      rotate(0.1);   // Rotate right by 0.1 radians
   }

   // Handle thrust - Down arrow accelerates ship
   if (pUI->isDown())
   {
      thrust(2.0, TIME);  // 2.0 m/s² acceleration for TIME seconds
      thrusting = true;    // Set flag for visual effect
   }

   // Handle projectile firing - Space bar
   // Will be implemented in future labs when Projectile class is available
   // Space bar detection is ready for future implementation
}

/***************************************************
 * THRUST
 * Apply thrust acceleration in the direction the ship is pointed
 * INPUT: acceleration in m/s², time in seconds
 ***************************************************/
void Dreamchaser::thrust(double acceleration, double time)
{
   // Create acceleration in the direction the ship is pointing
   Acceleration accel;
   accel.set(direction, acceleration);

   // Add this acceleration to the ship's velocity
   velocity.add(accel, time);
}

/***************************************************
 * ROTATE
 * Rotate the ship by the specified angle
 * INPUT: radians to rotate (positive = clockwise)
 ***************************************************/
void Dreamchaser::rotate(double radians)
{
   direction.rotate(radians);
}

/***************************************************
 * FIRE PROJECTILE
 * Launch a projectile from the front of the ship
 * Will be implemented in future labs when Projectile class is available
 ***************************************************/
void Dreamchaser::fireProjectile(std::vector<std::unique_ptr<Satellite>>* satellites)
{
   if (satellites != nullptr && !isDead())
   {
      // Create a new projectile with the ship's current state
      auto projectile = std::make_unique<Projectile>(position, direction, velocity);

      // Add the projectile to the satellite vector
      satellites->push_back(std::move(projectile));
   }
}

/***************************************************
 * MOVE
 * Move the DreamChaser according to physics
 * Override base class to handle user-controlled movement
 ***************************************************/
void Dreamchaser::move(double time)
{
   // Call base class move for gravity and physics
   Satellite::move(time);

   // Additional ship-specific movement logic
}

/***************************************************
 * DESTROY
 * When the DreamChaser is destroyed
 * Will be implemented in future labs when Fragment class is available
 ***************************************************/
void Dreamchaser::destroy(std::vector<std::unique_ptr<Satellite>>* satellites)
{
   //kill();
   for (int i = 0; i < 4; i++) {
      satellites->push_back(std::make_unique<Fragment>(*this, Angle(60.0 * i)));
   }
}

/***************************************************
 * DRAW
 * Draw the DreamChaser ship
 * Uses drawShip() function with thrust indicator
 ***************************************************/
void Dreamchaser::draw(ogstream* pgout) const
{
   if (pgout != nullptr)
   {
      pgout->drawShip(position, direction.getRadians(), thrusting);
   }
}