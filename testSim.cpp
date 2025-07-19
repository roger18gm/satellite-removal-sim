/***********************************************************************
 * Source File:
 *    TEST SIM
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    The unit tests for Sim
 ************************************************************************/
#define _USE_MATH_DEFINES
#include "sim.h"
#include "testSim.h"
#include <math.h>


 /*************************************
  * SIM MOVE NO COLLISION
  * input: satellite vector
  * output: no change should happen, should start with 11 satellites
  **************************************/
void TestSim::move_noCollision() 
{
   // SETUP
   Position ptUpperRight;
   ptUpperRight.metersFromPixels = 128000.0; /* 128km equals 1 pixel */
   ptUpperRight.x = 1000.0 * 128000.0;
   ptUpperRight.y = 1000.0 * 128000.0;
   Sim sim(ptUpperRight);

   // EXERCISE
   sim.move();

   // VERIFY
   assertUnit(sim.satellites.size() == 11);

   // TEARDOWN
   sim.satellites.clear();
}

/*************************************
 * SIM MOVE COLLISION 
 * input: satellite vector
 *  hub.pos.x = 10 000 000m hub.pos.y = 10 000 000 hub.radius = 5px
 *  starlink.pos.y = 10 000 000m starlink.pos.y = 10 000 000 starlink.radius = 5px
 *  distance to consider a collision = 1 280 000 = 128 000 * 10 (combined satellite radii x pixel zoom out) 
 *  actual distance between satellites = 1 414 213 = result of distance formula
 * output: radii haven't crossed, no collision yet
 **************************************/
void TestSim::move_twoSatellitesNoCollision()
{
   // SETUP
   Position ptUpperRight;
   ptUpperRight.metersFromPixels = 128000.0; /* 128km equals 1 pixel */
   ptUpperRight.x = 1000.0 * 128000.0;
   ptUpperRight.y = 1000.0 * 128000.0;
   Sim sim(ptUpperRight);
   sim.satellites.clear();
   auto hub = make_unique<Hubble>();
   hub->position.x = 10000000;
   hub->position.y = 10000000;
   hub->radius = 5.0;
   hub->dead = false;
   hub->age = 0;
   auto slink = make_unique<Starlink>();
   slink->position.x = 11000000;
   slink->position.y = 11000000;
   slink->radius = 5.0;
   slink->dead = false;
   slink->age = 0;
   sim.satellites.push_back(move(hub));
   sim.satellites.push_back(move(slink));

   // EXERCISE
   sim.move();

   // VERIFY
   assertUnit(sim.satellites.size() == 2);

   // TEARDOWN
   sim.satellites.clear();
}

/*************************************
 * SIM MOVE TWO SATELLITE COLLISION
 * input: satellite vector
 *  hub.pos.x = 10 000 000m hub.pos.y = 10 000 000 hub.radius = 5px
 *  starlink.pos.y = 10 000 000m starlink.pos.y = 10 000 000 starlink.radius = 5px
 *  distance to consider a collision = 1 280 000 = 128 000 * 10 (combined satellite radii x pixel zoom out) 
 * output: Hubble and Starlink collide, hubble makes 4, starlink makes 4
 **************************************/
void TestSim::move_satellitesCollision()
{
   // SETUP
   Position ptUpperRight;
   ptUpperRight.metersFromPixels = 128000.0; /* 128km equals 1 pixel */
   ptUpperRight.x = 1000.0 * 128000.0;
   ptUpperRight.y = 1000.0 * 128000.0; // 128 000 000.0
   Sim sim(ptUpperRight);
   sim.satellites.clear();
   auto hub = make_unique<Hubble>();
   hub->position.x = 10000000;
   hub->position.y = 10000000;
   hub->radius = 5.0;
   hub->dead = false;
   hub->age = 0;
   auto slink = make_unique<Starlink>();
   slink->position.x = 10000000;
   slink->position.y = 10000000;
   slink->radius = 5.0;
   slink->dead = false;
   slink->age = 0;
   sim.satellites.push_back(move(hub));
   sim.satellites.push_back(move(slink));
   // EXERCISE
   sim.move();

   // VERIFY
   assertUnit(sim.satellites.size() == 8);

   // TEARDOWN
   sim.satellites.clear();
}

/*************************************
 * SIM MOVE FRAGMENT COLLISION
 * input: satellite vector
 *  frag.pos.x = 10 000 000m frag.pos.y = 10 000 000 frag.radius = 2px
 *  sputnik.pos.y = 10 000 000m sputnik.pos.y = 10 000 000 sputnik.radius = 4px
 *  distance to consider a collision = 768 000 = 128 000 * 6 (combined satellite radii x pixel zoom out)
 * output: Fragment and Sputnik collide, frag makes 0, sputnik makes 4
 **************************************/
void TestSim::move_fragmentCollision()
{
   // SETUP
   Position ptUpperRight;
   ptUpperRight.metersFromPixels = 128000.0; /* 128km equals 1 pixel */
   ptUpperRight.x = 1000.0 * 128000.0;
   ptUpperRight.y = 1000.0 * 128000.0; // 128 000 000.0
   Sim sim(ptUpperRight);
   sim.satellites.clear();
   auto frag = make_unique<Fragment>();
   frag->position.x = 10000000;
   frag->position.y = 10000000;
   frag->radius = 2.0;
   frag->dead = false;
   frag->age = 0;
   auto sputnik = make_unique<Sputnik>();
   sputnik->position.x = 10400000;
   sputnik->position.y = 10400000;
   sputnik->radius = 4.0;
   sputnik->dead = false;
   sputnik->age = 0;
   sim.satellites.push_back(move(frag));
   sim.satellites.push_back(move(sputnik));
   // EXERCISE
   sim.move();

   // VERIFY
   assertUnit(sim.satellites.size() == 4);

   // TEARDOWN
   sim.satellites.clear();
}

/*************************************
 * SIM MOVE PROJECTILE COLLISION
 * input: satellite vector
 *  proj.pos.x = 10 000 000m proj.pos.y = 10 000 000 proj.radius = 0.5px
 *  gps.pos.y = 10 000 000m gps.pos.y = 10 000 000 gps.radius = 12px
 *  distance to consider a collision = 1 600 000 = 128 000 * 12.5 (combined satellite radii x pixel zoom out)
 * output: Gps and Projectile collide, gps makes 5
 **************************************/
void TestSim::move_projectileCollision()
{
   // SETUP
   Position ptUpperRight;
   ptUpperRight.metersFromPixels = 128000.0; /* 128km equals 1 pixel */
   ptUpperRight.x = 1000.0 * 128000.0;
   ptUpperRight.y = 1000.0 * 128000.0; // 128 000 000.0
   Sim sim(ptUpperRight);
   sim.satellites.clear();
   auto proj = make_unique<Projectile>();
   proj->position.x = 10000000.0;
   proj->position.y = 10000000.0;
   proj->radius = 0.5; // 64 000
   proj->dead = false;
   proj->age = 0;
   auto gps = make_unique<Gps>(1);
   gps->position.x = 11000000.0;
   gps->position.y = 11000000.0;
   gps->radius = 12.0; // 1 536 000
   gps->dead = false;
   gps->age = 0;
   sim.satellites.push_back(move(proj));
   sim.satellites.push_back(move(gps));
   // EXERCISE
   sim.move();

   // VERIFY
   assertUnit(sim.satellites.size() == 5);
}