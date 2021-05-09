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
  void saveTextData(int, int);
  void saveBinData(Pantry &, Refrigerator &);
  void loadBinData(Pantry &, Refrigerator &);
  void loadTextData(Pantry &, Refrigerator &);
};

#endif /* Config_hpp */
