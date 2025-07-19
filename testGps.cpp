/***********************************************************************
 * Source File:
 *    TEST GPS
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    The unit tests for GPS
 ************************************************************************/
#define _USE_MATH_DEFINES
#include "gps.h"
#include "testGps.h"
#include <math.h>

 /*************************************
  * DEFAULT CONSTRUCTOR 0
  * input: nothing (GPS satellite 0)
  * output: position (0.0, 26560000.0), velocity (-3880.0, 0.0), dead(false), angularVelocity(0.05), radius(12.0)
  **************************************/
void TestGps::defaultConstructor0()
{
   // SETUP

   // EXERCISE
   Gps gps0(0);

   // VERIFY
   assertEquals(gps0.position.x, 0.0);
   assertEquals(gps0.position.y, 26560000.0);
   assertEquals(gps0.velocity.dx, -3880.0);
   assertEquals(gps0.velocity.dy, 0.0);
   assertEquals(gps0.dead, false);
   assertEquals(gps0.angularVelocity, 0.05);
   assertEquals(gps0.radius, 12.0);
   assertEquals(gps0.direction.radians, 0.0);

   // TEARDOWN
}

/*************************************
 * DEFAULT CONSTRUCTOR 1
 * input: nothing (GPS satellite 1)
 * output: position (23001634.72, 13280000.0), velocity (-1940.0, 3360.18), dead(false), angularVelocity(0.05), radius(12.0)
 **************************************/
void TestGps::defaultConstructor1()
{
   // SETUP

   // EXERCISE
   Gps gps1(1);

   // VERIFY
   assertEquals(gps1.position.x, 23001634.72);
   assertEquals(gps1.position.y, 13280000.0);
   assertEquals(gps1.velocity.dx, -1940.0);
   assertEquals(gps1.velocity.dy, 3360.18);
   assertEquals(gps1.dead, false);
   assertEquals(gps1.angularVelocity, 0.05);
   assertEquals(gps1.radius, 12.0);
   assertEquals(gps1.direction.radians, 0.0);

   // TEARDOWN
}

/*************************************
 * DEFAULT CONSTRUCTOR 2
 * input: nothing (GPS satellite 2)
 * output: position (23001634.72, -13280000.0), velocity (1940.0, 3360.18), dead(false), angularVelocity(0.05), radius(12.0)
 **************************************/
void TestGps::defaultConstructor2()
{
   // SETUP

   // EXERCISE
   Gps gps2(2);

   // VERIFY
   assertEquals(gps2.position.x, 23001634.72);
   assertEquals(gps2.position.y, -13280000.0);
   assertEquals(gps2.velocity.dx, 1940.0);
   assertEquals(gps2.velocity.dy, 3360.18);
   assertEquals(gps2.dead, false);
   assertEquals(gps2.angularVelocity, 0.05);
   assertEquals(gps2.radius, 12.0);
   assertEquals(gps2.direction.radians, 0.0);

   // TEARDOWN
}

/*************************************
 * DEFAULT CONSTRUCTOR 3
 * input: nothing (GPS satellite 3)
 * output: position (0.0, -26560000.0), velocity (3880.0, 0.0), dead(false), angularVelocity(0.05), radius(12.0)
 **************************************/
void TestGps::defaultConstructor3()
{
   // SETUP

   // EXERCISE
   Gps gps3(3);

   // VERIFY
   assertEquals(gps3.position.x, 0.0);
   assertEquals(gps3.position.y, -26560000.0);
   assertEquals(gps3.velocity.dx, 3880.0);
   assertEquals(gps3.velocity.dy, 0.0);
   assertEquals(gps3.dead, false);
   assertEquals(gps3.angularVelocity, 0.05);
   assertEquals(gps3.radius, 12.0);
   assertEquals(gps3.direction.radians, 0.0);

   // TEARDOWN
}

/*************************************
 * DEFAULT CONSTRUCTOR 4
 * input: nothing (GPS satellite 4)
 * output: position (-23001634.72, -13280000.0), velocity (1940.0, -3360.18), dead(false), angularVelocity(0.05), radius(12.0)
 **************************************/
void TestGps::defaultConstructor4()
{
   // SETUP

   // EXERCISE
   Gps gps4(4);

   // VERIFY
   assertEquals(gps4.position.x, -23001634.72);
   assertEquals(gps4.position.y, -13280000.0);
   assertEquals(gps4.velocity.dx, 1940.0);
   assertEquals(gps4.velocity.dy, -3360.18);
   assertEquals(gps4.dead, false);
   assertEquals(gps4.angularVelocity, 0.05);
   assertEquals(gps4.radius, 12.0);
   assertEquals(gps4.direction.radians, 0.0);

   // TEARDOWN
}

/*************************************
 * DEFAULT CONSTRUCTOR 5
 * input: nothing (GPS satellite 5)
 * output: position (-23001634.72, 13280000.0), velocity (-1940.0, -3360.18), dead(false), angularVelocity(0.05), radius(12.0)
 **************************************/
