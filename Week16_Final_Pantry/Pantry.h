// Brian Hoerner
// CIS 1202.501
// 3 May 2021

// This application is meant to track the inventory of one's kitchen perishables,
// including and especially when they expire. It is meant to be an aid for
// keeping a tidy kitchen, and for curbing one's over-buying habits to
// prevent food waste. Menu navigation is performed by entering numbers
// from menus of options, or by entering Y / N chars when provided with
// yes-no choices.

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
  void storeFood(Food f)
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
};

class Refrigerator
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
  void storeFoodR(Food f)
  { coldStorage.push_back(f); }
  void markExpired(Calendar &);
  void confirmErase();
  void addFoodR(Calendar &);
  void addWaste(double w)
  { coldWastePrice += w; }
  void setColdItems(int i)
  { coldItems = i; }
  
  // Getters
  int countFoodR(bool);
  void countFoodR()
  { coldItems = countFoodR(false); }
  int countExpired(bool, bool);
  double getColdWastePrice()
  { return coldWastePrice; }
  int getColdItems()
  { return coldItems; }
};

#endif
