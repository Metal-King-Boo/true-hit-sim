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

// to start i need file i/o functionality for copious amounts of data
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
    
    // blurb of code that outputs a battle forecast similar to the one seen in FE5
    std::cout << "--------------\n";
    std::cout << "|" << unit->name << "       |\n";
    std::cout << "|" << unit->base.get_name() << "   |\n";
    std::cout << "|" << unit->weapon.get_name() << " |\n";
    std::cout << "|   ---------|\n";
    std::cout << "|  " << unit->character.get_level() << "| LV |  " << unit2->character.get_level() << "|\n";
    std::cout << "| " << unit->current_hp << "| HP | " << unit2->current_hp << "|\n";
    std::cout << "| " << damage(false, attack(arr[1], unit->weapon.get_weapon_might(), p1_weapon_triangle, weaponEffectiveness(unit->weapon.get_weapon_effective(), unit2->base.get_type(), unit2->base.get_race()), 0), defense(arr2[5], 0, 0)) << "| DMG| "
              << damage(false, attack(arr2[1], unit2->weapon.get_weapon_might(), p2_weapon_triangle, weaponEffectiveness(unit2->weapon.get_weapon_effective(), unit->base.get_type(), unit->base.get_race()), 0), defense(arr[5], 0, 0)) << "|\n";
    std::cout << "| " << p1_attack_speed << "| AC | " << p2_attack_speed << "|\n";
    std::cout << "| " << battleAccuracy(accuracy(unit->weapon.get_weapon_accuracy(), arr[2], arr[4], p1_weapon_triangle, 0), avoid(p2_attack_speed, arr2[4], 0, 0)) << "| HIT| "
              << battleAccuracy(accuracy(unit2->weapon.get_weapon_accuracy(), arr2[2], arr2[4], p2_weapon_triangle, 0), avoid(p1_attack_speed, arr[4], 0, 0)) << "|\n";
    std::cout << "|  " << p1_battle_crit_chance << "|CRIT|  " << p2_battle_crit_chance << "|\n";
    std::cout << "|---------   |\n";
    std::cout << "| " << unit2->weapon.get_name() << "|\n";
    std::cout << "|   " << unit2->base.get_name() << "|\n";
    std::cout << "|       " << unit->name << "|\n";   
    std::cout << "--------------\n";       
}

// used to determine if a character died to an attack in combat
// returns a boolean; takes in a unit struct
bool isDead(Unit *unit) {

    if(unit->current_hp == 0) {
        return true;
    }
    return false;
}

// used for the individual attacks
// this function is looped for each combat "round" possible in a fight
// a round consists of both parties attacking, or 1 party attacking and the other dying, or 1 party attacking and the other cannot retaliate.
// does not return anything
void combat(int *attacks1, int *attacks2, bool *combat_counter, int *triangle_speed_crit, int p1_damage, int p2_damage, Unit *unit, Unit *unit2) {
    
    // player 1 swings on the enemy
    // makes sure no value reaches zero
    unit2->current_hp -= p1_damage;
    if(unit2->current_hp < 0){
        unit2->current_hp = 0;
    }
    // decrement attacks1
    attacks1 --;
    // check if the opponent died
    if(isDead(unit2)){
        combat_counter = false;
        return;
    }

    // the enemy swings in retaliation
    // makes sure no value reaches zero
    unit->current_hp -= p2_damage;
    if(unit->current_hp < 0){
        unit->current_hp = 0;
    }
    // decrement attacks2
    attacks2--;
    // check if the opponent died
    if(isDead(unit)){
        combat_counter = false;
        return;
    }

    // when both players have attacked and no one died this checks
    // it will end that round of combat
    if(attacks1 == 0 && attacks2 == 0){
        combat_counter = false;
        return;
    }
    // should also account for brave weapons eventually
}

