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

void Pantry::tossFood()
{
  // List expired
	//  using for loop
	if (!(storage.size() > 0))
		return;
	for (int i = 0; i < storage.size(); i++)
	{
		if (storage[i].expired == true)
			cout << (i + 1) << ". " << storage[i].name << endl
					 << "\texpired on " << monthName(Pantry::expir.getmonth())
					 << ' ' << Pantry::expir.getDay() << ", "
					 << Pantry::expir.getYear() << endl;
	}
	// Prompt user
	cout << "\nWhich item would you like to toss out?"
			 << "\nChoose a number from the list above "
			 << "(1 - " << storage.size() << 
	// Get user response
	// Are you sure?
	// Delete vector element
	// Loop until quit
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
}
