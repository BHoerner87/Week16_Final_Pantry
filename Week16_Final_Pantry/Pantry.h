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
  friend class Config;
  std::vector<Food> storage;
  int pantryItems;
  int currentYear;
  int currentMonth;
  int currentDay;
  double wastePrice;
  
public:
  // Default Constructor
  Pantry()
  { pantryItems = 0; }
  
  // Setters
  void storeFood(Food f)
  { storage.push_back(f); }
  void markExpired(Calendar &);
  void confirmErase();
  void tossExpired(bool, bool);
  void addWaste(double w)
  { wastePrice += w; }
  void setPantryItems(int i)
  { pantryItems = i; }
  
  // Getters
  int countFood(bool);
  void countFood()    // Overloaded function updates pantryItems
  { pantryItems = countFood(false); }
  int countExpired(bool, bool);
  double getWastePrice()
  { return wastePrice; }
  int getPantryItems()
  { return pantryItems; }
  
  // Other Methods
  void addFood(Calendar &);
//  void storageDebug()
//  { for (int i = 0; i < storage.size(); i++)
//    {
//      std::cout << "Storage[" << i << "].name is" << storage[i].getName() << std::endl;
//      std::cout << "Storage[" << i << "].price is" << storage[i].getPrice() << std::endl;
//      // storage.FoodObject.getExYear() reaches into foodObject's Expiration object to use ITS getExYear function. This should return an int all the way back.
//      // But it returns bullshit and I still don't know why.
//      std::cout << "Storage[" << i << "] expires on: Y " << storage[i].getExYear() << " M " << storage[i].getExMonth() << " D " << storage[i].getExDay() << std::endl;;
//    }
//  }
};

#endif
