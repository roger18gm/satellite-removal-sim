/***********************************************************************
 * Header File:
 *    Gps
 * Author:
*    Roger Galan & Jessen Forbush
 * Summary:
 *    The Gps class
 ************************************************************************/

#pragma once
#include "satellite.h"

/***************************************************
 * Gps
 * a GPS satellite, there will be 6 in the program
 ***************************************************/
class Gps : public Satellite
{
public:
   Gps() : Satellite() {}
   Gps(int index);
   ~Gps() {}
   void draw(ogstream* pgout) const override;
   void destroy(std::vector<std::unique_ptr<Satellite>>* satellites) override;
};


class GpsCenter : public Part
{
public:
   GpsCenter(Satellite& whole, const Angle& direction, double radius) : Part(whole, direction, radius) {}
   ~GpsCenter() {}
   void draw(ogstream* pgout) const override;
   void destroy(std::vector<std::unique_ptr<Satellite>>* satellites) override;
};

class GpsLeft : public Part
{
public:
   GpsLeft(Satellite& whole, const Angle& direction, double radius) : Part(whole, direction, radius) {}
   ~GpsLeft() {}
   void draw(ogstream* pgout) const override;
   void destroy(std::vector<std::unique_ptr<Satellite>>* satellites) override;
};

class GpsRight : public Part
{
public:
   GpsRight(Satellite& whole, const Angle& direction, double radius) : Part(whole, direction, radius) {}
   ~GpsRight() {}
   void draw(ogstream* pgout) const override;
   void destroy(std::vector<std::unique_ptr<Satellite>>* satellites) override;
};