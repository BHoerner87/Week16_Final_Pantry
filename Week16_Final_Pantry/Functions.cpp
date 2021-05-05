//
//  Functions.cpp
//  Week16_Final_Pantry
//
//  Created by Brian Hoerner on 5/5/21.
//

#include "Date.h"
#include "Food.h"
#include "Functions.h"
#include "Kitchen.h"
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
  case 0: return; // Cancel // xxxxxxx expected a ';' after case
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

void addFood(int location, Date d, Kitchen &k)
{
  Food tmpFood;
  
  cout << "\nWhat kind of food are you adding? ";
  string tmpStr;
  getline(cin, tmpStr);
  tmpFood.setName(tmpStr);
  
  cout << "\nWhat is the price of the food?";
  double tmpDouble;
  while(!(cin >> tmpDouble))
  {
    cout << "\nPlease provide a valid price: ";
  }
  tmpFood.setPrice(tmpDouble);          // xxxxxxx no member called "setPrice" in Food
  
  cout << "Is this food item an entire meal? (Y / N)";
  char tmpChar = ' ';
  do{ cin >> tmpChar; }
  while(toupper(tmpChar) != 'Y' || toupper(tmpChar) != 'N');
  if (toupper(tmpChar) == 'Y')
    tmpFood.setMeal(true);
  else
  {
  tmpFood.setMeal(false);
  }
  
  cout << "\n1. Room temperature"
       << "\n2. Refrigerated"
     << "\n3. Frozen\n"
     << "\nPlease specify the temperature at which the food"
     << "\nmust be stored: ";
  int storageChoice;
  while (!(cin >> storageChoice) || storageChoice < 1 || storageChoice > 3)
  {
  cin.clear();
  cin.ignore(1000, '\n');
  cout << "\nPlease make a valid selection: ";
  }
  switch(storageChoice)
  {
    case 1:
      break;
    case 2:
      tmpFood.setCold(true);
      break;
    case 3:
      tmpFood.setFrozen(true);
    break;
  }
  
  cout << "\nLet's get the expiration date...\n";
  cout << "\nWhat year does the food expire? ";
  int tmpYear;
  while (!(cin >> tmpYear) || tmpYear < d.getYear() || tmpYear > (d.getYear() + 50))  // xxxxxxx use of undeclared identifier 'd'
  {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "\nPlease enter a valid year: ";
  }
  tmpFood.setExpiryYear(tmpYear);
  
  cout << setw(20) << left << "1. January" << setw(20) << "2. February" << setw(20) << "3. March" << setw(20) << "4. April" << endl
           << setw(20) << "5. May" << setw(20) << "6. June" << setw(20) << "7. July" << setw(20) << "8. August" << endl
           << setw(20) << "9. September" << setw(20) << "10. October" << setw(20) << "11. November" << setw(20) << "12. December"
           << endl;
  cout << "\nWhat month does the food expire? ";
  int tmpMonth;
  while (!(cin >> tmpMonth) || tmpMonth < 1 || tmpMonth > 12)
  {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "\nPlease enter a valid month: ";
  }
  tmpFood.setExpiryMonth(tmpMonth);
  
  cout << "\nWhat day does the food expire? ";
  int tmpDay;
  if(tmpMonth == 2)
    while (!(cin >> tmpDay || tmpDay < 1 || tmpDay >28))
    {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "\nPlease make a valid entry: ";
    }
  else if(tmpMonth == 4 || tmpMonth == 6 || tmpMonth == 9 || tmpMonth == 11)
  {
  while (!(cin >> tmpDay || tmpDay < 1 || tmpDay >28))
    {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "\nPlease make a valid entry: ";
      
    }
  }
  else
  {
  while (!(cin >> tmpDay) || tmpDay < 1 || tmpDay > 31)
  {
    cin.clear();
      cin.ignore(1000, '\n');
      cout << "\nPlease make a valid entry: ";
    }
  }
  tmpFood.setExpiryDay(tmpDay);
  
  // Place Food
  switch(destination)
    {
    case 1:
    {
      pantry.storage.push_back(tmpFood);
      break;
    }
    case 2:
    {
      refrigerator.storage.push_back(tmpFood);
      break;
    }
    case 3:
      {
      freezer.storage.push_back(tmpFood);
      break;
    }
  }
}
