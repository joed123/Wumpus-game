#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "event.h"
#ifndef GOLD_H
#define GOLD_H

using std::cout;
using std::endl;

class gold: public event {
   private:
   public:
      gold();
      int debug;
      void percept();
      void draw(); 
      bool land_room();
      bool wumpus_check();
};

#endif