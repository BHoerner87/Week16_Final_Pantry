//
//  Functions.hpp
//  Week16_Final_Pantry
//
//  Created by Brian Hoerner on 5/5/21.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Date.h"
#include "Kitchen.h"

int showMainMenu();
void addOrTossMenu();
int addOrTossChoice(int);
void addFood(int location, Date d, Kitchen &k);


#endif /* Functions_hpp */
