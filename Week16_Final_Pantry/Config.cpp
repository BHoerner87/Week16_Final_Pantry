// Brian Hoerner
// CIS 1202.501
// 3 May 2021

// This application is meant to track the inventory of one's kitchen perishables,
// including and especially when they expire. It is meant to be an aid for
// keeping a tidy kitchen, and for curbing one's over-buying habits to
// prevent food waste. Menu navigation is performed by entering numbers
// from menus of options, or by entering Y / N chars when provided with
// yes-no choices.

#include "Config.h"
#include "Pantry.h"

using namespace std;

void Config::saveTextData(int p, int r)
{
  // Write pantry items
  std::ofstream writeOut("config.txt", std::ios::out);
  if(!writeOut)
  {
    std::cout << "\nError opening file to write." << std::endl;
    return;
  }
  writeOut << p << endl << r;
  cout << "\nText data written. ";
  writeOut.close();
}

void Config::saveBinData(Pantry &p, Refrigerator &r)
{
  std::ofstream writeOut("pantry.dat", std::ios::out | std::ios::binary);
  if(!writeOut)
  {
    std::cout << "\nError opening file to write." << std::endl;
    return;
  }
  {
    for(int i = 0; i < p.storage.size(); i++)
    {
      writeOut.write((char *) &p.storage[i], sizeof(p.storage[i]));
    }
  }
  if(!writeOut.good())
  {
    std::cout << "\nProblem writing file.";
  }
  writeOut.close();
  
  // Write fridge data
  writeOut.open("refrigerator.dat", std::ios::out | std::ios::binary);
  if(!writeOut)
  {
    std::cout << "\nError opening file to write." << std::endl;
    return;
  }
  {
    for(int i = 0; i < r.storage.size(); i++)
    {
      writeOut.write((char *) &r.storage[i], sizeof(r.storage[i]));
    }
  }
  if(!writeOut.good())
  {
    std::cout << "\nProblem writing file.";
  }
  writeOut.close();
  saved = true;
  std::cout << "Food data saved!";
  std::cin.clear();
  std::cin.ignore(1000, '\n');
  std::cout << "\nPresse 'Enter' to continue...";
  std::cin.get();
}

void Config::loadTextData(Pantry &p, Refrigerator &r)
{
  ifstream readIn;
  readIn.open("config.txt");
  int tempInt;
  readIn >> tempInt;
  p.setPantryItems(tempInt);
  readIn >> tempInt;
  r.setPantryItems(tempInt);
}

void Config::loadBinData(Pantry &p, Refrigerator &r)
{
  std::ifstream readIn("pantry.dat", std::ios::in | std::ios::binary);
  if(!readIn)
  {
    std::cout << "\nError reading file." << std::endl;
    return;
  }
  for(int i = 0; i < p.getPantryItems(); i++)
  {
    Food tempFood;
    readIn.read((char *) &tempFood, sizeof(tempFood));
    p.storeFood(tempFood);
  }
  readIn.close();
  
  readIn.open("fridge.dat", std::ios::in | std::ios::binary);
  if(!readIn)
  {
    std::cout << "\nError reading file." << std::endl;
    return;
  }
  for(int i = 0; i < r.getPantryItems(); i++)
  {
    Food tempFood;
    readIn.read((char *) &tempFood, sizeof(tempFood));
    r.storeFood(tempFood);
  }
  readIn.close();
}
