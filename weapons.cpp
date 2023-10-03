#include <iostream>
#include "weapons.h"

// declarations of Weapons
// function that sets how strong a weapon is
void Weapon::set_weapon_might(unsigned int x){
    weapon_might = x;
}

// function that returns the weapon's strength
int Weapon::get_weapon_might(){
    return weapon_weight;
}

// function that sets how heavy a weapon is
void Weapon::set_weapon_weight(unsigned int x){
    weapon_weight = x;
}

// function that returns the weapon's weight
int Weapon::get_weapon_weight(){
    return weapon_weight;
}

// function that sets the weapon's kill count (FEATURE ONLY USED IN FE4)
// DEFAULT VALUE SHOULD BE ZERO;
void Weapon::set_weapon_kills(unsigned int x){
    weapon_kills = x;
}

// function that returns the weapon's kill count
int Weapon::get_weapon_kills(){
    return weapon_kills;
}

// function that sets the weapon's natural crit rate
void Weapon::set_weapon_crit(unsigned int x){
    weapon_crit = x;
}

// function that returns the weapon's natural crit rate
int Weapon::get_weapon_crit(){
    return weapon_crit;
}

// function that sets the weapon's accuracy
void Weapon::set_weapon_accuracy(unsigned int x){
    weapon_accuracy = x;
}

// function that returns the weapon's accuracy
int Weapon::get_weapon_accuracy(){
    return weapon_accuracy;
}

// function that sets the weapon's triangle position
void Weapon::set_weapon_triangle(char triangle){
    weapon_triangle = triangle;
}

// function that returns the weapon's triangle position
char Weapon::get_weapon_triangle(){
    return weapon_triangle;
}

// function that sets the weapon's unit effectiveness
void Weapon::set_weapon_effective(std::string effective){
    weapon_effective = effective;
}
// function that returns the weapon's unit effectiveness
std::string Weapon::get_weapon_effective(){
    return weapon_effective;
}

// function that sets any bonus stats a weapon has
void Weapon::set_bonus_stats(int *arr, unsigned int x){
    // iterates through arr to match up with the standard stat order
    for(int i = 0; i < x; i++){
        bonus_stats[i] = arr[i];
    }
}

// function that returns any bonus stats a weapon has
int* Weapon::get_bonus_stats(){
    return bonus_stats;
}