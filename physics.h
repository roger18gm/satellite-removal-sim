/***********************************************************************
 * Header File:
 *    PHYSICS
 * Author:
 *    Roger Galan & Jessen Forbush
 * Summary:
 *    Laws of motion, effects of gravity, wind resistence, etc.
 ************************************************************************/

#pragma once

#define _USE_MATH_DEFINES 
#include <math.h>
#include <cassert>  // for ASSERT 

# define TIME 48.0
# define RADIUS_EARTH 6378000.0
# define GRAVITY_EARTH 9.80665
# define POS_HORIZON_EARTH 0.0
# define POS_VERTICAL_EARTH 0.0


inline double computeGravity(double heightAboveEarth)
{
   return GRAVITY_EARTH * (RADIUS_EARTH / (RADIUS_EARTH + heightAboveEarth)) * (RADIUS_EARTH / (RADIUS_EARTH + heightAboveEarth));
}

inline double computeHeightAboveEarth(double x, double y)
{
   return sqrt((x * x) + (y * y)) - RADIUS_EARTH;
}

inline double directionOfGravityPull(double horizonPos, double verticalPos)
{
   return atan2(POS_HORIZON_EARTH - horizonPos, POS_VERTICAL_EARTH - verticalPos);
}

