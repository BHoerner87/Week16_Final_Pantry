//
//  Pantry.cpp
//  Week16_Final_Pantry
//
//  Created by Brian Hoerner on 5/3/21.
//
#include <iomanip>
#include <iostream>
#include "Pantry.h"

using namespace std;

int Pantry::countFood(bool toShow)  // Overloaded function
{
  int foodCount = 0;
  for (int i = 0; i < storage.size(); i++)
  {
    // On each iteration, accumulate foodCount for inventory's sake
    ++foodCount;
    // If toShow is set to true, this should output stored food information.
    if (toShow)
      cout << (i + 1) << ". " << storage[i].getName() << endl;
  }
  return foodCount;
}

int Refrigerator::countFood(bool toShow)  // Overloaded function
{
  int foodCount = 0;
  for (int i = 0; i < coldStorage.size(); i++)
  {
    // On each iteration, accumulate foodCount for inventory's sake
    ++foodCount;
    // If toShow is set to true, this should output stored food information.
    if (toShow)
      cout << (i + 1) << ". " << coldStorage[i].getName() << endl;
  }
  return foodCount;
}

void Pantry::markExpired(Calendar &c)
{
  for (int i = 0; i < storage.size(); i++)
  {
    // If current year bigger than expiration year set expired to true
    if (c.getYear() > storage[i].getExYear())
      storage[i].setIsExpired(true);
    // If current year same, current month bigger
    else if (c.getYear() == storage[i].getExYear() && c.getMonth() > storage[i].getExMonth())
      storage[i].setIsExpired(true);
    // If current year, month same; current day bigger
    else if (c.getYear() == storage[i].getExYear() &&
        c.getMonth() > storage[i].getExMonth() && c.getDay() >= storage[i].getExDay())
      storage[i].setIsExpired(true);
    else { storage[i].setIsExpired(false); }
  }
}

void Refrigerator::markExpired(Calendar &c)
{
  for (int i = 0; i < coldStorage.size(); i++)
  {
    // If current year bigger than expiration year set expired to true
    if (c.getYear() > coldStorage[i].getExYear())
      coldStorage[i].setIsExpired(true);
    // If current year same, current month bigger
    else if (c.getYear() == coldStorage[i].getExYear() && c.getMonth() > coldStorage[i].getExMonth())
      coldStorage[i].setIsExpired(true);
    // If current year, month same; current day bigger
    else if (c.getYear() == coldStorage[i].getExYear() &&
        c.getMonth() > coldStorage[i].getExMonth() && c.getDay() >= coldStorage[i].getExDay())
      coldStorage[i].setIsExpired(true);
    else { coldStorage[i].setIsExpired(false); }
  }
}

int Pantry::countExpired(bool toShow, bool toDelete)
{
  int expiredCount = 0;
  for (int i = 0; i < storage.size(); i++)
  {
    if(storage[i].getIsExpired() == true)
    {
      // Accumulate expiredCount
      ++expiredCount;
      // if toShow, print the item and its expiration date
      if (toShow)
      {
      cout << (i + 1) << ". " << storage[i].getName() << endl
           << "    expired on ";
        // Exchange an integer month value for the month's name
      int m = storage[i].getExMonth();
        {
          switch (m)
          {
            case 1: cout << "January "; break;
            case 2: cout << "February "; break;
            case 3: cout << "March "; break;
            case 4: cout << "April "; break;
            case 5: cout << "May "; break;
            case 6: cout << "June "; break;
            case 7: cout << "July "; break;
            case 8: cout << "August "; break;
            case 9: cout << "September "; break;
            case 10: cout << "October "; break;
            case 11: cout << "November "; break;
            case 12: cout << "December "; break;
            default: cout << "Invalid month "; break;
          }
        }
        cout << ' ' << storage[i].getExDay() << ", " << storage[i].getExYear() << endl;
      }
    }
  }
  if (toDelete && expiredCount > 0)
    confirmErase();
  
  return expiredCount;
}

