#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "event.h"
#ifndef BATS_H
#define BATS_H

using std::cout;
using std::endl;

class bats: public event {
   private:
   public:
      int debug;
      bats();
      void percept();
      void draw();
      bool land_room(); 
      bool wumpus_check();
};
#endif