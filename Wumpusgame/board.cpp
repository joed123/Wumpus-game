/******************************************************
** Program: board.cpp
** Author: Joseph Di Lullo
** Date: 5/25/2021
** Description: file for my board class 
** Input: movements, arrow shooting
** Output: board printed and updated.
******************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "board.h"
#include "wumpus.h"
#include "gold.h"
#include "bats.h"
#include "pit.h"


using std::cout;
using std::endl;
using std::cin;

/*********************************************************************
** Function: board constrctor
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
board::board(){
}

/*********************************************************************
** Function: void board::percept1(std::vector<std::vector<room>> &cave)
** Description: calls the sound functions if near an event
** Parameters: std::vector<std::vector<room>> &cave
** Pre-Conditions: 
** Post-Conditions:
*********************************************************************/
void board::percept1(std::vector<std::vector<room>> &cave){
    bool north = true;
    bool south = true;
    bool west = true;
    bool east = true;
    if (p.current_hori == 0){
        north = false;
    }
    if (p.current_hori == size - 1){
        south = false;
    }
    if (p.current_verti == 0){
        west = false;
    }
    if (p.current_verti == size - 1){
        east = false;
    }
    if (west == true){
        cave[p.current_hori][p.current_verti - 1].precept_room();

    }
    if (east == true){
        cave[p.current_hori][p.current_verti + 1].precept_room();
    }
    if (north == true){
        cave[p.current_hori - 1][p.current_verti].precept_room();
    }
    if (south == true){
        cave[p.current_hori + 1][p.current_verti].precept_room();
    }
}

/*********************************************************************
** Function: void board::setup_board(std::vector<std::vector<room>> &cave)
** Description: calls the functions that setup the board
** Parameters: std::vector<std::vector<room>> &cave
** Pre-Conditions: 
** Post-Conditions:
*********************************************************************/
void board::setup_board(std::vector<std::vector<room>> &cave){
    place_wumpus(cave);
    place_gold(cave);
    place_bat(cave);
    place_pit(cave);
    place_player(cave);
    play_game(cave);
}

/*********************************************************************
** Function: void board::wumpus_random(std::vector<std::vector<room>> &cave){
** Description: generates a random number to tell if the wumpus will move
** Parameters: std::vector<std::vector<room>> &cave
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
void board::wumpus_random(std::vector<std::vector<room>> &cave){
    if (wumpus){
        bool return1;
        int move = ((rand() + time(0)) % (4));
        if (move < 3){
            wumpus_move(cave);
        }
    }
}

/*********************************************************************
** Function: void board:: wumpus_move(std::vector<std::vector<room>> &cave)
** Description: moves the wumpus to a random location
** Parameters: std::vector<std::vector<room>> &cave
** Pre-Conditions: 
** Post-Conditions: wumpus is moved
*********************************************************************/
void board:: wumpus_move(std::vector<std::vector<room>> &cave){
    int horizantal = random_number();
    int vertical = random_number();
    if (cave[horizantal][vertical].ptr == nullptr){
        cave[horizantal][vertical] = cave[wumpus_hori][wumpus_verti];
        cave[wumpus_hori][wumpus_verti].ptr = nullptr;
        wumpus_verti = vertical;
        wumpus_hori = horizantal;
    }
    else{
        wumpus_move(cave);
    }
}

