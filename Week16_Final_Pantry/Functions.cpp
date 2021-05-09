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
#include "Food.h"
#include "Functions.h"
#include "Pantry.h"
#include <iomanip>
#include <iostream>

using namespace std;

int showMainMenu(Pantry &pantry, Refrigerator &fridge)
{
  int userChoice;
  cout << "\n\n-----------------------------------Main Menu------------------------------------\n\n";
  cout << "\nKitchen Inventory: " << (pantry.countFood(false) + fridge.countFood(false)); cout << "   "
       << "Expired Items: " << (pantry.countExpired(false, false) + fridge.countExpired(false, false));
  cout << "\nRunning Food Waste Tally: $" << (pantry.getWastePrice() + fridge.getWastePrice()) << endl << endl;
  cout << "1. Check Kitchen Inventory\n"
       << "2. Add Food\n"
       << "3. View Expired Food\n"
       << "4. Save Data\n"
       << "5. Load Data\n\n"
       << "0. Quit Application\n\n"
       << "Please choose from the menu above: ";
  while (!(cin >> userChoice) || userChoice < 0 || userChoice > 5)
  {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "\nPlease make a valid choice: ";
  }
  return userChoice;
}
