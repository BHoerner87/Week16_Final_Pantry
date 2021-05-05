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
#include <iomanip>
#include <iostream>

using namespace std;

void addFood(int location, Date d, Kitchen &k);

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
       << "\nWhere do you want to toss food from? ";
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
