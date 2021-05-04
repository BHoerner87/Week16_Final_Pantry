// Config settings
// Includes saved, which becomes false any time a new item is added, or an existing one tossed, or expiry check run

class Config
{
private:
  bool saved;
public:
  setToSaved()
  { saved = true; cout << "\nDate saved.\n" }
  
  setUnsaved()
  { saved = false; cout << "\nYou have unsaved data.\n" }
};
