/******************************************************
** Program: wumpus.cpp
** Author: Joseph Di Lullo
** Date: 5/25/2021
** Description: for wumpus class
** Input: 
** Output: 
******************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "wumpus.h"

using std::cout;
using std::endl;

/*********************************************************************
** Function: wumpus::wumpus()
** Description: wumpus constrcutor
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
wumpus::wumpus(){
}

/*********************************************************************
** Function: void wumpus::percept()
** Description: percept function
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
void wumpus::percept(){
    cout << "You smell a terrible stench." << endl;
}

/*********************************************************************
** Function: void wumpus::draw()
** Description: draw function
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
void wumpus::draw(){
    if (debug == 0){
        cout << "~&~";
    }
    else{
        cout << "   ";
    }
} 

/*********************************************************************
** Function: bool wumpus::land_room()
** Description: ends game if player walks into wumpus room
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
bool wumpus::land_room(){
    cout << "You walked into a room with the wumpus! Game over!" << endl;
    std::exit(1);
    return false;
}

/*********************************************************************
** Function: bool wumpus::wumpus_check()
** Description: returns true if the arrow kills the wumpus
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
bool wumpus::wumpus_check(){
    cout << "You hit the wumpus and killed it!" << endl;
    return true;
}