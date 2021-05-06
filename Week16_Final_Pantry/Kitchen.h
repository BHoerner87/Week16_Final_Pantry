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
  friend class Pantry;
  
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
  int getKitchenInventory()
  { return pantry.getFoodInventory(false) + fridge.getFoodInventory(false) + freezer.getFoodInventory(false); }
  void showKitchenInventory()
  {
    pantry.getFoodInventory(true);
    fridge.getFoodInventory(true);
    freezer.getFoodInventory(true);
    return;
  }
  double getFoodWaste()
  { return foodWastePrice; }
  
  // Kitchen accessing Food's setExpired function
  void kitchenSetExp(Date d)
  { pantry.mark}
  
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
  int accessHandleExpired(bool toShow, bool toDelete)
  { return pantry.handleExpired(toShow, toDelete); }
};

#endif /* Kitchen_hpp */
