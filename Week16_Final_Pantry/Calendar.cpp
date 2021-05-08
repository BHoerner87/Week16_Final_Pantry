//
//  Calendar.cpp
//  Week16_Final_Pantry
//
//  Created by Brian Hoerner on 5/7/21.
//

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
  cout << "\nWhat day of the month is it today? ";
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

void Expiration::setExYear()
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

void Expiration::setExMonth()
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

void Expiration::setExDay()
{
  int tempInt;
  cout << "\nWhat day of the month does the food expire? ";
  if (getExMonth() == 2)
  while (!(cin >> tempInt || tempInt < 1 || tempInt > 28))
    {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\nPlease make a valid entry: ";
    }
  else if (getExMonth() == 4 || getExMonth() == 6 || getExMonth() == 9 || getExMonth() == 11)
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
