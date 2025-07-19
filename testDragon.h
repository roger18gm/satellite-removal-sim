   /***********************************************************************
 * Header File:
 *    Test Dragon : Test the Dragon class
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    All the unit tests for Dragon
 ************************************************************************/

#pragma once
#include "dragon.h"
#include "unitTest.h"

 /***************************************************
  * DRAGON TEST
  * Test the Dragon class
  ***************************************************/
class TestDragon : public UnitTest
{
public:

   void run()
   {
      // Constructor Tests
      defaultConstructor();
      destroyDragon_3Parts_2Fragments();
      destroyDragonCenter_4Fragments();
      destroyDragonLeft_2Fragments();
      destroyDragonRight_2Fragments();

      report("Dragon");
   }

private:
   // Constructor Tests
   void defaultConstructor();
   void destroyDragon_3Parts_2Fragments();
   void destroyDragonCenter_4Fragments();
   void destroyDragonLeft_2Fragments();
   void destroyDragonRight_2Fragments();


};