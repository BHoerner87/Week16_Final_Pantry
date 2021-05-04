//
//  Kitchen.hpp
//  Week16_Final_Pantry
//
//  Created by Brian Hoerner on 5/3/21.
//

#ifndef KITCHEN_H
#define KITCHEN_H

#include "Pantry.h"

class Kitchen
{
private:
  static double foodWastePrice;
  
public:
  // Default Constructor
  // Establish pantry and others
  Pantry pantry;
  Refrigerator fridge;
  Freezer freezer;
  
  // Setters
  // Set the price; this is for loading from previous sessions
  void setLifetimeWaste(double d)
  { foodWastePrice = d; }
  // Add to the price; this is called as items expire
  void addLifetimeWaste(double d)
  { foodWastePrice += d; }
  
  // Getters
  double getFoodWaste()
  { return foodWastePrice; }
};

#endif /* Kitchen_hpp */
