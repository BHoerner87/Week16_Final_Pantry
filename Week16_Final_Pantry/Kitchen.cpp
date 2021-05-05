//
//  Kitchen.cpp
//  Week16_Final_Pantry
//
//  Created by Brian Hoerner on 5/3/21.
//

#include "Kitchen.h"

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
