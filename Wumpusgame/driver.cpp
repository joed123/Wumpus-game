/******************************************************
** Program: driver.cpp
** Author: Joseph Di Lullo
** Date: 5/25/2021
** Description: The driver for my adventure game 
** Input: 2 command line arguments
** Output: some couts for the command line arguments
******************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "room.h"
#include "event.h"
#include "wumpus.h"
#include "bats.h"
#include "pit.h"
#include "gold.h"
#include "board.h"
using std::cout;
using std::endl;

int main(int argc, char *argv[]){
    if ((argc != 3)){
		cout << "Invalid number of command line arguments!" << endl;
		return 1; 	
	}
    board b;
	b.size = atoi(argv[1]);
    std::string debug = argv[2];
    int debug1 = 2;
    if (debug == "true"){
        debug1 = 0;
    }
    else if (debug == "false"){
        debug1 = 1;
    }
    if ((b.size < 4) || (b.size > 20)){
		cout << "Invlaid board size!" << endl;
		return 1; 	
	}
    if ((debug1 != 0) && (debug1 != 1)){
        cout << "Invalid third command line argument please enter true(debug mode) or false(normal mode)!" << endl;
		return 1; 
    }
    srand(time(0));
    std::vector <std::vector<room>> cave(b.size, std::vector<room>(b.size));
    b.w.debug = debug1;
    b.b1.debug = debug1;
    b.b2.debug = debug1;
    b.p1.debug = debug1;
    b.p2.debug = debug1;
    b.g.debug = debug1;
    b.setup_board(cave);
    return 0;
}
