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
  { pantryItems = 0; wastePrice = 0.0; }
  
  // Setters
  virtual void storeFood(Food f)
  { storage.push_back(f); }
  virtual void markExpired(Calendar &);
  virtual void confirmErase();
//  void tossExpired(bool, bool);
  virtual void addWaste(double w)
  { wastePrice += w; }
  void setPantryItems(int i)
  { pantryItems = i; }
  
  // Getters
  virtual int countFood(bool);
  virtual void countFood()    // Overloaded function updates pantryItems
  { pantryItems = countFood(false); }
  virtual int countExpired(bool, bool);
  double getWastePrice()
  { return wastePrice; }
  int getPantryItems()
  { return pantryItems; }
  
  // Other Methods
  virtual void addFood(Calendar &);
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

class Refrigerator : public Pantry
{
private:
  friend class Config;
  std::vector<Food> coldStorage;
  int coldItems;
  double coldWastePrice;
  
public:
  // Default Constructor
  Refrigerator()
  { coldItems = 0; coldWastePrice = 0.0; }
  
  // Setters
  void storeFood(Food f)
  { coldStorage.push_back(f); }
  void markExpired(Calendar &);
  void confirmErase();
  void addFood(Calendar &);
  void addWaste(double w)
  { coldWastePrice += w; }
  
  // Getters
  int countFood(bool);
  void countFood()
  { coldItems = countFood(false); }
  int countExpired(bool, bool);
  double getColdWastePrice()
  { return coldWastePrice; }
  int getColdItems()
  { return coldItems; }
};

#endif
