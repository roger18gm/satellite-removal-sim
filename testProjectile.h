/***********************************************************************
 * Header File:
 *    TEST PROJECTILE
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    All the unit tests for Projectile
 ************************************************************************/

#pragma once
#include "projectile.h"
#include "unitTest.h"

 /***************************************************
  * PROJECTILE TEST
  * Test the Projectile class
  ***************************************************/
class TestProjectile : public UnitTest
{
public:

   void run()
   {
      // Constructor Tests
      defaultConstructor();
      constructorWithShipData();

      // Move Tests
      move_normal();
      move_expiration();
      move_alreadyExpired();

      // Behavior Tests
      destroy();
      firingFromShipAtAngle();
      multipleProjectiles();

      report("Projectile");
   }

private:
   // Constructor Tests
   void defaultConstructor();
   void constructorWithShipData();

   // Move Tests
   void move_normal();
   void move_expiration();
   void move_alreadyExpired();

   // Behavior Tests
   void destroy();
   void firingFromShipAtAngle();
   void multipleProjectiles();
};