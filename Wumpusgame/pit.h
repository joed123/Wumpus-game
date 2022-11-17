#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "event.h"

#ifndef PIT_H
#define PIT_H
using std::cout;
using std::endl;

class pit: public event {
   private:
   public:
      pit();
      int debug;
      void percept();
      void draw(); 
      bool land_room();
      bool wumpus_check();
};

#endif