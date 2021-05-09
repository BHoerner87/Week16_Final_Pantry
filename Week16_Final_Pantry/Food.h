// Brian Hoerner
// CIS 1202.501
// 3 May 2021

// This application is meant to track the inventory of one's kitchen perishables,
// including and especially when they expire. It is meant to be an aid for
// keeping a tidy kitchen, and for curbing one's over-buying habits to
// prevent food waste. Menu navigation is performed by entering numbers
// from menus of options, or by entering Y / N chars when provided with
// yes-no choices.

#ifndef FOOD_H
#define FOOD_H

#include "Calendar.h"
#include <iostream>

class Food
{
private:
  // Attributes
  std::string name;
  double price;
  bool isCold;
  
  // Expiration Data
  int exYear;
  int exMonth;
  int exDay;
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
  void setExYear();
  void setExMonth();
  void setExDay();
  
  // Getters
  std::string getName()
  { return name; }
  double getPrice()
  { return price; }
  bool getisExpired()
  { return isExpired; }
  
  // Expiration Setters
  void setIsExpired(bool b)
  { isExpired = b; }
  
  // Expiration Getters
  int getExYear()
  { return exYear; }
  int getExMonth()
  { return exMonth; }
  int getExDay()
  { return exDay; }
  bool getIsExpired()
  { return isExpired; }
};

#endif
