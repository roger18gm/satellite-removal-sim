/***********************************************************************
 * Source File:
 *    ACCELERATION
 * Author:
 *    Jessen Forbush & Roger Galan Manzano
 * Summary:
 *    Everything we need to know about changing speed
 ************************************************************************/

#include "acceleration.h"
#include "angle.h"

#include <cmath>

 /*********************************************
  * ACCELERATION : ADD
  *  a += a
  *  Add another acceleration segment to this one.
  *********************************************/
void Acceleration::add(const Acceleration& acceleration)
{
   ddx += acceleration.getDDX();
   ddy += acceleration.getDDY();
}

/*********************************************
* ACCELERATION : SET
* With a given angle (in radians) and value
* for magnitude size, calculate the horizontal
* and vertical acceleration components.
*********************************************/
void Acceleration::set(const Angle& angle, double magnitude)
{
   ddx = magnitude * sin(angle.getRadians());
   ddy = magnitude * cos(angle.getRadians());
}

