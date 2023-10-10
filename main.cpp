#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

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
// then i can move on to creating the GUI version utilizing this module

struct Unit {
    Character character;
    BaseClass base;
    Weapon weapon;
    std::string name;
    int game;
};

/*struct Myrmid {
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
};*/

// need a function to set the values of the character, class, weapon, and game for every struct created

// functions used to select which game's crit formula to use
int critSelect(Unit *unit) {
    int crit_chance;

    // switch case to get the particular game
    switch (unit->game)
    {
    // use case for FE6
    case 5:
        crit_chance = critChance(12, 0, 30, 0);
        break;
    // use case for FE7
    case 6:
        //crit_chance = critChance(7, 15, 30, 0, 0);
        break;
    default:
        break;
    }

    return crit_chance;
}

// functions used to select which game's dodge formula to use
int dodgeSelect(Unit *unit) {
    int dodge_chance;

    // switch case to get the particular game
    switch (unit->game)
    {
    // use case for FE6
    case 5:
        dodge_chance = dodgeChance(3, 0);
        break;
    // use case for FE7    
    case 6:
        //dodge_chance = dodgeChance(12, 0, 0);
        break;
    default:
        break;
    }

    return dodge_chance;
};

int main() {
    // the random number seed is generated based on the current time
    srand(time(0));
    int rng = randNum();
    Unit echidna;
    
    int arr[6] = {randNum(), randNum(), randNum(), randNum(), randNum(), randNum()};
    int arr2[7] = {randNum(), randNum(), randNum(), randNum(), randNum(), randNum(), randNum()};

    /*for(int i = 0; i < 5; i++){
        std::cout << attack(20, 30, 1, 1, 0) << " ";
    }

    std::cout << "\n\n";*/

    return 0;
}