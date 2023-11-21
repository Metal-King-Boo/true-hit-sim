#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

#include "classes.h"
#include "characters.h"
#include "weapons.h"
#include "arena.cpp"


// https://forums.serenesforest.net/index.php?/topic/91108-a-deep-dive-into-level-up-mechanics/


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

// need weapon level for blazing sword in character

// declaration of functions used in main
void createUnit(Unit *unit);
void createCharacter(Unit *unit);
void createClass(Unit *unit);
void createWeapon(Unit *unit);
void levelUp(Unit *unit);

// function used to populate a unit
// builds character, class, weapon, game, name, and current hp
// has no return value; takes in a unit struct
void createUnit(Unit *unit) {
    unit->game = 5;
    unit->name = "Dieck";

    createCharacter(unit);
    createClass(unit);
    createWeapon(unit);

    int *arr[8];
    *arr = unit->character.get_stats();
    unit->current_hp = *arr[0];
}

// function used to populate data on characters
// fills in the current level, stats, and growths
// has no return value; takes in a unit struct
void createCharacter(Unit *unit) {
    int arr[] = {26, 9, 12, 10, 5, 6, 1, 13};
    int arr2[] = {90, 40, 40, 30, 35, 20, 15, 0};
    unit->character.set_stats(arr, 8);
    unit->character.set_growths(arr2, 8);
    unit->character.set_level(5);
}

// function used to populate data on classes
// fills in the growths, 
// has no return value; takes in a unit struct
void createClass(Unit *unit) {
    int arr[] = {0, 0, 0, 0, 0, 0, 0, 0};
    unit->base.set_name("Mercenary");
    unit->base.set_race("Human");
    unit->base.set_type("Infantry");
    unit->base.set_growths(arr, 8);
}

// function used to populate data on weapons
// fills in the might, weight, accuracy, triangle, effectiveness, range, etc.
// has no return value; takes in a unit struct
void createWeapon(Unit *unit) {
    int arr[] = {0, 0, 0, 0, 0, 0, 0, 0};
    unit->weapon.set_name("Steel Sword");
    unit->weapon.set_weapon_might(8);
    unit->weapon.set_weapon_weight(10);
    unit->weapon.set_weapon_accuracy(70);
    unit->weapon.set_weapon_crit(0);
    unit->weapon.set_range(1, 1);
    unit->weapon.set_weapon_effective("None");
    unit->weapon.set_weapon_kills(0);
    unit->weapon.set_weapon_triangle('R');
    unit->weapon.set_brave(false);
    unit->weapon.set_bonus_stats(arr, 8);
}

// function used to level up a unit
// [FE6-8] forces up to 2 rerolls if no stat increased
// this is not effected by reaching stat caps
// has no return value; takes in a unit struct
void levelUp(Unit *unit){
    int total_growth_rates[8];
    int total_growths[8];
    bool leveled = false;
    int loop = 0;

    int *arr[8];
    int *arr2[8];
    int *arr3[8];
    *arr = unit->character.get_growths();
    *arr2 = unit->base.get_growths();
    *arr3 = unit->character.get_stats();

    // iterates to collect the total growth rate of all stats
    for(int i = 0; i < 8; i++) {
        total_growth_rates[i] = *arr[i] + *arr2[i];
    }

    // iterates to get which stats grow
    // loops it if no stats where gained [GBA]
    // loops a total of three times if you fail
    do {
        for(int j = 0; j < 8; j++) {
            int seed = randNum();
            if(seed <= total_growth_rates[j]) {
                total_growths[j] = 1;
                leveled = true;
            }
        }
        loop++;
    }
    while(leveled == false || loop == 3);

    // merge the stats to reflect the growth
    for(int k = 0; k < 8; k++) {
        total_growths[k] = total_growths[k] + *arr3[k];
    }

    // send the stats back to the unit and raise the level
    unit->character.set_growths(total_growths, 8);
    unit->character.set_level(unit->character.get_level() + 1);
}

