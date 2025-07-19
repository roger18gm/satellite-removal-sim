/***********************************************************************
 * Header File:
 *    PROJECTILE
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    The Projectile class for the orbital simulator
 ************************************************************************/

#pragma once
#include "satellite.h"

class TestProjectile;

/***************************************************
 * PROJECTILE
 * A projectile fired from the Dream Chaser to destroy space debris
 * ***************************************************/
class Projectile : public Satellite
{
   friend TestProjectile;

public:
   // Constructors
   Projectile();
   Projectile(const Position& shipPosition, const Angle& shipDirection, const Velocity& shipVelocity);
   ~Projectile() {}

   // Virtual function implementations
   void draw(ogstream* pgout) const override;
   void destroy(std::vector<std::unique_ptr<Satellite>>* satellites) override;
   void move(double time) override;

private:
   static const double PROJECTILE_SPEED;     // 9,000 m/s
   static const double PROJECTILE_RADIUS;    // 0.5 pixels (1 pixel diameter)
   static const int    PROJECTILE_LIFETIME;  // 70 game units
};