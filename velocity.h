/***********************************************************************
 * Header File:
 *    VELOCITY
 * Author:
 *    Jessen Forbush & Roger Galan Manzano
 * Summary:
 *    Everything we need to know about speed
 ************************************************************************/

#pragma once

 // for unit tests
class TestPosition;
class TestVelocity;
class TestAcceleration;
class TestSatellite;
class TestSputnik;
class TestStarlink;
class TestDragon;
class TestGps;
class TestHubble;
class TestDreamChaser;
class TestProjectile;
class TestSim;
// for add()
class Acceleration;
class Angle;


/*********************************************
 * Velocity
 * I feel the need, the need for speed
 *********************************************/
class Velocity
{
   // for unit tests
   friend TestPosition;
   friend TestVelocity;
   friend TestSatellite;
   friend TestSputnik;
   friend TestStarlink;
   friend TestDragon;
   friend TestGps;
   friend TestHubble;
   friend TestDreamChaser;
   friend TestProjectile;
   friend TestSim;


public:
   // constructors
   Velocity() : dx(0.0), dy(0.0) {}
   Velocity(double dx, double dy) : dx(dx), dy(dy) {}
   Velocity& operator = (const Velocity& vel);


   // getters
   double getDX()       const { return dx; }
   double getDY()       const { return dy; }
   double getSpeed()    const;
   Angle  getAngle()    const;

   // setters
   // setSpeed( speed)
   // setAngle(angle)
   void set(const Angle& angle, double magnitude);
   void setDxDy(double dx, double dy) { this->dx = dx; this->dy = dy; }
   void setDX(double dx) { this->dx = dx; }
   void setDY(double dy) { this->dy = dy; }
   void addDX(double dx) { this->dx += dx; }
   void addDY(double dy) { this->dy += dy; }
   void add(const Acceleration& acceleration, double time);
   void addV(const Velocity& rhs) { dx += rhs.dx; dy += rhs.dy; }
   void reverse() { dx *= -1; dy *= -1; }

private:
   double dx;           // horizontal velocity
   double dy;           // vertical velocity
};