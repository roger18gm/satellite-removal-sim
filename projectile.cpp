/***********************************************************************
 * Source File:
 *    PROJECTILE
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    Implementation of the Projectile class
 ************************************************************************/

#include "projectile.h"
#include "position.h"
#include "velocity.h"
#include "angle.h"
#include "uiDraw.h"

 // Static member definitions
const double Projectile::PROJECTILE_SPEED = 9000.0;  // 9,000 m/s
const double Projectile::PROJECTILE_RADIUS = 0.5;    // 1 pixel diameter
const int Projectile::PROJECTILE_LIFETIME = 70;      // 70 game units

/***************************************************
 * PROJECTILE : DEFAULT CONSTRUCTOR
 * Create a projectile at the origin (for testing purposes)
 ***************************************************/
Projectile::Projectile() : Satellite()
{
   radius = PROJECTILE_RADIUS;
   angularVelocity = 0.0;  // Projectiles don't rotate
   age = 0;
   dead = false;
}

/***************************************************
 * PROJECTILE : CONSTRUCTOR WITH SHIP DATA
 * Create a projectile fired from the Dream Chaser
 * INPUT: shipPosition - current position of the ship
 *        shipDirection - direction the ship is facing
 *        shipVelocity - current velocity of the ship
 ***************************************************/
Projectile::Projectile(const Position& shipPosition, const Angle& shipDirection, const Velocity& shipVelocity)
   : Satellite()
{
   radius = PROJECTILE_RADIUS;
   angularVelocity = 0.0;  // Projectiles don't rotate
   age = 0;
   dead = false;

   // Set projectile direction to match ship direction
   direction = shipDirection;

   // Calculate starting position 19 pixels in front of the ship
   // Using the formula: ptShipFront = rotate(ptShipCenter, 0.0, 19.0, radians)
   Position offset;
   offset.setPixelsX(19.0 * sin(shipDirection.getRadians()));
   offset.setPixelsY(19.0 * cos(shipDirection.getRadians()));

   position = shipPosition;
   position.addMetersX(offset.getMetersX());
   position.addMetersY(offset.getMetersY());

   // Set velocity: ship velocity + 9,000 m/s in ship direction
   velocity = shipVelocity;
   Velocity projectileVelocity;
   projectileVelocity.set(shipDirection, PROJECTILE_SPEED);
   velocity.addV(projectileVelocity);
}

/***************************************************
 * PROJECTILE : MOVE
 * Move the projectile according to physics and check for expiration
 * INPUT: time - time step for movement calculations
 ***************************************************/
void Projectile::move(double time)
{
   // Call base class move for physics (gravity affects projectiles)
   Satellite::move(time);

   // Check if projectile has expired (after 70 game units)
   if (age >= PROJECTILE_LIFETIME)
   {
      kill();
   }
}

/***************************************************
 * PROJECTILE : DRAW
 * Draw the projectile on the screen
 * INPUT: pgout - graphics output stream
 ***************************************************/
void Projectile::draw(ogstream* pgout) const
{
   if (pgout != nullptr && !isDead())
   {
      pgout->drawProjectile(position);
   }
}

/***************************************************
 * PROJECTILE : DESTROY
 * Handle projectile destruction (projectiles don't create fragments)
 * INPUT: satellites - vector of all satellites in the simulation
 ***************************************************/
void Projectile::destroy(std::vector<std::unique_ptr<Satellite>>* satellites)
{
   // Projectiles simply disappear when destroyed - no fragments created
   kill();
}