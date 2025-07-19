/***********************************************************************
 * Source File:
 *    SIM
 * Author:
 *    Roger Galan & Jessen Forbush
 * Summary:
 *    Puts everything into orbit and into a playable state
 ************************************************************************/

#pragma once
#include "sim.h"

double Sim::computeDistance(const Position& pos1, const Position& pos2)
{
   return sqrt((pos1.getPixelsX() - pos2.getPixelsX()) * (pos1.getPixelsX() - pos2.getPixelsX()) +
      (pos1.getPixelsY() - pos2.getPixelsY()) * (pos1.getPixelsY() - pos2.getPixelsY()));
}

/*************************************************************************
 * INPUT
 * Handle user input for the DreamChaser ship.
 *************************************************************************/
void Sim::input(const Interface* pUI)
{
   for (auto& satellite : satellites)
   {
      Dreamchaser* dreamChaser = dynamic_cast<Dreamchaser*>(satellite.get());
      if (dreamChaser != nullptr)
      {
         dreamChaser->input(pUI);
         if (pUI->isSpace())
         {
            dreamChaser->fireProjectile(&satellites);
         }
         break;
      }
   }
}

/*************************************************************************
 * MOVE
 * Updates the state of all game objects and handles collisions.
 *************************************************************************/
void Sim::move()
{
   double time = 48.0;
   for (auto& obj : satellites)
   {
      obj->move(time);
   }

   // Earth collision
   for (auto& obj : satellites)
   {
      if (!obj->isDead())
      {
         double earthPixelDistance = computeDistance(obj->getPosition(), earth.getPosition());

         if (earthPixelDistance < earth.getRadius() + obj->getRadius())
         {
            obj->kill(); // Mark satellite as dead.
         }
      }
   }

   // Satellite, Projectile, Fragment, Part collision
   for (size_t i = 0; i < satellites.size(); i++)
   {
      for (size_t j = i + 1; j < satellites.size(); j++)
      {
         // Could add another check to see if satellite age is past certain amount for newly spawned pieces
         if (!satellites[i]->isDead() && !satellites[j]->isDead())
         {
            double pixelDistance = computeDistance(satellites[i]->getPosition(), satellites[j]->getPosition());

            if (pixelDistance < satellites[i]->getRadius() + satellites[j]->getRadius()) // Satellite radius is in pixels
            {
               satellites[i]->kill();
               satellites[j]->kill();
            }
         }
      }
   }

   vector<Satellite*> toDestroy; // Store raw pointers of dead objects

   for (const auto& obj_ptr : satellites)
   {
      if (obj_ptr->isDead())
      {
         toDestroy.push_back(obj_ptr.get());
      }
   }

   // Now call destroy on them
   for (Satellite* deadObj : toDestroy)
   {
      deadObj->destroy(&satellites); 
   }

   // Remove the dead objects from the vector
   satellites.erase(
      remove_if(satellites.begin(), satellites.end(),
         [](const unique_ptr<Satellite>& s) { return s->isDead(); }),
      satellites.end());
}

/*************************************************************************
 * DRAW
 * Displays all game objects and the Earth.
 *************************************************************************/
void Sim::draw(ogstream* pgout)
{
   stars.drawAll(*pgout);
   earth.draw(pgout, radiansPerFrame);

   // Draw all satellites (polymorphically)
   for (const auto& obj : satellites)
   {
      if (!obj->isDead()) // Only draw if not dead
      {
         obj->draw(pgout);
      }
   }
}