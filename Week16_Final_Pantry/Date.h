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
//  // Destructor
//  ~Date()
//  {
//    std::cout << "Object deleted, I guess.";
//  }
  // Setters
  virtual void setYear(); // The expiration class will have a version
  virtual void setMonth();// 
  virtual void setDay();  // its user prompts.
  void setToday()
  { setYear(); setMonth(); setDay(); }
  
  // Getters
  virtual int getYear()
    { return year; }
  virtual int getMonth()
    { return month; }
  virtual int getDay()
    { return day; }
};

class Expiration : public Date
{
public:
  // Default Constructor
  Expiration()
  {
    year = 2021; month = 1; day = 1;
  }
  // Constructor
  Expiration(int y, int m, int d)
  {
    year = y;
    month = m;
    day = d;
  }
  // Setters
  void setYear();
  void setMonth();
  void setDay();
  void setExpiry()
  { getYear(); getMonth(); getDay(); }
};

//void correctEntry()
//{
//  std::cin.clear();
//  std::cin.ignore(1000, '\n');
//  std::cout << "\nPlease make a valid entry: ";
//}


#endif /* Calendar_hpp */
