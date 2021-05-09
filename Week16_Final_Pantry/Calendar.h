// Brian Hoerner
// CIS 1202.501
// 3 May 2021

// This application is meant to track the inventory of one's kitchen perishables,
// including and especially when they expire. It is meant to be an aid for
// keeping a tidy kitchen, and for curbing one's over-buying habits to
// prevent food waste. Menu navigation is performed by entering numbers
// from menus of options, or by entering Y / N chars when provided with
// yes-no choices.

#ifndef CALENDAR_H
#define CALENDAR_H

class Calendar
{
private:
  // Today's date
  int year;
  int month;
  int day;

public:
  
  // Setters;
  void setYear();
  void setMonth();
  void setDay();
  void setToday()
  { setYear(); setMonth(); setDay(); }

  // Getters
  int getYear()
  { return year; }
  int getMonth()
  { return month; }
  int getDay()
  { return day; }

  // Other mMthods
  static void monthString(int m);
};

class Expiration : public Calendar
{
private:
  int exYear;
  int exMonth;
  int exDay;
  
public:
  
  // Setters
  void setExYear();
  void setExMonth();
  void setExDay();
  
  // Getters
  int getExYear()
  { return exYear; }
  int getExMonth()
  { return exMonth; }
  int getExDay()
  { return exDay; }
};
#endif
