/***********************************************************************
 * Header File:
 *    Dragon
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    The Dragon class
 ************************************************************************/

#pragma once
#include "satellite.h"

 /***************************************************
  * DRAGON
  * a SpaceX Crew Dragon satellite
  ***************************************************/
class Dragon : public Satellite
{
public:
   Dragon();
   ~Dragon() {}
   void draw(ogstream* pgout) const override;
   void destroy(std::vector<std::unique_ptr<Satellite>>* satellites) override;
};

class DragonCenter : public Part
{
public:
   DragonCenter(Satellite& whole, const Angle& direction, double radius) : Part(whole, direction, radius) {}
   ~DragonCenter() {}
   void draw(ogstream* pgout) const override;
   void destroy(std::vector<std::unique_ptr<Satellite>>* satellites) override;
};

class DragonLeft : public Part
{
public:
   DragonLeft(Satellite& whole, const Angle& direction, double radius) : Part(whole, direction, radius) {}
   ~DragonLeft() {}
   void draw(ogstream* pgout) const override;
   void destroy(std::vector<std::unique_ptr<Satellite>>* satellites) override;
};

class DragonRight : public Part
{
public:
   DragonRight(Satellite& whole, const Angle& direction, double radius) : Part(whole, direction, radius) {}
   ~DragonRight() {}
   void draw(ogstream* pgout) const override;
   void destroy(std::vector<std::unique_ptr<Satellite>>* satellites) override;
};