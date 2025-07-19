/***********************************************************************
 * Source File:
 *    Gps
 * Author:
*    Roger Galan & Jessen Forbush
 * Summary:
 *    The Gps class
 ************************************************************************/

#pragma once
#include "gps.h"

/***************************************************
 * GPS NON DEFAULT CONSTRUCTOR
 * a GPS satellite, there will be 6 in the program.
 * Each will have a specific position, velocity, 
 * and radius of 10 pixels
 ***************************************************/
Gps::Gps(int index)
{
   radius = 12.0;
   angularVelocity = 0.05;

   if (index == 0)
   {
      position.setMeters(0.0, 26560000.0);
      velocity.setDxDy(-3880.0, 0.0);
   }
   if (index == 1)
   {
      position.setMeters(23001634.72, 13280000.0);
      velocity.setDxDy(-1940.0, 3360.18);
   }
   if (index == 2)
   {
      position.setMeters(23001634.72, -13280000.0);
      velocity.setDxDy(1940.0, 3360.18);
   }
   if (index == 3)
   {
      position.setMeters(0.0, -26560000.0);
      velocity.setDxDy(3880.0, 0.0);
   }
   if (index == 4)
   {
      position.setMeters(-23001634.72, -13280000.0);
      velocity.setDxDy(1940.0, -3360.18);
   }
   if (index == 5)
   {
      position.setMeters(-23001634.72, 13280000.0);
      velocity.setDxDy(-1940.0, -3360.18);
   }
};

/***************************************************
 * destroy
 * When a Whole GPS breaks, it creates 3 Parts and 2 Fragments.
 ***************************************************/
void Gps::destroy(std::vector<std::unique_ptr<Satellite>>* satellites)
{
   satellites->push_back(std::make_unique<GpsCenter>(*this, Angle(60.0), 8.0));
   satellites->push_back(std::make_unique<GpsLeft>(*this, Angle(180.0), 7.0)); // changing left and right to 3 makes them appear
   satellites->push_back(std::make_unique<GpsRight>(*this, Angle(300.0), 7.0)); // for some reason these break into fragments on spawn

   satellites->push_back(std::make_unique<Fragment>(*this, Angle(0.0)));
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(0.0)));
}

void GpsCenter::destroy(std::vector<std::unique_ptr<Satellite>>* satellites)
{
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(30.0)));
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(150.0)));
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(270.0)));
}

void GpsLeft::destroy(std::vector<std::unique_ptr<Satellite>>* satellites)
{
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(60.0)));
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(180.0)));
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(300.0)));
}

void GpsRight::destroy(std::vector<std::unique_ptr<Satellite>>* satellites)
{
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(90.0)));
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(210.0)));
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(330.0)));
}

/***************************************************
* SATELLITE DRAW
* Draw the satellite
***************************************************/
void Gps::draw(ogstream* pgout) const
{
   if (pgout != nullptr)
   {
      pgout->drawGPS(this->position, this->direction.getRadians());
   }
}
void GpsCenter::draw(ogstream* pgout) const
{
   if (pgout != nullptr)
   {
      pgout->drawGPSCenter(this->position, this->direction.getRadians());
   }
}

void GpsLeft::draw(ogstream* pgout) const
{
   if (pgout != nullptr)
   {
      pgout->drawGPSLeft(this->position, this->direction.getRadians());
   }
}

void GpsRight::draw(ogstream* pgout) const
{
   if (pgout != nullptr)
   {
      pgout->drawGPSRight(this->position, this->direction.getRadians());
   }
}