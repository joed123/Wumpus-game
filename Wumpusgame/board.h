#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "wumpus.h"
#include "gold.h"
#include "bats.h"
#include "pit.h"
#include "room.h"
#include "player.h"
#ifndef BOARD_H
#define BAORD_H

using std::cout;
using std::endl;


class board {
    private:
    public:
        wumpus w;
        bats b1;
        bats b2;
        gold g;
        pit p1;
        pit p2;
        player p;
        int size;
        int escape_hori;
        int escape_verti;
        int arrow_verti;
        int arrow_hori;
        int wumpus_hori;
        int wumpus_verti;
        bool wumpus = true;
        int debug;
        board();
        void setup_board(std::vector<std::vector<room>> &);
        void print_board(std::vector<std::vector<room>> &);
        void print_horizantal();
        int random_number();
        void place_wumpus(std::vector<std::vector<room>> &);
        void place_gold(std::vector<std::vector<room>> &);
        void place_bat(std::vector<std::vector<room>> &);
        void place_pit(std::vector<std::vector<room>> &);
        void place_player(std::vector<std::vector<room>> &);
        void percept1(std::vector<std::vector<room>> &);
        void move_room(std::vector<std::vector<room>> &);
        void play_game(std::vector<std::vector<room>> &);
        void bat_move(std::vector<std::vector<room>> &);
        void shoot_arrow(std::vector<std::vector<room>> &);
        void wumpus_move(std::vector<std::vector<room>> &);
        void wumpus_random(std::vector<std::vector<room>> &);
        bool end_game();
};

#endif