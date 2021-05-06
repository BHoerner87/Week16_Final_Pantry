// Config settings
// Includes saved, which becomes false any time a new item is added, or an existing one tossed, or expiry check run

#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>

class Config
{
private:
  bool saved;
public:
  void setToSaved()
  { saved = true; std::cout << "\nDate saved.\n"; }
  
  void setUnsaved()
  { saved = false; std::cout << "\nYou have unsaved data.\n"; }
};

#endif
