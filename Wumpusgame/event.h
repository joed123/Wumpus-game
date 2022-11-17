#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#ifndef EVENT_H
#define EVENT_H

using std::cout;
using std::endl;

class event {
   private:

   public:
      virtual void percept() = 0;
      virtual void draw() = 0;
      virtual bool land_room() = 0; 
      virtual bool wumpus_check() = 0;
};

#endif