int Refrigerator::countExpired(bool toShow, bool toDelete)
{
  int expiredCount = 0;
  for (int i = 0; i < coldStorage.size(); i++)
  {
    if(coldStorage[i].getIsExpired() == true)
    {
      // Accumulate expiredCount
      ++expiredCount;
      // if toShow, print the item and its expiration date
      if (toShow)
      {
      cout << (i + 1) << ". " << coldStorage[i].getName() << endl
           << "    expired on ";
        // Exchange an integer month value for the month's name
      int m = coldStorage[i].getExMonth();
        {
          switch (m)
          {
            case 1: cout << "January "; break;
            case 2: cout << "February "; break;
            case 3: cout << "March "; break;
            case 4: cout << "April "; break;
            case 5: cout << "May "; break;
            case 6: cout << "June "; break;
            case 7: cout << "July "; break;
            case 8: cout << "August "; break;
            case 9: cout << "September "; break;
            case 10: cout << "October "; break;
            case 11: cout << "November "; break;
            case 12: cout << "December "; break;
            default: cout << "Invalid month "; break;
          }
        }
        cout << ' ' << coldStorage[i].getExDay() << ", " << coldStorage[i].getExYear() << endl;
      }
    }
  }
  if (toDelete && expiredCount > 0)
    Refrigerator::confirmErase();
  
  return expiredCount;
}

void Pantry::confirmErase()
{
  cout << "\nDo you want to throw out your expired food? (Y / N): ";
  char userChoice = '0';
  while(!(cin >> userChoice) || (toupper(userChoice) != 'Y' && toupper(userChoice) != 'N'))
  {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Please choose 'Y' or 'N': ";
  }
  if (toupper(userChoice) == 'Y')
  {
    for (int i = 0; i < storage.size(); i++)
    {
      if (storage[i].getIsExpired() == true)
      {
        wastePrice += storage[i].getPrice();
        storage.erase (storage.begin()+i);
        --i;  // To compensate for i being evaluated against a now shorter vector.
      }
    }
    return ;
  }
  else { return; }
}

void Refrigerator::confirmErase()
{
  cout << "\nDo you want to throw out your expired food? (Y / N): ";
  char userChoice = '0';
  while(!(cin >> userChoice) || (toupper(userChoice) != 'Y' && toupper(userChoice) != 'N'))
  {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Please choose 'Y' or 'N': ";
  }
  if (toupper(userChoice) == 'Y')
  {
    for (int i = 0; i < coldStorage.size(); i++)
    {
      if (coldStorage[i].getIsExpired() == true)
      {
        coldWastePrice += coldStorage[i].getPrice();
        coldStorage.erase (coldStorage.begin()+i);
        --i;  // To compensate for i being evaluated against a now shorter vector.
      }
    }
    return ;
  }
  else { return; }
}

void Pantry::addFood(Calendar &cal)
{
  Food tmpFood;
  storeFood(tmpFood);
  int foodTracker = -1;
  for (int i = 0; i < storage.size(); i++)
  {
    ++foodTracker;
  }
  cout << "\nWhat kind of food are you adding? ";
  string tmpStr;
  cin.clear();
  cin.ignore(1000, '\n');
  getline(cin, tmpStr);
  storage[foodTracker].setName(tmpStr);

  cout << "\nWhat is the price of the food? ";
  double tmpDouble;
  while(!(cin >> tmpDouble))
  {
    cout << "\nPlease provide a valid price: ";
  }
  
  storage[foodTracker].setPrice(tmpDouble);
  storage[foodTracker].setExYear();
  storage[foodTracker].setExMonth();
  storage[foodTracker].setExDay();
  ++pantryItems;
  markExpired(cal);
}


void Refrigerator::addFood(Calendar &cal)
{
  Food tmpFood;
  storeFood(tmpFood);
  int foodTracker = -1;
  for (int i = 0; i < coldStorage.size(); i++)
  {
    ++foodTracker;
  }
  cout << "\nWhat kind of cold food are you adding? ";
  string tmpStr;
  cin.clear();
  cin.ignore(1000, '\n');
  getline(cin, tmpStr);
  coldStorage[foodTracker].setName(tmpStr);

  cout << "\nWhat is the price of the food? ";
  double tmpDouble;
  while(!(cin >> tmpDouble))
  {
    cout << "\nPlease provide a valid price: ";
  }
  
  coldStorage[foodTracker].setPrice(tmpDouble);
  coldStorage[foodTracker].setExYear();
  coldStorage[foodTracker].setExMonth();
  coldStorage[foodTracker].setExDay();
  ++coldItems;
  markExpired(cal);
}
