#include <iostream>
#include "characters.h"

// declarations used in Character
// function used to set the stats of a character
void Character::set_stats(int* arr, unsigned int x){
    // iterates through arr to apply them to stats
    for(int i = 0; i < x; i++){
        stats[i] = arr[i];
    }
}

// function used to get the stats of a character
int* Character::get_stats(){
    return stats;
}

// function used to set the growth rates of a character
void Character::set_growths(int* arr, unsigned int x){
    // iterates through arr to apply them to growths
    for(int i = 0; i < x; i++){
        growths[i] = arr[i];
    }
}

// function used to get the growth rates of a character
int* Character::get_growths(){
    return growths;
}

// function used to set the level of a character
void Character::set_level(unsigned int x){
    level = x;
}

// function used to get the level of a character
int Character::get_level(){
    return level;
}