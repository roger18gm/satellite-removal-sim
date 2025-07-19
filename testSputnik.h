/***********************************************************************
 * Header File:
 *    Test Sputnik : Test the Sputnik class
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    All the unit tests for Sputnik
 ************************************************************************/

#pragma once
#include "sputnik.h"
#include "unitTest.h"

 /***************************************************
  * SPUTNIK TEST
  * Test the Sputnik class
  ***************************************************/
class TestSputnik : public UnitTest
{
public:

   void run()
   {
      // Constructor Tests
      defaultConstructor();
      destroySputnik_4Fragments();


      report("Sputnik");
   }

private:
   // Constructor Tests
   void defaultConstructor();
   void destroySputnik_4Fragments();
};
