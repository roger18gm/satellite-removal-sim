/***********************************************************************
 * Source File:
 *    TEST HUBBLE
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    The unit tests for HUbble
 ************************************************************************/
#define _USE_MATH_DEFINES
#include "hubble.h"
#include "testHubble.h"
#include <math.h>

 /*************************************
  * DEFAULT CONSTRUCTOR
  * input: nothing
  * output: position(-4216400.0, 0.0), velocity(0.0, 3100.0), dead(false), angularVelocity(0.02), radius(0.0)
  **************************************/
void TestHubble::defaultConstructor()
{
   // SETUP

   // EXERCISE
   Hubble h;

   // VERIFY
   assertEquals(h.position.x, 0.0);
   assertEquals(h.position.y, -42164000.0);
   assertEquals(h.velocity.dx, 3100.0);
   assertEquals(h.velocity.dy, 0.0);
   assertEquals(h.dead, false);
   assertEquals(h.angularVelocity, 0.02);
   assertEquals(h.radius, 10.0);
   assertEquals(h.direction.radians, 0.0);

   // TEARDOWN
}

/*************************************
 * WHOLE HUBBLE DESTROY
 * input: satellite vector
 * output: 4 Parts
 **************************************/
void TestHubble::destroyHubble_4Parts()
{
   // SETUP
   Hubble hub;
   hub.direction.radians = M_PI;
   std::vector<std::unique_ptr<Satellite>> satellites;

   // EXERCISE
   hub.destroy(&satellites);

   // VERIFY
   assertEquals(satellites.size(), 4); // 4 fragments
   HubbleTelescope* ht = dynamic_cast<HubbleTelescope*>(satellites[0].get());
   HubbleComputer* hc = dynamic_cast<HubbleComputer*>(satellites[1].get());
   HubbleLeft* hl = dynamic_cast<HubbleLeft*>(satellites[2].get());
   HubbleRight* hr = dynamic_cast<HubbleRight*>(satellites[3].get());
   assertEquals(ht != nullptr, true);
   assertEquals(hc != nullptr, true);
   assertEquals(hl != nullptr, true);
   assertEquals(hr != nullptr, true);
   assertEquals(ht->direction.radians, M_PI);
   assertEquals(hc->direction.radians, M_PI);
   assertEquals(hl->direction.radians, M_PI);
   assertEquals(hr->direction.radians, M_PI);
   assertEquals(ht->radius, 10.0);
   assertEquals(hc->radius, 7.0);
   assertEquals(hl->radius, 8.0);
   assertEquals(hr->radius, 8.0);

   // TEARDOWN
   satellites.clear(); // unique_ptr automatically frees memory on destroy
}

/*************************************
 * PART HUBBLE TELESCOPE DESTROY
 * input: satellite vector
 * output: 3 Fragments
 **************************************/
void TestHubble::destroyHubbleTelescope_3Fragments()
{
   // SETUP
   Hubble hub;
   hub.direction.radians = M_PI;
   HubbleTelescope hubTelescope(hub, Angle(0.0), 10.0);
   std::vector<std::unique_ptr<Satellite>> satellites;

   // EXERCISE
   hubTelescope.destroy(&satellites);

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
 * PART HUBBLE COMPUTER DESTROY
 * input: satellite vector
 * output: 2 Fragments
 **************************************/
void TestHubble::destroyHubbleComputer_2Fragments()
{
   // SETUP
   Hubble hub;
   hub.direction.radians = M_PI;
   HubbleComputer hubComputer(hub, Angle(0.0), 7.0);
   std::vector<std::unique_ptr<Satellite>> satellites;

   // EXERCISE
   hubComputer.destroy(&satellites);

   // VERIFY
   assertEquals(satellites.size(), 2); // 2 fragments
   Fragment* f0 = dynamic_cast<Fragment*>(satellites[0].get());
   Fragment* f1 = dynamic_cast<Fragment*>(satellites[1].get());
   assertEquals(f0 != nullptr, true);
   assertEquals(f1 != nullptr, true);
   assertEquals(f0->direction.radians, M_PI);
   assertEquals(f1->direction.radians, M_PI);
   assertEquals(f0->radius, 2.0);
   assertEquals(f1->radius, 2.0);

   // TEARDOWN
   satellites.clear(); // unique_ptr automatically frees memory on destroy
}

/*************************************
 * PART HUBBLE LEFT DESTROY
 * input: satellite vector
 * output: 2 Fragments
 **************************************/
void TestHubble::destroyHubbleLeft_2Fragments()
{
   // SETUP
   Hubble hub;
   hub.direction.radians = M_PI;
   HubbleLeft hubLeft(hub, Angle(0.0), 8.0);
   std::vector<std::unique_ptr<Satellite>> satellites;

   // EXERCISE
   hubLeft.destroy(&satellites);

   // VERIFY
   assertEquals(satellites.size(), 2); // 3 fragments
   Fragment* f0 = dynamic_cast<Fragment*>(satellites[0].get());
   Fragment* f1 = dynamic_cast<Fragment*>(satellites[1].get());
   assertEquals(f0 != nullptr, true);
   assertEquals(f1 != nullptr, true);
   assertEquals(f0->direction.radians, M_PI);
   assertEquals(f1->direction.radians, M_PI);
   assertEquals(f0->radius, 2.0);
   assertEquals(f1->radius, 2.0);

   // TEARDOWN
   satellites.clear(); // unique_ptr automatically frees memory on destroy
}

/*************************************
 * PART HUBBLE RIGHT DESTROY
 * input: satellite vector
 * output: 2 Fragments
 **************************************/
void TestHubble::destroyHubbleRight_2Fragments()
{
   // SETUP
   Hubble hub;
   hub.direction.radians = M_PI;
   HubbleRight hubRight(hub, Angle(0.0), 8.0);
   std::vector<std::unique_ptr<Satellite>> satellites;

   // EXERCISE
   hubRight.destroy(&satellites);

   // VERIFY
   assertEquals(satellites.size(), 2); // 2 fragments
   Fragment* f0 = dynamic_cast<Fragment*>(satellites[0].get());
   Fragment* f1 = dynamic_cast<Fragment*>(satellites[1].get());
   assertEquals(f0 != nullptr, true);
   assertEquals(f1 != nullptr, true);
   assertEquals(f0->direction.radians, M_PI);
   assertEquals(f1->direction.radians, M_PI);
   assertEquals(f0->radius, 2.0);
   assertEquals(f1->radius, 2.0);

   // TEARDOWN
   satellites.clear(); // unique_ptr automatically frees memory on destroy
}