//
//  Config.hpp
//  Week16_Final_Pantry
//
//  Created by Brian Hoerner on 5/9/21.
//

#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <fstream>

#include "Pantry.h"
#include "Food.h"

class Config
{
private:
  bool saved;

public:
  Config()
  {
    saved = false;
  }
  void saveData(Pantry p)
  {
    // Write pantry items
    std::ofstream writeOut("config.dat", std::ios::out | std::ios::binary);
    if(!writeOut)
    {
      std::cout << "\nError opening file." << std::endl;
      return;
    }
    int tempInt = p.getPantryItems();
    writeOut.write((char *) &tempInt, sizeof(tempInt));
    for (int i = 0; i < tempInt; i++)
    {
      writeOut.write((char *) &p.storage[i], sizeof(&p.storage[i]));
    }
    if(!writeOut.good())
    {
      std::cout << "\nProblem writing file.";
    }
    writeOut.close();
    saved = true;
    std::cout << "\nData saved!";
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "\nPresse 'Enter' to continue...";
    std::cin.get();
  }
  void loadData(Pantry &p)
  {
    std::ifstream readIn("config.dat", std::ios::out | std::ios::binary);
    if(!readIn)
    {
      std::cout << "\nError reading file." << std::endl;
      return;
    }
    char * ch;
    readIn.read((char *) &ch, sizeof(p.getPantryItems()));
    p.setPantryItems((int)(size_t) ch);
    for(int i = 0; i < p.getPantryItems(); i++)
    {
      try
      {
        Food tempFood;
        readIn.read((char *) &tempFood, sizeof(tempFood));
        p.storeFood(tempFood);
        throw (0);
      }
      catch(int errorInt)
      {
        std::cout << "\nError reading in data.";
      }
    }
    readIn.close();
  }
};

#endif /* Config_hpp */
