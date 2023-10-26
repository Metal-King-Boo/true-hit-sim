#include <iostream>

#include "characters.h"

// declarations used in Character

// function used to set the stats of a character
// [HP, ATK/MAG, SKL, SPD, LCK, DEF, RES, CON]
// it takes in an array and an unsigned int
void Character::set_stats(int* arr, unsigned int x){
    // iterates through arr to apply the stats
    for(int i = 0; i < x; i++){
        stats[i] = arr[i];
    }
}

// function used to get the stats of a character
// [HP, ATK/MAG, SKL, SPD, LCK, DEF, RES, CON]
// returns an array
int* Character::get_stats(){
    return stats;
}

// function used to set the growth rates of a character
// [HP, ATK/MAG, SKL, SPD, LCK, DEF, RES, CON]
// it takes in an array and an unsigned int
void Character::set_growths(int* arr, unsigned int x){
    // iterates through arr to apply the growths
    for(int i = 0; i < x; i++){
        growths[i] = arr[i];
    }
}

// function used to get the growth rates of a character
// [HP, ATK/MAG, SKL, SPD, LCK, DEF, RES, CON]
// returns an array
int* Character::get_growths(){
    return growths;
}

// function used to set the level of a character
// it takes in an unsigned int
void Character::set_level(unsigned int x){
    level = x;
}

// function used to get the level of a character
// returns an int
int Character::get_level(){
    return level;
}

// testing function to display all information about a character
// displays all information from stats to level
// no parameters or return values
void Character::display(){
    std::cout << "Level: " << level << "\n";
    std::cout << "Character Statistics:\n";
    std::cout << "Stats: \n";
    std::cout << "HP - " << stats[0] << "         SPD - " << stats[3] << "\n";
    std::cout << "ATK/MAG - " << stats[1] << "    LCK - " << stats[4] << "\n";
    std::cout << "SKL/DEX - " << stats[2] << "    DEF - " << stats[5] << "\n";
    std::cout << "RES - " << stats[6] << "        CON - " << stats[7] << "\n";

    std::cout << "Character Growths:\n";
    std::cout << "HP - " << growths[0] << "%         SPD - " << growths[3] << "%\n";
    std::cout << "ATK/MAG - " << growths[1] << "%    LCK - " << growths[4] << "%\n";
    std::cout << "SKL/DEX - " << growths[2] << "%    RES - " << growths[5] << "%\n\n";
    std::cout << "RES - " << growths[6] << "%        CON - " << growths[6] << "%\n\n";
}