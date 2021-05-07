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
  
public:
  // Default Constructor
  Pantry()
  { pantryItems = 0; }
  
  // Setters
  void storeFood(Food f)
  { storage.push_back(f); }
  
  // Getters
  int countFood(bool);
  void countFood()    // Overloaded function updates pantryItems
  { pantryItems = countFood(false); }
};

#endif
