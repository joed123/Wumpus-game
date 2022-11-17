/******************************************************
** Program: room.cpp
** Author: Joseph Di Lullo
** Date: 5/25/2021
** Description: for room class
** Input: 
** Output: 
******************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "room.h"
using std::cout;
using std::endl;

/*********************************************************************
** Function: room::room()
** Description: room constrctor
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
room::room(){
}

/*********************************************************************
** Function: void room::print_room()
** Description: calls the draw functions for the events
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
void room::print_room(){
    if (ptr == nullptr){
        cout << "   ";
    } 
    else {
        ptr ->draw();
    }
}

/*********************************************************************
** Function: event* room::get_pointer()
** Description: returns pointer for the specific room
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
event* room::get_pointer(){
    return ptr;
}

/*********************************************************************
** Function: void room::set_pointer(event* ptr1)
** Description: sets a new pointer
** Parameters: event* ptr1
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
void room::set_pointer(event* ptr1){
    ptr = ptr1;
}

/*********************************************************************
** Function: void room::precept_room()
** Description: calls the percept functions for the events
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
void room::precept_room(){
 if (ptr == nullptr){
    } 
    else{
        ptr ->percept();
    }   
}