/***********************************************************************
 * Source File:
 *    TEST SPUTNIK
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    The unit tests for Sputnik
 ************************************************************************/
#define _USE_MATH_DEFINES
#include "sputnik.h"
#include "testSputnik.h"
#include <math.h>

 /*************************************
  * DEFAULT CONSTRUCTOR
  * input: nothing
  * output: position (-36515095.13, 21082000.0), velocity (2050.0, 2684.68), dead(false), angularVelocity(0.01), radius(4.0)
  **************************************/
void TestSputnik::defaultConstructor()
{
   // SETUP

   // EXERCISE
   Sputnik s;

   // VERIFY
   assertEquals(s.position.x, -36515095.13);
   assertEquals(s.position.y, 21082000.0);
   assertEquals(s.velocity.dx, 2050.0);
   assertEquals(s.velocity.dy, 2684.68);
   assertEquals(s.dead, false);
   assertEquals(s.angularVelocity, 0.01);
   assertEquals(s.radius, 4.0);
   assertEquals(s.direction.radians, 0.0);

   // TEARDOWN
}

/*************************************
 * WHOLE SPUTNIK DESTROY
 * input: satellite vector
 * output: 4 Fragments
 **************************************/
void TestSputnik::destroySputnik_4Fragments()
{
   // SETUP
   Sputnik sputnik;
   sputnik.direction.radians = M_PI;
   std::vector<std::unique_ptr<Satellite>> satellites;

   // EXERCISE
   sputnik.destroy(&satellites);

   // VERIFY
   assertEquals(satellites.size(), 4); // 4 fragments
   Fragment* f0 = dynamic_cast<Fragment*>(satellites[0].get());
   Fragment* f1 = dynamic_cast<Fragment*>(satellites[1].get());
   Fragment* f2 = dynamic_cast<Fragment*>(satellites[2].get());
   Fragment* f3 = dynamic_cast<Fragment*>(satellites[3].get());
   assertEquals(f0 != nullptr, true);
   assertEquals(f1 != nullptr, true);
   assertEquals(f2 != nullptr, true);
   assertEquals(f3 != nullptr, true);
   assertEquals(f0->direction.radians, M_PI);
   assertEquals(f1->direction.radians, M_PI);
   assertEquals(f2->direction.radians, M_PI);
   assertEquals(f3->direction.radians, M_PI);
   assertEquals(f0->radius, 2.0);
   assertEquals(f1->radius, 2.0);
   assertEquals(f2->radius, 2.0);
   assertEquals(f3->radius, 2.0);

   // TEARDOWN
   satellites.clear(); // unique_ptr automatically frees memory on destroy
}