/***********************************************************************
 * Header File:
 *    HUBBLE
 * Author:
*    Roger Galan & Jessen Forbush
 * Summary:
 *    The Hubble Satellite class
 ************************************************************************/

#pragma once
#include "satellite.h"

 /***************************************************
  * HUBBLE
  * a Hubble telescope satellite
  ***************************************************/
class Hubble : public Satellite
{
public:
   Hubble();
   ~Hubble() {}
   void draw(ogstream* pgout) const override;
   void destroy(std::vector<std::unique_ptr<Satellite>>* satellites) override;
};

class HubbleTelescope : public Part
{
public:
   HubbleTelescope(Satellite& whole, const Angle& direction, double radius) : Part(whole, direction, radius) {}
   //HubbleTelescope(Satellite& whole, const Angle& direction) : Satellite(whole, direction) {}
   ~HubbleTelescope() {}
   void draw(ogstream* pgout) const override;
   void destroy(std::vector<std::unique_ptr<Satellite>>* satellites) override;
};

class HubbleComputer : public Part
{
public:
   HubbleComputer(Satellite& whole, const Angle& direction, double radius) : Part(whole, direction, radius) {}
   //HubbleComputer(Satellite& whole, const Angle& direction) : Satellite(whole, direction) {}
   ~HubbleComputer() {}
   void draw(ogstream* pgout) const override;
   void destroy(std::vector<std::unique_ptr<Satellite>>* satellites) override;
};

class HubbleLeft : public Part
{
public:
   HubbleLeft(Satellite& whole, const Angle& direction, double radius) : Part(whole, direction, radius) {}
   //HubbleLeft(Satellite& whole, const Angle& direction) : Satellite(whole, direction) {}
   ~HubbleLeft() {}
   void draw(ogstream* pgout) const override;
   void destroy(std::vector<std::unique_ptr<Satellite>>* satellites) override;
};

class HubbleRight : public Part
{
public:
   HubbleRight(Satellite& whole, const Angle& direction, double radius) : Part(whole, direction, radius) {}
   //HubbleRight(Satellite& whole, const Angle& direction) : Satellite(whole, direction) {}
   ~HubbleRight() {}
   void draw(ogstream* pgout) const override;
   void destroy(std::vector<std::unique_ptr<Satellite>>* satellites) override;
};

