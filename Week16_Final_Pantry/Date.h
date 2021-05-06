//
//  Calendar.hpp
//  Week16_Final_Pantry
//
//  Created by Brian Hoerner on 5/3/21.
//

#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date
{
private:
  bool dateSet;
  
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
// Tried to have Destructor but it gave compiler errors.
//  ~Date()
//  {
//    std::cout << "Object deleted, I guess.";
//  }
  // Setters
  virtual void setYear(); // The expiration class will have a version
  virtual void setMonth();// 
  virtual void setDay();  // its user prompts.
  void setToday()
  { setYear(); setMonth(); setDay(); dateSet = true;}
  
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
  void setYear(int);
  void setYear();
  void setMonth(int);
  void setMonth();
  void setDay(int);
  void setDay();
  void setExpiry()
  { setYear(); setMonth(); setDay(); }
};

// Tried to shorten other code by putting repeat code into this function,
// but was unable to call it successfully. Some compiler trouble about
// symbols.
//void correctEntry()
//{
//  std::cin.clear();
//  std::cin.ignore(1000, '\n');
//  std::cout << "\nPlease make a valid entry: ";
//}


#endif /* Calendar_hpp */
