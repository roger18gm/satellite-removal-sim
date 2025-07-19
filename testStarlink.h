/***********************************************************************
 * Header File:
 *    Test Starlink : Test the Starlink class
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    All the unit tests for Starlink
 ************************************************************************/

#pragma once
#include "starlink.h"
#include "unitTest.h"

 /***************************************************
  * STARLINK TEST
  * Test the Starlink class
  ***************************************************/
class TestStarlink : public UnitTest
{
public:

   void run()
   {
      // Constructor Tests
      defaultConstructor();
      destroyStarlink_2Part_2Fragments();
      destroyStarlinkBody_3Fragments();
      destroyStarlinkArray_3Fragments();

      report("Starlink");
   }

private:
   // Constructor Tests
   void defaultConstructor();
   void destroyStarlink_2Part_2Fragments();
   void destroyStarlinkBody_3Fragments();
   void destroyStarlinkArray_3Fragments();


};
