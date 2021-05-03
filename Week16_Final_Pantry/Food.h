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
//  Date::
  Expiration expir;
  int quantity;
public:
  // Default constructor
  Food()
  { name = ""; quantity = 1;}
  // Setters
  void addItem();
  void setName(std::string str)
  { name = str;};
    
};

#endif /* Food_hpp */
