/***********************************************************************
 * Source File:
 *    TEST PROJECTILE
 * Author:
 *    Jessen Forbush and Roger Galan
 * Summary:
 *    The unit tests for Projectile
 ************************************************************************/
#define _USE_MATH_DEFINES
#include "projectile.h"
#include "testProjectile.h"
#include <math.h>

 /*************************************
  * DEFAULT CONSTRUCTOR
  * input: nothing
  * output: position(200.0, 200.0), velocity(0.0, 0.0), dead(false), angularVelocity(0.0), radius(0.5), age(0)
  **************************************/
void TestProjectile::defaultConstructor()
{
   // SETUP

   // EXERCISE
   Projectile p;

   // VERIFY
   assertEquals(p.position.x, 200.0);
   assertEquals(p.position.y, 200.0);
   assertEquals(p.velocity.dx, 0.0);
   assertEquals(p.velocity.dy, 0.0);
   assertEquals(p.dead, false);
   assertEquals(p.angularVelocity, 0.0);
   assertEquals(p.radius, 0.5);
   assertEquals(p.age, 0);
   assertEquals(p.direction.radians, 0.0);

   // TEARDOWN
}

/*************************************
 * CONSTRUCTOR WITH SHIP DATA
 * input: ship at (100px, 200px), pointing right (?/2), velocity (1000, 500)
 * output: projectile 19px in front of ship with ship velocity + 9000 m/s in ship direction
 **************************************/
void TestProjectile::constructorWithShipData()
{
   // SETUP
   Position shipPos;
   shipPos.setPixelsX(100.0);
   shipPos.setPixelsY(200.0);

   Angle shipDir;
   shipDir.setRadians(M_PI_2); // 90 degrees (pointing right)

   Velocity shipVel;
   shipVel.setDxDy(1000.0, 500.0);

   // EXERCISE
   Projectile p(shipPos, shipDir, shipVel);

   // VERIFY
   assertEquals(p.radius, 0.5);
   assertEquals(p.dead, false);
   assertEquals(p.age, 0);
   assertEquals(p.angularVelocity, 0.0);
   assertEquals(p.direction.radians, M_PI_2);

   // Position should be 19 pixels to the right of ship (since ship points right)
   double expectedX = shipPos.getMetersX() + (19.0 * 40.0); // 19 pixels * 40 meters/pixel
   assertEquals(p.position.x, expectedX);
   assertEquals(p.position.y, shipPos.getMetersY());

   // Velocity should be ship velocity + 9000 m/s in ship direction (right)
   assertEquals(p.velocity.dx, 1000.0 + 9000.0);
   assertEquals(p.velocity.dy, 500.0);

   // TEARDOWN
}

/*************************************
 * MOVE - NORMAL OPERATION
 * input: projectile at age 30 with velocity
 * output: position changes, age increments, still alive
 **************************************/
void TestProjectile::move_normal()
{
   // SETUP
   Projectile p;
   p.position.x = 1000.0;
   p.position.y = 2000.0;
   p.velocity.dx = 100.0;
   p.velocity.dy = 200.0;
   p.age = 30;

   double initialX = p.position.x;
   double initialY = p.position.y;

   // EXERCISE
   p.move(48.0); // Standard time step

   // VERIFY
   // Position should have changed due to velocity and gravity
   assertEquals(p.position.x != initialX, true);
   assertEquals(p.position.y != initialY, true);

   // Age should have incremented
   assertEquals(p.age, 31);

   // Should not be dead yet
   assertEquals(p.dead, false);

   // TEARDOWN
}

/*************************************
 * MOVE - EXPIRATION
 * input: projectile at age 69 (one frame before expiration)
 * output: age becomes 70, projectile dies
 **************************************/
void TestProjectile::move_expiration()
{
   // SETUP
   Projectile p;
   p.age = 69; // One frame before expiration

   // EXERCISE
   p.move(48.0);

   // VERIFY
   assertEquals(p.age, 70);
   assertEquals(p.dead, true);

   // TEARDOWN
}

/*************************************
 * MOVE - ALREADY EXPIRED
 * input: projectile at age 75 (already expired and dead)
 * output: age increments, remains dead
 **************************************/
void TestProjectile::move_alreadyExpired()
{
   // SETUP
   Projectile p;
   p.age = 75; // Already past expiration
   p.dead = true; // Already dead

   // EXERCISE
   p.move(48.0);

   // VERIFY
   assertEquals(p.age, 76);
   assertEquals(p.dead, true);

   // TEARDOWN
}

/*************************************
 * DESTROY
 * input: alive projectile, satellite vector
 * output: projectile is dead, no new satellites created
 **************************************/
void TestProjectile::destroy()
{
   // SETUP
   Projectile p;
   std::vector<std::unique_ptr<Satellite>> satellites;
   size_t initialSize = satellites.size();

   // EXERCISE
   p.destroy(&satellites);

   // VERIFY
   assertEquals(p.dead, true);
   assertEquals(satellites.size() == initialSize, true); // No fragments created

   // TEARDOWN
}

/*************************************
 * FIRING FROM SHIP AT ANGLE
 * input: ship at origin pointing up (0 radians), zero velocity
 * output: projectile 19 pixels up from ship with 9000 m/s upward velocity
 **************************************/
void TestProjectile::firingFromShipAtAngle()
{
   // SETUP
   Position shipPos;
   shipPos.setPixelsX(0.0);
   shipPos.setPixelsY(0.0);

   Angle shipDir;
   shipDir.setRadians(0.0); // Pointing up

   Velocity shipVel;
   shipVel.setDxDy(0.0, 0.0);

   // EXERCISE
   Projectile p(shipPos, shipDir, shipVel);

   // VERIFY
   // Position should be 19 pixels up from ship
   assertEquals(p.position.x, 0.0);
   assertEquals(p.position.y, 19.0 * 40.0); // 19 pixels * 40 m/pixel

   // Velocity should be 9000 m/s upward
   assertEquals(p.velocity.dx, 0.0);
   assertEquals(p.velocity.dy, 9000.0);
   assertEquals(p.direction.radians, 0.0);

   // TEARDOWN
}

/*************************************
 * MULTIPLE PROJECTILES
 * input: two ships at different positions and directions
 * output: two independent projectiles with different properties
 **************************************/
void TestProjectile::multipleProjectiles()
{
   // SETUP
   Position shipPos1, shipPos2;
   shipPos1.setPixelsX(100.0);
   shipPos1.setPixelsY(100.0);
   shipPos2.setPixelsX(200.0);
   shipPos2.setPixelsY(200.0);

   Angle dir1, dir2;
   dir1.setRadians(0.0);     // Up
   dir2.setRadians(M_PI_2);  // Right

   Velocity vel;
   vel.setDxDy(0.0, 0.0);

   // EXERCISE
   Projectile p1(shipPos1, dir1, vel);
   Projectile p2(shipPos2, dir2, vel);

   // VERIFY
   // Projectiles should be independent
   assertEquals(p1.position.x != p2.position.x, true);
   assertEquals(p1.position.y != p2.position.y, true);
   assertEquals(p1.velocity.dx != p2.velocity.dx, true);
   assertEquals(p1.velocity.dy != p2.velocity.dy, true);
   assertEquals(p1.direction.radians != p2.direction.radians, true);

   // Both should be alive
   assertEquals(p1.dead, false);
   assertEquals(p2.dead, false);

   // Both should have correct radius
   assertEquals(p1.radius, 0.5);
   assertEquals(p2.radius, 0.5);

   // TEARDOWN
}