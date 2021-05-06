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
  double price;
  bool isMeal;    // Qualifies as meal for meal suggestion functionality
  bool isCold;    // Must be refrigerated
  bool isFrozen;  // Must be frozen
  bool isExpired; // May come in handy. Might end up being covered by functions though.
  friend class Kitchen;
  friend class Pantry;
  
protected:
  Expiration expiry;
  friend class Pantry;
  
public:
  // Default constructor
  Food()
  { name = ""; }
  
  // Setters
  void setName(std::string str)
  { name = str;}
  void setPrice(double p)
  { price = p; }
  void setMeal(bool b)
  { isMeal = b; }
  void setCold(bool b)
  { isCold = b; }
  void setFrozen(bool b)
  { isFrozen = b; }
  void setExpired(bool b)
  { isExpired = b; }
  
  // Getters
  std::string getName()
  { return name; }
  double getPrice()
  { return price; }
  bool mealValue()
  { return isMeal; }
  bool coldValue()
  { return isCold; }
  bool frozenValue()
  { return isFrozen; }
  bool getExpiry()
  { return isExpired; }
  
  // Expiration Setters
  void setExpiryYear()
  { expiry.setYear(); }
  void setExpiryYear(int y)
  { expiry.setYear(y); }
  
  void setExpiryMonth()
  { expiry.setMonth(); }
  void setExpiryMonth(int m)
  { expiry.setMonth(m); }
  
  void setExpiryDay()
  { expiry.setDay(); }
  void setExpiryDay(int d)
  { expiry.setDay(d); }
  
  void setExpired(Date d, Expiration e);
  
  // Expiration Getters
  int getExpYear()
  { return expiry.getYear(); }
  int getExpMonth()
  { return expiry.getMonth(); }
  int getExpDay()
  { return expiry.getDay(); }
};

#endif /* Food_hpp */
