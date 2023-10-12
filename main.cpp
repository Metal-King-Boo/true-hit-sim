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
    int current_hp;
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
        crit_chance = critChance(12, 30, 0, unit->base.get_name());
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

    // 113 and 51 respectively
    int val1 = attack(20, 30, 1, true, 0);
    int val2 = attack(20, 30, 1, false, 0);

    // 28 and 17 respectively
    int val3 = defense(25, 0, 3);
    int val4 = defense(7, 0, 10);

    // 69, 23, 0, and 0 respectively
    int val5 = damage(true, val2, val3);
    int val6 = damage(false, val2, val3);
    int val7 = damage(true, 15, 20);
    int val8 = damage(false, 15, 20);

    // 68 and 38 respectively
    int val9 = critChance(17, 30, 30, 0);
    int val10 = critChance(17, 0, 30, 0);

    // 10 and 2 respectively
    int val11 = dodgeChance(20, 0);
    int val12 = dodgeChance(5, 0);

    // 99, 89, and 79 respectively
    int val13 = accuracy(80, 15, 5, 1, 0);
    int val14 = accuracy(80, 15, 5, 2, 0);
    int val15 = accuracy(80, 15, 5, 3, 0);

    // 21, 10, and 0 respectively
    int val16 = attackSpeed(25, 10, 6);
    int val17 = attackSpeed(10, 5, 14);
    int val18 = attackSpeed(5, 10, 1);

    // 70 and 25 respectively
    int val19 = avoid(val17, 20, 0, 30);
    int val20 = avoid(val18, 5, 0, 20);

    // 29 and 0 respectively
    int val21 = battleAccuracy(val13, val19);
    int val22 = battleAccuracy(10, val20);


    std::cout << "calling the function gets = " << val21 << " ";

    std::cout << "\n\n";

    std::cout << "calling the function gets = " << val22 << " ";

    std::cout << "\n\n";

    return 0;
}