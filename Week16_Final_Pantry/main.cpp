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
  Refrigerator fridge;
  
  Calendar cal;
  Config config;
  
  cal.setToday();
  
  int userChoice;
  // Main menu loop
  do
  {
    userChoice = showMainMenu(pantry, fridge);
    
    switch(userChoice)
    {
      case 1: // Check Kitchen Inventory
        // the true bool has pantry.countFood() display what it is counting.
        cout << "\nPantry:\n";
        pantry.countFood(true);
        cout << "\nRefrigerator:\n";
        fridge.countFoodR(true);
        break;
      case 2: // Add food
      {
        cout << "\nDoes the food need to be stored cold? (Y / N): ";
        char userChar = '0';
        while (!(cin >> userChar) || (toupper(userChar) != 'Y' && toupper(userChar) != 'N'))
        {
          cin.clear();
          cin.ignore(1000, '\n');
          cout << "\nPlease enter 'Y' or 'N': ";
        }
        if (userChar == 'Y')   // This is supposed to put food in the fridge.
        {                      // Something about this is messed up and still
          fridge.addFoodR(cal);// placing things in the Pantry.
        }
        else{ pantry.addFood(cal); }
        break;
      }
      case 3: // Check Expired
      {
        pantry.countExpired(true, true);
        break;
      }
      case 4: // Save Data
        pantry.countFood();
        fridge.countFoodR();
        config.saveTextData(pantry.getPantryItems(), fridge.getColdItems());
        config.saveBinData(pantry, fridge);
        break;
      case 5: // Load Data
        config.loadTextData(pantry, fridge);
        config.loadBinData(pantry, fridge);
        break;
      case 6: // Debug Display
        cout << "\nPantry storage: " << pantry.getPantryItems();
        cout << "\nFridge storage: " << fridge.getColdItems();
        break;
      case 0: // End
        break;
    }
  } while (userChoice != 0);
  
  return 0;
}
