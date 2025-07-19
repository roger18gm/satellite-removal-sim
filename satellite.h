/***********************************************************************
 * Header File:
 *    Satellite
 * Author:
 *    Roger Galan & Jessen Forbush
 * Summary:
 *    All the information about the satellite base class
 ************************************************************************/

#pragma once

#include "position.h"  // for POINT
#include "velocity.h"  // for VELOCITY
#include "uiDraw.h"    // for DRAW* and RANDOM
#include "uiInteract.h"  // for Interface
#include "angle.h"     // for ANGLE

#define _USE_MATH_DEFINES 
#include <math.h>
#include <cassert>  // for ASSERT 
#include <vector>

#define TIME 48.0 
# define RADIUS_EARTH 6378000.0
# define GRAVITY_EARTH 9.80665
# define POS_HORIZON_EARTH 0.0
# define POS_VERTICAL_EARTH 0.0

class TestSatellite;
class TestSputnik;
class TestHubble;
class TestDreamChaser;
class TestStarlink;
class TestDragon;
class TestGps;
class TestSim;

class Satellite
{
   friend TestSatellite;
   friend TestSputnik;
   friend TestHubble;
   friend TestDreamChaser;
   friend TestStarlink;
   friend TestDragon;
   friend TestGps;
   friend TestSim;

public:
   Satellite() : position(200.0, 200.0), velocity(0.0, 0.0), dead(false), angularVelocity(0.0), radius(0.0), age(0) {}
   Satellite(Satellite& s, Angle a);
   Satellite(Satellite& s, Angle a, double radius);
   virtual ~Satellite() = default;

   double getRadius()            const { return radius;  }
   bool isDead()                 const { return dead; }
   const Position& getPosition() const { return position; }
   void kill()                         { dead = true; }

   virtual void draw(ogstream* pgout)                                  const = 0;
   virtual void destroy(std::vector<std::unique_ptr<Satellite>>* satellites) = 0;
   virtual void move(double time);
   virtual void input(const Interface* pUI) {};

private:
   inline double getGravity(double heightAboveEarth)
   {
      return GRAVITY_EARTH * (RADIUS_EARTH / (RADIUS_EARTH + heightAboveEarth)) * 
                             (RADIUS_EARTH / (RADIUS_EARTH + heightAboveEarth));
   }

   inline double computeHeightAboveEarth(Position& pos)
   {
      return sqrt((pos.getMetersX() * pos.getMetersX()) + 
                  (pos.getMetersY() * pos.getMetersY())) - RADIUS_EARTH;
   }

   inline double directionOfGravityPull(Position& pos)
   {
      return atan2(POS_HORIZON_EARTH - pos.getMetersX(), 
                   POS_VERTICAL_EARTH - pos.getMetersY());
   }

protected:
   Velocity velocity;
   Position position;
   Angle direction;
   double angularVelocity;
   bool dead;
   double radius;
   int age;

};

/***************************************************
 * SATELLITE DERIVED
 * A simple derived class so we can test Satellite
 ***************************************************/
class SatelliteDerived : public Satellite
{
public:
   SatelliteDerived() : Satellite() {}
   SatelliteDerived(SatelliteDerived& s, Angle a) : Satellite(s, a) {};
   ~SatelliteDerived() {}

   // Implement pure virtual functions so this class is concrete
   virtual void draw(ogstream* pgout) const override { assert(false); }
   virtual void destroy(std::vector<std::unique_ptr<Satellite>>* satellites) override { assert(false); }
};

/***************************************************
 * SATELLITE DUMMY
 * The dummy double! - Everything returns FALSE
 ***************************************************/
class SatelliteDummy : public Satellite
{
public:
   SatelliteDummy() : Satellite() {}
   SatelliteDummy(SatelliteDummy& s, Angle a) : Satellite(s, a) {};
   ~SatelliteDummy() {}

   double getRadius()            const { assert(false); return true; }
   bool isDead()                 const { assert(false); return true; }
   const Position& getPosition() const { assert(false); return position; }
   void kill()                         { assert(false); }
   virtual void draw(ogstream* pgout) const override { assert(false); }
   virtual void destroy(std::vector<std::unique_ptr<Satellite>>* satellites) override { assert(false); }
   virtual void move(double time) override { assert(false); }
};


class Part : public Satellite
{
public: 
   Part() : Satellite() {}
   Part(Satellite& whole, Angle & direction) : Satellite(whole, direction) {}
   Part(Satellite& s, Angle a, double radius) : Satellite(s, a, radius) {} // params can be const
   ~Part() {}
};

class Fragment : public Satellite
{
public:
   Fragment() : Satellite() {}
   Fragment(Satellite& whole, const Angle& direction) : Satellite(whole, direction) { angularVelocity = 0.5; radius = 2.0; }
   ~Fragment() {}
   void draw(ogstream* pgout)  const;
   void destroy(std::vector<std::unique_ptr<Satellite>>* satellites) override;
   void move(double time);
};