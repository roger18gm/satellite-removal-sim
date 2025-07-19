/*************************************************************
 * 1. Name:5
 *      Sim
 * 2. Assignment Name:
 *      Lab 12: Orbit Simulator
 *
 * Created by:
 *      Roger Galan & Jessen Forbush
 *****************************************************************/
#pragma once

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include "earth.h"
#include "satellite.h"
#include "dreamchaser.h"
#include "sputnik.h"
#include "gps.h"
#include "hubble.h"
#include "dragon.h"
#include "starlink.h"
#include "projectile.h"
#include "star.h"

using namespace std;

class TestSim;

/*************************************************************************
 * Sim
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Sim
{
   friend class TestSim;
public:
   Sim(Position ptUpperRight) :
      ptUpperRight(ptUpperRight), stars(150)
   {
      frameRate = 30.0;
      hoursPerDay = 24.0;
      minutesPerHour = 60.0;
      secondsPerMinute = 60.0;
      secondsPerDay = hoursPerDay * minutesPerHour * secondsPerMinute;
      timeDilation = hoursPerDay * minutesPerHour;
      radiansInOneDay = -2.0 * M_PI;
      radiansPerFrame = (radiansInOneDay / frameRate) * (timeDilation / secondsPerDay);

      // Spawn stars and satellites
      stars.resetAll(ptUpperRight);
      satellites.push_back(make_unique<Dreamchaser>());
      for (int i = 0; i < 6; i++) {
         satellites.push_back(make_unique<Gps>(i));
      }
      satellites.push_back(make_unique<Hubble>());
      satellites.push_back(make_unique<Sputnik>());
      satellites.push_back(make_unique<Dragon>());
      satellites.push_back(make_unique<Starlink>());
   }
   vector<unique_ptr<Satellite>> satellites;
   void input(const Interface* pUI);
   void move();
   void draw(ogstream* pgout);
   double computeDistance(const Position& pos1, const Position& pos2);

   Position ptUpperRight;
   Earth earth;
   Stars stars;

   double frameRate;
   double hoursPerDay;
   double minutesPerHour;
   double secondsPerMinute;
   double secondsPerDay;
   double timeDilation;
   double radiansInOneDay;
   double radiansPerFrame;
};

