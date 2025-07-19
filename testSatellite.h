/***********************************************************************
 * Header File:
 *    Test Satellite : Test the Satellite class
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    All the unit tests for Satellite
 ************************************************************************/

#pragma once
#include "satellite.h"
#include "unitTest.h"

 /***************************************************
  * SATELLITE TEST
  * Test the Satellite class
  ***************************************************/
class TestSatellite : public UnitTest
{
public:

   void run()
   {
      // Constructor Tests
      defaultConstructor();
      constructorWithPosition();

      // Getter Tests
      getRadiusDefault();
      getPositionInitial();
      isDeadInitial();
      isDeadAfterKill();

      // Action Tests
      killAliveToDead();
      killAlreadyDead();

      // Move Tests - Basic
      moveZeroTime();
      moveZeroVelocity();
      moveWithVelocity();
      moveWithAngularVelocity();

      // Move Tests - Physics/Scenarios
      getPositionAfterMove();
      moveAtEarthSurface();
      moveGPSOrbit();

      report("Satellite");
   }

private:
   // Constructor Tests
   void defaultConstructor();
   void constructorWithPosition();

   // Getter Tests
   void getRadiusDefault();
   void getPositionInitial();
   void isDeadInitial();
   void isDeadAfterKill();

   // Action Tests
   void killAliveToDead();
   void killAlreadyDead();

   // Move Tests - Basic
   void moveZeroTime();
   void moveZeroVelocity();
   void moveWithVelocity();
   void moveWithAngularVelocity();

   // Move Tests - Physics/Scenarios
   void getPositionAfterMove();
   void moveAtEarthSurface();
   void moveGPSOrbit();
};
