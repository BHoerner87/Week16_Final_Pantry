//
//  Pantry.cpp
//  Week16_Final_Pantry
//
//  Created by Brian Hoerner on 5/3/21.
//
#include <iomanip>
#include <iostream>
#include "Pantry.h"

using namespace std;

void addFood(int location)
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

void Pantry::tossFood()
{
  int userChoice;
	do{
		// List expired
		//  using for loop
		if (!(storage.size() > 0))
			return;
		for (int i = 0; i < storage.size(); i++)
		{
			if (storage[i].getExpiry() == true)
				cout << (i + 1) << ". " << storage[i].getName() << endl
						 << "\texpired on " << monthName(storage[i].getExpMonth())
						 << ' ' << storage[i].getExpDay() << ", "
						 << storage[i].getExpYear() << endl;
		}
		// Prompt user
		cout << "\nWhich item would you like to toss out?"
				 << "\nChoose a number from the list above "
				 << "(1 - " << storage.size() << " or 0 to quit: ";
		// Get user response
		
		while (!(cin >> userChoice) || userChoice < 0 || userChoice > storage.size())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Please make a valid selection: ";
		}
		if (userChoice == 0)
			return;
		char userChar = '0';
    while (toupper(userChar) != 'Y' && toupper(userChar) != 'N')
    {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "\nThat is not a valid option. Please try again.";
    }
		if (toupper(userChar) != 'Y')
			continue;
		else
		{
			storage.erase(storage.begin() + (userChoice - 1));
		}
		// Delete vector element
		// Loop until quit
	}
	while (!(userChoice == 0));
}

string Pantry::monthName(int m)
{
	switch (m)
	{
		case 1: return "January ";		// I believe I'm right in not
		case 2: return "February ";		// including "break" because
		case 3: return "March ";			// "return" will leave the function
		case 4: return "April ";
		case 5: return "May ";
		case 6: return "June ";
		case 7: return "July ";
		case 8: return "August ";
		case 9: return "September ";
		case 10: return "October ";
		case 11: return "November ";
		case 12: return "December ";
  }
  // The compiler complained that I did not have a return value in all control paths.
  return "I'm just doing this for the compiler's sake.";
}
