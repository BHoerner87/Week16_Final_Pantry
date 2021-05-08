// Whiteboard will contain the data previously used by the Kitchen class.
//    Unlike the Kitchen class, Whiteboard will not contain other classes. It will only track data.
// Whiteboard will include:

// foodWaste  // a tracker for the amount of money wasted by throwing out expired food.
// an instance of the Calendar class--I'm not willing to lose that class yet.
// totalFood  // a running total of the food in the pantry
  //   don't forget to subtract when tossing food
// totalExpired // current amount of expired food. This will be added with a mutator function
    // which will itself be fed by a return value from an accumulator function in the Pantry class.
    // e.g. updateExpiredCount(pantry.catchExpired()) (or something) which will scan the
    // pantryStorage vector's Food items, accumulating each time one whose isExpired == true
        // While I'm here thinking about it, a Pantry class, I sure hope, can access w.getDate()
        // (-style functions) which will return it the date information it needs to compare with
        // its Foods' expiration dates and determine isExpired (via a setExpired() mutator)

#ifndef WHITEBOARD_H
#define WHITEBOARD_H

#include "Calendar.h"

class Whiteboard
{
private:
  Calendar cal;       // to contain date of app's current usage
  double wastePrice;  // to track money wasted

public:
  // Setters
  void setToday()
  { cal.setYear(); cal.setMonth(); cal.setDay(); }
  void addWaste(double w)
  { wastePrice += w; }

  // Getters
  double getWastePrice()
  { return wastePrice; }

  // Other methods

};

#endif
