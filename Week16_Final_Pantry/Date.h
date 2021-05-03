//
//  Calendar.hpp
//  Week16_Final_Pantry
//
//  Created by Brian Hoerner on 5/3/21.
//

#ifndef CALENDAR_H
#define CALENDAR_H

#include <iostream>

class Date
{
protected:
  int year, month, day;
  
public:
  // Default constructor;
  Date()
  {
    year = 2021;
    month = 1;
    day = 1;
  }
  // Constructor
  Date(int y, int m, int d)
  {
    year = y;
    month = m;
    day = d;
  }
  void setMonth();
  // Getters
};

class Expiration : public Date
{
public:
  Expiration()
  {
    year = 2021; month = 1; day = 1;
  }
  void setExpiry()
  {
    // Prompt user for expiry year
    // Set expiry year
    // Prompt user for expiry month
    // Set expiry month
    // Prompt user for expiry day
    // Set expiry day
  }
};

#endif /* Calendar_hpp */
