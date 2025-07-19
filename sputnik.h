/***********************************************************************
 * Header File:
 *    SPUTNIK
 * Author:
*    Roger Galan & Jessen Forbush
 * Summary:
 *    The Sputnik Satellite class
 ************************************************************************/

#pragma once
#include "satellite.h"

 /***************************************************
  * SPUTNIK
  * a Sputnik telescope satellite
  ***************************************************/
class Sputnik : public Satellite
{
public:
   Sputnik();
   ~Sputnik() {}
   void draw(ogstream* pgout) const override;
   void destroy(std::vector<std::unique_ptr<Satellite>>* satellites) override;
};

