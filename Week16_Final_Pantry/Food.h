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
  int yearAdded;
  int monthAdded;
  int dayAdded;
  
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
  void setYearAdded(int y)
  { yearAdded = y; }
  void setMonthAdded(int m)
  { monthAdded = m; }
  void setDayAdded(int d)
  { dayAdded = d; }
  void setExpired(bool e)
  { isExpired = e; }
  
  // Getters
  std::string getName()
  { return name; }
  double getPrice()
  { return price; }
  bool getisExpired()
  { return isExpired; }
  
  // Expiration Setters
  void setIsExpired(int, int, int); // Need to be fed years from cal getters
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
  bool getIsExpired()
  { return isExpired; }
};

#endif
