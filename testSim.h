/***********************************************************************
* Header File:
*    Test Sim : Test the main Sim class
* Author:
*    Jessen Forbush & Roger Galan
* Summary:
*    All the unit tests for Sim
************************************************************************/

#pragma once
#include "sim.h"
#include "unitTest.h"

/***************************************************
 * SIM TEST
 * Test the Sim class
 ***************************************************/
class TestSim : public UnitTest
{
public:

   void run()
   {
      move_noCollision();
      move_twoSatellitesNoCollision();
      move_satellitesCollision();
      move_fragmentCollision();
      move_projectileCollision();

      report("Sim");
   }

private:
   void move_noCollision();
   void move_twoSatellitesNoCollision();
   void move_satellitesCollision();
   void move_fragmentCollision();
   void move_projectileCollision();
};