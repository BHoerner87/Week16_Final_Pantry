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
  
  int exYear;
  int exMonth;
  int exDay;
  //  Expiration expiration;
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
  { isExpired = b; }// Need to be fed years from cal getters
  // Food::setExYear()/Month()/Day() should access the
  //  setYear()(etc.) functions of a Food object's expiration member,
  //  setting the expiration member variables.
  //  That is: AddFood > setExYear > expiration.setYear().
  //    expiration.setYear() should not require an argument. It
  //    prompts the user on its own for input, and sets the expiration.year
  //    member variable before returning.
  //      4:48pm 05/08/21 This has been a good lesson in not using
  //       similar names. All this verbiage was to hunt down my logical
  //       error, which was calling expiration.setYear(etc.). I forgot
  //       Expiration objects had both a setYear and a setExYear because
  //       of some decision or another I made a day or so ago.
//  void setExYear()
//  { expiration.setExYear(); }
//  void setExMonth()
//  { expiration.setExMonth(); }
//  void setExDay()
//  { expiration.setExDay(); }
  
  // Expiration Getters
  int getExYear()
  { return exYear; }
  int getExMonth()
  { return exMonth; }
  int getExDay()
  { return exDa; }
  bool getIsExpired()
  { return isExpired; }
};

#endif
