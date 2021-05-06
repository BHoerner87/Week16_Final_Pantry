//
//  Pantry.hpp
//  Week16_Final_Pantry
//
//  Created by Brian Hoerner on 5/3/21.
//

#ifndef PANTRY_H
#define PANTRY_H

#include <vector>
#include "Date.h"
#include "Food.h"

class Pantry
{
private:
  int pantryItemCount;
  std::vector<Food> storage;
  friend class Kitchen;
  friend class Food;
  friend class Pantry;
  friend class Date;
  friend class Expiration;
  
public:
  // Default Constructor
  Pantry()
  { pantryItemCount = 0; }
  
  // Setters
  void storeFood(Food f)
  { storage.push_back(f); }
  int getInventory();
  void markExpired(Food f, Date d);
  
  // Getters
  int getFoodInventory(bool toShow);
  int handleExpired(bool, bool);
  void clearExpired();
	
	// Other methods
	std::string monthName(int m);
  
};

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
};

#endif /* Pantry_hpp */
