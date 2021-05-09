// Brian Hoerner
// CIS 1202.501
// 3 May 2021

// This application is meant to track the inventory of one's kitchen perishables,
// including and especially when they expire. It is meant to be an aid for
// keeping a tidy kitchen, and for curbing one's over-buying habits to
// prevent food waste. Menu navigation is performed by entering numbers
// from menus of options, or by entering Y / N chars when provided with
// yes-no choices.

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
  void saveTextData(int, int);
  void saveBinData(Pantry &, Refrigerator &);
  void loadBinData(Pantry &, Refrigerator &);
  void loadTextData(Pantry &, Refrigerator &);
};

#endif
