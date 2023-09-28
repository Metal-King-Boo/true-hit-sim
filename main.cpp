#include <iostream>
#include <string>
#include "classes.h"
#include "characters.h"
#include "weapons.h"
#include "arena.cpp"

/*
    Values used for the game int, to represent which game structure is being used
    0 = FE1    4 = FE5    8 = FE9    12 = FE13   16 = FE17
    1 = FE2    5 = FE6    9 = FE10   13 = FE14  
    2 = FE3    6 = FE7    10 = FE11  14 = FE15
    3 = FE4    7 = FE8    11 = FE12  15 = FE16
*/

// to start i need i/o functionality for copious amounts of data
// then i can move on to creating the GUI version utilzing this module

struct Myrmid {
    Character character;
    Myrmidon myrmidon;
    Weapon weapon;
    int game;
};

struct Merc {
    Character character;
    Mercenary mercenary;
    Weapon weapon;
    int game;
};

int main() {
    Myrmid rutger;
    Merc echidna;
    int rng = randNum();
    
    return 0;
}