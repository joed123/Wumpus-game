/******************************************************
** Program: bats.cpp
** Author: Joseph Di Lullo
** Date: 5/25/2021
** Description: for bats class
** Input: 
** Output: 
******************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "bats.h"
#include "board.h"
#include <time.h>

using std::cout;
using std::endl;

/*********************************************************************
** Function: bats::bats()
** Description: bats constrcutor
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
bats::bats(){
}

/*********************************************************************
** Function: void bats::percept()
** Description: bat percept function
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
void bats::percept(){
    cout << "You hear wings flapping." << endl;
}

/*********************************************************************
** Function: void bats::draw()
** Description: draws bats
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
void bats::draw(){
    if(debug == 0){
        cout << "^-^";
    }
    else {
        cout << "   ";
    }
} 

/*********************************************************************
** Function: bool bats::land_room()
** Description: called if user walks into room with super bat
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
bool bats::land_room(){
    cout << "You ran into a super bat!" << endl;
    return false;
}

/*********************************************************************
** Function: bool bats::wumpus_check()
** Description: checks if wumpus is alive
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
bool bats::wumpus_check(){
    return false;
}