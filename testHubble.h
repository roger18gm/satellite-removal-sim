/***********************************************************************
 * Header File:
 *    Test Hubble : Test the Hubble class
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    All the unit tests for Hubble
 ************************************************************************/

#pragma once
#include "hubble.h"
#include "unitTest.h"

 /***************************************************
  * HUBBLE TEST
  * Test the Hubble class
  ***************************************************/
class TestHubble : public UnitTest
{
public:

   void run()
   {
      // Constructor Tests
      defaultConstructor();
      destroyHubble_4Parts();
      destroyHubbleTelescope_3Fragments();
      destroyHubbleComputer_2Fragments();
      destroyHubbleLeft_2Fragments();
      destroyHubbleRight_2Fragments();

      report("Hubble");
   }

private:
   // Constructor Tests
   void defaultConstructor();
   void destroyHubble_4Parts();
   void destroyHubbleTelescope_3Fragments();
   void destroyHubbleComputer_2Fragments();
   void destroyHubbleLeft_2Fragments();
   void destroyHubbleRight_2Fragments();

};
