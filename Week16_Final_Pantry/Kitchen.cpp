//
//  Kitchen.cpp
//  Week16_Final_Pantry
//
//  Created by Brian Hoerner on 5/3/21.
//

#include <iostream>
#include <iomanip>
#include "Kitchen.h"

using namespace std;

// Crawl pantries, mark all expired food
void Kitchen::kitchenSetExp(Pantry p, Date d)
{
  for (int i = 0; i < storage.size(); i++)
  {
    pantry.markExpired(storage[i], d);
}
