#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "event.h"

#ifndef PLAYER_H
#define PLAYER_H

using std::cout;
using std::endl;


class player: public event {
    private:
    public:
        int arrow = 3;
        int current_hori;
        int current_verti;
        bool treasure;
        player();
        void percept();
        void draw(); 
        bool land_room();
        bool wumpus_check();
};

#endif