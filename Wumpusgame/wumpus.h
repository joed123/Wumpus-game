#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "event.h"
#ifndef WUMPUS_H
#define WUMPUS_H

using std::cout;
using std::endl;

class wumpus: public event {
   private:
   public:
      int debug;
      wumpus();
      void percept();
      void draw(); 
      bool land_room();
      bool wumpus_check();
};
#endif