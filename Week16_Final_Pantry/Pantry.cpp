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
  if (toDelete)
    confirmErase();
  
  return expiredCount;
}

void Pantry::confirmErase()
{
  cout << "\nDo you want to throw out your expired food? ";
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
        storage.erase (storage.begin()+i);
        --i;  // To compensate for i being evaluated against a now shorter vector.
      }
    }
  }
  else { return; }
}
// The addFood() function should create a temporary food object,
// then store it in a vector.

// The addFood() function should
//  1. Create tmpFood
//  2. Get a string from the user for the food name
//  3. Set that name in the food object
//  4. Get a double for the price of the food
//  5. Set that price in the food object.
//      This is for accumulating food waste on tossed food later.
//  6. Call the tmpFood.setExYear/Month/Day() functions
//      These functions access the member variables of the Expiration
//      object expiration in the Food object.
// 7. 
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
  
  // Set Expiration Date
  storage[foodTracker].setExYear();
  storage[foodTracker].setExMonth();
  storage[foodTracker].setExDay();
  ++pantryItems;
  markExpired(cal);
}

//void Pantry::tossExpired(bool toShow, bool toErase)
//{
//  int exCount = 0;
//  for (int i = 0; i < storage.size(); i++)
//  {
//    // If the item is not currently marked as expired...
//    if (storage[i].getIsExpired())
//    {
//      if (toShow)
//      {
//        cout << ""
//      }
//    }
//  }
//}
// This function should be redundant as I've packed it into handleExpired()
//int Pantry::getExpCount()
//{
//  if (storage.size() == 0)
//    return 0;
//  int expCount = 0;
//  for (int i = 0; i < storage.size(); i++)
//  {
//    if (storage[i].getExpiry() == true)
//      ++expCount;
//  }
//  return expCount;
//}

/*int Pantry::getFoodInventory(bool toShow)
{
  // if to show is not on, just return itemcount
  if (storage.size() == 0)
  {
//    cout << "\nNo items in storage."
//         << "\nPress 'Enter' to continue...";
//    cin.clear();
//    cin.ignore(1000, '\n');
//    cin.get();
    return 0;
  }
  pantryItemCount = 0;
  for (int i = 0; i < storage.size(); i++)
  {
    ++pantryItemCount;
    if (toShow == true)
      cout << (i + 1) << ". " << storage[i].getName() << endl;
  }
  return pantryItemCount;
}*/

/*int Pantry::handleExpired(bool toShow, bool toDelete)
{
  // Add up expired
  if (storage.size() == 0)
    return 0;
  int expCount = 0;
  for (int i = 0; i < storage.size(); i++)
  {
    if (storage[i].getExpiry() == true)
      ++expCount;
    if (toShow == true)
    {
      cout << (i + 1) << ". " << storage[i].getName() << endl
                      << "\texpired on " << monthName(storage[i].getExpMonth())
                      << ' ' << storage[i].getExpDay() << ", "
                      << storage[i].getExpYear() << endl;
    }
  }
  if (toDelete == true)
  {
    cout << "\nDo you want to toss all expired food?";
    char userChar = '0';
    while (toupper(userChar) != 'Y' && toupper(userChar) != 'N')
    {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "\nThat is not a valid option. Please try again.";
    }
    if (toupper(userChar) != 'Y')
    {
      for (int i = 0; i < storage.size(); i++)
      {
        // This loop should erase all expired food in the vector
        if (storage[i].getExpiry() == true) // if expired food is enccountered
        { // Storage.erase(from storage[0] + current position (if i is [6], erase happens at [6])
          storage.erase(storage.begin() + (i));
          --i; // Set i -1, to counter the for loop +1 so that when the next elements move forward in
               // the vector, nothing gets skipped for checking. If we erase 6, then 7 becomes 6, but i
               // advances to 7, then the previous 7 (now 6) would be skipped.
        }
      }
    }
  }
  return expCount;
}

// Gets a Food from its own storage vector
// Gets Date handed to it from elsewhere???????????
void markExpired(Food f, Date d)
{
  if((d.getYear() > f.getExpYear()) ||
     ((d.getYear() == f.getExpYear()) && (d.getMonth() > f.getExpMonth())) ||
     ((d.getYear() == f.getExpYear()) && (d.getMonth() == f.getExpMonth()) && (d.getDay() >= f.getExpDay())))
    f.setExpired(true);
}

string Pantry::monthName(int m)
{
  switch (m)
  {
    case 1: return "January ";    // I believe I'm right in not
    case 2: return "February ";    // including "break" because
    case 3: return "March ";      // "return" will leave the function
    case 4: return "April ";
    case 5: return "May ";
    case 6: return "June ";
    case 7: return "July ";
    case 8: return "August ";
    case 9: return "September ";
    case 10: return "October ";
    case 11: return "November ";
    case 12: return "December ";
  }
  // The compiler complained that I did not have a return value in all control paths.
  return "I'm just doing this for the compiler's sake.";
}*/

//int Pantry::getInventory()
//{
//  pantryItemCount = 0;
//  for (int i = 0; i < storage.size(); i++)
//  {
//    ++pantryItemCount;
//  }
//  return pantryItemCount;
//}

//void Pantry::clearExpired()
//{
//
//}
//void Pantry::tossFood()
//{
//  int userChoice;
//	do{
//		// List expired
//		//  using for loop
//		if (!(storage.size() > 0))
//			return;
//		for (int i = 0; i < storage.size(); i++)
//		{
//			if (storage[i].getExpiry() == true)
//				cout << (i + 1) << ". " << storage[i].getName() << endl
//						 << "\texpired on " << monthName(storage[i].getExpMonth())
//						 << ' ' << storage[i].getExpDay() << ", "
//						 << storage[i].getExpYear() << endl;
//		}
//		// Prompt user
//		cout << "\nWhich item would you like to toss out?"
//				 << "\nChoose a number from the list above "
//				 << "(1 - " << storage.size() << " or 0 to quit: ";
//		// Get user response
//
//		while (!(cin >> userChoice) || userChoice < 0 || userChoice > storage.size())
//		{
//			cin.clear();
//			cin.ignore(1000, '\n');
//			cout << "Please make a valid selection: ";
//		}
//		if (userChoice == 0)
//			return;
//		char userChar = '0';
//    while (toupper(userChar) != 'Y' && toupper(userChar) != 'N')
//    {
//      cin.clear();
//      cin.ignore(1000, '\n');
//      cout << "\nThat is not a valid option. Please try again.";
//    }
//		if (toupper(userChar) != 'Y')
//			continue;
//		else
//		{
//			storage.erase(storage.begin() + (userChoice - 1));
//		}
//		// Delete vector element
//		// Loop until quit
//	}
//	while (!(userChoice == 0));
//}
