/***********************************************************************
 * Header File:
 *    ANGLE
 * Author:
 *    Jessen Forbush & Roger Galan Manzano
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#pragma once

#define _USE_MATH_DEFINES
#include <math.h>   // for M_PI which is 3.14159

 // for the unit tests
class TestAngle;
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

/************************************
 * ANGLE
 ************************************/
class Angle
{
public:
   // for the unit tests
   friend TestAcceleration;
   friend TestVelocity;
   friend TestAngle;
   friend TestSatellite;
   friend TestSputnik;
   friend TestStarlink;
   friend TestDragon;
   friend TestGps;
   friend TestHubble;
   friend TestDreamChaser;
   friend TestProjectile;
   friend TestSim;


   // Constructors
   Angle() : radians(0.0) {}
   Angle(const Angle& rhs) : radians(rhs.radians) {}
   Angle(double degrees) : radians(degrees) {}

   // Getters
   double getDegrees() const { return convertToDegrees(radians); }
   double getRadians() const { return radians; }

   //         dx
   //    +-------/
   //    |      /
   // dy |     /
   //    |    / 1.0
   //    | a /
   //    |  /
   //    | /
   // dx = sin a
   // dy = cos a
   double getDx() const { return sin(radians); }
   double getDy() const { return cos(radians); }
   bool isRight() const { return normalize(radians) > 0.0 && normalize(radians) < M_PI; }
   bool isLeft()  const { return normalize(radians) > M_PI && normalize(radians) < 2.0 * M_PI; }



   // Setters
   void setDegrees(double degrees) { radians = normalize(convertToRadians(degrees)); }
   void setRadians(double radians) { this->radians = normalize(radians); }
   void setUp() { radians = 0.0; }
   void setDown() { radians = M_PI; }
   void setRight() { radians = M_PI * 0.5; }
   void setLeft() { radians = M_PI * 1.5; }
   void reverse() { radians = normalize(radians + M_PI); }
   void rotate(double amount) { setRadians(amount + radians); }
   Angle& add(double delta)
   {
      radians = normalize(radians + delta);
      return *this;
   }
   // set based on the components
   //         dx
   //     +-------/
   //     |      /
   //  dy |     /
   //     |    /
   //     | a /
   //     |  /
   //     | /
   void setDxDy(double dx, double dy) { radians = normalize(atan(dx / dy)); }
   Angle operator+(double degrees) const { return Angle(); }

private:
   double convertToDegrees(double radians) const
   {
      return radians * (180.0 / M_PI);
   }
   double convertToRadians(double degrees) const
   {
      return degrees * (M_PI / 180.0);
   }
   double normalize(double radians) const;

   double radians;   // 360 degrees equals 2 PI radians
};

#include <iostream>

/*******************************************************
 * OUTPUT ANGLE
 * place output on the screen in degrees
 *******************************************************/
inline std::ostream& operator << (std::ostream& out, const Angle& rhs)
{
   out << rhs.getDegrees() << "degree";
   return out;
}