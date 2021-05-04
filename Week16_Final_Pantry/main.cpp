// Brian Hoerner
// CIS 1202.501
// 3 May 2021
// This Pantry Application will allow the user to keep track of his or her
// kitchen items and check their expiration dates against the current date
// to identify products which should be discarded.
// In a future version I would like the application to be able to suggest
// potential meals from available food items.
#include "Config.h"
#include "Date.h"
#include "Food.h"
#include "Kitchen.h"
#include "Pantry.h"
#include <iostream>

using namespace std;

int main()
{
  Kitchen k;
  Date d;
  d.setToday();
  do
  {
	int userChoice = showMainMenu();
	// switch(userChoice);
  } while (userChoice != 0);
  
  return 0;
}

int showMainMenu()
{
  int userChoice;
  
  cout << "\nMade it past the Today. Testing Expiration: \n";
  // What else needs to be done to set up before the main menu displays?
  // A function to update all inventory items' expiry booleans (this also runs at save time)
  cout << "\n\n-----------------------------------Main Menu------------------------------------\n\n";
  // Call function to 1. Check all inventory for expiration and 2. Update the static expired inventory variable
  // then 3. Display "\nYou have n expired items.\n\n"
  cout << "1. Check Kitchen Inventory\n"
       << "2. View expired\n"
	   << "3. Add or Toss Food\n"
	   << "4. Manage Data\n\n"
	   << "0. Quit Application";
}

int addOrTossMenu()
{
  int userChoice;
  cout << "1. Pantry\n"
	 << "2. Refrigerator\n"
	 << "3. Freezer\n\n"
	 << "0. Cancel\n\n"
	 << "Please make a selection from the menu above: "
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
	  addOrTossChoice(1);
	  break;
	}
	case 2: // refrigerator
	{
	  addOrTossChoice(2);
	  break;
	}
	case 3: // freezer
	{
	  addOrTossChoice(3);
	  break;
	}
	case 0; break; // Cancel
  }
}

int addOrTossChoice(int location)
{
  int userChoice;
  cout << "\n1. Add"
       << "\n2. Toss"
	   << "\n0. Cancel\n"
	   << "\nDo you want to add to your inventory or toss items? "
  while(!(cin >> userChoice) || userChoice < 0 || userChoice > 2)
  {
	cin.clear();
    cin.ignore(1000, '\n');
	cout << "Please make a valid selection: ";
  }
  switch (userChoice)
  case 1:
  { 
    
    break;
  }
  case 2:
  {
	
	break;
  }
  break;
  case 0: break; // Cancel
}

