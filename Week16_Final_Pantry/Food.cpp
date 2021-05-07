//
//  Food.cpp
//  Week16_Final_Pantry
//
//  Created by Brian Hoerner on 5/3/21.
//

#include "Food.h"

using namespace std;

void Food::setIsExpired()
{
  if (Calendar::getYear() > getExYear())
      setExpired(true);
  else if (Calendar::getMonth() > getExMonth())
  { setExpired(true); }
  else if (Calendar::getDay() >= getExDay())
  { setExpired(true); }
}
