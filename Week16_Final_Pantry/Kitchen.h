//
//  Kitchen.hpp
//  Week16_Final_Pantry
//
//  Created by Brian Hoerner on 5/3/21.
//

#ifndef KITCHEN_H
#define KITCHEN_H

#include "Pantry.h"
#include "Date.h"

class Kitchen
{
private:
  static double foodWastePrice;
  
protected:
  // Default Constructor
  // Establish pantry and others
  Pantry pantry;
  Refrigerator fridge;
  Freezer freezer;
  
public:
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
  
  // Public method for passing an object through Kitchen
  // to public pantry.storefood()
  void storeFoodP(Food f)
  { pantry.storeFood(f); }
  void storeFoodR(Food f)
  { pantry.storeFood(f); }
  void storeFoodF(Food f)
  { pantry.storeFood(f); }
  
  // Public method for accessing protected member pantry's
  // handleExpired method
  void accessHandleExpired(bool toShow, bool toDelete)
  { pantry.handleExpired(toShow, toDelete); }
};

#endif /* Kitchen_hpp */
