/******************************************************
** Program: gold.cpp
** Author: Joseph Di Lullo
** Date: 5/25/2021
** Description: for gold class
** Input: 
** Output: 
******************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "gold.h"


using std::cout;
using std::endl;

/*********************************************************************
** Function: gold::gold()
** Description: gold cunstructor
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
gold::gold(){
}

/*********************************************************************
** Function: void gold::percept()
** Description: gold percept
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
void gold::percept(){
    cout << "You see a glimmer nearby." << endl;
}

/*********************************************************************
** Function: void gold::draw()
** Description: draws gold
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
void gold::draw(){
    if (debug == 0){
        cout << " $ ";
    }
    else{
        cout << "   ";
    }
} 

/*********************************************************************
** Function: bool gold::land_room()
** Description: if players walks into gold room
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
bool gold::land_room(){
    return true;
}

/*********************************************************************
** Function: bool gold::wumpus_check()
** Description: checks if wumpus is alive
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
bool gold::wumpus_check(){
    return false;
}