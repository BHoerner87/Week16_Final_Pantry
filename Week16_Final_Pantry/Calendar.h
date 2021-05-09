#ifndef CALENDAR_H
#define CALENDAR_H

// I am going to test removing the Calendar class and trying to
// replicate its fuctionality (and expiration) with primitive ints
// in main and the Food class.

// Calendar replaces the old Date class but will do the same thing.
// Calendar should only be kept as an instance on (in) the Whiteboard class
// Calendar's derived class, Expiration, will exist inside the Food class

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
