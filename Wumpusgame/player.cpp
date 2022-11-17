/******************************************************
** Program: player.cpp
** Author: Joseph Di Lullo
** Date: 5/25/2021
** Description: for player class
** Input: 
** Output: 
******************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "player.h"


using std::cout;
using std::endl;

/*********************************************************************
** Function: player::player()
** Description: player constrcutor
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
player::player(){
}

/*********************************************************************
** Function: void player::percept(){
** Description: 
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
void player::percept(){
}

/*********************************************************************
** Function: void player::draw()
** Description: draws player
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
void player::draw(){
    cout << " * ";
} 

/*********************************************************************
** Function: bool player::land_room()
** Description: 
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
bool player::land_room(){
    return false;
}

/*********************************************************************
** Function: bool player::wumpus_check(){
** Description: checks if there is a wumpus
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
bool player::wumpus_check(){
    return false;
}
