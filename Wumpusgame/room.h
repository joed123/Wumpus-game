#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "event.h"
#ifndef ROOM_H
#define ROOM_H

using std::cout;
using std::endl;

class room {
    private:
    public:
        bool adventurer = false;
        event * ptr = nullptr;
        event* get_pointer();
        room();
        void print_room();
        void set_pointer(event*);
        void precept_room();
};

#endif