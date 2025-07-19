/***********************************************************************
 * Header File:
 *    Test Dreamchaser : Test the Dreamchaser class
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    All the unit tests for Hubble
 ************************************************************************/

#pragma once
#include "hubble.h"
#include "unitTest.h"

 /***************************************************
  * Dream Chaser TEST
  * Test the Ship class
  ***************************************************/
class TestDreamChaser : public UnitTest
{
public:

   void run()
   {
      // Constructor Tests
      defaultConstructor();
      thrust_once();
      rotate_left();
      rotate_right();
      input_none();
      input_downKeyPressed();
      input_leftKeyPressed();
      input_rightKeyPressed();

      report("Dreamchaser");
   }

private:
   // Constructor Tests
   void defaultConstructor();
   void thrust_once();
   void rotate_left();
   void rotate_right();
   void input_none();
   void input_downKeyPressed();
   void input_leftKeyPressed();
   void input_rightKeyPressed();

};
