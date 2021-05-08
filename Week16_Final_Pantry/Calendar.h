#ifndef CALENDAR_H
#define CALENDAR_H

// Calendar replaces the old Date class but will do the same thing.
// Calendar should only be kept as an instance on (in) the Whiteboard class
// Calendar's derived class, Expiration, will exist inside the Food class

class Calendar
{
private:
  // Today's date
  static int year;
  static int month;
  static int day;

public:
  // Setters;
  void setYear(int y)
  { year = y; }
  static void setYear();
  void setMonth(int m)
  { month = m; }
  static void setMonth();
  void setDay(int d)
  { day = d; }
  static void setDay();

  // Getters
  static int getYear()
  { return year; }
  static int getMonth()
  { return month; }
  static int getDay()
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
