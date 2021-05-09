// Brian Hoerner
// CIS 1202.501
// 3 May 2021

// This application is meant to track the inventory of one's kitchen perishables,
// including and especially when they expire. It is meant to be an aid for
// keeping a tidy kitchen, and for curbing one's over-buying habits to
// prevent food waste. Menu navigation is performed by entering numbers
// from menus of options, or by entering Y / N chars when provided with
// yes-no choices.

#include <iostream>
#include <iomanip>
#include "Food.h"

using namespace std;

void Food::setExYear()
{
  int tempInt;
  cout << "\nWhat is the expiration year? ";
  while (!(cin >> tempInt) || tempInt < 2021 || tempInt > (2036))
  {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "\nPlease enter a valid year: ";
  }
  exYear = tempInt;
  cout << "\nExpiration year set!\n";
}

void Food::setExMonth()
{
  int tempInt;
  cout << '\n' << setw(20) << left << "1. January" << setw(20) << "2. February"
       <<            setw(20) << "3. March" << setw(20) << "4. April" << endl
       << setw(20) << "5. May" << setw(20) << "6. June" << setw(20) << "7. July"
       << setw(20) << "8. August" << endl << setw(20) << "9. September" << setw(20)
       << "10. October" << setw(20) << "11. November" << setw(20) << "12. December"
       << endl;
  cout << "\nWhat is the expiration month? ";
  while (!(cin >> tempInt) || tempInt < 1 || tempInt > 12)
  {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "\nPlease enter a valid month: ";
  }
  exMonth = tempInt;
  cout << "\nExpiration Month set!\n";
  return;
}

void Food::setExDay()
{
  int tempInt;
  cout << "\nOn what day does the food expire? ";
  
  if (exMonth == 2)
  {
    while (!(cin >> tempInt || tempInt < 1 || tempInt > 28))
    {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\nPlease make a valid entry: ";
    }
  }
  else if (exMonth == 4 || exMonth == 6 || exMonth == 9 || exMonth == 11)
  {
    while (!(cin >> tempInt) || tempInt < 1 || tempInt > 30)
    {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\nPlease make a valid entry: ";
    }
  }
  else
  {
    while (!(cin >> tempInt) || tempInt < 1 || tempInt > 31)
    {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\nPlease make a valid entry: ";
    }
  }
  exDay = tempInt;
  cout << "\nExpiration Date set!";
  return;
}
