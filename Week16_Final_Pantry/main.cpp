// Brian Hoerner
// CIS 1202.501
// 3 May 2021
// This Pantry Application will allow the user to keep track of his or her
// kitchen items and check their expiration dates against the current date
// to identify products which should be discarded.
// In a future version I would like the application to be able to suggest
// potential meals from available food items.
#include "Calendar.h"
#include "Config.h"
#include "Food.h"
#include "Functions.h"
#include "Pantry.h"
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
  Pantry pantry;
  Calendar cal;
  Config config;
  
  cal.setToday();
  
  int userChoice;
  // Main menu loop
  do
  {
    // Update foods as expired before displaying anything
    // updateFunction()
    
    // pantry.countFood(false) is supposed to return a value and not print anything.
    cout << "\nKitchen Inventory: " << pantry.countFood(false); cout << "   "
         << "Expired Items: " << pantry.countExpired(false, false);
    
    // Call the main menu
    userChoice = showMainMenu();
    // Use returned int from main menu for switch
    switch(userChoice)
    {
      case 1: // Check Kitchen Inventory
        // the true bool has pantry.countFood() display what it is counting.
        pantry.countFood(true);
        break;
      case 2: // Add food
      {
        // Call the add food function from pantry.
        pantry.addFood(cal);
        break;
      }
      case 3: // Check Expired
      {
//        pantry.storageDebug();
        pantry.countExpired(true, true);
        break;
      }
      case 4: // Save Data
        config.saveData(pantry);
        break;
      case 5: // Load Data
        config.loadData(pantry);
        break;
      case 0: // End
        break;
    }
  } while (userChoice != 0);
  
  return 0;
}