// shows the relevant information for battle with two units
// shows lvl, current hp, damage, hit rate, accuracy, speed, names, classes, and weapons
// has no return value; takes in two unit structs
void battleForecast(Unit *unit, Unit *unit2) {
    int *arr = unit->character.get_stats();
    int *arr2 = unit2->character.get_stats();

    int p1_weapon_triangle = weaponTriangle(unit->weapon.get_weapon_triangle(), unit2->weapon.get_weapon_triangle());
    int p2_weapon_triangle = weaponTriangle(unit2->weapon.get_weapon_triangle(), unit->weapon.get_weapon_triangle());
    int p1_attack_speed = attackSpeed(arr[3], unit->weapon.get_weapon_weight(), arr[7]);
    int p2_attack_speed = attackSpeed(arr2[3], unit2->weapon.get_weapon_weight(), arr2[7]);
    int p1_battle_crit_chance = battleCritChance(critChance(arr[2], unit->weapon.get_weapon_crit(), 0, unit->base.get_name()), dodgeChance(arr2[4], 0));
    int p2_battle_crit_chance = battleCritChance(critChance(arr2[2], unit2->weapon.get_weapon_crit(), 0, unit2->base.get_name()), dodgeChance(arr[4], 0));
    
    // 
    std::cout << "--------------\n";
    std::cout << "|" << unit->name << "       |\n";
    std::cout << "|" << unit->base.get_name() << "   |\n";
    std::cout << "|" << unit->weapon.get_name() << " |\n";
    std::cout << "|   ---------|\n";
    std::cout << "|  " << unit->character.get_level() << "| LV |  " << unit2->character.get_level() << "|\n";
    std::cout << "| " << unit->current_hp << "| HP | " << unit2->current_hp << "|\n";
    // incorrect it shows the damage with the crit attached
    // should just be attack() - defense() no crit involved
    std::cout << "| " << damage(false, attack(arr[1], unit->weapon.get_weapon_might(), p1_weapon_triangle, weaponEffectiveness(unit->weapon.get_weapon_effective(), unit2->base.get_type(), unit2->base.get_race()), 0), defense(arr2[5], 0, 0)) << "| DMG| "
              << damage(false, attack(arr2[1], unit2->weapon.get_weapon_might(), p2_weapon_triangle, weaponEffectiveness(unit2->weapon.get_weapon_effective(), unit->base.get_type(), unit->base.get_race()), 0), defense(arr[5], 0, 0)) << "|\n";
    std::cout << "|  " << p1_attack_speed << "| AC |  " << p2_attack_speed << "|\n";
    std::cout << "| " << battleAccuracy(accuracy(unit->weapon.get_weapon_accuracy(), arr[2], arr[4], p1_weapon_triangle, 0), avoid(p2_attack_speed, arr2[4], 0, 0)) << "| HIT| "
              << battleAccuracy(accuracy(unit2->weapon.get_weapon_accuracy(), arr2[2], arr2[4], p2_weapon_triangle, 0), avoid(p1_attack_speed, arr[4], 0, 0)) << "|\n";
    std::cout << "| " << p1_battle_crit_chance << "|CRIT| " << p2_battle_crit_chance << "|";
    std::cout << "|---------   |\n";
    std::cout << "| " << unit2->weapon.get_name() << "|\n";
    std::cout << "|   " << unit2->base.get_name() << "|\n";
    std::cout << "|       " << unit->name << "|\n";   
    std::cout << "--------------\n";       
}

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

// make a combat forecast?
// preferably so

// have to make a uml diagram for how main will run combat
// need to decide on 1 vs multiple combatants

// level up feature needs to be added 

int main() {
    // the random number seed is generated based on the current time
    srand(time(0));
    int rng = randNum();
    Unit echidna;
    Unit gorgon;
    
    createUnit(&echidna);
    createUnit(&gorgon);

    std::cout << "Current HP: " << echidna.current_hp << "\n";
    std::cout << "Game: FE" << echidna.game + 1 << "\n";
    std::cout << "Name: " << echidna.name << "\n\n";

    echidna.character.display();
    echidna.base.display();
    echidna.weapon.display();

    return 0;
}