void TestGps::defaultConstructor5()
{
   // SETUP

   // EXERCISE
   Gps gps5(5);

   // VERIFY
   assertEquals(gps5.position.x, -23001634.72);
   assertEquals(gps5.position.y, 13280000.0);
   assertEquals(gps5.velocity.dx, -1940.0);
   assertEquals(gps5.velocity.dy, -3360.18);
   assertEquals(gps5.dead, false);
   assertEquals(gps5.angularVelocity, 0.05);
   assertEquals(gps5.radius, 12.0);
   assertEquals(gps5.direction.radians, 0.0);

   // TEARDOWN
}

/*************************************
 * WHOLE GPS DESTROY
 * input: satellite vector
 * output: 3 Gps Parts, and 2 Fragments
 **************************************/
void TestGps::destroyGps_3Parts2Fragments()
{
   // SETUP
   Gps gps(1);
   gps.direction.radians = M_PI;
   std::vector<std::unique_ptr<Satellite>> satellites;

   // EXERCISE
   gps.destroy(&satellites);

   // VERIFY
   assertEquals(satellites.size(), 5); // 3 gps parts, 2 fragments
   GpsCenter* gc = dynamic_cast<GpsCenter*>(satellites[0].get());
   GpsLeft* gl = dynamic_cast<GpsLeft*>(satellites[1].get());
   GpsRight* gr = dynamic_cast<GpsRight*>(satellites[2].get());
   Fragment* f0 = dynamic_cast<Fragment*>(satellites[3].get());
   Fragment* f1 = dynamic_cast<Fragment*>(satellites[4].get());
   assertEquals(gc != nullptr, true);
   assertEquals(gl != nullptr, true);
   assertEquals(gr != nullptr, true);
   assertEquals(f0 != nullptr, true);
   assertEquals(f1 != nullptr, true);
   assertEquals(gc->direction.radians, M_PI);
   assertEquals(gl->direction.radians, M_PI);
   assertEquals(gr->direction.radians, M_PI);
   assertEquals(f0->direction.radians, M_PI);
   assertEquals(f1->direction.radians, M_PI);
   assertEquals(gc->radius, 8.0);
   assertEquals(gl->radius, 7.0);
   assertEquals(gr->radius, 7.0);
   assertEquals(f0->radius, 2.0);
   assertEquals(f1->radius, 2.0);

   // TEARDOWN
   satellites.clear(); // unique_ptr automatically frees memory on destroy
}

/*************************************
 * GPS CENTER DESTROY
 * input: satellite vector
 * output: 3 Fragments
 **************************************/
void TestGps::destroyGpsCenter_3Fragments()
{
   // SETUP
   Gps gps(1);
   gps.direction.radians = M_PI;
   GpsCenter gpsCenter(gps, Angle(0.0), 7.0);
   std::vector<std::unique_ptr<Satellite>> satellites;

   // EXERCISE
   gpsCenter.destroy(&satellites);

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
   satellites.clear();
}

/*************************************
 * GPS LEFT DESTROY
 * input: satellite vector
 * output: 3 Fragments
 **************************************/
void TestGps::destroyGpsLeft_3Fragments()
{
   // SETUP
   Gps gps(1);
   gps.direction.radians = M_PI;
   GpsLeft gpsLeft(gps, Angle(0.0), 7.0);
   std::vector<std::unique_ptr<Satellite>> satellites;

   // EXERCISE
   gpsLeft.destroy(&satellites);

   // VERIFY
   assertUnit(satellites.size() == 3); // 3 fragments
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
   satellites.clear();
}

/*************************************
 * GPS RIGHT DESTROY
 * input: satellite vector
 * output: 3 Fragments
 **************************************/
void TestGps::destroyGpsRight_3Fragments()
{
   // SETUP
   Gps gps(1);
   gps.direction.radians = M_PI;
   GpsRight gpsRight(gps, Angle(0.0), 6.0);
   std::vector<std::unique_ptr<Satellite>> satellites;

   // EXERCISE
   gpsRight.destroy(&satellites);

   // VERIFY
   assertUnit(satellites.size() == 3); // 3 fragments
   Fragment* f0 = dynamic_cast<Fragment*>(satellites[0].get());
   Fragment* f1 = dynamic_cast<Fragment*>(satellites[1].get());
   Fragment* f2 = dynamic_cast<Fragment*>(satellites[2].get());
   assertUnit(f0 != nullptr);
   assertUnit(f1 != nullptr);
   assertUnit(f2 != nullptr);
   assertUnit(f0->direction.radians == M_PI);
   assertUnit(f1->direction.radians == M_PI);
   assertUnit(f2->direction.radians == M_PI);
   assertUnit(f0->radius == 2.0);
   assertUnit(f1->radius == 2.0);
   assertUnit(f2->radius == 2.0);

   // TEARDOWN
   satellites.clear();
}