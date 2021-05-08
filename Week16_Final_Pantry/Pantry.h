//
//  Pantry.hpp
//  Week16_Final_Pantry
//
//  Created by Brian Hoerner on 5/3/21.
//

#ifndef PANTRY_H
#define PANTRY_H

#include <vector>
#include "Food.h"

class Pantry
{
private:
  std::vector<Food> storage;
  int pantryItems;
  int currentYear;
  int currentMonth;
  int currentDay;
  
public:
  // Default Constructor
  Pantry()
  { pantryItems = 0; }
  
  // Setters
  void storeFood(Food f)
  { storage.push_back(f); }
  void tossExpired(bool, bool);
  // When food is tossed out, its price must be accumulated and
  // added to the whiteboard's waste count;
  // The whiteboard's food count must also be updated
  
  // Getters
  int countFood(bool);
  void countFood()    // Overloaded function updates pantryItems
  { pantryItems = countFood(false); }
  int countExpired(bool);
  
  // Other Methods
  void addFood(int, int, int);
};

#endif
