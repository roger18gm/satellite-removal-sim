/***********************************************************************
 * Source File:
 *    SPUTNIK
 * Author:
*    Roger Galan & Jessen Forbush
 * Summary:
 *    The Sputnik class
 ************************************************************************/

#pragma once
#include "sputnik.h"

 /***************************************************
  * SPUTNIK
  * the Sputnik satellite default constructor
  * We will place our Sputnik in a elliptical, retrograde 
  * (opposite the spin of the earth) orbit. This means that 
  * the initial position is at (-36,515,095.13 m, 21,082,000.0 m) 
  * and the initial velocity is (2050.0 m/s, 2684.68 m/s).
  * The radius of Sputnik is going to be 4 pixels, drawn not to scale.
  ***************************************************/
Sputnik::Sputnik()
{
   radius = 4.0;
   angularVelocity = 0.01;
   position.setMeters(-36515095.13, 21082000.0);
   velocity.setDxDy(2050.0, 2684.68);
};

/***************************************************
 * DESTROY
 * When Sputnik comes into contact with another 
 * element in the simulation it breaks up into 4 fragments.
 ***************************************************/
void Sputnik::destroy(std::vector<std::unique_ptr<Satellite>>* satellites)
{
   kill();
   for (int i = 1; i < 5; i++) {
      satellites->push_back(std::make_unique<Fragment>(*this, Angle(45.0 * i)));
   }
}

/***************************************************
* SATELLITE DRAW
* Draw the satellite
***************************************************/
void Sputnik::draw(ogstream* pgout) const
{
   if (pgout != nullptr)
   {
      pgout->drawSputnik(position, direction.getRadians());
   }
}