/*********************************************************************
** Function: void board::shoot_arrow(std::vector<std::vector<room>> &cave)
** Description: shoots an arrow if the user chooses to do so
** Parameters: std::vector<std::vector<room>> &cave
** Pre-Conditions: 
** Post-Conditions: arrow is shot
*********************************************************************/
void board::shoot_arrow(std::vector<std::vector<room>> &cave){
    std::string direction = "t"; 
    if (p.arrow > 0){
        while (direction == "t"){
            cout << "Which way would you like to shoot the arrow?('w' (north), 'a' (west), 's' (south), or 'd' (east), or 'n' (no))" << endl;
            cin >> direction;
            if (direction == "w"){
                cout << "You shot an arrow north!" << endl;
                int i = 0;
                arrow_hori = p.current_hori;
                arrow_verti = p.current_verti;
                while (i < 3 and arrow_hori != 0){
                    arrow_hori--;
                    if (cave[arrow_hori][arrow_verti].ptr != nullptr){
                        if (cave[arrow_hori][arrow_verti].ptr ->wumpus_check()){
                            cave[arrow_hori][arrow_verti].ptr = nullptr;
                            wumpus = false;
                        }
                    }
                i++;
                }
            wumpus_random(cave);
            p.arrow--;
            }
            else if (direction == "s"){
                cout << "You shot an arrow south!" << endl;
                int i = 0;
                arrow_hori = p.current_hori;
                arrow_verti = p.current_verti;
                while (i < 3 and arrow_hori != size - 1){
                    arrow_hori++;
                    if (cave[arrow_hori][arrow_verti].ptr != nullptr){
                        if (cave[arrow_hori][arrow_verti].ptr ->wumpus_check()){
                            cave[arrow_hori][arrow_verti].ptr = nullptr;
                            wumpus = false;
                        }
                    }
                    i++;
                }
            wumpus_random(cave);
            p.arrow--;
            }
            else if (direction == "a"){
                cout << "You shot an arrow west!" << endl;
                int i = 0;
                arrow_hori = p.current_hori;
                arrow_verti = p.current_verti;
                while (i < 3 and arrow_verti != 0){
                    arrow_verti--;
                    if (cave[arrow_hori][arrow_verti].ptr != nullptr){
                        if (cave[arrow_hori][arrow_verti].ptr ->wumpus_check()){
                            cave[arrow_hori][arrow_verti].ptr = nullptr;
                            wumpus = false;
                        }
                    }
                    i++;
                }
            wumpus_random(cave);
            p.arrow--;
            }
            else if (direction == "d"){
                cout << "You shot an arrow east!" << endl;
                int i = 0;
                arrow_hori = p.current_hori;
                arrow_verti = p.current_verti;
                while (i < 3 and arrow_verti != size - 1){
                    arrow_verti++;
                    if (cave[arrow_hori][arrow_verti].ptr != nullptr){
                        if (cave[arrow_hori][arrow_verti].ptr ->wumpus_check()){
                            cave[arrow_hori][arrow_verti].ptr = nullptr;
                            wumpus = false;
                        }
                    }
                    i++;
                }
            wumpus_random(cave);
            p.arrow--;
            }
            else if (direction == "n"){
                cout << "You choose to not shoot an arrow!" << endl;
            }
            else {
                cout << "Invalid entry for direction" << endl;
                direction = "t";
            }
        }
    }
    else{
        cout << "You do not have any arrows to shoot!" << endl;
    }
}

bool board:: end_game(){
    if ((p.treasure) and ((p.current_hori == escape_hori) and (p.current_verti == escape_verti))){
        return true;
    }
    else{
        return false;
    }
}

