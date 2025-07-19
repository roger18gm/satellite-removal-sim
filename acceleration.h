/***********************************************************************
 * Header File:
 *    ACCELERATION
 * Author:
 *    Jessen Forbush & Roger Galan Manzano
 * Summary:
 *    Everything we need to know about acceleration
 ************************************************************************/


#pragma once

#include "angle.h"

class TestAcceleration;
class TestVelocity;
class TestProjectile;
class TestPosition;
class Angle;


/*********************************************
 * Acceleration
 * Let's get moving
 *********************************************/
class Acceleration
{
   friend TestPosition;
   friend TestVelocity;
   friend TestAcceleration;
   friend TestProjectile;

public:
   // constructors
   Acceleration() : ddx(0.0), ddy(0.0) {}
   Acceleration(double ddx, double ddy) : ddx(ddx), ddy(ddy) {}
   Acceleration(double magnitude, Angle& angle) { set(angle, magnitude); }
   // operator = (velocity?)

   // getters
   double getDDX()   const { return this->ddx; }
   double getDDY()   const { return this->ddy; }
   // Velocity getVelocity(time)
   
   // setters                        
   void setDDX(double ddx) { this->ddx = ddx; }
   void setDDY(double ddy) { this->ddy = ddy; }
   void set(const Angle& a, double magnitude);

   // Add methods
   void add(const Acceleration& acceleration);
   void addDDX(double ddx) { this->ddx += ddx; }
   void addDDY(double ddy) { this->ddy += ddy; }


private:
   double ddx;     // horizontal acceleration
   double ddy;     // vertical acceleration
};