//void addFood(int location, Date d, Kitchen &k)
//{
//  Food tmpFood;
//
//  cout << "\nWhat kind of food are you adding? ";
//  string tmpStr;
//  cin.clear();
//  cin.ignore(1000, '\n');
//  getline(cin, tmpStr);
//  tmpFood.setName(tmpStr);
//
//  cout << "\nWhat is the price of the food? ";
//  double tmpDouble;
//  while(!(cin >> tmpDouble))
//  {
//    cout << "\nPlease provide a valid price: ";
//  }
//  tmpFood.setPrice(tmpDouble);
//
//  cout << "\nIs this food item an entire meal? (Y / N): ";
//  char tmpChar = ' ';
//  do{ cin >> tmpChar; }
//  while(toupper(tmpChar) != 'Y' && toupper(tmpChar) != 'N'); // This needs validation
//  if (toupper(tmpChar) == 'Y')
//    tmpFood.setMeal(true);
//  else
//  {
//  tmpFood.setMeal(false);
//  }
//
//  cout << "\nLet's get the expiration date...\n";
//  cout << "\nWhat year does the food expire? ";
//  int tmpYear;
//  while (!(cin >> tmpYear) || tmpYear < d.getYear() || tmpYear > (d.getYear() + 50))  // xxxxxxx use of undeclared identifier 'd'
//  {
//    cin.clear();
//    cin.ignore(1000, '\n');
//    cout << "\nPlease enter a valid year: ";
//  }
//  tmpFood.setExpiryYear(tmpYear);
//
//  cout << "\n" << setw(20) << left << "1. January" << setw(20) << "2. February" << setw(20) << "3. March" << setw(20) << "4. April" << endl
//           << setw(20) << "5. May" << setw(20) << "6. June" << setw(20) << "7. July" << setw(20) << "8. August" << endl
//           << setw(20) << "9. September" << setw(20) << "10. October" << setw(20) << "11. November" << setw(20) << "12. December"
//           << endl;
//  cout << "\nWhat month does the food expire? ";
//  int tmpMonth;
//  while (!(cin >> tmpMonth) || tmpMonth < 1 || tmpMonth > 12)
//  {
//    cin.clear();
//    cin.ignore(1000, '\n');
//    cout << "\nPlease enter a valid month: ";
//  }
//  tmpFood.setExpiryMonth(tmpMonth);
//
//  cout << "\nWhat day does the food expire? ";
//  int tmpDay;
//  if(tmpMonth == 2)
//    while (!(cin >> tmpDay || tmpDay < 1 || tmpDay >28))
//    {
//      cin.clear();
//      cin.ignore(1000, '\n');
//      cout << "\nPlease make a valid entry: ";
//    }
//  else if(tmpMonth == 4 || tmpMonth == 6 || tmpMonth == 9 || tmpMonth == 11)
//  {
//  while (!(cin >> tmpDay || tmpDay < 1 || tmpDay >28))
//    {
//      cin.clear();
//      cin.ignore(1000, '\n');
//      cout << "\nPlease make a valid entry: ";
//
//    }
//  }
//  else
//  {
//  while (!(cin >> tmpDay) || tmpDay < 1 || tmpDay > 31)
//  {
//    cin.clear();
//      cin.ignore(1000, '\n');
//      cout << "\nPlease make a valid entry: ";
//    }
//  }
//  tmpFood.setExpiryDay(tmpDay);
//
//  cout << "\n1. Room temperature"
//       << "\n2. Refrigerated"
//       << "\n3. Frozen\n"
//       << "\nPlease specify the temperature at which the food"
//       << "\nmust be stored: ";
//  int storageChoice;
//  while (!(cin >> storageChoice) || storageChoice < 1 || storageChoice > 3)
//  {
//  cin.clear();
//  cin.ignore(1000, '\n');
//  cout << "\nPlease make a valid selection: ";
//  }
//  switch(storageChoice)
//  {
//    case 1:
//      break;
//    case 2:
//      tmpFood.setCold(true);
//      break;
//    case 3:
//      tmpFood.setFrozen(true);
//    break;
//  }
//
//  // Place Food
//  switch(location)
//  {
//    case 1:
//    {
//      if (tmpFood.coldValue() == true)
//      {
//        cout << "\nYou cannot place cold food in the pantry.";
//        k.storeFoodR(tmpFood);
//        cout << "\nYour " << tmpFood.getName() << " was placed in the refrigerator.";
//        break;
//      }
//      else if (tmpFood.frozenValue() == true)
//      {
//        cout << "\nYou cannot place frozen food in the pantry.";
//        k.storeFoodF(tmpFood);
//        cout << "\nYour " << tmpFood.getName() << " was placed in the freezer.";
//        break;
//      }
//      else
//      {
//        k.storeFoodP(tmpFood);
//        cout << "\nYour " << tmpFood.getName() << " was placed in the pantry.";
//      }
//      break;
//    }
//    case 2:
//    {
//      if (tmpFood.frozenValue() == true)
//      {
//        cout << "\nYou likely should not place frozen food in the pantry."
//             << "\nAre you sure you want to do this? ";
//        do{ cin >> tmpChar; }
//        while(toupper(tmpChar) != 'Y' && toupper(tmpChar) != 'N');
//        if (toupper(tmpChar) == 'N')
//        {
//          k.storeFoodF(tmpFood);
//          cout << "\nYour " << tmpFood.getName() << " was placed in the refrigerator.";
//          break;
//
//        }
//        else{ k.storeFoodR(tmpFood); }
//        cout << "\nYour " << tmpFood.getName() << " was placed in the freezer.";
//      }
//      break;
//    }
//    case 3:
//    {
//      k.storeFoodF(tmpFood);
//      cout << "\nYour " << tmpFood.getName() << " was placed in the freezer.";
//      break;
//    }
//  }
//  cout << "\nPress Enter to continue...";
//  cin.clear();
//  cin.ignore(1000, '\n');
//  cin.get();
//}

//void tossFood(int location, Date d, Kitchen &k)
//{
//  cout << "\n1. Pantry"
//       << "\n2. Refrigerator"
//       << "\n3. Freezer"
//       << "\n4. Toss all expired food\n"
//       << "\n0. Cancel\n"
//       << "\nWhere do you want to toss food from? ";
//  int userChoice;
//  while (!(cin >> userChoice) || userChoice < 0 || userChoice > 4)
//  {
//  cin.clear();
//  cin.ignore(1000, '\n');
//  cout << "\nPlease make a valid selection: ";
//  }
//  switch(location)
//  {
//  case 1: // Call pantry's remove function
//  case 2: // Call fridge remove function
//  case 3:  // Call freezer remove function
//  {
//
//    break;
//  }
//  case 0: // Cancel
//  {
//      break;
//  }
//  }
//}
