/***********************************************************************
 * Source File:
 *    HUBBLE
 * Author:
*    Roger Galan & Jessen Forbush
 * Summary:
 *    The Hubble class
 ************************************************************************/

#pragma once
#include "hubble.h"

/***************************************************
 * HUBBLE
 * the Hubble satellite default constructor
 * We will start with the telescope at (0.0 m, -42,164,000.0 m) 
 * with a velocity of (3,100.0 m/s, 0.0 m/s).
 * The radius of Hubble is going to be 10 pixels
 ***************************************************/
Hubble::Hubble()
{
   radius = 10.0;
   angularVelocity = 0.02;
   position.setMeters(0.0, -42164000.0);
   velocity.setDxDy(3100.0, 0.0);
};

/***************************************************
 * DESTROY
 * When the Hubble breaks, it creates 4 Parts
 ***************************************************/
void Hubble::destroy(std::vector<std::unique_ptr<Satellite>>* satellites)
{
   satellites->push_back(std::make_unique<HubbleTelescope>(*this, Angle(0.0), 10.0));
   satellites->push_back(std::make_unique<HubbleComputer>(*this, Angle(90.0), 7.0));
   satellites->push_back(std::make_unique<HubbleLeft>(*this, Angle(180.0), 8.0));
   satellites->push_back(std::make_unique<HubbleRight>(*this, Angle(270.0), 8.0));
}

void HubbleTelescope::destroy(std::vector<std::unique_ptr<Satellite>>* satellites)
{
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(0.0)));
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(120.0)));
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(240.0)));
}

void HubbleComputer::destroy(std::vector<std::unique_ptr<Satellite>>* satellites)
{
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(0.0)));
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(180.0)));
}

void HubbleLeft::destroy(std::vector<std::unique_ptr<Satellite>>* satellites)
{
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(0.0)));
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(180.0)));
}

void HubbleRight::destroy(std::vector<std::unique_ptr<Satellite>>* satellites)
{
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(0.0)));
   satellites->push_back(std::make_unique<Fragment>(*this, Angle(180.0)));
}

/***************************************************
* SATELLITE DRAW
* Draw the satellite
***************************************************/
void Hubble::draw(ogstream* pgout) const
{
   if (pgout != nullptr)
   {
      pgout->drawHubble(this->position, this->direction.getRadians());
   }
}

void HubbleTelescope::draw(ogstream* pgout) const
{
   if (pgout != nullptr)
   {
      pgout->drawHubbleTelescope(this->position, this->direction.getRadians());
   }
}

void HubbleComputer::draw(ogstream* pgout) const
{
   if (pgout != nullptr)
   {
      pgout->drawHubbleComputer(this->position, this->direction.getRadians());
   }
}

void HubbleLeft::draw(ogstream* pgout) const
{
   if (pgout != nullptr)
   {
      pgout->drawHubbleLeft(this->position, this->direction.getRadians());
   }
}

void HubbleRight::draw(ogstream* pgout) const
{
   if (pgout != nullptr)
   {
      pgout->drawHubbleRight(this->position, this->direction.getRadians());
   }
}