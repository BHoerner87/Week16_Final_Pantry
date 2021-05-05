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
#include "Functions.h"
#include "Kitchen.h"
#include "Pantry.h"
#include <iostream>

using namespace std;

int main()
{
  Kitchen k;
  Date d;
  d.setToday();
  int userChoice;
  do {
	userChoice = showMainMenu();
	switch(userChoice)
  {
    case 1: addO
  }
  
  } while (userChoice != 0);
  
  return 0;
}



void tossFood()
{
  cout << "\n1. Pantry"
       << "\n2. Refrigerator"
	   << "\n3. Freezer"
	   << "\n4. Toss all expired food\n"
	   << "\n0. Cancel\n"
       << "\nWhere do you want to toss food from? "
  int userChoice;
  while (!(cin >> userChoice) || userChoice < 0 || userChoice > 4)
  {
	cin.clear();
	cin.ignore(1000, '\n');
	cout << "\nPlease make a valid selection: ";
  }
  switch(userChoice)
  {
	case 1: // Call pantry's remove function
	case 2: // Call derived remove function
    case 3:	// Call derived remove function
	{
	  
	  break;
	}
	case 4:	// Toss all food
	{
	  break;
	}
	case 0: // Cancel
	{
      break;
	}
  }
}
