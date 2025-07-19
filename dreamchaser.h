/***********************************************************************
 * Header File:
 *    DREAMCHASER
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    The DreamChaser (user-controlled ship) class
 ************************************************************************/

#pragma once
#include "satellite.h"
#include "uiInteract.h"

class TestDreamchaser;

/***************************************************
 * DREAMCHASER
 * The Sierra Nevada Corporation Dream Chaser spaceplane
 * This is the user-controlled ship in the simulation
 ***************************************************/
class Dreamchaser : public Satellite
{
   friend TestDreamchaser;

public:
   // Constructors
   Dreamchaser();
   ~Dreamchaser() {}

   // Satellite Virtual Functions
   void draw(ogstream* pgout) const override;
   void destroy(std::vector<std::unique_ptr<Satellite>>* satellites) override;
   void input(const Interface* pUI) override;
   void move(double time) override;

   // DreamChaser specific methods
   void thrust(double acceleration, double time);
   void rotate(double radians);
   void fireProjectile(std::vector<std::unique_ptr<Satellite>>* satellites);

private:
   bool thrusting;  // Whether the ship is currently thrusting
};