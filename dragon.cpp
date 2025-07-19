/***********************************************************************
 * Source File:
 *    Dragon
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    The Dragon class
 ************************************************************************/

#include "dragon.h"

 /***************************************************
  * DRAGON
  * the Dragon satellite default constructor
  * We will put this satellite in a low earth orbit at
  * (0.0 m, 8,000,000.0 m) with a velocity of (-7,900.0 m/s, 0.0 m/s).
  * The radius of Dragon is going to be 7 pixels.
  ***************************************************/
Dragon::Dragon()
{
   radius = 7.0;
   angularVelocity = 0.05;
   position.setMeters(0.0, 8000000.0);
   velocity.setDxDy(-7900.0, 0.0);
}

/***************************************************
 * destroy
 * When the Crew Dragon comes into contact with another element
 * in the simulation it breaks up into 3 pieces and 2 fragments.
 ***************************************************/
void Dragon::destroy(std::vector<std::unique_ptr<Satellite>>* satellites)
{
   satellites->push_back(std::make_unique<DragonCenter>(*this, Angle(0.0), 6.0));
   satellites->push_back(std::make_unique<DragonLeft>(*this, Angle(120.0), 6.0));
   satellites->push_back(std::make_unique<DragonRight>(*this, Angle(240.0), 6.0));

   satellites->push_back(std::make_unique<Fragment>(*this, Angle(60.0)));
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(180.0)));
}

void DragonCenter::destroy(std::vector<std::unique_ptr<Satellite>>* satellites)
{
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(0.0)));
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(90.0)));
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(180.0)));
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(270.0)));
}

void DragonLeft::destroy(std::vector<std::unique_ptr<Satellite>>* satellites)
{
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(90.0)));
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(270.0)));
}

void DragonRight::destroy(std::vector<std::unique_ptr<Satellite>>* satellites)
{
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(90.0)));
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(270.0)));
}

/***************************************************
 * SATELLITE DRAW
 * Draw all the pieces.
 ***************************************************/
void Dragon::draw(ogstream* pgout) const
{
   if (pgout != nullptr)
   {
      pgout->drawCrewDragon(this->position, this->direction.getRadians());
   }
}

void DragonCenter::draw(ogstream* pgout) const
{
   if (pgout != nullptr)
   {
      pgout->drawCrewDragonCenter(this->position, this->direction.getRadians());
   }
}

void DragonLeft::draw(ogstream* pgout) const
{
   if (pgout != nullptr)
   {
      pgout->drawCrewDragonLeft(this->position, this->direction.getRadians());
   }
}

void DragonRight::draw(ogstream* pgout) const
{
   if (pgout != nullptr)
   {
      pgout->drawCrewDragonRight(this->position, this->direction.getRadians());
   }
}