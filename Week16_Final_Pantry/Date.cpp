//
//  Calendar.cpp
//  Week16_Final_Pantry
//
//  Created by Brian Hoerner on 5/3/21.
//

#include "Date.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Destructor

// Date Implementations
void Date::setYear()
{
  cout << "\nPlease enter the current year: ";
  while (!(cin >> Date::year) || Date::year < 2021 || Date::year > 2099)
  {
    cout << "\nPlease make a valid entry: ";
  }
}

void Date::setMonth()
{
  cout << setw(20) << left << "1. January" << setw(20) << "2. February" << setw(20) << "3. March" << setw(20) << "4. April" << endl
           << setw(20) << "5. May" << setw(20) << "6. June" << setw(20) << "7. July" << setw(20) << "8. August" << endl
           << setw(20) << "9. September" << setw(20) << "10. October" << setw(20) << "11. November" << setw(20) << "12. December"
           << endl;
  cout << "\nPlease enter the current month: ";
  while (!(cin >> Date::month) || Date::month < 1 || Date::month > 12)
  {
    cout << "\nPlease make a valid entry: ";
  }
}

void Date::setDay()
{
  cout << "\nPlease enter the current day: ";
  if (Date::month == 2)
    while (!(cin >> Date::day || Date::day < 1 || Date::day >28))
    {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\nPlease make a valid entry: ";
      
    }
  else if (Date::month == 4 || Date::month == 6 || Date::month == 9 || Date::month == 11)
  {
    while (!(cin >> Date::day) || Date::day < 1 || Date::day > 30)
    {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\nPlease make a valid entry: ";
    }
  }
  else
    while (!(cin >> Date::day) || Date::day < 1 || Date::day > 31)
    {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\nPlease make a valid entry: ";
    }
}

// Expiration Implementations
void Expiration::setYear(int y)
{ Expiration::year = y; }
void Expiration::setYear()
{
  cout << "\nPlease enter the expiration date year: ";
  while (!(cin >> Expiration::year) || Expiration::year < 2021 || Expiration::year > (year + 50)) // Grains like rice can last this long when stored properly, but let's be realistic here...
  {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "\nPlease make a valid entry: ";
  }
}
void Expiration::setMonth(int m)
{ Expiration::month = m; }
void Expiration::setMonth()
{
  cout << setw(20) << left << "1. January" << setw(20) << "2. February" << setw(20) << "3. March" << setw(20) << "4. April" << endl
           << setw(20) << "5. May" << setw(20) << "6. June" << setw(20) << "7. July" << setw(20) << "8. August" << endl
           << setw(20) << "9. September" << setw(20) << "10. October" << setw(20) << "11. November" << setw(20) << "12. December"
           << endl;
  cout << "\nPlease enter the expiration month: ";
  while (!(cin >> Expiration::month) || Expiration::month < 1 || Expiration::month > 12)
  {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "\nPlease make a valid entry: ";
  }
}

void Expiration::setDay(int d)
{ Expiration::day = d; }
void Expiration::setDay()
{
  cout << "\nPlease enter the current day: ";
  if (Expiration::month == 2)
    while (!(cin >> Expiration::day || Expiration::day < 1 || Expiration::day >28))
    {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\nPlease make a valid entry: ";
    }
  else if (Expiration::month == 4 || Expiration::month == 6 || Expiration::month == 9 || Expiration::month == 11)
  {
    while (!(cin >> Expiration::day) || Expiration::day < 1 || Expiration::day > 30)
    {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\nPlease make a valid entry: ";
    }
  }
  else
    while (!(cin >> Expiration::day) || Expiration::day < 1 || Expiration::day > 31)
    {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\nPlease make a valid entry: ";
    }
}
