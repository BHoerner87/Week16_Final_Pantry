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
  static int pantryItemCount;
  std::vector<Food> storage;
  
public:
  // Constructor
  Pantry()
  { pantryItemCount = 0; }
  
  // Setters
  virtual Food addFood();
  void tossFood();
  
  // Getters
  int foodInventory()
  { return pantryItemCount; }
	
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
  virtual Food addFood();
  
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
