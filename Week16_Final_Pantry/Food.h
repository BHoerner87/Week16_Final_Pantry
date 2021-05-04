//
//  Food.hpp
//  Week16_Final_Pantry
//
//  Created by Brian Hoerner on 5/3/21.
//

#ifndef FOOD_H
#define FOOD_H

#include "Date.h"
#include <iostream>

class Food
{
private:
  std::string name;
  bool isMeal;    // Qualifies as meal for meal suggestion functionality
  bool isCold;    // Must be refrigerated
  bool isFrozen;  // Must be frozen
//  Date::
  Expiration expir;
  int quantity;
public:
  // Default constructor
  Food()
  { name = ""; quantity = 1;}
  // Setters
  void setName(std::string str)
  { name = str;}
  void setMeal(bool b)
  { isMeal = b; }
  void setCold(bool b)
  { isCold = b; }
  void setFrozen(bool b)
  { isFrozen = b; }
};

#endif /* Food_hpp */
