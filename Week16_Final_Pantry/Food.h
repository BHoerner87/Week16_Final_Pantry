//
//  Food.hpp
//  Week16_Final_Pantry
//
//  Created by Brian Hoerner on 5/3/21.
//

#ifndef FOOD_H
#define FOOD_H

#include "Calendar.h"
#include <iostream>

class Food
{
private:
  std::string name;
  double price;
  Expiration expiration;
  bool isExpired;
  
public:
  // Default constructor
  Food()
  { name = ""; price = 0.0; isExpired = false; }
  
  // Setters
  void setName(std::string str)
  { name = str;}
  void setPrice(double p)
  { price = p; }
  void setExpired(bool e)
  { isExpired = e; }
  
  // Getters
  std::string getName()
  { return name; }
  double getPrice()
  { return price; }
  bool getExpiry()
  { return isExpired; }
  
  // Expiration Setters
  void setIsExpired();
  void setExYear()
  { expiration.setYear(); }
  void setExMonth()
  { expiration.setMonth(); }
  void setExDay()
  { expiration.setDay(); }
  
  // Expiration Getters
  int getExYear()
  { return expiration.getYear(); }
  int getExMonth()
  { return expiration.getMonth(); }
  int getExDay()
  { return expiration.getDay(); }
};

#endif
