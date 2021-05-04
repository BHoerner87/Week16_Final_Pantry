// Brian Hoerner
// CIS 1202.501
// 3 May 2021
// This Pantry Application will allow the user to keep track of his or her
// kitchen items and check their expiration dates against the current date
// to identify products which should be discarded.
// In a future version I would like the application to be able to suggest
// potential meals from available food items.
#include "Date.h"
#include <iostream>

using namespace std;

int main()
{
  Date d;
  d.setToday();
  cout << "\nMade it past the Today. Testing Expiration: \n";
  Expiration e;
  e.setExpiry();
  cout << "\nMade it through expiry setting. Exiting program.";
  return 0;
}

void setupKitchen()
{
  
}
