// Brian Hoerner
// CIS 1202.501
// 3 May 2021

// This application is meant to track the inventory of one's kitchen perishables,
// including and especially when they expire. It is meant to be an aid for
// keeping a tidy kitchen, and for curbing one's over-buying habits to
// prevent food waste. Menu navigation is performed by entering numbers
// from menus of options, or by entering Y / N chars when provided with
// yes-no choices.

#include "Calendar.h"
#include <iomanip>
#include <iostream>

using namespace std;

void Calendar::setYear()
{
  int tempInt;
  cout << "\nWhat is the current year? ";
  while (!(cin >> tempInt) || tempInt < 2021 || tempInt > 2099)
  {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "\nPlease enter a valid year: ";
  }
  year = tempInt;
  cout << "\nYear set!" << endl;
  return;
}

void Calendar::setMonth()
{
  int tempInt;
  cout << '\n' << setw(20) << left << "1. January" << setw(20) << "2. February" << setw(20) << "3. March" << setw(20) << "4. April" << endl
       << setw(20) << "5. May" << setw(20) << "6. June" << setw(20) << "7. July" << setw(20) << "8. August" << endl
       << setw(20) << "9. September" << setw(20) << "10. October" << setw(20) << "11. November" << setw(20) << "12. December"
       << endl;
  cout << "\nPlease enter the current month: ";
  while (!(cin >> tempInt) || tempInt < 1 || tempInt > 12)
  {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "\nPlease enter a valid month: ";
  }
  month = tempInt;
  cout << "\nMonth set!" << endl;
  return;
}

void Calendar::setDay()
{
  int tempInt;
  cout << "\nWhat day is it today? ";
  if (month == 2)
  while (!(cin >> tempInt || tempInt < 1 || tempInt > 28))
    {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "\nPlease make a valid entry: ";
    }
  else if (month == 4 || month == 6 || month == 9 || month == 11)
  {
    while (!(cin >> tempInt) || tempInt < 1 || tempInt > 30)
    {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "\nPlease make a valid entry: ";
    }
  }
  else
  {
    while (!(cin >> tempInt) || tempInt < 1 || tempInt > 31)
    {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "\nPlease make a valid entry: ";
    }
  }
  day = tempInt;
  cout << "\nDay set!" << endl;
  return;
}
