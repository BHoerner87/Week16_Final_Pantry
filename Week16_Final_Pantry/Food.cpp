//
//  Food.cpp
//  Week16_Final_Pantry
//
//  Created by Brian Hoerner on 5/3/21.
//

#include "Food.h"

using namespace std;

void addItem()
{
  // Create new instance
  Food *foodItem = new Food;
  // Set name
  cout << "\nWhat is the name of the item you are adding? ";
  string tmpName = "";
  getline(cin, tmpName);
  setName(tmpName);
  cout << "\n"
  // Call Expiration setter function or something I don't know
  // Set quantity
  // Probably package all this stogether, eh? Or no, it should
  // probably be menu-driven so you can overwrite / update things.

}