// used for the total combat scene 
// so far only works for physical attacks and base classes
// might make separate versions of this for different ranges or a selector
// also need to think about magic damage
void strike(Unit *unit, Unit *unit2, bool brave) {
    int *arr = unit->character.get_stats();
    int *arr2 = unit2->character.get_stats();
    int p1_attacks;
    int p2_attacks;

    // defines all the values used in the combat for p1
    int p1_weapon_triangle = weaponTriangle(unit->weapon.get_weapon_triangle(), unit2->weapon.get_weapon_triangle());
    int p1_attack_speed = attackSpeed(arr[3], unit->weapon.get_weapon_weight(), arr[7]);
    int p1_battle_crit_chance = battleCritChance(critChance(arr[2], unit->weapon.get_weapon_crit(), 0, unit->base.get_name()), dodgeChance(arr2[4], 0));
    int p1_weapon_effective = weaponEffectiveness(unit->weapon.get_weapon_effective(), unit2->base.get_type(), unit2->base.get_race());
    int p1_attack = attack(arr[1], unit->weapon.get_weapon_might(), p1_weapon_triangle, p1_weapon_effective, 0);

    // defines all the values used in combat for p2
    int p2_weapon_triangle = weaponTriangle(unit2->weapon.get_weapon_triangle(), unit->weapon.get_weapon_triangle());
    int p2_attack_speed = attackSpeed(arr2[3], unit2->weapon.get_weapon_weight(), arr2[7]);
    int p2_battle_crit_chance = battleCritChance(critChance(arr2[2], unit2->weapon.get_weapon_crit(), 0, unit2->base.get_name()), dodgeChance(arr[4], 0));
    int p2_weapon_effective = weaponEffectiveness(unit2->weapon.get_weapon_effective(), unit->base.get_type(), unit->base.get_race());
    int p2_attack = attack(arr2[1], unit2->weapon.get_weapon_might(), p2_weapon_triangle, p2_weapon_effective, 0);

    int p1_defense = defense(arr[5], 0, 0);
    int p2_defense = defense(arr2[5], 0, 0);

    int triangle_speed_crit[] = {p1_weapon_triangle, p1_attack_speed, p1_battle_crit_chance, p2_weapon_triangle, p2_attack_speed, p2_battle_crit_chance};

    // gives the attack counts for each person in combat
    // the first if statement matches for when unit 1 is faster than unit 2
    if(p1_attack_speed > p2_attack_speed) {
        // this runs to check if unit 1 will double unit 2
        if((p1_attack_speed - p2_attack_speed) >= 4) {
            p1_attacks = 2;
            p2_attacks = 1;
        } else { 
            p1_attacks = 1;
            p2_attacks = 1;
        }
    } 
    // the else if statement matches for when unit 2 is faster than unit 1
    else if(p2_attack_speed > p1_attack_speed) {
        // this runs to check if unit 2 will double unit 1
        if((p2_attack_speed - p1_attack_speed) >= 4) {
            p2_attacks = 2;
            p1_attacks = 1;
        } else {
            p2_attacks = 1;
            p1_attacks = 1;
        }
    } 
    // the else statement matches for when unit 1 or unit 2 are the same speed
    else {
        p1_attacks = 1;
        p2_attacks = 1;
    }

    // -------------------------------  FINISH FOR ATTACKS --------------------------
    
    bool combat_counter = true;

    do
    {
        int p1_damage = damage(criticalCheck(p1_battle_crit_chance), p1_attack, p2_defense);
        int p2_damage = damage(criticalCheck(p2_battle_crit_chance), p2_attack, p1_defense);
        combat(&p1_attacks, &p2_attacks, &combat_counter, triangle_speed_crit, p1_damage, p2_damage, unit, unit2);
    } while (combat_counter);
    
}

/*
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
};*/

// need to decide on 1 vs multiple combatants
// level up feature needs to be added [complete?]
// promotion needs to be added
// isAlive(), strike(), and combat() functions need to be made [isAlive() is done, strike() in progress, combat() in progress]
// need to add advanced classes slot
// eventually switch to no longer using the console to display

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

    battleForecast(&echidna, &gorgon);

    return 0;
}