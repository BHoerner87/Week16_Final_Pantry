//
//  Food.cpp
//  Week16_Final_Pantry
//
//  Created by Brian Hoerner on 5/3/21.
//

#include "Food.h"

using namespace std;

void Food::setIsExpired(int year, int month, int day)
{
  if (year > getExYear())
      setExpired(true);
  else if (month > getExMonth())
  { setExpired(true); }
  else if (day >= getExDay())
  { setExpired(true); }
}
