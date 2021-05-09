//
//  Functions.cpp
//  Week16_Final_Pantry
//
//  Created by Brian Hoerner on 5/5/21.
//

#include "Calendar.h"
#include "Food.h"
#include "Functions.h"
#include <iomanip>
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
       << "2. Add Food\n"
       << "3. View Expired Food\n"
       << "4. Save Data\n"
       << "5. Load Data\n\n"
       << "0. Quit Application\n\n"
       << "Please choose from the menu above: ";
  while (!(cin >> userChoice) || userChoice < 0 || userChoice > 6)
  {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "\nPlease make a valid choice: ";
  }
  return userChoice;
}
