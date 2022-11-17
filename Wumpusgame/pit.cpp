/******************************************************
** Program: pit.cpp
** Author: Joseph Di Lullo
** Date: 5/25/2021
** Description: for pit class
** Input: 
** Output: 
******************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "pit.h"

using std::cout;
using std::endl;

/*********************************************************************
** Function: pit::pit()
** Description: pit constrctor
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
pit::pit(){
}

/*********************************************************************
** Function: void pit::percept()
** Description: percept function for pit
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
void pit::percept(){
    cout << "You feel a breeze." << endl;
}

/*********************************************************************
** Function: void pit::draw()
** Description: draw function for pit
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
void pit::draw(){
    if (debug == 0){
        cout << " O ";
    }
    else{
        cout << "   ";
    }
} 

/*********************************************************************
** Function: bool pit::land_room()
** Description: ends game if user walks into room with a pit
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
bool pit::land_room(){
    cout << "You walked into a room with a pit! Game over!" << endl;
    std::exit(1);
    return false;
}

/*********************************************************************
** Function: bool bats::wumpus_check()
** Description: checks if wumpus is alive
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
bool pit::wumpus_check(){
    return false;
}