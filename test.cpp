/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testPosition.h"
#include "testAcceleration.h"
#include "testVelocity.h"
#include "testAngle.h"
#include "testSatellite.h"
#include "testSputnik.h"
#include "testStarlink.h"
#include "testDragon.h"
#include "testGps.h"
#include "testHubble.h"
#include "testDreamchaser.h"
#include "testProjectile.h"
#include "testSim.h"

#ifdef _WIN32
#include <windows.h>
#include <iostream>
using namespace std;
#endif

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
#ifdef _WIN32
   AllocConsole();
   FILE* stream;
   errno_t err;
   err = freopen_s(&stream, "CONOUT$", "a", stdout);
#endif // _WIN32

   // Unit tests
   TestAngle().run();
   TestAcceleration().run();
   TestVelocity().run();
   TestPosition().run();
   TestSatellite().run();
   TestSputnik().run();
   TestStarlink().run();
   TestDragon().run();
   TestGps().run();
   TestHubble().run();
   TestDreamChaser().run();
   TestProjectile().run();
   TestSim().run();
}