/*********************************************************************
** Function: void board::play_game(std::vector<std::vector<room>> &cave)
** Description: where the game is controlled/played
** Parameters: std::vector<std::vector<room>> &cave
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
void board::play_game(std::vector<std::vector<room>> &cave){
    bool game = true;
    while (game == true){
        print_board(cave);
        percept1(cave);
        move_room(cave);
        print_board(cave);
        if (end_game()){
            game = false;
            cout << "You won the game, congratulations! The game is over!" << endl;
            std::exit(1);
        }
        percept1(cave);
        shoot_arrow(cave);
    }
}

/*********************************************************************
** Function: void board::bat_move(std::vector<std::vector<room>> &cave)
** Description: the super bat moves the user
** Parameters: std::vector<std::vector<room>> &cave
** Pre-Conditions: 
** Post-Conditions: user is moved to a new room
*********************************************************************/
void board::bat_move(std::vector<std::vector<room>> &cave){
    int horizantal = random_number();
    int vertical = random_number();
    if (cave[horizantal][vertical].ptr == nullptr){
        cave[horizantal][vertical] = cave[p.current_hori][p.current_verti];
            cave[p.current_hori][p.current_verti].ptr = nullptr;
                cave[p.current_hori][p.current_verti].adventurer = false;
                p.current_verti = vertical;
                p.current_hori = horizantal;
    }
    else{
        if (cave[horizantal][vertical].ptr ->land_room()){
            cout << "You collected the gold!" << endl;
            cave[horizantal][vertical] = cave[p.current_hori][p.current_verti];
            cave[p.current_hori][p.current_verti].ptr = nullptr;
            cave[p.current_hori][p.current_verti].adventurer = false;
            p.current_hori = horizantal;
            p.current_verti = vertical;
            p.treasure = true;
        }
        else {
            bat_move(cave);
        }
    }
}

/*********************************************************************
** Function: void board::move_room(std::vector<std::vector<room>> &cave)
** Description: the user chooses what direction to move in this function
** Parameters: std::vector<std::vector<room>> &cave
** Pre-Conditions: 
** Post-Conditions: user is moved to a new room
*********************************************************************/
void board::move_room(std::vector<std::vector<room>> &cave){
    std::string movement = "t"; 
    bool north = true;
    bool south = true;
    bool west = true;
    bool east = true;
    if (p.current_hori == 0){
        north = false;
    }
    if (p.current_hori == size - 1){
        south = false;
    }
    if (p.current_verti == 0){
        west = false;
    }
    if (p.current_verti == size - 1){
        east = false;
    }
    while (movement == "t"){
        cout << endl;
        cout << "which way would you like to move? ('w' (north), 'a' (west), 's' (south), or 'd' (east)): ";
        cin >> movement;
        if (movement == "w"){
            if (north == true){
                if (cave[p.current_hori - 1][p.current_verti].ptr == nullptr){
                    cave[p.current_hori - 1][p.current_verti] = cave[p.current_hori][p.current_verti];
                    cave[p.current_hori][p.current_verti].ptr = nullptr;
                    cave[p.current_hori][p.current_verti].adventurer = false;
                    p.current_hori--;
                }
                else{
                    if (cave[p.current_hori - 1][p.current_verti].ptr ->land_room()){
                        cout << "You collected the gold!" << endl;
                        cave[p.current_hori - 1][p.current_verti] = cave[p.current_hori][p.current_verti];
                        cave[p.current_hori][p.current_verti].ptr = nullptr;
                        cave[p.current_hori][p.current_verti].adventurer = false;
                        p.current_hori--;
                        p.treasure = true;
                    }
                    else {
                    bat_move(cave);
                    }
                }
            }  
            else{
                cout << "Your not able to move north!" << endl;
                movement = "t"; 
            }
        }
        else if (movement == "s"){
            if (south == true){
                if (cave[p.current_hori + 1][p.current_verti].ptr == nullptr){
                    cave[p.current_hori + 1][p.current_verti] = cave[p.current_hori][p.current_verti];
                    cave[p.current_hori][p.current_verti].ptr = nullptr;
                    cave[p.current_hori][p.current_verti].adventurer = false;
                    p.current_hori++;
                }
                else{
                    if (cave[p.current_hori + 1][p.current_verti].ptr ->land_room()){
                        cout << "You collected the gold!" << endl;
                        cave[p.current_hori + 1][p.current_verti] = cave[p.current_hori][p.current_verti];
                        cave[p.current_hori][p.current_verti].ptr = nullptr;
                        cave[p.current_hori][p.current_verti].adventurer = false;
                        p.current_hori++;
                        p.treasure = true;
                    }
                    else {
                        bat_move(cave);
                    }
                }
            }   
            else{
                cout << "Your not able to move south!" << endl;
                movement = "t"; 
            }
        } 
        else if (movement == "a"){
            if (west == true){
                if (cave[p.current_hori][p.current_verti - 1].ptr == nullptr){
                    cave[p.current_hori][p.current_verti - 1] = cave[p.current_hori][p.current_verti];
                    cave[p.current_hori][p.current_verti].ptr = nullptr;
                    cave[p.current_hori][p.current_verti].adventurer = false;
                    p.current_verti--;
                }
                else{
                    if (cave[p.current_hori][p.current_verti - 1].ptr ->land_room()){
                        cout << "You collected the gold!" << endl;
                        cave[p.current_hori][p.current_verti - 1] = cave[p.current_hori][p.current_verti];
                        cave[p.current_hori][p.current_verti].ptr = nullptr;
                        cave[p.current_hori][p.current_verti].adventurer = false;
                        p.current_verti--;
                        p.treasure = true;
                    }
                    else {
                        bat_move(cave);
                    }
                }   
            }
            else{
                cout << "Your not able to move west!" << endl;
                movement = "t"; 
            }
        }
        else if (movement == "d"){
            if (east == true){
                if (cave[p.current_hori][p.current_verti + 1].ptr == nullptr){
                    cave[p.current_hori][p.current_verti + 1] = cave[p.current_hori][p.current_verti];
                    cave[p.current_hori][p.current_verti].ptr = nullptr;
                    cave[p.current_hori][p.current_verti].adventurer = false;
                    p.current_verti++;
                }
                else{
                    if (cave[p.current_hori][p.current_verti + 1].ptr ->land_room()){
                        cout << "You collected the gold!" << endl;
                        cave[p.current_hori][p.current_verti + 1] = cave[p.current_hori][p.current_verti];
                        cave[p.current_hori][p.current_verti].ptr = nullptr;
                        cave[p.current_hori][p.current_verti].adventurer = false;
                        p.current_verti++;
                        p.treasure = true;
                    }  
                    else {
                        bat_move(cave);
                    }
                }
            }
            else{
                cout << "Your not able to move east!" << endl;
                movement = "t"; 
            }
        }
        else {
            cout << "Invalid input try again!" << endl;
        }
    }
}

