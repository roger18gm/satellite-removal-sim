/***********************************************************************
* Source File :
*Starlink
* Author :
   *Jessen Forbush& Roger Galan
   * Summary :
   *The Starlink class
   ************************************************************************/

#include "starlink.h"

   /***************************************************
    * STARLINK
    * the Starlink satellite default constructor
    * We will therefore put our Starlink satellite at
    * (0.0 m, -13,020,000.0 m) with a velocity of (5,800.0 m/s, 0.0 m/s).
    * The radius of the satellite is 6 pixels.
    ***************************************************/
   Starlink::Starlink()
{
   radius = 6.0;
   angularVelocity = 0.05;
   position.setMeters(0.0, -13020000.0);
   velocity.setDxDy(5800.0, 0.0);
}

/***************************************************
 * destroy
 * When a Starlink comes into contact with another element
 * in the simulation it breaks up into 2 pieces and 2 fragments.
 ***************************************************/
void Starlink::destroy(std::vector<std::unique_ptr<Satellite>>* satellites)
{
   satellites->push_back(std::make_unique<StarlinkBody>(*this, Angle(90.0), 2.0));
   satellites->push_back(std::make_unique<StarlinkArray>(*this, Angle(270.0), 4.0));

   satellites->push_back(std::make_unique<Fragment>(*this, Angle(45.0)));
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(135.0)));
}

void StarlinkBody::destroy(std::vector<std::unique_ptr<Satellite>>* satellites)
{
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(60.0)));
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(120.0)));
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(180.0)));
}

void StarlinkArray::destroy(std::vector<std::unique_ptr<Satellite>>* satellites)
{
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(0.0)));
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(240.0)));
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(300.0)));
}

/***************************************************
 * SATELLITE DRAW
 * Draw all the pieces.
 ***************************************************/
void Starlink::draw(ogstream* pgout) const
{
   if (pgout != nullptr)
   {
      pgout->drawStarlink(position, direction.getRadians());
   }
}

void StarlinkBody::draw(ogstream* pgout) const
{
   if (pgout != nullptr)
   {
      pgout->drawStarlinkBody(position, direction.getRadians());
   }
}

void StarlinkArray::draw(ogstream* pgout) const
{
   if (pgout != nullptr)
   {
      pgout->drawStarlinkArray(position, direction.getRadians());
   }
}