/***********************************************************************
 * Source File:
 *    TEST STARLINK
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    The unit tests for Starlink
 ************************************************************************/
#define _USE_MATH_DEFINES
#include "starlink.h"
#include "testStarlink.h"
#include <math.h>

 /*************************************
  * DEFAULT CONSTRUCTOR
  * input: nothing
  * output: position (0.0, -13020000.0), velocity (5800.0, 0.0), dead(false), angularVelocity(0.05), radius(6.0)
  **************************************/
void TestStarlink::defaultConstructor()
{
   // SETUP

   // EXERCISE
   Starlink s;

   // VERIFY
   assertEquals(s.position.x, 0.0);
   assertEquals(s.position.y, -13020000.0);
   assertEquals(s.velocity.dx, 5800.0);
   assertEquals(s.velocity.dy, 0.0);
   assertEquals(s.dead, false);
   assertEquals(s.angularVelocity, 0.05);
   assertEquals(s.radius, 6.0);
   assertEquals(s.direction.radians, 0.0);

   // TEARDOWN
}

/*************************************
 * WHOLE STARLINK DESTROY
 * input: satellite vector
 * output: 2 Parts, 2 Fragments
 **************************************/
void TestStarlink::destroyStarlink_2Part_2Fragments()
{
   // SETUP
   Starlink starlink;
   starlink.direction.radians = M_PI;
   std::vector<std::unique_ptr<Satellite>> satellites;

   // EXERCISE
   starlink.destroy(&satellites);

   // VERIFY
   assertEquals(satellites.size(), 4); // 2 parts, 2 fragments
   StarlinkBody* sb = dynamic_cast<StarlinkBody*>(satellites[0].get());
   StarlinkArray* sa = dynamic_cast<StarlinkArray*>(satellites[1].get());
   Fragment* f0 = dynamic_cast<Fragment*>(satellites[2].get());
   Fragment* f1 = dynamic_cast<Fragment*>(satellites[3].get());
   assertEquals(sb != nullptr, true);
   assertEquals(sa != nullptr, true);
   assertEquals(f0 != nullptr, true);
   assertEquals(f1 != nullptr, true);
   assertEquals(sb->direction.radians, M_PI);
   assertEquals(sa->direction.radians, M_PI);
   assertEquals(f0->direction.radians, M_PI);
   assertEquals(f1->direction.radians, M_PI);
   assertEquals(sb->radius, 2.0);
   assertEquals(sa->radius, 4.0);
   assertEquals(f0->radius, 2.0);
   assertEquals(f1->radius, 2.0);

   // TEARDOWN
   satellites.clear(); // unique_ptr automatically frees memory on destroy
}

/*************************************
 * STARLINK BODY DESTROY
 * input: satellite vector
 * output: 3 Fragments
 **************************************/
void TestStarlink::destroyStarlinkBody_3Fragments()
{
   // SETUP
   Starlink starlink;
   starlink.direction.radians = M_PI;
   StarlinkBody starlinkBody(starlink, Angle(0.0), 2.0);
   std::vector<std::unique_ptr<Satellite>> satellites;

   // EXERCISE
   starlinkBody.destroy(&satellites);

   // VERIFY
   assertEquals(satellites.size(), 3); // 3 fragments
   Fragment* f0 = dynamic_cast<Fragment*>(satellites[0].get());
   Fragment* f1 = dynamic_cast<Fragment*>(satellites[1].get());
   Fragment* f2 = dynamic_cast<Fragment*>(satellites[2].get());
   assertEquals(f0 != nullptr, true);
   assertEquals(f1 != nullptr, true);
   assertEquals(f2 != nullptr, true);
   assertEquals(f0->direction.radians, M_PI);
   assertEquals(f1->direction.radians, M_PI);
   assertEquals(f2->direction.radians, M_PI);
   assertEquals(f0->radius, 2.0);
   assertEquals(f1->radius, 2.0);
   assertEquals(f2->radius, 2.0);

   // TEARDOWN
   satellites.clear(); // unique_ptr automatically frees memory on destroy
}

/*************************************
 * STARLINK ARRAY DESTROY
 * input: satellite vector
 * output: 3 Fragments
 **************************************/
void TestStarlink::destroyStarlinkArray_3Fragments()
{
   // SETUP
   Starlink starlink;
   starlink.direction.radians = M_PI;
   StarlinkArray starlinkArray(starlink, Angle(0.0), 4.0);
   std::vector<std::unique_ptr<Satellite>> satellites;

   // EXERCISE
   starlinkArray.destroy(&satellites);

   // VERIFY
   assertEquals(satellites.size(), 3); // 3 fragments
   Fragment* f0 = dynamic_cast<Fragment*>(satellites[0].get());
   Fragment* f1 = dynamic_cast<Fragment*>(satellites[1].get());
   Fragment* f2 = dynamic_cast<Fragment*>(satellites[2].get());
   assertEquals(f0 != nullptr, true);
   assertEquals(f1 != nullptr, true);
   assertEquals(f2 != nullptr, true);
   assertEquals(f0->direction.radians, M_PI);
   assertEquals(f1->direction.radians, M_PI);
   assertEquals(f2->direction.radians, M_PI);
   assertEquals(f0->radius, 2.0);
   assertEquals(f1->radius, 2.0);
   assertEquals(f2->radius, 2.0);

   // TEARDOWN
   satellites.clear(); // unique_ptr automatically frees memory on destroy
}