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
  
public:
  // Default Constructor
//  Pantry()
//  { pantryItemCount = 0; }
  
  // Setters
  void storeFood(Food f)
  { storage.push_back(f); }
  
  // Getters
  int countFood(bool);
  //int getFoodInventory(bool toShow);
  //int handleExpired(bool, bool);
  //void clearExpired();
};
/*
class Refrigerator : public Pantry
{
private:
  int refrigeratorItemCount;

public:
  // Constructor
  Refrigerator()
  { refrigeratorItemCount = 0; }
  
  // Setters
//  virtual Food addFood();
  
  // Getters
  int refrigeratorInventory()
  { return refrigeratorItemCount; }
};

class Freezer : public Refrigerator
{
private:
  int freezerItemCount;
  
public:
  // Constructor
  Freezer()
  { freezerItemCount = 0; }
};*/

#endif
