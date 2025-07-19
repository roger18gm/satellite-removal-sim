/***********************************************************************
 * Header File:
 *    EARTH
 * Author:
 *    Roger Galan & Jessen Forbush
 * Summary:
 *    Mother Earth
 ************************************************************************/

#pragma once

#include "position.h"  // for POINT
#include "velocity.h"  // for VELOCITY
#include "uiDraw.h"    // for DRAW* and RANDOM
#include "angle.h"     // for ANGLE


#include <cassert>  // for ASSERT 

# define RADIUS_EARTH 6378000.0

class TestSatellite;
class TestSim;

class Earth
{
   class TestSatellite;
   friend TestSim;
public:
   Earth() : position(0.0, 0.0), direction(0.0), angularVelocity(1.0), radius(RADIUS_EARTH / 128000.0) {}
   virtual ~Earth() = default;

   double getRadius()            const { return radius; }
   const Position& getPosition() const { return position; }

   void draw(ogstream* pgout, double angleEarth) {
      direction.rotate(angleEarth);
      pgout->drawEarth(position, direction.getRadians());
   }

private:
   Position position;
   Angle direction;
   double angularVelocity;
   double radius;
};