/*********************************************************************
** Function: void board::print_board(std::vector<std::vector<room>> &cave)
** Description: baord is printed
** Parameters: std::vector<std::vector<room>> &cave
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
void board::print_board(std::vector<std::vector<room>> &cave){
    cout << endl;
    cout << "The wumpus is represented by ~&~" << endl;
    cout << "A bat is represented by ^-^" << endl;
    cout << "A pit is represented by O" << endl;
    cout << "The gold is represented by $" << endl;
    cout << "The player is represented by *" << endl;
    cout << "The starting horizantal is: " << escape_hori << endl;
    cout << "The starting vertical is: " << escape_verti << endl;
    print_horizantal();
    for (int i = 0; i < size; i ++){
        for (int j = 0; j < size; j++){
            cout << "|";
            cave[i][j].print_room();
        }
        cout << "|" << endl;
        print_horizantal();
    }
}

/*********************************************************************
** Function: void board::print_horizantal()
** Description: horizantal lines on board is printed
** Parameters: std::vector<std::vector<room>> &cave
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
void board::print_horizantal(){
    for (int i = 0; i < size; i++){
        cout << "____";
    }
    cout << "_" << endl;
    cout << endl;
}

/*********************************************************************
** Function: int board::random_number()
** Description: generates a random number for the board
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
int board::random_number(){
    int s = ((rand() + time(0)) % (size));
    return s;
}

/*********************************************************************
** Function: void board::place_wumpus(std::vector<std::vector<room>> &cave)
** Description: creates and places the wumpus
** Parameters: std::vector<std::vector<room>> &cave
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
void board::place_wumpus(std::vector<std::vector<room>> &cave){
int vertical = random_number();
int horizantal = random_number();
int cave1 = 0;
while (cave1 == 0){
    if (cave[horizantal][vertical].get_pointer() != nullptr){
        vertical = random_number();
        horizantal = random_number();
        cave1 = 0;
    }
    else{
        cave[horizantal][vertical].ptr = &w;
        wumpus_hori = horizantal;
        wumpus_verti = vertical;
        cave1 = 1;
    }
}
}

/*********************************************************************
** Function: void board::place_gold(std::vector<std::vector<room>> &cave)
** Description: creates and places the gold
** Parameters: std::vector<std::vector<room>> &cave
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
void board::place_gold(std::vector<std::vector<room>> &cave){
int vertical = random_number();
int horizantal = random_number();
int cave1 = 0;
while (cave1 == 0){
    if (cave[horizantal][vertical].get_pointer() != nullptr){
        vertical = random_number();
        horizantal = random_number();
        cave1 = 0;
    }
    else{
        cave[horizantal][vertical].ptr = &g;
        cave1 = 1;
    }
}
}

/*********************************************************************
** Function: void board::place_bat(std::vector<std::vector<room>> &cave)
** Description: creates and places the bats
** Parameters: std::vector<std::vector<room>> &cave
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
void board::place_bat(std::vector<std::vector<room>> &cave){
int vertical = random_number();
int horizantal = random_number();
int vertical1 = random_number();
int horizantal1 = random_number();
int cave1 = 0;
int cave2 = 0;
while (cave1 == 0){
    if (cave[horizantal][vertical].get_pointer() != nullptr){
        vertical = random_number();
        horizantal = random_number();
        cave1 = 0;
    }
    else {
        cave[horizantal][vertical].ptr = &b1;
        cave1 = 1;
    }
}
while (cave2 == 0){
    if (cave[horizantal1][vertical1].get_pointer() != nullptr){
        vertical1 = random_number();
        horizantal1 = random_number();
        cave1 = 0;
    }
    else {
        cave[horizantal1][vertical1].ptr = &b2;
        cave2 = 1;
    }
}
}

/*********************************************************************
** Function: void board::place_pit(std::vector<std::vector<room>> &cave)
** Description: creates and places the pits
** Parameters: std::vector<std::vector<room>> &cave
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
void board::place_pit(std::vector<std::vector<room>> &cave){
int vertical = random_number();
int horizantal = random_number();
int vertical1 = random_number();
int horizantal1 = random_number();
int cave1 = 0;
int cave2 = 0;
while (cave1 == 0){
    if (cave[horizantal][vertical].get_pointer() != nullptr){
        vertical = random_number();
        horizantal = random_number();
        cave1 = 0;
    }
    else {
        cave[horizantal][vertical].ptr = &p1;
        cave1 = 1;
    }
}
while (cave2 == 0){
    if (cave[horizantal1][vertical1].get_pointer() != nullptr){
        vertical1 = random_number();
        horizantal1 = random_number();
        cave2 = 0;
    }
    else {
        cave[horizantal1][vertical1].ptr = &p2;
        cave2 = 1;
    }
}
}

/*********************************************************************
** Function: void board::place_player(std::vector<std::vector<room>> &cave)
** Description: creates and places the player
** Parameters: std::vector<std::vector<room>> &cave
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/
void board::place_player(std::vector<std::vector<room>> &cave){
int vertical = random_number();
int horizantal = random_number();
int cave1 = 0;
while (cave1 == 0){
     if (cave[horizantal][vertical].get_pointer() != nullptr){
        vertical = random_number();
        horizantal = random_number();
        cave1 = 0;
    }
    else{
        cave[horizantal][vertical].ptr = &p;
        escape_hori = horizantal;
        escape_verti = vertical;
        p.current_hori = horizantal;
        p.current_verti = vertical;
        p.treasure = false;
        cave1 = 1;
    }
}
}

