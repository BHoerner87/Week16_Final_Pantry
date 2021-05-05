//
//  Functions.cpp
//  Week16_Final_Pantry
//
//  Created by Brian Hoerner on 5/5/21.
//

#include "Functions.h"
#include <iostream>

using namespace std;

int showMainMenu()
{
  // What else needs to be done to set up before the main menu displays?
  // A function to update all inventory items' expiry booleans (this also runs at save time)
  int userChoice;
  cout << "\n\n-----------------------------------Main Menu------------------------------------\n\n";
  // Call function to 1. Check all inventory for expiration and 2. Update the static expired inventory variable
  // then 3. Display "\nYou have n expired items.\n\n"
  cout << "1. Check Kitchen Inventory\n"
       << "2. View expired\n"
     << "3. Add or Toss Food\n"
     << "4. Manage Data\n\n"
     << "0. Quit Application\n\n"
     << "Please choose from the menu above: ";
  while (!(cin >> userChoice) || userChoice < 0 || userChoice > 4)
  {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "\nPlease make a valid choice: ";
  }
  return userChoice;
}

void addOrTossMenu()
{
  int userChoice;
  cout << "1. Pantry\n"
   << "2. Refrigerator\n"
   << "3. Freezer\n\n"
   << "0. Cancel\n\n"
   << "Please make a selection from the menu above: ";
  while(!(cin >> userChoice) || userChoice < 0 || userChoice > 3)
  {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Please make a valid selection: ";
  }
  switch (userChoice)
  {
  case 1: // pantry
  {
    addOrTossChoice(1); // xxxxxxxx Use of an undeclared specifier 'addOrTossChoice'
    break;
  }
  case 2: // refrigerator
  {
    addOrTossChoice(2); // xxxxxxxx Use of an undeclared specifier 'addOrTossChoice'
    break;
  }
  case 3: // freezer
  {
    addOrTossChoice(3); // xxxxxxxx Use of an undeclared specifier 'addOrTossChoice'
    break;
  }
  case 0: break; // Cancel // xxxxxxx expected a ';' after case
  }
}

int addOrTossChoice(int location)
{
  int userChoice;
  cout << "\n1. Add"
       << "\n2. Toss"
       << "\n0. Cancel\n"
       << "\nDo you want to add to your inventory or toss items? ";
  while(!(cin >> userChoice) || userChoice < 0 || userChoice > 2)
  {
  cin.clear();
    cin.ignore(1000, '\n');
  cout << "Please make a valid selection: ";
  }
  switch (userChoice)
  {
    case 1:
    {
      addFood(location);  // xxxxxxxxxx Use of an undeclared identifier addFood()
      break;
    }
    case 2:
    {
    
    break;
    }
    break;
    case 0: break; // Cancel
  }
}
